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
const int MAXN = 1e3+1;
int a[MAXN][MAXN];
int vis[MAXN][MAXN];
int conn[MAXN][MAXN];
int sz[MAXN][MAXN];
const int dx[4] = {0, 0, -1, +1};
const int dy[4] = {-1, +1, 0, 0};
void c_p_c()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
  c_p_c();
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		a[i][j] = 0;
  		vis[i][j] = 0;
  		conn[i][j] = 0;
  		sz[i][j] = 0;
  	}
  }
  queue <pair<int,int>> q;
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		int x;
  		cin >> x;
  		a[i][j] = x;
  	}
  }
  int cc=0;
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		if(!vis[i][j] && a[i][j] == 1)
  		{
  			cc++;
  			q.push({i,j});
  			while(!q.empty())
  			{
  				pair<int,int> p = q.front();
  				q.pop();
  				int f = p.first;
  				int s = p.second;
  				conn[f][s] = cc;
  				vis[f][s] = 1;
  				if(f-1 >= 0 && a[f-1][s] == 1 && vis[f-1][s] == 0)
  				{
  					q.push({f-1,s});
  				}
  				if(f+1 < n && a[f+1][s] == 1 && vis[f+1][s] == 0)
  				{
  					q.push({f+1,s});
  				}
  				if(s-1 >= 0 && a[f][s-1] == 1 && vis[f][s-1] == 0)
  				{
  					q.push({f,s-1});
  				}
  				if(s+1 < m && a[f][s+1] == 1 && vis[f][s+1] == 0)
  				{
  					q.push({f,s+1});
  				}
  			}
  		}
  	}
  }
  int N = 1e5+1;
  vector <int> mp(N,0);
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		if(conn[i][j] > 0)
  		{
  			mp[conn[i][j]]++;
  		}
  		
  	}
  }
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		if(conn[i][j] > 0)
  		{
  			sz[i][j] = mp[conn[i][j]];
  		}
  	}
  }
  int ans = INT_MIN;
  for(int i=1;i<n;i++)
  {
  	for(int j=1;j<m;j++)
  	{
  		if(sz[i][j] == 0)
  		{
  			int tans=1;
  			vector<int> groups ;
            for (int d = 0; d < 4; d += 1) {
                groups.push_back(conn[i + dx[d]][j + dy[d]]);
            }
            sort(groups.begin(), groups.end());
            groups.resize(unique(groups.begin(), groups.end()) - groups.begin());
            for (auto itr : groups) {
                tans += mp[itr];
            }
  			ans = max(ans,tans);
  		}
  	}
  }
  cout<<ans<<endl;
  return 0;
}
