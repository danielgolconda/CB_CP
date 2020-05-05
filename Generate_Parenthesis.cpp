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
void solve(string curr,int idx,int n,int oc,int cc)
{
	if(curr.size() == 2*n)
	{
		cout<<curr<<endl;
		return ;
	}
	if(cc < oc && cc < n)
	{
		solve(curr+')',idx+1,n,oc,cc+1);
	}
	if(oc < n)
	{
		solve(curr+'(',idx+1,n,oc+1,cc);
	}
	return ;
}
int32_t main()
{
  c_p_c();
  int n;
  cin >> n;
  solve("",0,n,0,0);
  return 0;
}

