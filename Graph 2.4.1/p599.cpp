#include<bits/stdc++.h>
using namespace std;

typedef vector<char> vii;
void ConComp(char start, map<char, vii>& AdjList, map<char, char>& v);

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t > 0)
	{
		map<char, vii> AdjList;
		map<char, char> v;
		char str[6];
		scanf("%s", str);
		while(str[0] != '*')
		{
			AdjList[str[1]].push_back(str[3]);
			AdjList[str[3]].push_back(str[1]);
			while ((getchar()) != '\n');
			scanf("%s", str);
		}
		char c;
		while ((getchar()) != '\n');
		scanf("%c", &c);
		v[c] = 'n';
		while(c != '\n')
		{
			scanf("%c", &c);

			if(c != ',' && c != '\n')
				v[c] = 'n';
		}
		int CompNum = 0;
		for(map<char, vii>::iterator it = AdjList.begin(); it != AdjList.end(); it++)
		{
			if(v[it->first] == 'n')
			{
				v[it->first] = 'y';
				ConComp(it->first, AdjList, v);
				CompNum+=1;
				}
		}
		int acorn = 0;
		for(map<char, char>::iterator it = v.begin(); it != v.end(); it++)
		{
			if(it->second == 'n')
				acorn += 1;
		}
		cout<<"There are "<<CompNum<<" tree(s) and "<<acorn<< " acorn(s).\n";
		t--;
	}
	return 0;
}
void ConComp(char start, map<char, vii>& AdjList, map<char, char>& v)
{
	for(vii::iterator it = AdjList[start].begin(); it != AdjList[start].end(); it++)
	{
		if(v[*it] == 'n')
		{
			v[*it] = 'y';
			ConComp(*it, AdjList, v);
		}
	}
	return;
}