#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vi;
typedef map<char, int> mcc;

void addEdge(char* edge, char* init, map<char, vi>& AdjList, mcc& list)
{
	AdjList[edge[0]].push_back(edge[1]);
	AdjList[edge[1]].push_back(edge[0]);
	if(edge[0] == init[0] || edge[0] == init[1] || edge[0] == init[2])
		list[edge[0]] = 3;
	else
		list[edge[0]] = 0;
	if(edge[1] == init[0] || edge[1] == init[1] || edge[1] == init[2])
		list[edge[1]] = 3;
	else
		list[edge[1]] = 0;
}
int countYears(map<char, vi>& AdjList, mcc& list, priority_queue< pair<int, char> >& p)
{
	
	pair<int, char> tmp;
	while(p.empty() == false)
	{
		tmp = p.top();
		p.pop();
		int flag = 0;
		for(map<char, vi>::iterator it = AdjList.begin(); it != AdjList.end(); it++)
		{
			char cur = it->first;
			if(find(AdjList[cur].begin(), AdjList[cur].end(), tmp.second) != AdjList[cur].end())
			{
				flag = 1;
				list[cur] += 1;
				if(list[cur] == 3)
					p.push(pair<int, char>(tmp.first - 1, cur)); //tmp->first - 1
			}
		}	
	}
	return tmp.first;
}
bool allEltOfListAct(mcc& list, int vertices)
{
	int count = 0;
	for(mcc::iterator it = list.begin(); it != list.end(); it++)
	{
		if(it->second < 3)
			return false;
		else
			count++;
	}
	if(vertices == count)
		return true;
	else
		return false;
}
int main(void)
{
	int m,n;
	while(cin >> n >> m)
	{
		map<char, vi> AdjList;
		mcc list;
		char init[4];
		char edge[3];
		while((getchar()) != '\n');
		scanf("%s", init);
		for(int i = 0; i < m; i++)
		{
			while((getchar()) != '\n');
			scanf("%s", edge);
			addEdge(edge, init, AdjList, list);
		}
		if(n != 3)
		{
			priority_queue< pair<int, char> > p; //int is for day num 
			p.push(pair<int, char>(0, init[0]));
			p.push(pair<int, char>(0, init[1]));
			p.push(pair<int, char>(0, init[2]));
			int num = countYears(AdjList, list, p);
			bool b = allEltOfListAct(list, n);
			if(b == true)
				printf("WAKE UP IN, %d, YEARS\n", (-1) * num);
			else
				printf("THIS BRAIN NEVER WAKES UP\n");
		}
		else
			printf("WAKE UP IN, 0, YEARS\n");
	}	
	return 0;
}