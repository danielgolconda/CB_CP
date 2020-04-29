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
#define int long int 
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
 int n;
 cin >> n;
 vector<int> a(n);
 for(int i=0;i<n;i++)
 {
  cin >> a[i];
 }

  vector<int> dp(n,1);

  for(int i=1;i<n;i++)
  {
    for(int j=0;j<i;j++)
    {
      if(a[i] > a[j])
      {
        if(dp[i] < dp[j]+1)
        {
          dp[i] = dp[j]+1;
        }
      }
    }
  }
  int ans = INT_MIN;
  for(int i=0;i<dp.size();i++)
  {
    ans = max(ans,dp[i]);
  }
  cout<<ans<<endl;
 return 0;  
}
