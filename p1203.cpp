#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	char s[100];
	scanf("%s", s);
	priority_queue< pair < pair <int, int> , int> > p;
	while(strcmp(s, "Register") == 0)
	{
		int m1, m2;
		scanf("%d%d", &m1, &m2);
		pair < pair <int, int> , int> tmp;
		tmp.first.first = (-1) * m2;
		tmp.first.second = (-1) * m1;
		tmp.second = m2;
		p.push(tmp);
		while ((getchar()) != '\n');
		scanf("%s", s);
	}
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		pair < pair <int, int> , int> tmp;
		tmp = p.top();
		int val = tmp.second;
		p.pop();
		pair < pair <int, int> , int> tmp1;
		tmp1 = tmp;
		tmp1.first.first = tmp1.first.first - val;
		p.push(tmp1);
		printf("%d\n", (-1) * (tmp.first.second));
	}
	return 0;
}