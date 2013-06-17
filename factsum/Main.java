import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.lang.NullPointerException;
public class Main
{
	public HashMap<Long,Long> hm = new HashMap<Long,Long>();
	public long retfact(long n)
	{
		if(hm.containsKey(n))
		{
			return hm.get(n);
		}
		long i,j = 0;
		for(i = 2;i * i<=n;i++)
		{
			if(n%i == 0)
			{
				j = n/i;
				long sum = retfact(i) + retfact(j);
				hm.put(n,sum);
				return sum;
			}				
		}
		hm.put(n,n);
		return n;

	}
	public static void main(String[] args) throws IOException
	{
		try
		{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			long n;
			long i,sum,a,j;
			String strn;
			strn = br.readLine();
			Main mainobj = new Main();
			mainobj.hm.put(1L,0L);
			while(!strn.equals(""))
			{
				n = Long.parseLong(strn);
				sum = 0;
				/*for(i = 2; i*i <= n;i++)
				{
					if(n%i==0)
					{
						a = 0;
						j = n/i;
						while(n%i==0)
						{
							n = n/i;
							a++;
						}
						sum += i*a;
						a = 0;
						while(n%j==0)
						{
							n = n/j;
							a++;
						}
						sum+= j*a;
					}
				}*/
				sum = mainobj.retfact(n);
				System.out.print(sum);
				System.out.print("\n");
				strn = br.readLine();
			}
		}
		catch(NullPointerException e)
		{
		}
	}	
}
