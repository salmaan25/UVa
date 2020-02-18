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
vector<ll> dp(10010);
map<ll, vi> den;
map<ll ,ll> b;

void fillDP() {
	for(auto it: b)
		den[it.first].resize(10010, 0);
	for(ll i = 0; i < 10010; i++)
		dp[i] = MAX;
	dp[0] = 0;
	for(ll i = 1; i < 10010; i++) {
		ll minDen = -1;
		for(auto it: b) {
			if(i-it.first >= 0 && dp[i-it.first] < MAX) {
				if(den[it.first][i-it.first] < it.second) {
					if(dp[i-it.first] + 1 < dp[i]) {
						dp[i] = dp[i-it.first] + 1;
						minDen = it.first;
					}
				}
			}
		}
		if(minDen != -1) {
			for(auto it: den)
				it.second[i] = it.second[i-minDen];
			den[minDen][i] += 1; 
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
			ll t;
			cin>>t;
			if(b.find(t) == b.end())
				b[t] = 1;
			else
				b[t] += 1;
		}
		fillDP();
		// cout<<"FDdfdf"<<endl;
		bool flag = true;
		ll ind = m;
		// cout<<dp[2000]<<endl;
		for(ll ind = m; ind < 10010; ind++) {
			if(dp[ind] < MAX) {
				cout<<ind<<" "<<dp[ind]<<endl;
				flag = false;
				break;
			}
		}
		if(flag)
			cout<<"-1"<<endl;
		dp.clear();
		b.clear();
	}
	return 0;
}