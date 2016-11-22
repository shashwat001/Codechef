//shashwat001

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

typedef long long int lli;
typedef pair<int,int> pi;

vector<pi > v;

void do_flip(int *list, int length, int num)
{
    int swap;
    int i=0;
    for(i;i<--num;i++)
    {
        swap=list[i];
        list[i]=list[num];
        list[num]=swap;
    }
}


int pancake_sort(int *list, unsigned int length)
{
    //If it's less than 2 long, just return it as sorting isn't really needed...
    if(length<2)
        return 0;
 
    int i,a,max_num_pos,moves;
    moves=0;
 
    for(i=length;i>1;i--)
    {
        //Find position of the max number in pos(0) to pos(i)
        max_num_pos=0;
        for(a=0;a<i;a++)
        {
            if(list[a]>list[max_num_pos])
                max_num_pos=a;
        }
 
        if(max_num_pos==i-1)
            //It's where it need to be, skip
            continue;
 
 
        //Get the found max number to the beginning of the list (unless it already is)
        if(max_num_pos)
        {
        	v.pb(mp(0,max_num_pos+1));
            moves++;
            do_flip(list, length, max_num_pos+1);
        }
 
 
        //And then move it to the end of the range we're working with (pos(0) to pos(i))
        moves++;
        v.pb(mp(0,i));
        do_flip(list, length, i);
 
        //Then everything above list[i-1] is sorted and don't need to be touched
 
    }
 
    return moves;
}

void print_array(int * list,int n)
{
	int i;
	for(i = 0;i < n;i++)
	{
		cout<<list[i]<<" ";
	}
	cout<<endl;
}

int main(int argc, char **argv)
{
    //Just need some random numbers. I chose <100
    int list[10005];
    int i;
    int n;
    cin>>n;
    srand(time(NULL));
    for(i=0;i<n;i++)
        list[i]=rand()%100;
 
 
    //Print list, run code and print it again displaying number of moves
//    printf("\nOriginal: ");
//    print_array(list, n);
 
    int moves = pancake_sort(list, n);
 
//    printf("\nSorted: ");
//    print_array(list, n);
    printf("%d\n", moves);
    for(i = 0;i < v.size();i++)
    {
    	//cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;
}
