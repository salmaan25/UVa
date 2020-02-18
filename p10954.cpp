#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);
	while(n != 0)
	{
		priority_queue<int> p;
		int tmp;
		for(int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			p.push((-1) * tmp);
		}
		int cost = 0;
		while(p.size() != 1)
		{
			int tmp1 = p.top();
			p.pop();
			int tmp2 = p.top();
			p.pop();
			p.push(tmp1 + tmp2);
			cost += tmp1 + tmp2;
		}
		printf("%d\n", (-1) * cost);
		scanf("%d", &n);
	}
	return 0;
}