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

const int N = 2010;
int cache[N][N][53];

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int solve(vector<int>& a,vector<int>& b,int n,int m,int k)
{
  if(k < 0)
  {
    return INT_MIN;
  }
  if(n <= 0 || m <= 0)
  {
    return 0;
  }
  if(cache[n][m][k] != -1)
  {
    return cache[n][m][k];
  }
  // No changes made
  if(a[n-1] == b[m-1])
  {
    return cache[n][m][k] = solve(a,b,n-1,m-1,k) + 1;
  }
  else
  {
    return cache[n][m][k] = max(solve(a,b,n-1,m,k),max(solve(a,b,n,m-1,k),solve(a,b,n-1,m-1,k-1) + 1));
  }
}

int32_t main()
{
 c_p_c();
 memset(cache,-1,sizeof(cache));
 int n,m,k;
 cin >> n >> m >> k;
 vector <int> a(n),b(m);
 for (int i = 0; i < n; ++i)
 {
  cin >> a[i];
 }
 for (int i = 0; i < m; ++i)
 {
  cin >> b[i];
 }
 cout<<solve(a,b,n,m,k)<<endl;
 return 0;  
}
