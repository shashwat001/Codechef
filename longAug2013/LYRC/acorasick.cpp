#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long llint;

#define pb push_back

const int MAXD = 19;
int sumd[505] = {0};
vector<int> v[250010];
char s[50005];

struct AhoCorasick {
	static const int NONE = 0;
	static const int MAXN = 250010;
	static const int CHARSET = 256;

	int end;
	int tag[MAXN];
	int fail[MAXN];
	int trie[MAXN][CHARSET];

	void init() {
		tag[0] = NONE;
		fill(trie[0], trie[0] + CHARSET, -1);
		end = 1;
	}

	int add(int m, const int* s) {
		int p = 0;
		for (int i = 0; i < m; ++i) {
			if (trie[p][*s] == -1) {
				tag[end] = NONE;
				fill(trie[end], trie[end] + CHARSET, -1);
				trie[p][*s] = end++;
			}
			p = trie[p][*s];
			++s;
		}
		return p;
	}

	void build() 
	{
		queue<int> bfs;
		fail[0] = 0;
		for (int i = 0; i < CHARSET; ++i) {
			if (trie[0][i] != -1) {
				fail[trie[0][i]] = 0;
				bfs.push(trie[0][i]);
			} else {
				trie[0][i] = 0;
			}
		}
		while (!bfs.empty()) {
			int p = bfs.front();
			tag[p] |= tag[fail[p]];
			bfs.pop();
			for (int i = 0; i < CHARSET; ++i) {
				if (trie[p][i] != -1) {
					fail[trie[p][i]] = trie[fail[p]][i];
					bfs.push(trie[p][i]);
				} else {
					trie[p][i] = trie[fail[p]][i];
				}
			}
		}
	}
	
	void update()
	{
		int p = 0;
		int i,l;
		l = strlen(s);
		for(i = 0;i < l;i++)
		{
			while(trie[p][(int)s[i]] == -1)
			{
				p = fail[p];
			}
			p = trie[p][(int)s[i]];
			if(tag[p]!=NONE)
			{
				for(int k = 0;k < v[p].size();k++)
				{
					sumd[v[p][k]]++;
				}
			}
				
		}
	}
} ac;




int main() 
{
	int i;
    int n, t, a[5005];
    char buf[5005];
    scanf("%d",&n);
    ac.init();
    for ( i = 0; i < n; ++i) {
        scanf("%s", buf);
        t = (int)strlen(buf);
        for (int j = 0; j < t; ++j) {
            a[j] = buf[j];
        }
        int state = ac.add(t,a);
        v[state].pb(i);
        ac.tag[ac.add(t, a)] = 1;
    }
    ac.build();
    int p;
    scanf("%d",&p);
    for(i = 0;i < p;i++)
    {
    	scanf("%s",s);
    	ac.update();
    }
    for(i = 0;i < n;i++)
    {
    	printf("%d\n",sumd[i]);
    }

    return 0;
}

