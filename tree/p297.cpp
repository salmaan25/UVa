#include <bits/stdc++.h>
using namespace std;

typedef struct box box;
struct box
{
	char c;
	box* nextBox;
};
void initBox(box* b) { b->nextBox = NULL; }
void MakeTrie(string s, box* b, int* p)
{
	initBox(b);
	if(*p > (int)s.size()){ return;}
	b->c = s[*p];
	if(s[*p] == 'p')
	{
		box* b1 = (box*)malloc(4 * sizeof(box));
		b->nextBox = b1;
		*p += 1;
		MakeTrie(s, &b[0], p);
		*p += 1;
		MakeTrie(s, &b[1], p);
		*p += 1;
		MakeTrie(s, &b[2], p);
		*p += 1;
		MakeTrie(s, &b[3], p);
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t > 0)
	{
		while((getchar()) != '\n');
		string s1;
		cin >> s1;
		string s2;
		while((getchar()) != '\n');
		cin >> s2;
		box b1, b2;
		int p = 0;
		if(b1.c == 'p')
			MakeTrie(s1, &b1, &p);
		if(b2.c == 'p')
			MakeTrie(s2, &b2, &p);
		int n = 32;
		Union(b1, b2);
		int ans = countSquares(b1, b2, &n);
		t--;
	}
	return 0;
}