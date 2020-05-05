#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long int 
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int cache[100005];
void c_p_c()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
int solve(int n,int m)
{
	if(n < m)
	{
		return 1;
	}
	if(cache[n] != -1)
	{
		return cache[n];
	}
	return cache[n]= (((solve(n-1,m)%mod)+(solve(n-m,m)%mod))%mod);	
}
int32_t main()
{
  c_p_c();
  int tc;
  cin >> tc;
  while(tc--)
  {
  	int n,m;
  	cin >> n >> m;
  	memset(cache,-1,sizeof(cache));
  	cout<<solve(n,m)<<endl;
  }
  return 0;
}

