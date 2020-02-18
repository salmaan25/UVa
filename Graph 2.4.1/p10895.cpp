#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii; 
typedef vector<ii> vii;
int main(void)
{
	int r, c;
	scanf("%d%d", &r, &c);
	map<int, vii> AdjList;
	for(int i = 0; i < r; i++)
	{
		int nonZeroEltNum = 0;
		scanf("%d", &nonZeroEltNum);
		if(nonZeroEltNum == 0)
		{
			while ((getchar()) != '\n');
		}
		else
		{
			int arPos[nonZeroEltNum];
			for(int j = 0; j < nonZeroEltNum; j++)
				scanf("%d", &arPos[j]);
			int arVal[nonZeroEltNum];
			for(int j = 0; j < nonZeroEltNum; j++)
				scanf("%d", &arVal[j]);
			for(int j = 0; j < nonZeroEltNum; j++)
			{
				pair<int, int> p;
				p.first = i;
				p.second = arVal[j];
				AdjList[arPos[j] - 1].push_back(p);
			}
		}
	}
	printf("%d %d\n", c, r);
	int colCheck = 0;
	for(map<int, vii>::iterator it = AdjList.begin(); it != AdjList.end(); it++)
	{
		if(colCheck == it->first)
		{
			int arPos[r];
			int arVal[r];
			int num = 0;
			for(vii::iterator it1 = (it->second).begin(); it1 != (it->second).end(); it1++)
			{
				arPos[num] = it1->first;
				arVal[num] = it1->second;
				num++;
			}
			if(num == 0)
				printf("0\n\n");
			else
			{
				printf("%d", num);
				for(int i = 0; i < num; i++)
					printf(" %d", arPos[i] + 1);
				printf("\n");
				for(int i = 0; i < num; i++)
				{
					if(i == 0)
						printf("%d", arVal[i]);
					else
						printf(" %d", arVal[i]);
				}
				printf("\n");
			}
			colCheck++;
		}
		else
		{
			printf("0\n\n");
			it--;
			colCheck++;
		}
	}
	if(colCheck != c)
		printf("0\n\n");
	return 0;
}