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

const int MAXN = 1e6+1;
vector<int> adj[MAXN];
int vis[MAXN];
int col[MAXN];
unordered_map <int,int> cmp;
int cc;
void c_p_c()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

void dfs(int s)
{
	cmp[s] = cc;
	col[cc]++;
	vis[s] = 1;
	for(int u:adj[s])
	{
		if(vis[u] == 0)
		{
			dfs(u);
		}
	}
}
int32_t main()
{
  c_p_c();
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++)
  {
  	int x,y;
  	cin >> x >> y;
  	x++; y++;
  	adj[x].push_back(y); adj[y].push_back(x);
  }
  for(int i=1;i<=n;i++)
  {
  	if(vis[i] == 0)
  	{
  		cc++;
  		dfs(i);
  	}
  }
  int ans = 0;
  for(int i=1;i<=n;i++)
  {
  	ans+=(n - col[cmp[i]]);
  }
  cout<<(ans>>1)<<endl;
  return 0;
}

