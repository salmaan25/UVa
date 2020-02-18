#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main(void)
{
	int n, q;
	while(cin >> n >> q)
	{
		map<int, vi> m;
		for(int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			m[tmp].push_back(i + 1);
		}
		//printf("%lu %lu", m.size(), m[1].size());
		for(int i = 0; i < q; i++)
		{
			int k,v;
			scanf("%d%d", &k, &v);
			if(m.find(v) != m.end())
			{
				if(k <= (m[v]).size())
					printf("%d\n", m[v][k - 1]);
				else
					printf("0\n");
			}
			else
				printf("0\n");
		}
	}
	return 0;
}