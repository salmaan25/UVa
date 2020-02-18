#include <stdio.h>
#include <map>
#include <string>

using namespace std;

//typedef map <string, int> dict;

/*void generatelentgth(const dict& dictionary)
{
	for(int i = 0; i < )
}*/

int main(void)
{
	//dict dictionary;
	map <string, int> dictionary;
	char str[6];
	/*for(int len = 1; len <= 4; len++)
	{
		generatelentgth(len, dictionary);
	}*/
	int count = 0;
	for(int i = 0; i < 26; i++)
	{
		str[0] = (char)(i + 'a');
		str[1] = '\0';
		dictionary[str] = count;
		count++;
	}
	
	for(int i = 0; i < 25; i++)
	{
		str[0] = (char)(i + 'a');
		for(int j = i + 1; j < 26; j++)
		{
			str[1] = (char)('a' + j);
			str[2] = '\0';
			dictionary[str] = count;
			count++;
			//dictionary[(char)()]
		}
	}
	for(int i = 0; i < 24; i++)
	{
		str[0] = (char)(i + 'a');
		for(int j = i + 1; j < 25; j++)
		{
			str[1] = (char)(j + 'a');
			for(int k = j + 1; k < 26; k++)
			{
				str[2] = (char)('a' + k);
				str[3] = '\0';
				dictionary[str] = count;
				count++;
			}
		}
	}
	for(int i = 0; i < 23; i++)
	{
		str[0] = (char)(i + 'a');
		for(int j = i + 1; j < 24; j++)
		{
			str[1] = (char)(j + 'a');
			for(int k = j + 1; k < 25; k++)
			{
				str[2] = (char)(k + 'a');
				for(int l = k + 1; l < 26; l++)
				{
					str[3] = (char)(l + 'a');
					str[4] = '\0';
					dictionary[str] = count;
					count++;
				}
			}
		}
	}
	for(int i = 0; i < 22; i++)
	{
		str[0] = (char)(i + 'a');
		for(int j = i + 1; j < 23; j++)
		{
			str[1] = (char)(j + 'a');
			for(int k = j + 1; k < 24; k++)
			{
				str[2] = (char)(k + 'a');
				for(int l = k + 1; l < 25; l++)
				{
					str[3] = (char)(l + 'a');
					for(int m = l + 1; m < 26; m++)
					{
						str[4] = (char)(m + 'a');
						str[5] = '\0';
						dictionary[str] = count;
						count++;
					}
				}
			}
		}
	}
	char s[10];
	scanf("%s", s);
	printf("%d\n", dictionary[s] + 1);
	return 0;
}