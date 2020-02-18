#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii; 
typedef vector<ii> vii;
int main(void)
{
	int r, c;
	while(cin >> r >> c)
	{
		//scanf("%d%d", &r, &c);
		vector<vii> AdjList(c);
		for(int i = 0; i < r; i++)
		{
			int nonZeroEltNum = 0;
			scanf("%d", &nonZeroEltNum);
			//printf("%d\n", nonZeroEltNum);
			if(nonZeroEltNum == 0)
			{
				while ((getchar()) != '\n');
				char c;
				scanf("%c", &c);
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
		for(int i = 0; i < c; i++)
		{
			if(AdjList[i].empty() == true)
				printf("0\n\n");
			else
			{
				printf("%d", (int)AdjList[i].size());
				for(int j = 0; j < (int)AdjList[i].size(); j++)
				{
					printf(" %d", AdjList[i][j].first + 1);
				}
				printf("\n");
				for(int j = 0; j < (int)AdjList[i].size(); j++)
				{
					if(j == 0)
						printf("%d", AdjList[i][j].second);
					else
						printf(" %d", AdjList[i][j].second);
				}
				printf("\n");
			}
		}
	}
	return 0;
}