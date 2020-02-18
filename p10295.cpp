#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <utility>
#include <map>

using namespace std;

int main(void)
{
	int n, t;
	scanf("%d%d", &n, &t);
	map<string, pair<int, int> > m;
	for(int i = 0; i < n; i++)
	{
		char s[100];
		scanf("%s", s);
		int val = 0;
		scanf("%d", &val);
		m[s].first = val;
	}
	while(t > 0)
	{
		char s[100];
		scanf("%s", s);
		while(strcmp(s, ".") != 0)
		{
			map<string, pair<int, int> >::iterator it = m.find(s);
			if(it != m.end())
				m[s].second += 1;
			scanf("%s", s);
		}
		int ans = 0;
		for(map<string, pair<int, int> >::iterator it = m.begin(); it != m.end(); it++)
		{
			ans += ((*it).second.second) * ((*it).second.first);
		}
		printf("%d\n", ans);
		for(map<string, pair<int, int> >::iterator it = m.begin(); it != m.end(); it++)
		{
			((*it).second.second) = 0;
		}
		t--;
	}
	return 0;
}