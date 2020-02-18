#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector< pair<ll, ll> > vii;
#define pb push_back
#define mp make_pair
ll m, n;
ll M;
vii a;
ll dp[111][10210];
void makeDP() {
	// printf("in\n");
	// printf("%lld\n", m);
	for(ll i = 0; i < 111; i++) {
		for(ll j = 0; j < 10201; j++)
			dp[i][j] = -1;
	}
	dp[1][m] = 0;
	// printf("1    %lld    %lld\n", m, dp[1][m]);
	if(a[0].first <= m) {
		dp[1][m-a[0].first] = a[0].second;
		// printf("1   %lld    %lld\n", m-a[0].first, a[0].second);
	}
	for(ll i = 2; i <= n; i++) {
		for(ll j = 0; j <= m; j++) {
			if(dp[i-1][j] != -1) {
				dp[i][j] = max(dp[i-1][j], dp[i][j]);
				// printf("%lld   %lld   %lld\n", i, j, dp[i-1][j]);
				if(j >= a[i-1].first) {
					// printf("%lld   %lld    %lld\n", i, j-a[i-1].first, dp[i][j] + a[i-1].second);
					dp[i][j-a[i-1].first] = max(dp[i][j] + a[i-1].second, dp[i][j-a[i-1].first]);
				}
			}
		}
	}
	// printf("out\n");
}

int main(void) {
	n = 0, m = 0, M = 0;
	while(scanf("%lld %lld", &M, &n) == 2) {
		if(M > 1800)
			m= M+200;
		else
			m = M;
		// printf("%lld  %lld\n", m, n);
		for(ll i = 0; i < n; i++) {
			ll t1, t2;
			scanf("%lld%lld", &t1, &t2);
			a.pb(mp(t1, t2));
			// printf("%lld  %lld\n", t1, t2);
		}
		makeDP();
		if(n == 0)
			printf("0\n");
		else {
			ll ans = 0;
			if(m == M) {
				// printf("infdnnf\n");
				// printf("%lld\n", m);
				// printf("%lld\n", dp[n][1700]);
				for(ll i = 0; i <= m; i++) {
					if(dp[n][i] >= ans)
						ans = dp[n][i];
				}
				printf("%lld\n", ans);
			}
			else {
				vii b;
				for(ll i = 0; i <= m; i++) {
					if(dp[n][i] != -1)
						b.pb(mp(dp[n][i], m-i));
				}
				sort(b.begin(), b.end(), greater< pair<ll, ll> >());
				bool flag = true;
				for(ll i = 0; i < (ll)b.size(); i++) {
					if(b[i].second > 2000) {
						flag = false;
						printf("%lld\n", b[i].first);
						break;
					}
					else {
						if(b[i].second <= M) {
							flag = false;
							printf("%lld\n", b[i].first);
							break;
						}
					}
				}
				if(flag)
					printf("0\n");	
			}
		}
		a.clear();
	}
	return 0;
}