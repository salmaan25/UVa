#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int t;
	scanf("%d", &t);
	int cat;
	scanf("%d", &cat);
	map<string, pair<int, map<string, int> > > 	m;
	for(int i = 0; i < cat; i++)
	{
		char s[100];
		int n, d;
		scanf("%s%d%d", s, &n, &d);
		m[s].first = d;
		for(int j = 0; j < n; j++)
		{
			char str[100];
			scanf("%s", str);
			(m[s].second)[str] = 0;
		}
	}
	return 0;
}