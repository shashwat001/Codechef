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
#include <unistd.h>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

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
	
	static Point readPoint()
	{
		Point p;
		scanf("%d %d",&p.row,&p.col);
		return p;
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
struct dir transformeddir = {0,1,2,3};

int n,m,i,j;
int curapple = 0;
Point apple[1000000];
class snake
{
	public:
	
	int length;

	Point temphead;
	int headdir;
	int points[40][40];
	list<Point *> body;
	snake()
	{
		length = 1;
		temphead.row = 0;
		temphead.col = 0;
		for(i = 0;i < n;i++)
			for(j = 0;j < m;j++)
				points[i][j] = '.';
		points[0][0] = '*';
		body.push_front(new Point(temphead));
		headdir = normaldir.right;
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
		
		body.push_front(new Point(temphead.row,temphead.col));
		points[temphead.row][temphead.col] = '*';
		if(temphead == apple[curapple])
		{
			curapple++;	
			length++;		
		}
		else
		{
			Point *tail = body.back();
			points[tail->row][tail->col] = '.';
			body.pop_back();
		}
		if(checkcollision() == true)
		{
			return true;
		}
		return false;
		
	}
};
snake s;
void printsnake()
{	
	for(i = 0;i < n;i++)
	{
		printf("\033[F");
	}
	s.points[apple[curapple].row][apple[curapple].col] = 'o';
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < m;j++)
		{
			printf("%c",s.points[i][j]);
		}
		printf("\n");
	}
	fflush(stdout);
}
int main ()
{
	int nummoves;
	FILE *data = fopen("input","r");
	FILE *solution = fopen("output","r");
	
	fscanf(data,"%d %d",&n,&m);
	for(i = 0;i < n*m-1;i++)
	{
		fscanf(data,"%d %d",&apple[i].row,&apple[i].col);
	}
//	printsnake();
//	usleep(400*1000);
	fscanf(solution,"%d",&nummoves);
	for(i = 0;i < nummoves;i++)
	{
		int curmove;
		fscanf(solution,"%d",&curmove);
		bool collision = s.move(curmove);
		
//		printsnake();
//		usleep(400*1000);
		if(collision == true)
		{
			printf("collision %d",i);
			return 0;
		}
	}
	
				
			
	return 0;
}
