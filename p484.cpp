#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector <int> v;
	map <int, int> m;
	int t;
	scanf("%d", &t);
	while(t != -1)
	{
		if(m[t] == 0)
			v.push_back(t);
		m[t]++;
		scanf("%d", &t);
	}
	/*for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		printf("%d %d\n", it->first, it->second);
	}*/
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
		printf("%d %d\n", *it, m[*it]);
	return 0;
}