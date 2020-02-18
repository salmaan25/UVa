#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
class UnionFind
{
private: vi p, rank;
public:
	void UnionInit(int N)
	{
		rank.assign(N, 0);
		p.assign(N, 0);
		for(int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i)
	{
		if(p[i] == i)
			return i;
		else
			return findSet(p[i]);
	}
	bool isSameSet(int i, int j)
	{
		if(findSet(i) == findSet(j))
			return true;
		else
			return false;
	}
	void unionSet(int i, int j)
	{
		if(isSameSet(i, j) == false)
		{
			int x = findSet(i);
			int y = findSet(j);
			if(rank[x] > rank[y])
			{
				p[y] = x;
			}
			else
			{
				p[x] = y;
				if(rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};

int main(void)
{
	int t;
	scanf("%d", &t);
	vector< pair<int, int> > v;
	while((getchar()) != '\n');
	while(t > 0)
	{
		int num;
		scanf("%d", &num);
		UnionFind u;
		u.UnionInit(num);
		char null;
		scanf("%c", &null);
		char a;
		scanf("%c", &a);
		int corAns = 0, WrongAns = 0;
		while(a != '\n')
		{
			int b, c;
			scanf("%d%d", &b, &c);
			if(a == 'c')
			{
				u.unionSet(b - 1, c - 1);
			}
			else if(a == 'q')
			{
				if(u.isSameSet(b - 1, c - 1) == true)
					corAns += 1;
				else
					WrongAns += 1;
			}
			scanf("%c", &null);
			scanf("%c", &a);
		}
		/*if(t == 1)
			printf("%d,%d\n", corAns, WrongAns);
		else
			printf("%d,%d\n\n", corAns, WrongAns);*/
		v.push_back(pair<int, int>(corAns, WrongAns));
		t--;
	}

	for(vector< pair<int, int> >::iterator it = v.begin(); it != v.end(); it++)
	{
		printf("%d,%d\n\n", it->first, it->second);
	}
	return 0;
}