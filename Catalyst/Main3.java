/* Shubhang Verma */
import java.io.*;
import java.util.*;
import java.math.*;
public class Main3 {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		InputStream inputstream = System.in;
		OutputStream outputstream = System.out;
		InputReader in = new InputReader(inputstream);
		OutputWriter out = new OutputWriter(outputstream);
		mysolver mysol = new mysolver();
		mysol.solve(in, out);
		out.close();

	}

}


class mysolver {
	long mod = 1000000009;
	long A[];
	TreeSet<String> ts;
	int cnt;
	String f1="";
	TreeSet<String> mytree;
	String[] ar1={"cian","ph","th","ch","cc","gh","sh","ck",
			"tion","eo","ea"};
	String[] ar2={"xn","f","d","x","x","j","x","k","xn","ee","ee"};
	public void replace(String s,int depth)
	{
		if(depth==11)
		{

			if(ts.contains(s))
			{
				mytree.add(s);
			} 
			return;
		}
		String s2 = s.replace(ar2[depth],ar1[depth]);
		
		
		replace(s,depth+1);
		replace(s2,depth+1);
		
		
		
	}
	public void dfs(String[] str,int depth,String s)
	{
		
		int length = str.length;
		if(depth==length)
		{
			//System.out.println(s);

			for(int i=10;i>=0;i--)
			{
				if(s.contains(ar1[i]))
				{
					return;
				}
			}
			
//			for(int i=10;i>=0;i--)
//			{
//				
//				s2 = s2.replace(ar2[i],ar1[i]);
//				s3 = s.replace(ar2[i],ar1[i]);
//				if(ts.contains(s2))
//				{
//					cnt++;
//					mytree.add(s2);
//				}
//				
//				if(ts.contains(s3))
//				{
//					cnt++;
//					mytree.add(s3);
//				}
////				if(s2.equals("shirt"))
////				{
////					//s2 = s2.replace(ar2[i],ar1[i]);
////					//System.out.println(s);
////				}
//				
//			}

			
//			if(ts.contains(s2))
//			{
//				cnt++;
//				mytree.add(s2);
//			}
			replace(s,0);
//			for(int i=0;i<11;i++)
//			{
//				String s2 = s.replace(ar1[i],ar2[i]);
//				if(ts.contains(s2))
//				{
//					mytree.add(s2);
//					//System.out.println(ar1[i]+" "+ar2[i]+" "+s2);
//					//cnt++;
//				}
//				s2 = s.replace(ar2[i],ar1[i]);
//				if(ts.contains(s2))
//				{
//					mytree.add(s2);
//					//System.out.println(ar1[i]+" "+ar2[i]+" "+s2);
//					//cnt++;
//				}
//			}
			
		}
		else
		{
			String s1 = ts.higher(s);
			if(s1!=null)
			{
				if(s1.length()<s.length())
					return ;
				for(int k = 0;k < s.length();k++)
				{
					if(s.charAt(k) != s1.charAt(k))
						return;
				}
			}
			for(int i=0;i<str[depth].length();i++)
			{
				dfs(str,depth+1,s+Character.toString(str[depth].charAt(i)));
			}
		}
		
	}
	public void solve(InputReader in,OutputWriter out) throws IOException
	{
			
		ts = new TreeSet();
		BufferedReader br = new BufferedReader(new FileReader("/USER/USER/codes/dictionary.txt"));
		for(int i=1;i<=18609;i++)
		{
			String line = br.readLine();
			//System.out.println(line);
			ts.add(line);
		}
		
		String str="a I U v o b I I i i c I ( i c d I ( i c e I U i c f I I i u g I ( i c h S S i c i I U v o j S S i c k I ( i c l D H v o m I I i i n I ( i c o - C i o p I I i i q o - i i r I ( i c s I ( i c t S S i c u - C i c v I I i u w o - i i x S S i c y I ( i c z I ( i c";
		String[] st = str.split(" ");
		//String s1 = in.readString();
		//System.out.println(st[5*k+4]+" "+st[5*k+1]+" "+st[5*k+2]+" "+st[5*k+3]+" ");
		int countwords = in.readInt();
		for(int k=0;k<countwords;k++)
		{
			int count=in.readInt();
			
			String stringarray[] = new String[count];
			for(int i=0;i<count;i++)
			{
				stringarray[i]="";
			}
			for(int i=0;i<count;i++)
			{
				String s1 = in.readString();
				String s2 = in.readString();
				String s3 = in.readString();
				String s4 = in.readString();
				
				for(int j=0;j<26;j++)
				{
					
					if(st[5*j+1].equals(s1)==true && st[5*j+2].equals(s2)==true && st[5*j+3].equals(s3)==true && st[5*j+4].equals(s4)==true )
					{
						int l1 = j+'a';
						stringarray[i] = stringarray[i]+(Character.toString((char)l1));
					}
				}
			}
			cnt=0;
			mytree = new TreeSet<String>();
			dfs(stringarray,0,"");
			
			Iterator<String> it = mytree.iterator();
//			while(it.hasNext())
//			{
//				String st1 = it.next();
//				int check=0;
//				for(int i=0;i<8;i++)
//				{
//					if(st1.substring(0,ar3[i].length()).equals(ar3[i]))
//							{
//								check=1;
//								break;
//							}
//				}
//				if(check==1)
//				{
//					ts.remove(st1);
//				}
//			}
			cnt = mytree.size();
			System.out.print(cnt+" ");
			it = mytree.iterator();
			while(it.hasNext())
			{
				String st1 = it.next();
				System.out.print(st1+" ");
			}
			
		}
		
		
			
	}
	public long findans(int i,int val)
	{
		long v1 = (i-1);
		int v2 = val/2;
		if(val/2-1==0 && v1==0)
			return 2;
		for(int j=2;j<val/2;j++)
		{
			v1 = ((v1*((long)(i-j)))/(long)j)%mod;
		}
		v1 = (v1*A[v2])%mod;
		v1 = (v1*A[v2])%mod;
		v1 = (v1*2)%mod;
		return v1;
	}
	public long modmulinverse(long a,long m)
	{
	    long x = 0,y = 1,u = 1,v = 0; 
	    long e = m,f = a;
	    long c,d,q,r;
	    while(f != 1)
	    {
	        q = e/f;
	        r = e%f;
	        c = x-q*u;
	        d = y-q*v;
	        x = u;
	        y = v;
	        u = c;
	        v = d;
	        e = f;
	        f = r;
	    } 
	    u = (u+m)%m;
	    return u;
	}
}
class InputReader {
 
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;
 
	public InputReader(InputStream stream) {
		this.stream = stream;
	}
 
	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}
 
	public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}
 
	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}
 
	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}
 
	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
 
	public String next() {
		return readString();
	}
 
	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
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
 
	public void close() {
		writer.close();
	}
 
	public void printLine(int i) {
		writer.println(i);
	}
}
 
class IOUtils {
 
	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}
 
	}
