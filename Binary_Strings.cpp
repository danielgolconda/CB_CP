#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
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


void c_p_c()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
int cache[150][2];
int solve(string curr,int n,int idx)
{
	if(curr.size() == n)
	{
		return 1;
	}
	if(cache[idx][curr[idx]-'0'] != -1)
	{
		return cache[idx][curr[idx]-'0']; 
	}
	if(curr[idx] == '0')
	{
		return cache[idx][curr[idx]-'0'] = solve(curr+'0',n,idx+1)+solve(curr+'1',n,idx+1);
	}
	if(curr[idx] == '1')
	{
		return cache[idx][curr[idx]-'0'] = solve(curr+'0',n,idx+1);
	}
}
int32_t main()
{
  c_p_c();
  int tc;
  cin >> tc;
  while(tc--)
  {
  	int n;
  	cin >> n;
  	memset(cache,-1,sizeof(cache));
  	int o = solve("1",n,0);
  	int z = solve("0",n,0);
  	cout<<(o+z)<<endl;
  }
  return 0;
}

