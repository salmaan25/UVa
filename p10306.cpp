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
ll dp[310][310];
vii c;
ll s;
ll m;
ll MAX = 1000000000;

void fillDP() {
	for(ll i = 0; i <= s; i++) {
		for(ll j = 0; j <= s; j++)
			dp[i][j] = MAX;
	}
	for(ll i = 0; i < (ll)c.size(); i++)
		dp[c[i].first][c[i].second] = 1;
	for(ll i = 0; i <= s; i++) {
		for(ll j = 0; j <= s; j++) {
			for(ll k = 0; k < (ll)c.size(); k++) {
				if(i-c[k].first >= 0 && j-c[k].second >= 0)
					dp[i][j] = min(dp[i-c[k].first][j-c[k].second] + 1, dp[i][j]);
			}
		}
	}
}

int main(void) {
	IOS;
	ll t;
	cin>>t;
	while(t--) {
		// ll m ,s;
		cin>>m>>s;
		for(ll i = 0; i < m; i++) {
			ll t1, t2;
			cin>>t1>>t2;
			c.pb(mp(t1, t2));
		}
		fillDP();
		if(m == 0 && s == 0)
			cout<<0<<endl;
		else {
			ll ans = MAX;
			for(ll i = 0; i <= s; i++) {
				for(ll j = 0; j <= s; j++) {
					if(i*i + j*j == s*s) {
						if(dp[i][j] < MAX) {
							ans = min(ans, dp[i][j]);
						}
					}
				}
			}
			if(ans == MAX)
				cout<<"not possible"<<endl;
			else
				cout<<ans<<endl;
			c.clear();
		}
	}	
	return 0;
}