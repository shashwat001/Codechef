#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <sys/time.h>
#include <unistd.h>
#include <chrono>

#define S1(n) scanf("%d", &n)
#define S2(a,b) scanf("%d %d", &a, &b)
#define MOD 163577857
#define SIZE 100

class ExamRoom
{
    int n;
public:
    ExamRoom(int N):n(N){}

    int seat()
    {

    }

    void leave(int p)
    {

    }
}

struct stNode
{
    int size, max, rightoffset, leftoffset, maxleft, maxright, start, end;
};
stNode st[1000];
void buildSt(int n, int start, int end, int idx)
{
    st[idx].size = end-start+1;
    st[idx].max = end-start+1;
    st[idx].start = start;
    st[idx].end = end;
    st[idx].rightoffset = end-start+1;
    st[idx].leftoffset = end-start+1;
    st[idx].maxleft = start;
    st[idx].maxright = end;
    if(start == end)
        return;

    int mid = start + (end-start)/2;
    buildSt(n, start, mid, 2*idx+1);
    buildSt(n, mid+1, end, 2*idx+2);
}

void updateSt(int k, int start, int end, int idx, bool isadd)
{
    if(k< start || k > end)
        return;

    if(start == end)
    {
        if(isadd)
        {
            st[idx].max = 0;
            st[idx].rightoffset = 0;
            st[idx].leftoffset = 0;
            st[idx].maxleft = -1;
            st[idx].maxright = -1;
        }
        else
        {
            st[idx].max = 1;
            st[idx].rightoffset = 1;
            st[idx].leftoffset = 1;
            st[idx].maxleft = start;
            st[idx].maxright = end;
        }
        return;
    }

    int mid = start + (end-start)/2;
    addSt(k, start, mid, idx*2+1);
    addSt(k, mid+1, end, idx*2+2);


    st[idx].leftoffset = st[idx*2+1].size != st[idx*2+1].leftoffset ? st[idx*2+1].leftoffset : st[idx*2+1].size + st[idx*2+2].leftoffset;
    st[idx].rightoffset = st[idx*2+2].size != st[idx*2+2].rightoffset ? st[idx*2+2].rightoffset : st[idx*2+2].size + st[idx*2+1].rightoffset;

    int tempmax = st[idx*2+1].rightoffset + st[idx*2+2].leftoffset;
    int tempmaxleft = st[idx*2+1].rightoffset
    tempmax = max(tempmax, st[idx*2+1].max);
    tempmax = max(tempmax, st[idx*2+2].max);
    st[idx].max = tempmax;
}

int main()
{

    buildSt(n, 0, n-1, 0);
    return 0;
}
