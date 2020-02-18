#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t > 0)
	{
		int g, sg, sb;
		scanf("%d%d%d", &g, &sg, &sb);
		multiset<int> SforG;
		multiset<int> SforB;
		for(int i = 0; i < sg; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			SforG.insert((-1) * tmp);
		}
		for(int i = 0; i < sb; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			SforB.insert((-1) * tmp);
		}
		int arB[g];
		int arG[g];
		int countG = 0, countB = 0, count = 0;
		while(SforB.empty() == false && SforG.empty() == false)
		{
			count = 0;
			countG = 0;
			countB = 0;
			while(SforB.empty() == false && SforG.empty() == false)
			{
				if(count < g)
				{
					int tmp1 = *(SforB.begin());
					int tmp2 = *(SforG.begin());
					SforG.erase(SforG.begin());
					SforB.erase(SforB.begin());
					if(tmp1 < tmp2)
					{
						arB[countB] = tmp1 - tmp2;
						countB++;
					}
					else if(tmp1 > tmp2)
					{
						arG[countG] = tmp2 - tmp1;
						countG++;
					}
					count++;
				}
				else
					break;
			}	
			for(int i = 0; i < countG; i++)
				SforG.insert(arG[i]);
			for(int i = 0; i < countB; i++)
				SforB.insert(arB[i]);
		}
		if(SforB.empty() == false )
		{
			printf("blue wins\n");
			for(multiset<int>::iterator itB = SforB.begin(); itB != SforB.end(); itB++)
			{
				printf("%d\n", (-1) * (*itB));
			}
		}
		else if(SforG.empty() == false)
		{
			printf("green wins\n");	
			for(multiset<int>::iterator itG = SforG.begin(); itG != SforG.end(); itG++)
				printf("%d\n", (-1) * (*itG));
		}
		else
			printf("green and blue died\n");
		if(t - 1)
			printf("\n");
		t--;
	}
	return 0;
}