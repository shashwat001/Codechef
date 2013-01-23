class Alco
{  static int n=0,m=0,k=0; static int inp[]=new int[18];

    public static void main(String []args)throws IOException{
     InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter outt = new OutputWriter(outputStream);

        int t=in.readInt(); // test cases input
        while(t-->0){
            n=in.readInt();k=in.readInt();m=in.readInt(); // n,k & m input

            int inp1[]=new int[n];
            for(int i=0;i<n;i++){
          inp1[i]=inp[i]=in.readInt();  // n ratings
        }
        if(m==1) {
          outt.printLine("-1"); continue;  // impossible case
        }
            outt.printLine(recurse(0,inp1));

        }
        outt.close();
    }
    static int recurse(int i,int arr[]){  // main recursive function to be checked

        if(i<n){
            int a[]=new int[n];
            for(int j=0;j<n;j++){
          a[j]=arr[j];
        }    // without increment case
            int aa=recurse(i+1,a);
            a[i]++; // with incremented case
            int bb=recurse(i+1,a);
            int c=Math.min(aa,bb);  // choosing minimum value
            return c;
        }
        else{
        for(int y=0;y<n;++y)
          System.out.print(arr[y]+" ");
        System.out.print("\n");
            int max=0;int maxf=0;boolean good=true;
            for(int x=0;x<=n-k;x++){
                max=0;maxf=0;
                for(int y=x;y<k+x;y++){
                   max=Math.max(max,arr[y]); 
                }
                for(int y=x;y<k+x;y++){
                   if(arr[y]==max) maxf++; 
                }
                if(maxf>=m) good=false;;

            }
            int change=0;
            for(int x=0;x<n;x++){
                if(arr[x]!=inp[x]) change++;
            }
            if(good==true)
            return change;
            else return 999;
        }
    }
}
