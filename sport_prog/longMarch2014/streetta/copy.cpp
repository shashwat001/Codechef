//shashwat001  
//Tuesday 11 March 2014 07:33:00 PM IST

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back
#define MAXSIZE 300005

typedef long long int lli;
typedef pair<lli,lli> pi;

struct coll
{
    lli a,d,a1,d1;
    list<pi > l;
};

struct inputnode
{
    int c,u,v,a,d;
} inputn[300004];


coll M[4*MAXSIZE];
vector<int> vi;

void update(lli b,lli e,lli node,lli i,lli j,lli a,lli d)
{
    if(j<b || i>e)
        return ;
    if(b==i && e==j)
    {
        M[node].a+=a;
        M[node].d+=d;
        return ;
    }
    lli mid = (b+e)/2;
    if(j <= mid)
    {
        update(b,mid,2*node,i,j,a,d);
    }
    else if(i<=mid && mid<=j)
    {
        update(b,mid,2*node,i,mid,a,d);
        //update(b,mid,2*node,i,j,a,d);
        a = a+(vi[mid+1]-vi[i])*d;
        update(mid+1,e,2*node+1,mid+1,j,a,d);

    }
    else
    {
        update(mid+1,e,2*node+1,i,j,a,d);
    }


}
void update2(lli b,lli e,lli node,lli i,lli j,lli a,lli d)
{
    if(j<b || i>e)
        return ;
    if(b==i && e==j)
    {
        if(M[node].a1 == INF)
        {
            M[node].a1 = a;
        }
        else
        {
            M[node].a1+=a;
        }
        M[node].d1+=d;
        return ;
    }
    lli mid = (b+e)/2;
    if(j <= mid)
    {
        update2(b,mid,2*node,i,j,a,d);
    }
    else if(i<=mid && mid<=j)
    {
        update2(b,mid,2*node,i,mid,a,d);
        //update(b,mid,2*node,i,j,a,d);
        a = a+(vi[mid+1]-vi[i])*d;
        update2(mid+1,e,2*node+1,mid+1,j,a,d);

    }
    else
    {
        update2(mid+1,e,2*node+1,i,j,a,d);
    }


}


lli query(lli b,lli e,lli node,lli idx)
{
    if(b==e)
    {
        return M[node].a;
    }
    lli mid = (b+e)/2;
    lli curval = M[node].a+(vi[idx]-vi[b])*M[node].d;
    if(idx<=mid)
    {
        return curval + query(b,mid,2*node,idx);
    }
    else
    {
        return curval + query(mid+1,e,2*node+1,idx);
    }
}
lli query2(lli b,lli e,lli node,lli idx)
{
    if(b==e)
    {
        return M[node].a1;
    }
    lli mid = (b+e)/2;
    lli curval = M[node].a1+(vi[idx]-vi[b])*M[node].d1;
    lli childval;
    if(idx<=mid)
    {
        childval = query2(b,mid,2*node,idx);
    }
    else
    {
        childval = query2(mid+1,e,2*node+1,idx);
    
    }
    if(M[node].a1 == INF)
        return childval;
    if(childval == INF && M[node].a1 != INF)
        return curval;
    return max(childval,curval);

}


int main(int argc, char *argv[])
{



    lli n,aa,d,u,v,idx,c,m,i;
    cin>>n>>m;
    vector<int>::iterator it;

    for(i = 0;i < 4*MAXSIZE;i++)
    {
        M[i].a = M[i].d1 = M[i].d = 0;
        M[i].a1 = INF;
    }
    for(i = 0;i < m;i++)
    {
        cin>>c;
        inputn[i].c = c;
        if(c==1 || c==2)
        {
            cin>>u>>v>>aa>>d;
            u--;v--;
            vi.pb(u);
            vi.pb(v);
            inputn[i].u = u;
            inputn[i].v = v;
            inputn[i].a = d;            
            inputn[i].d = aa;
//            update(0,n-1,1,u,v,aa,d);
        }
        else
        {
            cin>>idx;
            idx--;
            vi.pb(idx);
            inputn[i].u = idx;
//            cout<<query(0,n-1,1,idx)<<endl;
        }
    
    }
    sort(vi.begin(),vi.end());
    it = unique(vi.begin(),vi.end());
    vi.resize(distance(vi.begin(),it));
    n = vi.size();
//    cout<<n<<endl;
    for(i = 0;i < m;i++)
    {
        c = inputn[i].c;
        if(c==1)
        {
            u = inputn[i].u;
            v = inputn[i].v;
            aa = inputn[i].a;            
            d = inputn[i].d;
            it =lower_bound(vi.begin(),vi.end(),u);
            lli beg = (lli)(it - vi.begin());
            it = lower_bound(vi.begin(),vi.end(),v);
            lli end = (lli)(it - vi.begin());
            update2(0,n-1,1,beg,end,aa,d);
        }
        else if(c==2)
        {
            u = inputn[i].u;
            v = inputn[i].v;
            aa = inputn[i].a;            
            d = inputn[i].d;
            it = lower_bound(vi.begin(),vi.end(),u);
            lli beg = (lli)(it - vi.begin());
            it = lower_bound(vi.begin(),vi.end(),v);
            lli end = (lli)(it - vi.begin());
            update(0,n-1,1,beg,end,aa,d);

        }
        else
        {
            idx = inputn[i].u;
            it = lower_bound(vi.begin(),vi.end(),idx);
            lli beg = (lli)(it - vi.begin());

            lli val1 = query(0,n-1,1,beg);
            lli val2 = query2(0,n-1,1,beg);
            if(val2 == INF)
                cout<<"NA\n";
            else
                cout<<val1+val2<<endl;
        }
    
    }

    return 0;
}
