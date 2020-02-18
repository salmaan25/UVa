#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define PI 3.1415926535897932384626433832795
int MOD=1e9+7;
int powmod(int a,int l, int md){int res=1;while(l){if(l&1)res=res*a%md;l/=2;a=a*a%md;}return res;}
typedef long long ll; typedef vector<ll> vi; typedef pair<ll, ll> ii; typedef vector<ii> vii;
#define pb push_back
int __set(int b, int i) {return b|(1<<i);} //set ith bit
int __unset(int b, int i) {return b&!(1<<i);}
int __check(int b, int i) {return b&(1<<i);} //returns 0 if ith bit is 0
int mul(int a, int b) {return ((a%MOD)*(b%MOD))%MOD;}
int add(int a, int b) {return (a+b)%MOD;}
int sub(int a, int b) {return (((a-b)%MOD)+MOD)%MOD;}
int __div(int a, int b) {return mul(a, powmod(b, MOD-2, MOD));} //if MOD is prime;
const ll inf = 0xFFFFFFFFFFFFFFFL; //very large number
priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>> > pq; //for min priority_queue
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
clock_t time_p=clock();
void time()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
int dx[] = {0, 0, 1, -1}, dy[]={1, -1, 0, 0};
int32_t main(void)
{
	IOS;
	string s; cin>>s; int n = s.length();
	int dp[n][2];
	dp[0][0]=1; dp[0][1]=0;
	dp[1][0] = (s[0]==s[1]?0:2);
	dp[1][1] = 1;
	if(s[0]==s[1] || s[1]==s[2]) {
		dp[2][0]=2; dp[2][1]=2;
	}
	else {
		dp[2][0]=3; dp[2][1]=2;
	}
	for(int i = 3; i < n; i++) {
		if(s[i]==s[i-1])
			dp[i][0]=dp[i-1][1]+1;
		else
			dp[i][0]=max(dp[i-1][0]+1, dp[i-1][1]+1);
		if(s[i-3]==s[i-1] && s[i-2]==s[i])
			dp[i][1]=dp[i-2][0]+1;
		else
			dp[i][1]=max(dp[i-2][0], dp[i-2][1])+1;
	}
	cout<<max(dp[n-1][0], dp[n-1][1])<<endl;
	time();	
	return 0;
}