import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Pairsum
{
	public static void main (String args[])  throws IOException,NullPointerException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		String[] k = new String[n];
		int i;
		for(i = 0;i < n;i++)
		{
			k[i] = st.nextToken();
		}


		BigInteger[] sum = new BigInteger[n+1];
		BigInteger[] f = new BigInteger[n+1];
		sum[0] = BigInteger.ZERO;
		f[0] = BigInteger.ZERO;
		for(i = 1;i <= n;i++)
		{
			sum[i] = sum[i-1].add(new BigInteger(k[i-1]));
			f[i] = f[i-1].add(sum[i].multiply(new BigInteger(k[i-1])));			
		}
		
		int m = Integer.parseInt(br.readLine());
		for(i = 0;i < m;i++)
		{
			StringTokenizer st1 = new StringTokenizer(br.readLine().trim());
			int l = Integer.parseInt(st1.nextToken())+1;
			int r = Integer.parseInt(st1.nextToken())+1;
			BigInteger val = f[r].subtract(f[l-1].add(sum[l-1].multiply(sum[r].subtract(sum[l-1]))));
			out.println(val);
		}
		out.close();
	}
}
