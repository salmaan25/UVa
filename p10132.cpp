#include <stdio.h>
#include <string>
#include <map>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <utility>
#include <iostream>

using namespace std;

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t > 0)
	{
		map<string, pair<int, int> > m;
		char ar[10];
		scanf("%s", ar);
		int count = 0;
		int wordcount = 0;
		while(strcmp(ar, "end") != 0)
		{
			wordcount += 1;
			count += strlen(ar);
			m[ar].second += 1;
			m[ar].first = strlen(ar);
			scanf("%s", ar);
		}
		int file_count = wordcount / 2;
		int file_len = count / file_count;
		/*for(map<string, pair<int, int> >::iterator it = m.begin(); it != m.end(); it++)
		{
			cout<< it->first <<" ";
			printf("%d %d\n", (*it).second.first, (*it).second.second);
		}
		printf("%d %d\n", wordcount, wordlen);*/
		for(map<string, pair<int, int> >::iterator it = m.begin(); it != m.end(); it++)
		{
			
		}
		t--;
	}
	return 0;
}