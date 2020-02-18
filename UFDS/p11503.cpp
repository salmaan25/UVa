#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vi;
class UnionFind 
{ 																	// OOP style
	private: 
	map<string, string> p;
	map<string, int> rank;
	map<string, int> eltCount; 											// remember: vi is vector<int>
	public:
	void add(string s1, string s2) {
		if(p.find(s1) == p.end()){
			p[s1] = s1;
			rank[s1] = 0;
			eltCount[s1] = 1; }
		if(p.find(s2) == p.end()) {
			p[s2] = s2;
			rank[s2] = 0;
			eltCount[s2] = 1; }}
	string findSet(string i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(string i, string j) { 
		return findSet(i) == findSet(j); } 
	void unionSet(string i, string j) {
		if (!isSameSet(i, j)) { 															 // if from different set
			string x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
				eltCount[x] += eltCount[y];}						 // rank keeps the tree short
			else{ 
				p[x] = y;
				eltCount[y] += eltCount[x];
				if (rank[x] == rank[y]) rank[y]++; }}}
	int countELt(string i){
		return eltCount[findSet(i)];} 
};

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t > 0)
	{
		int n;
		scanf("%d", &n);
		map<string, int> rank;
		map<string, string> p;
		map<string, vi> AdjList;
		UnionFind u;
		for(int i = 0; i < n; i++)
		{
			while((getchar()) != '\n');
			string s1, s2;
			cin >> s1;
			char c;
			scanf("%c", &c);
			cin >> s2;
			AdjList[s1].push_back(s2);
			AdjList[s2].push_back(s1);
			u.add(s1, s2);
			u.unionSet(s1, s2);
			int ans = u.countELt(s1);
			printf("%d\n", ans);
		}
		t--;
	}
	return 0;
}