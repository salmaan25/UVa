//g++ --std=c++11 auto.cpp
//-fsanitize=address for segfault
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mem(a,val) memset(a,val,sizeof(a))
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
const ll inf = 0xFFFFFFFFFFFFFFFL; //very large number
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
clock_t time_p=clock();
void time()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

#define MAXN 200010
#define MAXLG 20
string A;
struct entry { 
	int nr[2], p;
} L[MAXN];
int P[MAXLG][MAXN], N, i, stp, cnt;

int cmp(struct entry a, struct entry b) {
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

void make() {
	for(N = A.length(), i = 0; i < N; i ++)
		P[0][i] = A[i] - 'a';
	for(stp = 1, cnt = 1; cnt >> 1 < N; stp++, cnt <<= 1) {
		for(i = 0; i < N; i ++) { 
			L[i].nr[0] = P[stp - 1][i];
			L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
			L[i].p = i; 
		}
		sort(L, L + N, cmp);
		for(i = 0; i < N; i++) P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
 	}
}

int lcp(int x, int y)
{
	int k, ret = 0; 
	if (x == y) 
		return N - x;
	for (k = stp - 1; k >= 0 && x < N && y < N; k--) {
		if (P[k][x] == P[k][y]) {
			x += 1 << k; 
			y += 1 << k;
			ret += 1 << k; 
		}
	}
	return ret;
} 

int32_t main(void)
{
	IOS;
	ll t;
	cin>>t;
	while(t--) {
		ll n;
		string s;
		cin>>n>>s;
		// ll n = s.length();
		A = s+s;
		make();
		vii ls(2*n);
		for(ll i = 0; i < 2*n; i++) {
			ls[i].first = P[stp-1][i];
			ls[i].second = i;
		}
		sort(ls.begin(), ls.end());
		vi pos;
		ll flag = 0;
		for(ll i = 0; i < 2*n; i++) {
			if(2*n - ls[i].second >= n) {
				if(flag == 0) {
					flag = 1;
					pos.pb(ls[i].second);	
				}
				else {
					if(lcp(ls[i].second, pos[(ll)pos.size()-1]) >= n)
						pos.pb(ls[i].second);
				}
			}
		}
		sort(pos.begin(), pos.end());
		cout<<pos[0]<<endl;
	}
	time();
	return 0;
}