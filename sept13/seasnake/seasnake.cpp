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

#define MAXSTEP 900000

typedef long long int lli;
typedef pair<int,int> pi;

class Point
{
	public:
	int row,col;
	
	Point()
	{}
	
	Point(int row,int col)
	{
		this->row = row;
		this->col = col;
	}
	
	Point(Point& pt)
	{
		this->row = pt.row;
		this->col = pt.col;
	}
	
	Point readPoint()
	{
		scanf("%d %d",&row,&col);
	}
	
	bool operator==(const Point& operand)
	{
		return (row==operand.row && col==operand.col);
	}
};

struct dir
{
	int left,right,up,down;
};
struct dir normaldir={2,3,0,1};

int n,m,i,j;
Point apple[1000];

class snake
{
	public:
	
	int length;

	Point temphead;
	int headdir;
	list<Point *> body;
	int curapple;
	vector<int> moves;
	list<Point *>::iterator it;
	snake()
	{
		length = 1;
		temphead.row = 0;
		temphead.col = 0;
		body.push_front(new Point(temphead));
		headdir = normaldir.right;
		curapple = 0;
	}
	
	bool checkcollision()
	{
		list<Point *>::iterator it;
		Point *head = body.front();
		it = body.begin();
		it++;
		while(it!=body.end())
		{
			if(**it == *head)
			{
				return true;
			}
			it++;
		}
		return false;
	}
	
	bool move(int dirn)
	{
		if(dirn==normaldir.left)
		{
			temphead.col = (temphead.col+m-1)%m;
			headdir = normaldir.left;
		}
		else if(dirn==normaldir.right)
		{
			temphead.col = (temphead.col+m+1)%m;
			headdir = normaldir.right;
		}
			
		else if(dirn==normaldir.up)
		{
			temphead.row = (temphead.row+n-1)%n;
			headdir = normaldir.up;
		}
			
		else if(dirn==normaldir.down)
		{
			temphead.row = (temphead.row+n+1)%n;
			headdir = normaldir.down;
		}
		moves.pb(dirn);
		body.push_front(new Point(temphead));
		if(temphead == apple[curapple])
		{
			curapple++;	
			length++;		
		}
		else
		{
			body.pop_back();
		}
		if(checkcollision() == true)
		{
			printf("collision %d",curapple);
			exit(0);
			return true;	
		}
		return false;
		
	}
};

void solvecolumn(snake& s)
{
	while(s.curapple<n*m-1)
	{
		s.move(normaldir.down);		
	} 
}
void solverow(snake& s)
{
	while(s.curapple<n*m-1)
	{
		s.move(normaldir.right);
	} 
}

bool tailinnext1(snake& s)
{
	if(n<=3)
		return true;
	Point *head = s.body.front();
	Point *tail = s.body.back();
	if(head->row == tail->row)
		return true;
	if(tail->row > head->row)
	{
		if(tail->row <= ((head->row+2)))
			return true;
	}
	else
	{
		if(head->row+2<n)
		{
			return false;
		}
		if(tail->row <= ((head->row+2)%n))
			return true;
			
	}
	return false;
	
}

int greedy1(snake& s)
{
	if(apple[s.curapple].row != s.temphead.row)
	{
		s.move(normaldir.down);
	}
	else
	{
		return 0;
	}
	return 1;
}
void solve1(snake& s)
{
	while(s.curapple<n*m-1)
	{
		if(!tailinnext1(s) && (s.temphead.col==0 || s.temphead.col==m-1))
		{
			int skip_next = greedy1(s);
			if(skip_next==1)
				continue;
		}
		if(s.temphead.col<m-1 && s.headdir==normaldir.right)
		{
			s.move(normaldir.right);
		}
		else if (s.temphead.col == m-1 && s.headdir==normaldir.right)
		{
			s.move(normaldir.down);
		}
		else if(s.temphead.col == m-1 && s.headdir == normaldir.down)
		{
			s.move(normaldir.left);
		}
		else if(s.temphead.col>0 && s.headdir==normaldir.left)
		{
			s.move(normaldir.left);
		}
		else if(s.temphead.col==0 && s.headdir==normaldir.left)
		{
			s.move(normaldir.down);
		}
		else if(s.temphead.col==0 && s.headdir==normaldir.down)
		{
			s.move(normaldir.right);
		}
		else
		{
			assert("Situation not handled");
		}
	}
}

bool tailinnext2(snake& s)
{
	if(m<=3)
		return true;
	Point *head = s.body.front();
	Point *tail = s.body.back();
	if(head->col == tail->col)
		return true;
	if(tail->col > head->col)
	{
		if(tail->col <= ((head->col+2)))
			return true;
	}
	else
	{
		if(head->col+2<m)
		{
			return false;
		}
		if(tail->col <= ((head->col+2)%m))
			return true;
			
	}
	return false;
	
}

int greedy2(snake& s)
{
	if(apple[s.curapple].col != s.temphead.col)
	{
		s.move(normaldir.right);
	}
	else
	{
		return 0;
	}
	return 1;
}
void solve2(snake& s)
{
	
	while(s.curapple<n*m-1)
	{
		if(!tailinnext2(s) && (s.temphead.row==0 || s.temphead.row==n-1))
		{
			int skip_next = greedy2(s);
			if(skip_next==1)
				continue;
		}
		if(s.temphead.row<n-1 && s.headdir==normaldir.down)
		{
			s.move(normaldir.down);
		}
		else if (s.temphead.row == n-1 && s.headdir==normaldir.down)
		{
			s.move(normaldir.right);
		}
		else if(s.temphead.row == n-1 && s.headdir == normaldir.right)
		{
			s.move(normaldir.up);
		}
		else if(s.temphead.row>0 && s.headdir==normaldir.up)
		{
			s.move(normaldir.up);
		}
		else if(s.temphead.row==0 && s.headdir==normaldir.up)
		{
			s.move(normaldir.right);
		}
		else if(s.temphead.row==0 && s.headdir==normaldir.right)
		{
			s.move(normaldir.down);
		}
		else
		{
			assert("Situation not handled");
		}
	}
}


void printmoves(snake& s)
{
	printf("%d\n",s.moves.size());
	for(i = 0;i < (int)s.moves.size();i++)
	{
		printf("%d\n",s.moves[i]);
	}
}

	snake s1,s2,s;
int main ()
{

	scanf("%d %d",&n,&m);
	for(i = 0;i < n*m-1;i++)
	{
		apple[i].readPoint();
	}
	if(m==1)
	{
		solvecolumn(s);
	}
	else if(n==1)
	{
		solverow(s);
	}
	else
	{
		if(n%2==0 && m%2==0)
		{
			solve1(s1);
			solve2(s2);
			if(s1.moves.size() < s2.moves.size())
			{
				s = s1;
			}
			else
			{
				s = s2;
			}
		}
		else if(n%2==0)
		{
			solve1(s);
		}
		else
		{
			solve2(s);
		}
	}
	if(s.moves.size() > MAXSTEP)
	{
		assert(0);
	}
	printmoves(s);
	return 0;
}


