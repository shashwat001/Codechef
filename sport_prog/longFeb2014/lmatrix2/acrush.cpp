#ifdef _MSC_VER
#define LOCAL
#endif
#ifdef LOCAL
#define DEBUG
#endif
#ifdef DEBUG
//#define DEBUG_SLOW
#endif

const double TIME_LIMIT=0.95;

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <stdarg.h>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long uint64;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define POW2(X) (((uint)1)<<(X))
typedef vector<int> VI;
typedef pair<int,int> ipair;

#ifdef DEBUG
#define ASSERT(_Expression) (void)((!!(_Expression)||(__assert((#_Expression),__LINE__),0)))
void __assert(const char *_Message,const unsigned _Line) {printf("ASSERTION FAILED\n");printf("Message = %ls\n",_Message);printf("Line = %u\n",_Line); exit(0);}
#endif

#ifdef _MSC_VER
#define TIMES_PER_SEC (1.75e9)
#else
#define TIMES_PER_SEC (3.05e9)
#endif

uint64 rdtsc()
{
#ifdef _MSC_VER
	__asm { rdtsc }
#else
	uint64 time;
	__asm__ volatile ("rdtsc" : "=A" (time));
	return time;
#endif
}

double gettime()
{
	return (double)rdtsc()/TIMES_PER_SEC;
}

#ifdef _MSC_VER
class Timer
{
public:
		static uint64 timeUsed[1024];
		int id;
		uint64 startTime;
		Timer(int id=0) { this->id=id; startTime=rdtsc(); }
		~Timer() { timeUsed[id]+=(rdtsc()-startTime); }
		static void show()
		{
				for (int i=0;i<1024;i++) if (timeUsed[i]>0)
				{
						char str[100]; sprintf(str,"%.6lf",timeUsed[i]/TIMES_PER_SEC);
						string s=str; if (LENGTH(s)<15) s=" "+s;
						printf("Timer   %4d %s\n",i,s.c_str());
				}
		}
};
uint64 Timer::timeUsed[1024]={0};

class Counter
{
public:
		static int cnt[1024];
		Counter(int id=0) {  cnt[id]++; }
		~Counter() { }
		static void show()
		{
				for (int i=0;i<1024;i++) if (cnt[i]>0) printf("Counter %4d %9d\n",i,cnt[i]);
		}
};
int Counter::cnt[1024]={0};
#endif

#define MT_N 624
#define MT_M 397
#define MT_MSB 0x80000000U
#define MT_LS31B 0x7FFFFFFFU
#define MT_A 2567483615U

class MersenneTwister // pseudo-random number generator
{
	uint twistory[MT_N]; // history (i.e., previous states) of the generator
	int pos;
public:
	MersenneTwister(uint seed=0)
	{
		twistory[0]=seed;
		for (int i=1;i<MT_N;i++) twistory[i]=1812433253U*(twistory[i-1]^(twistory[i-1]>>30))+i;
		pos=0;
	}
	void reset(uint seed=0)
	{
		twistory[0]=seed;
		for (int i=1;i<MT_N;i++) twistory[i]=1812433253U*(twistory[i-1]^(twistory[i-1]>>30))+i;
		pos=0;
	}
	void generate(void)
	{
		uint tmp; int i;
		for (i=0;i<MT_N-MT_M;i++)
		{
			tmp=(twistory[i]&MT_MSB)+(twistory[i+1]&MT_LS31B);
			twistory[i]=twistory[i+MT_M]^(tmp>>1)^(MT_A&-(tmp&1));
		}
		for (;i<MT_N-1;i++)
		{
			tmp=(twistory[i]&MT_MSB)+(twistory[i+1]&MT_LS31B);
			twistory[i]=twistory[i+MT_M-MT_N]^(tmp>>1)^(MT_A&-(tmp&1));
		}
		tmp=(twistory[i]&MT_MSB)+(twistory[0]&MT_LS31B);
		twistory[i]=twistory[MT_M-1]^(tmp>>1)^(MT_A&-(tmp&1));
	}
	uint rand_unsigned()
	{
		if (pos==0) generate();
		uint ans=twistory[pos++];
		pos&=-(pos!=624); // if (pos == 624) pos = 0;
		ans^=ans>>11;
		ans^=(ans<<7)&2636928640U;
		ans^=(ans<<15)&4022730752U;
		ans^=ans>>18;
		return ans;
	}
	double next_double()
	{
		return next_int(32768)/32768.0;
	}
	int rand_signed()
	{
		return rand_unsigned()>>1;
	}
	int next_int(int n)
	{
		if (n==1) return 0;
		return rand_unsigned()%n; // close enough
	}
	int next_int(int a,int b)
	{
		if (a==b) return a;
		return rand_unsigned()%(b-a+1)+a; // close enough
	}
};

#define PACK2(a,b) (((a)<<8)|(b))
#define PACK4(a,b,c,d) ((PACK2(a,b)<<16)|PACK2(c,d))
inline void UPACK2(int s,int &a,int &b) { a=(s>>8); b=(s&255); }
inline void UPACK4(int s,int &a,int &b,int &c,int &d) { a=(s>>24); b=((s>>16)&255); c=((s>>8)&255); d=(s&255); }
inline ipair create_move(int x1,int y1,int x2,int y2,int d) { return make_pair(PACK4(x1,y1,x2,y2),d); }

const int MAXN=100;
const int MAXN2=MAXN*MAXN;
const int MAX_NUM_STATES=128;

int size_x;
int size_y;
int a[MAXN][MAXN];
int p[MAXN][MAXN];

int best_num_moves;
ipair best_moves[MAXN2];

int lgcd[16][16];

int num_moves;
ipair moves[MAXN2];

#ifdef DEBUG
int global_a[MAXN][MAXN];
#endif

class State
{
public:
	int a[MAXN][MAXN];
	int num_moves;
	ipair moves[MAXN2];
	int cost;

	void copy_to_global()
	{
		for (int x=0;x<size_x;x++) memcpy(::a[x],a[x],size_y*sizeof(int));
		::num_moves=num_moves;
		memcpy(::moves,moves,num_moves*sizeof(ipair));
	}
	void copy_from_global()
	{
#ifdef DEBUG
		int s[MAXN][MAXN];
		memset(s,0,sizeof(s));
		for (int i=0;i<::num_moves;i++)
		{
			int x1,y1,x2,y2,d=::moves[i].second;
			UPACK4(::moves[i].first,x1,y1,x2,y2);
			ASSERT(x1>=0 && x1<=x2 && x2<size_x && y1>=0 && y1<=y2 && y2<size_y);
			s[x1][y1]+=d; s[x2+1][y2+1]+=d; s[x1][y2+1]-=d; s[x2+1][y1]-=d;
		}
		for (int x=0;x<size_x;x++) for (int y=0;y<size_y;y++)
		{
			if (x>0) s[x][y]+=s[x-1][y];
			if (y>0) s[x][y]+=s[x][y-1];
			if (x>0 && y>0) s[x][y]-=s[x-1][y-1];
			ASSERT(((global_a[x][y]-s[x][y])%p[x][y]+p[x][y])%p[x][y]==::a[x][y]);
		}
#endif
		for (int x=0;x<size_x;x++) memcpy(a[x],::a[x],size_y*sizeof(int));
		num_moves=::num_moves;
		memcpy(moves,::moves,num_moves*sizeof(ipair));
		cost=num_moves*MAXN;
		for (int x=0;x<size_x;x++) for (int y=0;y<size_y;y++) if (!a[x][y]) cost++;
	}
};
int num_states[2];
State states[2][MAX_NUM_STATES];

int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}

void generate(int seed)
{
	MersenneTwister rnd(seed);
	int s=0;
	for (int i=0;i<128;i++) s|=rnd.rand_signed();
	if (s==0) { printf("Bad SEED."); exit(0); }
	size_x=rnd.next_int(66,99);
	size_y=rnd.next_int(66,99);
	for (int x=0;x<size_x;x++) for (int y=0;y<size_y;y++) p[x][y]=rnd.next_int(1,10);
	for (int x=0;x<size_x;x++) for (int y=0;y<size_y;y++) a[x][y]=rnd.next_int(p[x][y]);
}

void update(int num_moves,ipair moves[])
{
	if (num_moves>=best_num_moves) return;
	best_num_moves=num_moves;
	memcpy(best_moves,moves,num_moves*sizeof(ipair));
}

void preprocess()
{
	for (int i=0;i<16;i++) for (int j=0;j<16;j++) lgcd[i][j]=gcd(i,j);
}

void init()
{
	for (int x=0;x<size_x;x++) for (int y=0;y<size_y;y++) a[x][y]=(p[x][y]-a[x][y])%p[x][y];
	best_num_moves=0;
	for (int x=0;x<size_x;x++) for (int y=0;y<size_y;y++) if (a[x][y]) best_moves[best_num_moves++]=create_move(x,y,x,y,a[x][y]);	
}

inline bool add(int &m,int &d,int a,int p)
{
	if (m%p==0) return (d%p==a);
	if (m==1) { m=p; d=a; return true; }
	int g=lgcd[p][m%p];
	if ((d-a)%g!=0) return false;
	int d0=d%p;
	if (d0==a) { m*=p/g; return true; }
	int m0=m%p;
	for (;d0!=a;d+=m) { d0+=m0; if (d0>=p) d0-=p; }
	m*=p/g;
	return true;
}

inline void update(int &a,int d,int m)
{
	int c=(a+d)%m;
	if (c<0) c+=m;
	a=c;
}

ipair get_best_move(int x,int y,int lasty,int sc)
{
	// Constraints:
	// 1) [y, lasty] /subset [y1, y2]
	// 2) MUST clear at least x cells in row x.
	// 3) Can't rollback any cell in row x.
	int bests=-1,bestx2=0;
	ipair best_move;
	for (int y2=lasty;y2<size_y && y2<=lasty+3;y2++) for (int y1=y;y1>=0 && y1>=y-3;y1--)
	{
		int m=p[x][y],d=a[x][y],c=0;
		for (int ey=y1;ey<=y2;ey++)
			if (add(m,d,a[x][ey],p[x][ey])) { if (a[x][ey]) c++; }
			else if (!a[x][ey]) { c=-1; break; }
		if (c<sc) { if (y1==y) y2=size_y; break; }
		int s=c;
		if (s>bests || s==bests && x<bestx2) bests=s,bestx2=x,best_move=create_move(x,y1,x,y2,d);
		for (int x2=x+1;x2<size_x;x2++)
		{
			for (int ey=y1;ey<=y2;ey++)
				if (add(m,d,a[x2][ey],p[x2][ey])) { if (a[x2][ey]) s++; }
				else if (!a[x2][ey]) s--;
			if (s<-2) break;
			if (s>bests || s==bests && x2<bestx2) bests=s,bestx2=x2,best_move=create_move(x,y1,x2,y2,d);
			if (m==2520)
			{
				int ed[16];
				for (int i=1;i<=10;i++) ed[i]=d%i;
				for (x2++;x2<size_x;x2++)
				{
					for (int ey=y1;ey<=y2;ey++)
					{
						int a0=a[x2][ey],d0=ed[p[x2][ey]];
						if (a0==d0) { if (a0) s++; }
						else if (!a0) s--;
					}
					if (s<-2) break;
					if (s>bests || s==bests && x2<bestx2) bests=s,bestx2=x2,best_move=create_move(x,y1,x2,y2,d);
				}
				break;
			}
		}
	}
#ifdef DEBUG
	ASSERT(bests>=0);
#endif
	return best_move;
}

int get_best_tx(int x,int sy,int ty,int refx,int d)
{
	int best_tx=x-1,best_s=0,s=0;
	int ed[16],fd[16];
	for (int i=1;i<=10;i++) { ed[i]=d%i; if (ed[i]<0) ed[i]+=i; fd[i]=(i-ed[i])%i; }
	for (int tx=x;tx<size_x;tx++)
	{
		if (tx<=refx)
			for (int y=sy;y<=ty;y++)
			{
				int a0=a[tx][y],f0=fd[p[tx][y]];
				if (f0==0) continue;
				if (a0==0) { if (a0!=f0) s++; }
				else if (a0==f0) s--;
			}
		else
			for (int y=sy;y<=ty;y++)
			{
				int a0=a[tx][y],d0=ed[p[tx][y]];
				if (d0==0) continue;
				if (d0==a0) { if (a0) s++; }
				else if (!a0) s--;
			}
		if (s>=best_s) best_s=s,best_tx=tx;
	}
	return best_tx;
}

void beam_search(double time_limit_overall)
{
#ifdef LOCAL
	Counter c1(1);
	Timer t1(1);
#endif
#ifdef DEBUG
	memcpy(global_a,a,sizeof(a));
#endif
	State state;
	num_moves=0;
	num_states[0]=1;
	states[0][0].copy_from_global();
	for (int x=0;x<size_x;x++)
	{
		double current_time=gettime();
		double time_limit=current_time+(time_limit_overall-current_time)/(size_x-x);
#ifdef DEBUG
		ASSERT(num_states[x&1]<=MAX_NUM_STATES);
#endif
		ipair q[MAX_NUM_STATES];
		for (int i=0;i<num_states[x&1];i++) q[i]=MP(states[x&1][i].cost,i);
		sort(q,q+num_states[x&1]);
		num_states[(x+1)&1]=0;
		bool is_time_out=false;
		for (int cl=0;cl<num_states[x&1];cl++) for (int is_reverse_y=0;is_reverse_y<2;is_reverse_y++)
		{
			if (cl>0 && !is_time_out) is_time_out=(gettime()>time_limit);
			if (is_time_out) break;
			states[x&1][q[cl].second].copy_to_global();
			if (is_reverse_y)
			{
				for (int x2=x;x2<size_x;x2++) reverse(a[x2],a[x2]+size_y);
				for (int x2=x;x2<size_x;x2++) reverse(p[x2],p[x2]+size_y);
				for (int i=0;i<num_moves;i++)
				{
					int sx,sy,tx,ty;
					UPACK4(moves[i].first,sx,sy,tx,ty);
#ifdef DEBUG
					ASSERT(sx>=0 && sx<=tx && tx<size_x && sy>=0 && sy<=ty && ty<size_y);
#endif
					moves[i].first=PACK4(sx,size_y-1-ty,tx,size_y-1-sy);
				}
			}
			int cut1[MAXN],cutidx1[MAXN][16],cutp1[MAXN][16],cutd1[MAXN][16];
			int cut2[MAXN],cutidx2[MAXN][16],cutp2[MAXN][16],cutd2[MAXN][16],cutcost2[MAXN][16];
			int mcut_pos=-1;
			memset(cut1,0,sizeof(cut1));
			memset(cut2,0,sizeof(cut2));
			for (int i=0;i<num_moves;i++)
			{
				int sx,sy,tx,ty,d=moves[i].second;
				UPACK4(moves[i].first,sx,sy,tx,ty);
#ifdef DEBUG
				ASSERT(sx>=0 && sx<=tx && tx<size_x && sy>=0 && sy<=ty && ty<size_y);
#endif
				if (tx<x-1) continue;
#ifdef DEBUG
				ASSERT(sy>=0 && sy<=ty && ty<size_y);
#endif
				if (ty-sy>8) continue;
				if (tx==x-1) { if (cut1[sy]<16) cutidx1[sy][cut1[sy]]=i,cutp1[sy][cut1[sy]]=ty,cutd1[sy][cut1[sy]++]=d; }
				else if (cut2[sy]<16)
				{
					int cost=0,fd[16];
					for (int k=1;k<=10;k++) { fd[k]=d%k; if (fd[k]>0) fd[k]=k-fd[k]; }
					for (int ex=x+1;ex<=tx;ex++) for (int ey=sy;ey<=ty;ey++)
					{
						int a0=a[ex][ey],d0=fd[p[ex][ey]];
						if (d0==0) continue;
						if (a0==0) cost++;
						else if (a0==d0) cost--;
					}
					if (cost<8) cutidx2[sy][cut2[sy]]=i,cutp2[sy][cut2[sy]]=ty,cutcost2[sy][cut2[sy]]=cost,cutd2[sy][cut2[sy]++]=d;
				}
			}
#ifdef DEBUG
			for (int y=0;y<size_y;y++) ASSERT(cut1[y]<=16 && cut2[y]<=16);
#endif
			int count=0,row_sy[MAXN],row_ty[MAXN],row_d[MAXN];
			ipair row_moves[MAXN];
			for (int y=0;y<size_y;y++) if (a[x][y])
			{
#ifdef LOCAL
				Timer t12(12);
#endif
				int ed_pos=count-1;
				for (;ed_pos>=0 && row_ty[ed_pos]!=y-1;ed_pos--);
				int ed=(ed_pos<0)?0:row_d[ed_pos];
				int cp=0,pidx[512],psy[512],pty[512],pd[512],pc[512];
				if (y-1>mcut_pos) mcut_pos=y-1;
				for (int i=mcut_pos+1;i<size_y && i<y+8;i++)
				{
					for (int j=0;j<cut1[i];j++) if (cutp1[i][j]<y+8)
						pidx[cp]=cutidx1[i][j],psy[cp]=i,pty[cp]=cutp1[i][j],pc[cp]=0,pd[cp++]=cutd1[i][j];
					for (int j=0;j<cut2[i];j++) if (cutp2[i][j]<y+8)
						pidx[cp]=cutidx2[i][j],psy[cp]=i,pty[cp]=cutp2[i][j],pc[cp]=cutcost2[i][j],pd[cp++]=-cutd2[i][j];
				}
#ifdef DEBUG
				ASSERT(cp<=512);
				for (int i=0;i<cp;i++) ASSERT(psy[i]>=y);
#endif
				int best_sc=0,best_scost=0,best_lasty=-1,best_ld=0,best_lp1=0,best_lp2=0,best_d=0;
				for (int lp1=0;lp1<1+cp;lp1++) for (int lp2=((lp1==0)?0:(lp1+1));lp2<1+cp;lp2++) for (int ld=0;ld<10;ld++)
				{
					if (ed_pos<0 && ld>0) break;
					int m=1,d=0,sc=0,lasty,finaly;
					for (int y2=y;y2<size_y;y2++)
					{
						int a0=a[x][y2];
						if (y2<ld+y) update(a0,-ed,p[x][y2]);
						if (lp1 && y2>=psy[lp1-1] && y2<=pty[lp1-1]) update(a0,-pd[lp1-1],p[x][y2]);
						if (lp2 && y2>=psy[lp2-1] && y2<=pty[lp2-1]) update(a0,-pd[lp2-1],p[x][y2]);
						if (add(m,d,a0,p[x][y2])) { if (a[x][y2]) lasty=y2,sc++; }
						else if (!a[x][y2]) break;
						finaly=y2;
					}
#ifdef DEBUG
					ASSERT(sc>0 && lasty>=y);
#endif
					if (d==0) continue;
					if (lasty<y+ld) { if (finaly<y+ld) break; lasty=y+ld; }
					if (lp1 && lasty<pty[lp1-1]) { if (finaly<pty[lp1-1]) continue; lasty=pty[lp1-1]; }
					if (lp2 && lasty<pty[lp2-1]) { if (finaly<pty[lp2-1]) continue; lasty=pty[lp2-1]; }
					int scost=0;
					if (lp1) scost+=pc[lp1-1];
					if (lp2) scost+=pc[lp2-1];
					if (sc>best_sc || sc==best_sc && scost<best_scost)
						best_sc=sc,best_scost=scost,best_lasty=lasty,best_ld=ld,best_lp1=lp1,best_lp2=lp2,best_d=d;
				}
#ifdef DEBUG
				ASSERT(best_sc>0 && best_d>0);
#endif
				if (best_ld>0)
				{
#ifdef DEBUG
					ASSERT(ed_pos>=0 && ed_pos<count && ed>0 && ed==row_d[ed_pos] && row_ty[ed_pos]+1==y);
#endif
					for (int ey=y;ey<y+best_ld;ey++) update(a[x][ey],-ed,p[x][ey]);
					row_ty[ed_pos]+=best_ld;
#ifdef DEBUG
					ASSERT(y+best_ld-1<=best_lasty);
#endif
				}
				for (int lp_step=0;lp_step<2;lp_step++)
				{
					int lp=((lp_step==0)?best_lp1:best_lp2)-1;
					if (lp<0) continue;
#ifdef DEBUG
					ASSERT(pidx[lp]>=0 && pidx[lp]<num_moves);
#endif
					int sx,sy,tx,ty;
					UPACK4(moves[pidx[lp]].first,sx,sy,tx,ty);
#ifdef DEBUG
					ASSERT(sx>=0 && sx<=tx && tx<size_x && sy>=0 && sy<=ty && ty<size_y);
					ASSERT(tx>=x-1);
					for (int k=0;k<count;k++)
					{
						if (k==ed_pos && best_ld>0) continue;
						ASSERT(row_ty[k]<psy[lp]);
					}
#endif
					for (int ey=psy[lp];ey<=pty[lp];ey++) update(a[x][ey],-pd[lp],p[x][ey]);
					for (int ex=x+1;ex<=tx;ex++) for (int ey=psy[lp];ey<=pty[lp];ey++) update(a[ex][ey],-pd[lp],p[ex][ey]);
					if (tx==x-1)
						moves[pidx[lp]].first=PACK4(sx,sy,x,ty);
					else
						moves[pidx[lp]].first=PACK4(sx,sy,x-1,ty);
#ifdef DEBUG
					ASSERT(pty[lp]<=best_lasty);
#endif
				}
				row_sy[count]=y;
				row_ty[count]=best_lasty;
				row_d[count++]=best_d;
#ifdef DEBUG
				ASSERT(y<=best_lasty && best_d>=0 && best_d<2520 && count<=size_y);
#endif
				for (int ey=y;ey<=best_lasty;ey++) update(a[x][ey],-best_d,p[x][ey]);
				if (best_lasty>mcut_pos) mcut_pos=best_lasty;
			}
#ifdef DEBUG
			for (int y=0;y<size_y;y++) ASSERT(a[x][y]==0);
#endif
			for (int k=0;k<count;k++) row_moves[k]=create_move(x,row_sy[k],x,row_ty[k],row_d[k]);
			int last_row_changed[MAXN];
			memset(last_row_changed,255,sizeof(last_row_changed));
			for (int step=0;step<1;step++) for (int k=0;k<count;k++)
			{
#ifdef LOCAL
				Timer t13(13);
#endif
				int sx,sy,tx,ty,d=row_moves[k].second,sc=0,firsty=-1,lasty=-1;
				UPACK4(row_moves[k].first,sx,sy,tx,ty);
				bool changed=false;
				for (int y=max(0,sy-3);y<=min(size_y-1,ty+3);y++) if (last_row_changed[y]>=step-1) { changed=true; break; }
				if (!changed) continue;
				for (int ex=sx;ex<=tx;ex++) for (int ey=sy;ey<=ty;ey++)
				{
					update(a[ex][ey],d,p[ex][ey]);
					if (!(ex==sx && a[ex][ey])) continue;
					if (firsty<0) firsty=ey;
					lasty=ey;
					sc++;
				}
#ifdef DEBUG
				ASSERT(sc>0);
#endif
				ipair best_move=get_best_move(x,firsty,lasty,sc);
				d=best_move.second;
				UPACK4(best_move.first,sx,sy,tx,ty);
				for (int ex=sx;ex<=tx;ex++) for (int ey=sy;ey<=ty;ey++) update(a[ex][ey],-d,p[ex][ey]);
				if (best_move!=row_moves[k]) for (int y=sy;y<=ty;y++) last_row_changed[y]=step;
				row_moves[k]=best_move;
			}
#ifdef DEBUG
			for (int y=0;y<size_y;y++) ASSERT(a[x][y]==0);
#endif
			if (is_reverse_y)
			{
				for (int x2=x;x2<size_x;x2++) reverse(a[x2],a[x2]+size_y);
				for (int x2=x;x2<size_x;x2++) reverse(p[x2],p[x2]+size_y);
				for (int i=0;i<num_moves;i++)
				{
					int sx,sy,tx,ty;
					UPACK4(moves[i].first,sx,sy,tx,ty);
#ifdef DEBUG
					ASSERT(sx>=0 && sx<=tx && tx<size_x && sy>=0 && sy<=ty && ty<size_y);
#endif
					moves[i].first=PACK4(sx,size_y-1-ty,tx,size_y-1-sy);
				}
				for (int k=0;k<count;k++)
				{
					int sx,sy,tx,ty;
					UPACK4(row_moves[k].first,sx,sy,tx,ty);
					row_moves[k].first=PACK4(sx,size_y-1-ty,tx,size_y-1-sy);
				}
			}
			for (int k=0;k<count;k++) moves[num_moves++]=row_moves[k];
			for (int i=0;i<num_moves;i++)
			{
#ifdef LOCAL
				Timer t11(11);
#endif
				int sx,sy,tx,ty;
				UPACK4(moves[i].first,sx,sy,tx,ty);
				if (tx<x) continue;
				int d=moves[i].second;
				int new_tx=get_best_tx(x,sy,ty,tx,moves[i].second);
				if (new_tx==tx) continue;
				if (new_tx>tx)
					for (int ex=tx+1;ex<=new_tx;ex++) for (int y=sy;y<=ty;y++) update(a[ex][y],-d,p[ex][y]);
				else
					for (int ex=new_tx+1;ex<=tx;ex++) for (int y=sy;y<=ty;y++) update(a[ex][y],d,p[ex][y]);
				moves[i].first=PACK4(sx,sy,new_tx,ty);
			}
			state.copy_from_global();
			int add_pos;
			if (num_states[(x+1)&1]<MAX_NUM_STATES)
				states[(x+1)&1][add_pos=(num_states[(x+1)&1]++)].cost=1000000000;
			else
			{
				add_pos=0;
				for (int i=0;i<num_states[(x+1)&1];i++) if (states[(x+1)&1][i].cost<states[(x+1)&1][add_pos].cost) add_pos=i;
			}
#ifdef DEBUG
			ASSERT(num_states[(x+1)&1]<=MAX_NUM_STATES && add_pos>=0 && add_pos<num_states[(x+1)&1]);
#endif
			if (state.cost<states[(x+1)&1][add_pos].cost) states[(x+1)&1][add_pos]=state;
		}
	}
	for (int i=0;i<num_states[size_x&1];i++) update(states[size_x&1][i].num_moves,states[size_x&1][i].moves);
}

void process()
{
	double start_time=gettime();
	double time_limit=start_time+TIME_LIMIT;
	int _a[MAXN][MAXN],_p[MAXN][MAXN];
	bool is_transposed=false;
	if (size_x<size_y)
	{
		is_transposed=true;
		memcpy(_a,a,sizeof(a));
		memcpy(_p,p,sizeof(p));
		swap(size_x,size_y);
		for (int x=0;x<size_x;x++) for (int y=0;y<size_y;y++) a[x][y]=_a[y][x];
		for (int x=0;x<size_x;x++) for (int y=0;y<size_y;y++) p[x][y]=_p[y][x];
	}
	preprocess();
	init();
	memcpy(_a,a,sizeof(a));
	memcpy(_p,p,sizeof(p));
	beam_search(time_limit);
	memcpy(a,_a,sizeof(a));
	memcpy(p,_p,sizeof(p));
	if (is_transposed)
		for (int i=0;i<best_num_moves;i++)
		{
			int sx,sy,tx,ty;
			UPACK4(best_moves[i].first,sx,sy,tx,ty);
			best_moves[i].first=PACK4(sy,sx,ty,tx);
		}
}

int main()
{
#ifdef LOCAL
	const int MAXSEED=100;
	int case_study=-1;
	int num_cases=0;
	double sum_scores=0;
	double sum_used_time=0;
	for (int seed=0;seed<MAXSEED;seed++)
	{
		if (case_study>=0 && seed!=case_study) continue;
		generate(seed);
#else
		scanf("%d%d",&size_x,&size_y);
		for (int i=0;i<size_x;i++) for (int j=0;j<size_y;j++) scanf("%d",&p[i][j]);
		for (int i=0;i<size_x;i++) for (int j=0;j<size_y;j++) scanf("%d",&a[i][j]);
#endif
		int _size_x=size_x;
		int _size_y=size_y;
		int _a[MAXN][MAXN],_p[MAXN][MAXN];
		memcpy(_a,a,sizeof(a));
		memcpy(_p,p,sizeof(p));
#ifdef LOCAL
		double start_time=gettime();
#endif
		process();
#ifdef LOCAL
		double end_time=gettime();
#endif
		if (best_num_moves<0 || best_num_moves>_size_x*_size_y) { printf("Invalid count."); exit(0); }
		int s[MAXN][MAXN];
		memset(s,0,sizeof(s));
		for (int i=0;i<best_num_moves;i++)
		{
			int x1,y1,x2,y2,d=best_moves[i].second;
			UPACK4(best_moves[i].first,x1,y1,x2,y2);
			if (!(x1>=0 && x1<=x2 && x2<_size_x && y1>=0 && y1<=y2 && y2<_size_y)) { printf("Invalid box."); exit(0); }
			if (d<=0 || d>10000) { printf("Invalid d."); exit(0); }
			s[x1][y1]+=d; s[x2+1][y2+1]+=d; s[x1][y2+1]-=d; s[x2+1][y1]-=d;
		}
		for (int x=0;x<_size_x;x++) for (int y=0;y<_size_y;y++)
			if (x==0) s[x][y]=((y==0)?s[x][y]:s[x][y-1]+s[x][y]);
			else s[x][y]=((y==0)?s[x-1][y]+s[x][y]:s[x-1][y]+s[x][y-1]-s[x-1][y-1]+s[x][y]);
		for (int x=0;x<_size_x;x++) for (int y=0;y<_size_y;y++) if ((s[x][y]+_a[x][y])%_p[x][y]!=0) { printf("Non-zero number."); exit(0); }
#ifdef LOCAL
		double score=100.0*(double)best_num_moves/(double)_size_x/(double)_size_y;
		num_cases++;
		sum_scores+=score;
		sum_used_time+=end_time-start_time;
		printf("seed = %d   n = %d   m = %d   score = %.3lf    run_time = %.3lf\n",seed,_size_x,_size_y,score,end_time-start_time);
	}
	printf("avg_score = %.3lf\n",sum_scores/num_cases);
	printf("avg_time  = %.3lf\n",sum_used_time/num_cases);
	Timer::show();
	Counter::show();
#else
	printf("%d\n",best_num_moves);
	for (int i=0;i<best_num_moves;i++)
	{
		int x1,y1,x2,y2;
		UPACK4(best_moves[i].first,x1,y1,x2,y2);
		printf("%d %d %d %d %d\n",x1+1,y1+1,x2+1,y2+1,best_moves[i].second);
	}
#endif
	return 0;
}
