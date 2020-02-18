#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <ctype.h>
#include <string.h>
#include <math.h>

using namespace std;

void process(char* str, int len)
{
	char str1[len];
	int counter = 0;
	for(int i = 0; i < len; i++)
	{
		if(((int)(str[i]) >= 'a' && (int)(str[i]) <= 'z') || ((int)(str[i]) >= 'A' && (int)(str[i]) <= 'Z'))
		{
			if((int)(str[i]) >= 'A' && (int)(str[i]) <= 'Z')
			{
				str[i] = 'a' - 'A' + (int)(str[i]);
				str1[counter] = str[i];
				counter++;
			}
			else
			{
				str1[counter] = str[i];
				counter++;
			}
		}
	}
	for(int i = 0; i < counter; i++)
		str[i] = str1[i];
	str[counter] = '\0';
}

int main(void)
{
	char str[100];
	scanf("%s", str);
	map <string, int> m;
	while(strcmp(str, "END_OF_FILE") != 0)
	{
		process(str, strlen(str));
		m[str] += 1;
		scanf("%s", str);
	}
	int count = 0;
	for(map<string, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		count += it->second;
	}
	float E_T = 0.0;
	for(map<string, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		E_T += (float)(it->second) * (log10((float)(count)) - log10((float)(it->second)));
	}
	E_T = E_T / ((float)(count));
	float E_max = log10((float)(count));
	float E_rel = E_T / E_max;
	E_rel = E_rel * 100.0;
	printf("%d %.1f %.1f", count, E_T, E_rel); 
	return 0;
}