#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int m, n;
	scanf("%d%d", &m, &n);
	while(m != 0 || n != 0)
	{
		int count = 0;
		set<int> s1;
		for(int i = 0; i < m; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			s1.insert(tmp);
		}
		for(int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			set<int>::iterator it = s1.find(tmp);
			if(it != s1.end())
				count++;
		}
		printf("%d\n", count);
		scanf("%d%d", &m, &n);
	}
	return 0;	
}