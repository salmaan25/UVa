#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
/*class UnionFind
{
private: vi p, rank;
public:
    UnionFind(int N)
    {
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i)
    {
        if(p[i] == i)
            return i;
        else
            return findSet(p[i]);
    }
    bool isSameSet(int i, int j)
    {
        if(findSet(i) == findSet(j))
            return true;
        else
            return false;
    }
    void unionSet(int i, int j)
    {
        if(isSameSet(i, j) == false)
        {
            int x = findSet(i);
            int y = findSet(j);
            if(rank[x] > rank[y])
            {
                p[y] = x;
            }
            else
            {
                p[x] = y;
                if(rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
};*/
class UnionFind { // OOP style
private: vi p, rank; // remember: vi is vector<int>
public:
UnionFind(int N) { rank.assign(N, 0);
p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {
if (!isSameSet(i, j)) { // if from different set
int x = findSet(i), y = findSet(j);
if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
else { p[x] = y;
if (rank[x] == rank[y]) rank[y]++; }
} } };

int main(void)
{
int T,n,x,y,cont1,cont2;
    char c;
    string s;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++)
    {
        scanf("\n%d\n",&n);
        
        UnionFind u(n);
        cont1=cont2=0;
        
        while(1)
        {
            if(!getline(cin,s) || s.empty()) break;
            sscanf(s.c_str(),"%c %d %d",&c,&x,&y);
            
            if(c=='c') u.unionSet(x,y);
            else u.findSet(x)== u.findSet(y)? cont1++:cont2++;
        }
        
        if(tc!=1) printf("\n");
        printf("%d,%d\n",cont1,cont2);
    }
    return 0;
}