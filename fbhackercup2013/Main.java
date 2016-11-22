import java.io.*;
import java.util.*;
import java.math.*;
public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
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
	public void solve(InputReader in,OutputWriter out) throws NumberFormatException, IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long t ;
		t = Long.parseLong(br.readLine());
		long cases=1;
		
		while(t--!=0)
		{
			//String st = in.readString();
			//String letters = in.readString();
			String test = br.readLine();
			//System.out.println(test);
			String s[] = test.split(" ");
			
			char letter[] = s[0].toCharArray();
			long length = letter.length;
			long no = Long.parseLong(s[1]);
			long val = length;
			long count=1;
			while(true)
			{
				//System.out.println("yo");
				if(val > no)
				{
					break;
				}
				else
				{
					count++;
					no = no-val;
					val = val*length;
				}
			}
			
			//System.out.println(no);
			long len =0;
			char fill[] = new char[100];
			int flag = 0;
			while(len<count)
			{
				long val1=length;
				long i;
				long v1=1;
				long sum = 0;
				for(i=len+1;i<count;i++)
				{
					v1 = v1*length;
					sum += v1;
				}
				
				if(no>sum)
				{
					flag = 1;
					
					break;
				}
				for(i=0;i<length;i++)
				{
					if(no-v1<=0)
					{
						fill[(int)len++]=letter[(int)i];
						break;
					}
					else
					{
						no = no-v1;
					}
				}
			}
			if(flag == 1)
			{
						cases++;
			continue;

			}
			System.out.print("Case #"+cases+": ");
			for(int j=0;j<count;j++)
			{
				System.out.print(fill[j]);
			}
			System.out.println();
			cases++;
		}
		
		
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
