#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);
	while(n != 0)
	{
		long long int count = 0;
		multiset<int> s;
		while(n > 0)
		{
			int p;
			scanf("%d", &p);
			for(int i = 0; i < p; i++)
			{
				int tmp;
				scanf("%d", &tmp);
				s.insert(tmp);
			}
			count += (long long int)(*(s.rbegin()) - *(s.begin()));
			s.erase(s.begin());
			multiset<int>::iterator it = s.end();
			it--;
			s.erase(it);
			n--;
		}
		printf("%lld\n", count);
		scanf("%d", &n);
	}
	return 0;
}