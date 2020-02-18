#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// vector< pair<ii> m;
ll MAX = 1000000000;
ll m;
ll n;
ll dp[110][20010];
vi den;

void fillDP() {
	for(ll i = 0; i < 110; i++) {
		for(ll j = 0; j < 20010; j++)
			dp[i][j] = MAX;
	}
	dp[0][den[0]] = 1;
	dp[0][0] = 0;
	// cout<<dp[n-1][1400]<<endl;
	for(ll i = 1; i < n; i++) {
		for(ll j = 0; j < 20010; j++) {
			if(dp[i-1][j] < MAX) {
				dp[i][j] = min(dp[i-1][j], dp[i][j]);
				if(j + den[i] < 20010)
					dp[i][j+den[i]] = min(dp[i-1][j] + 1, dp[i][j + den[i]]);
			}
		}
	}
}

int main(void) {
	IOS;
	ll t;
	cin>>t;
	while(t--) {
		cin>>m;
		cin>>n;
		for(ll i = 0; i < n; i++) {
			ll t1;
			cin>>t1;
			den.pb(t1);
		}
		if(n == 0 && m == 0)
			cout<<"0 0"<<endl;
		else {
			fillDP();
			for(ll i = m; i < 20010; i++) {
				if(dp[n-1][i] < MAX) {
					cout<<i<<" "<<dp[n-1][i]<<endl;;
					break;
				}
			}
		}
		den.clear();
	}
	return 0;
}
