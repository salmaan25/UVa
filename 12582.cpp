#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define PI 3.1415926535897932384626433832795
int powmod(int a,int b,int mod) {int res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
typedef long long ll; typedef vector<ll> vi; typedef pair<ll, ll> ii; typedef vector<ii> vii;
#define pb push_back
int __set(int b, int i) {return b|(1<<i);} //set ith bit
int __unset(int b, int i) {return b&!(1<<i);}
int __check(int b, int i) {return b&(1<<i);} //returns 0 if ith bit is 0
const ll inf = 0xFFFFFFFFFFFFFFFL; //very large number
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int32_t main(void)
{
	// IOS;
	int t, tc=0; cin>>t;
	while(++tc<=t) {
		string s;
		cin>>s; int n = s.length();
		// int ch[26]={}, ct=0;
		// for(int i = 0; i < n; i++) {
		// 	if(!ch[s[i]-'A']) {
		// 		ct++;
		// 		ch[s[i]-'A']=1;
		// 	}
		// }
		// cout<<ct<<endl;
		vector<vi> adjlist(26); int vis[26]={};
		vis[s[0]-'A']=1; stack<int> st; st.push(s[0]-'A');
		int node=s[0]-'A';
		for(int i = 1; i < n; i++) {
			// cout<<node<<" "<<i<<" "<<st.size()<<endl;
			if(vis[s[i]-'A']) {
				// cout<<"in"<<endl;
				st.pop();
				if(!st.empty())
					node=st.top();
			} else {
				adjlist[node].pb(s[i]-'A');
				adjlist[s[i]-'A'].pb(node);
				vis[s[i]-'A']=1;
				st.push(s[i]-'A');
				node=s[i]-'A';
			}
		}
		cout<<"Case "<<tc<<endl;
		for(int i = 0; i < 26; i++) {
			if(adjlist[i].size())
				cout<<(char)(i+'A')<<" = "<<adjlist[i].size()<<endl;
		}
	} 	
	return 0;
}