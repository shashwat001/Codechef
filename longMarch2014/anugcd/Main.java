/* Shubhang Verma */
import java.io.*;
import java.util.*;
import java.math.*;
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		InputStream inputstream = System.in;
		InputReader in = new InputReader(inputstream);
		mysolver mysol = new mysolver();
		mysol.solve(in);
	}

}


class mysolver {
	ArrayList<ArrayList<Integer>> ar;
	ArrayList<ArrayList<Integer>> pos;
	ArrayList<ArrayList<Integer>> seg;
	ArrayList<ArrayList<Integer>> count;

	public void solve(InputReader in)
	{
		//System.out.println(Math.sqrt(100000));
		PrintWriter out1 = new PrintWriter(new BufferedOutputStream(System.out));
		int n = in.readInt();
		int m = in.readInt();
		ar = new ArrayList<ArrayList<Integer>>();
		pos = new ArrayList<ArrayList<Integer>>();
		seg = new ArrayList<ArrayList<Integer>>();
		count = new ArrayList<ArrayList<Integer>>();
		
		for(int i=0;i<100001;i++)
		{
			ar.add(new ArrayList<Integer>());
			pos.add(new ArrayList<Integer>());
			seg.add(new ArrayList<Integer>());
			count.add(new ArrayList<Integer>());
		}
		
	    
		for(int i=0;i<n;i++)
		{
			int A = in.readInt();
			int x = A;
			int sq = (int)Math.sqrt(A);
			for(int j=2;j<=sq;j++)
			{
				if(x%j==0)
				{
					while(x%j==0)
					{
						x= x/j;
					}
					
					pos.get(j).add(i);
					ar.get(j).add(A);
				}
			}
			if(x!=1)
			{
				pos.get(x).add(i);
				ar.get(x).add(A);
			}
		}
		int size;
		for(int i=2;i<100001;i++)
		{
			size = pos.get(i).size();
			if(size==0)
				continue;
			
			for(int j=0;j<=4*size;j++)
			{
				seg.get(i).add(0);
				count.get(i).add(0);
			}
                     //System.out.println(size+"  ++++++++++++++++++++++++++++++++  ");
			makesegmenttree(i,0,size-1,1);

		}
		int max,maxc,sq,cpy,g,x,y;
		for(int i=0;i<m;i++)
		{
			g = in.readInt();
			x = in.readInt();
			y = in.readInt();
			
			sq = (int)Math.sqrt(g);
			cpy = g;
			max = -1;
			maxc =0;
			x--;
			y--;
			for(int j=2;j<=sq;j++)
			{
				if(cpy%j==0)
				{
					//System.out.println("cpy : "+cpy+"j :"+j);
					while(cpy%j==0)
					{
						cpy = cpy/j;
					}
					
					//do something
					if(pos.get(j).size()==0)
					continue;
					//System.out.println("Size : "+pos.get(j).size());
					int low = lower(j,0,pos.get(j).size()-1,x);
					int high = upper(j,0,pos.get(j).size()-1,y);
					if(pos.get(j).get(high)>y)
					{
						high--;
					}
					if(high<low)
						continue;
					else if(pos.get(j).get(high)<=y && pos.get(j).get(low)>=x && pos.get(j).get(high)>=pos.get(j).get(low))
					{
						result rs = querymax(j,0,pos.get(j).size()-1,low,high,1);
						
						if(rs == null)
							continue;
						if(rs.max>=max)
						{
							max = rs.max;
							maxc = rs.count;
						}
					}
				}
			}
			if(cpy!=1)
			{
				//do something
				if(pos.get(cpy).size()!=0)
				{
					int low = lower(cpy,0,pos.get(cpy).size()-1,x);
					int high = upper(cpy,0,pos.get(cpy).size()-1,y);
					if(pos.get(cpy).get(high)>y)
					{
						high--;
					}
					if(high<low)
					{
						
					}
					else if(pos.get(cpy).get(high)<=y && pos.get(cpy).get(low)>=x && pos.get(cpy).get(high)>=pos.get(cpy).get(low))
					{
						result rs = querymax(cpy,0,pos.get(cpy).size()-1,low,high,1);
						//System.out.println(pos.get(cpy).size()+" ++++");
						//System.out.println(low+" "+high+"++++");
						if(rs!=null && rs.max>max)
						{
							max = rs.max;
							maxc = rs.count;
							//System.out.println("YO 1");
						}
						
					}
				}
			}
			
			if(max==-1)
			{
				out1.println("-1 -1");
			}
			else
			{
				out1.println(max+" "+maxc);
			}
		}
		
		out1.close();
	}
	public int lower(int i,int low,int high,int idx)
	{
		if(low==high)
		{
			return low;
		}
		int mid = (low+high)/2;
		if(pos.get(i).get(mid)==idx)
			return mid;
		else if(pos.get(i).get(mid)>idx)
		{
			return lower(i,low,mid,idx);
		}
		else
		{
			return lower(i,mid+1,high,idx);
		}
	
	}
	
	public int upper(int i,int low,int high,int idx)
	{
		if(low==high)
		{
			return low;
		}
		int mid = (low+high)/2;
		
		if(pos.get(i).get(mid)==idx)
			return mid;
		else if(pos.get(i).get(mid)>idx)
		{
			return upper(i,low,mid,idx);
		}
		else
		{
			return upper(i,mid+1,high,idx);
		}
		
	}
	
	public void makesegmenttree(int i,int start,int end,int idx)
	{
	     // System.out.println(idx+"  **********  ");
		if(start==end)
		{
			seg.get(i).set(idx,ar.get(i).get(start));
			count.get(i).set(idx,1);
			return;
		}
		else
		{
			
			int mid = (start+end)/2;
			makesegmenttree(i,start,mid,2*idx);
			makesegmenttree(i,mid+1,end,2*idx+1);
			int v1 = seg.get(i).get(2*idx);
			int v2 = seg.get(i).get(2*idx+1);
			
			if(v1==v2)
			{
				//System.out.println("HIHI");
				int c1 = count.get(i).get(2*idx);
				int c2 = count.get(i).get(2*idx+1);
				count.get(i).set(idx,c1+c2);
			}
			else if(v1<v2)
			{
				//System.out.println("HIHI ++");
				count.get(i).set(idx,count.get(i).get(2*idx+1));
			}
			else
			{
				//System.out.println("HIHI +33");
				//System.out.println(seg.get(i).get(2*idx)+" |||| "+seg.get(i).get(2*idx+1));
				count.get(i).set(idx,count.get(i).get(2*idx));
			}
			
			seg.get(i).set(idx,Math.max(v1,v2));
		}
	
	}
	
	public result querymax(int i,int first,int last,int begin,int end,int idx)
	{
		//System.out.println("Index : "+idx+"   "+i);
		if(first>end || last<begin)
		{
			return null;
		}
		else if(first>=begin && last<=end)
		{
			result rs = new result();
			rs.count = count.get(i).get(idx);
			rs.max = seg.get(i).get(idx);
			return rs;
		}
		else
		{
			int mid = (first+last)/2;
			result val1 = querymax(i,first,mid,begin,end,2*idx);
			result val2 = querymax(i,mid+1,last,begin,end,2*idx+1);
			if(val1!=null && val2!=null)
			{
				if(val1.max==val2.max)
				{
					//System.out.println(val1.count+" "+val2.count);
					
					val1.count+=val2.count;
					//System.out.println("GOt it "+idx);
					return val1;
				}
				else if(val1.max> val2.max)
				{
					return val1;
				}
				else
				{
					return val2;
				}
			}
			else if(val1==null && val2!=null)
			{
				return val2;
			}
			else if(val2==null && val1!=null)
			{
				return val1;
			}
			else
				return null;
		}
		
	}
}
class result {
	int count;
	int max;
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
