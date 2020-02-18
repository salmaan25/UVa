#include <bits/stdc++.h>

using namespace std;

typedef struct info info;
struct info
{
	queue <int> index;
	int count;
};
int main(void)
{
	int t;
	scanf("%d", &t);
	while(t > 0)
	{
		map <int, info> m;
		int n;
		scanf("%d", &n);
		int start = 0, len = 1, maxLen = 0;
		for(int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			m[tmp].count += 1;
			if(m[tmp].count >= 2)
			{
				if(start <= m[tmp].index.back())
				{
					len = i - start;
					if(len > maxLen)
						maxLen = len;
					start = m[tmp].index.back() + 1;
				}
			}
			m[tmp].index.push(i);
		}
		if(n - start < maxLen)
			printf("%d\n", maxLen);
		else 
			printf("%d\n",n - start);
		t--;
	}
	return 0;
}