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
priority_queue<int, vector<int>, greater<int> > pq; //for min priority_queue
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
clock_t time_p=clock();
void time()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

int32_t main(void)
{
	IOS;
	int p1, p2; cin>>p1;
	int tc=1;
	while(p1) {
		ii per1[p1];
		for(int i = 0; i < p1; i++)
			cin>>per1[i].ff>>per1[i].ss;
		cin>>p2; ii per2[p2];
		for(int i = 0; i < p2; i++)
			cin>>per2[i].ff>>per2[i].ss;
		int mn=inf;
		// cout<<"GOOD"<<endl;
		for(int i = 0; i < p1; i++) {
			for(int j = 0; j < p2; j++) {
				if(tc==1 && abs(per1[i].ff-per2[j].ff)+abs(per1[i].ss-per2[j].ss)==0)
					cout<<i<<" "<<j<<endl;
				mn=min(mn, abs(per1[i].ff-per2[j].ff)+abs(per1[i].ss-per2[j].ss));
			}
		}
		cout<<mn<<endl;
		cin>>p1;
		tc++;
	}
	time();	
	return 0;
}