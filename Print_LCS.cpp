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
#define int             long long
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
//#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

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
 
 string a,b;
    cin >> a;
    cin >> b;
    int n=a.size(),m=b.size();
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++)
    {
      for(int j=0;j<m+1;j++)
      {
        if(i == 0 || j == 0)
        {
          dp[i][j] = 0;
        }
      }
    }
    for(int i=1;i<n+1;i++)
    {
      for(int j=1;j<m+1;j++)
      {
        if(a[i-1] == b[j-1])
        {
          dp[i][j] = 1 + dp[i-1][j-1];
        }
        else
        {
          dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
      }
    }
    string res="";
    int i = n,j=m;
    while(i > 0 && j > 0)
    {
      if(a[i-1] == b[j-1])
      {
        res+=a[i-1];
        i--;
        j--;
      }
      else
      {
        if(dp[i-1][j] > dp[i][j-1])
        {
          i--;
        }
        else
        {
          j--;
        }
      }
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
 return 0;  
}
