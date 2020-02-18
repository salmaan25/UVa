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
int set(int b, int i) {return b|(1<<i);} //set ith bit
int unset(int b, int i) {return b&!(1<<i);}
int check(int b, int i) {return b&(1<<i);} //returns 0 if ith bit is 0
const ll inf = 0xFFFFFFFFFFFFFFFL; //very large number
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
// int n=-1, m=-1, s=-1;

ii rot_right(ii pos) {
	swap(pos.ff, pos.ss);
	pos.ss *= -1;
	return pos;
}
ii rot_left(ii pos) {
	swap(pos.ff, pos.ss);
	pos.ff *= -1;
	return pos;
}
ii move(ii pos, ii ori) {
	if(ori.ff!=0)
		return {pos.ff, pos.ss+ori.ff};
	else
		return {pos.ff-ori.ss, pos.ss};
}
int32_t main(void)
{
	IOS;
	int n, m, s;
	while(1) {
		cin>>n>>m>>s;
		// cout<<n<<" "<<m<<" "<<s<<endl;
		if((n==0 && m==0 && s==0))
			break;
		vector<string> mat(n);
		ii pos; ii ori;
		for(int i = 0; i < n; i++) {
			cin>>mat[i];
			for(int j = 0; j < m; j++) {
				if(mat[i][j]!='*'&&mat[i][j]!='.'&&mat[i][j]!='#') {
					pos={i, j};
					if(mat[i][j]=='N') ori={0,1};
					else if(mat[i][j]=='S') ori={0,-1};
					else if(mat[i][j]=='L') ori={1,0}; 
					else ori={-1,0};
				}
			}
		}
		string in;
		cin>>in; int ans=0;
		int taken[n][m]= {};
		for(int i = 0; i < s; i++) {
			// cout<<"("<<pos.ff<<" "<<pos.ss<<")"<<" ("<<ori.ff<<" "<<ori.ss<<")"<<endl;
			ii cur_pos=pos;
			if(in[i]=='D')
				ori=rot_right(ori);
			else if(in[i]=='E')
				ori=rot_left(ori);
			else {
				// cout<<"in"<<i<<"("<<pos.ff<<" "<<pos.ss<<")"<<" ("<<ori.ff<<" "<<ori.ss<<")"<<endl;
				cur_pos=move(pos, ori);
				// cout<<"indded "<<cur_pos.ff<<" "<<cur_pos.ss<<endl;
				if(cur_pos.ff<0 || cur_pos.ff>n-1 || cur_pos.ss<0 || cur_pos.ss>m-1 || mat[cur_pos.ff][cur_pos.ss]=='#') {
					cur_pos=pos;
				}
				else {
					// cout<<"in"<<endl;
					pos=cur_pos;
					if(mat[pos.ff][pos.ss]=='*' && !taken[pos.ff][pos.ss]) {
						ans++;
						taken[pos.ff][pos.ss]=1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}