#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
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
#define int  long int
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = 1e5+1;
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
  int tc;
  cin >> tc;
  while(tc--)
  {
    vector<vector<int>> adj(101,vector<int>());
    int n,m;
    cin >> n;
    vector<int> jump(101,0);
    for(int i=0;i<n;i++)
    {
      int a,b;
      cin >> a >> b;
      jump[a] = (b-a);
    }
    cin >> m;
    for(int i=0;i<m;i++)
    {
      int a,b;
      cin >> a >> b;
      jump[a] = (b-a);
    }
    for(int i=1;i<101;i++)
    {
      for(int dice = 1;dice <= 6;dice++)
      {
        int j = i+dice;
        j += jump[j];
        if(j <= 100)
        {
          adj[i].push_back(j);
        }
      }
    }
    adj[100].push_back(100);
    /*for(int i=1;i<101;i++)
    {
      cout<<i<<"->";
      for(int j=0;j<adj[i].size();j++)
      {
        cout<<adj[i][j]<<" ";
      }
      cout<<endl;
    }*/
    vector<int> vis(101,0);// keeping track of visited or not
    vector<int> th(101,0); // throws nunber
    
    // BFS for Single Source Shortest Path(SSSP)
    queue <int> q;
    q.push(1);
    while(!q.empty())
    {
      int f=q.front();
      q.pop();
      vis[f] = 1;
      for(auto u:adj[f])
      {
        if(vis[u] == 0)
        {
          q.push(u);
          th[u] = th[f] + 1;
          vis[u] = 1; 
        }
      }
    }
    if(th[100] > 0)
    {
      cout<<th[100]<<endl;
    }
    else // If we cannot reach 100 i.e all snakes are present 
    {
      cout<<-1<<endl;
    }
  }
  return 0; 
}
