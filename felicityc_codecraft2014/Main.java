import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		int t;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String strt = br.readLine();
		t = Integer.parseInt(strt);
		while(t-- != 0)
		{
			String n,m,k;
			strt = br.readLine();
			StringTokenizer st = new StringTokenizer(strt);
			n = st.nextToken();
			k = st.nextToken();
			m = st.nextToken();
			BigInteger bn = new BigInteger(n);
			BigInteger bk = new BigInteger(k);
			BigInteger bm = new BigInteger(m);
			int i;
			for(i = 1;i <= 104;i++)
			{
				bn = bn.multiply(bk);
				if(bn.compareTo(bm) > 0)
				{
					break;
				}
				
			}
			System.out.println(i-1);
			
		}
	}
}
