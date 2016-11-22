import java.io.*;
import java.util.*;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author shashwat001
 */
public class Main 
{
    static int[] primes = new int[10000001];
    static int[] dx = {0,1,0,-1};
    static int[] dy = {1,0,-1,0};
    static int MAX = 1000000;

    public Main() 
    {

    }
    
    
    public static void main(String[] args)
    {
        initprime();
        
        String str;
        int t,i,j;
        //BufferedReader r = new BufferedReader(new InputStreamReader(System.in));\
        CharBufferedIO io = new CharBufferedIO(System.in, System.out);

          //  str = r.readLine();

            //t = Integer.parseInt(str);
            t = io.readInt();
            while(t > 0)
            {
                int[][] d = new int[351][351];
                int[][] e = new int[351][351];
                int n;
                //r = new BufferedReader(new InputStreamReader(System.in));
                //str = r.readLine();
                //n = Integer.parseInt(str);
                n = io.readInt();
                for(i = 0;i < n;i++)
                {
                    //r = new BufferedReader(new InputStreamReader(System.in));
                    //str = r.readLine();
                    //String[] nums = str.split(" ");
                    for(j = 0;j < n;j++)
                    {
                        //d[i][j] = Integer.parseInt(nums[j]);
                        d[i][j] = io.readInt();
                    }
                }   

                System.out.print(findmasterpassword(d, e, n)+"");
                System.out.print('\n');
                t = t-1;

            }


    }
    private static void initprime()
    {
        primes[0] = primes[1] = -1;
        int i,j;
        int cnt = 0;
        for(i = 2;i < MAX;i++ )
        {
            if(primes[i] == -1) 
            {
                continue;
            }
            primes[i] = cnt++;
            for(j = i+i;j <= MAX;j+=i)
            {
                primes[j] = -1;
            }
        }
    }
    

    
    static int findmasterpassword(int[][] d,int[][] e, int n)
    {
        int i,j,k,sum = 0,x,y;
        for(i = 0;i < n;i++)
        {
            for(j = 0;j < n;j++)
            {
                if(primes[d[i][j]]>=0)
                {
                    sum += primes[d[i][j]];
                    continue;
                }
                
                if(e[i][j] == 1 || e[i][j]==2)
                {
                    continue;
                }
                
                if((d[i][j]&1) > 0)
                {
                    for(k = 0;k < 4;k++)                        
                    {
                        x = i+dx[k];
                        y = j+dy[k];
                        if(inbounds(x, y, n))
                        {
                            if(e[x][y]==1) 
                            {
                                break;
                            }
                        }
                    }
                    
                    
                    if(k==4)
                    {
                        sum+=(d[i][j]+3)/2;
                        for(k = 0;k < 2;k++)
                        {
                            x = i+dx[k];
                            y = j+dy[k];
                            if(inbounds(x, y, n))
                            {
                                if(primes[d[x][y]]<0)
                                {
                                    if((d[x][y]&1) > 0)
                                    {
                                        e[x][y] = 1;
                                    }
                                }
                            }
                        }
                        e[i][j] = 1;
                    }
                }
                
                else
                {
                    for(k = 0;k < 4;k++)
                        
                    {
                        x = i+dx[k];
                        y = i+dy[k];
                        if(inbounds(x, y, n))
                        {
                            if(e[x][y]==2) 
                            {
                                break;
                            }
                        }
                    }
                    
                    
                    if(k==4)
                    {
                        sum+=d[i][j]/2;
                        for(k = 0;k < 2;k++)
                        {
                            x = i+dx[k];
                            y = j+dy[k];
                            if(inbounds(x, y, n))
                            {
                                if(primes[d[x][y]]<0)
                                {
                                    if((d[x][y]&1) == 0)
                                    {
                                        e[x][y] = 2;
                                    }
                                }
                            }
                        }
                        e[i][j] = 2;
                    }
                }
            }
        }
        return sum;
    }
    
    static boolean inbounds(int x,int y,int n)
    {
        return (x>=0 && x<n && y>=0 && y<n);
    }
}

class CharBufferedIO {
	private InputStream in;
	private OutputWriter out;
	private static final int MAX_CHARS = 1024;
	private byte[] buf = new byte[MAX_CHARS];
	private int curChar;
	private int numChars;
 
	public CharBufferedIO(InputStream in, OutputStream out) {
		this.in = in;
		this.out = new OutputWriter(out);
	}
 
	public int readInt() {
		int c = read();
		while (isSpaceChar(c)) {
                c = read();
            }
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}
	
	public long readLong() {
		int c = read();
		while (isSpaceChar(c)) {
                c = read();
            }
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}
 
	public double readDouble() {
		StringBuffer res = new StringBuffer();
		int c = read();
		while (isSpaceChar(c)) {
                c = read();
            }
		while (!isSpaceChar(c)) {
			res.appendCodePoint(c);
			c = read();
		}
		return Double.parseDouble(res.toString());
	}	
	
	public String readString() {
		int c = read();
		while (isSpaceChar(c)) {
                c = read();
            }
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}
	
	public void print(Object...objects) {
		out.print(objects);
	}
	
	public void printLine(Object...objects) {
		out.printLine(objects);
	}
	
	public void close() {
		try {in.close();} 
		catch (IOException e) {}
		out.close();
	}
 
	private boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
	
	private int read() {
		if (numChars == -1) {
                throw new InputMismatchException();
            }
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = in.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0) {
                        return -1;
                    }
		}
		return buf[curChar++];
	}
}
 class OutputWriter {
	private final PrintWriter writer;
 
	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}
 
	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}
 
	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0) {
                        writer.print(' ');
                    }
			writer.print(objects[i]);
		}
	}
 
	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}
 
	public void close() {
		writer.close();
	}
} 
