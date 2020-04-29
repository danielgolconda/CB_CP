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

int32_t main()
{
 c_p_c();

 int n,k;
 cin >> n >> k;
 vector<int> a(n);
 for(int i=0;i<n;i++)
 {
  cin >> a[i];
 }
 int start = 0,end = 0,c=0,si = -1,se = -1,ans = INT_MIN;
 while(end < n)
 {
  int win = (end-start);
  if(ans < win)
  {
    ans = win;
    si = start;
    se = end-1;
  }
  if(c < k)
  {
    if(a[end] == 1)
    {
      end++;
    }
    else if(a[end] == 0)
    {
      c++;
      end++;
    }
  }
  else
  {
    if(a[end] == 1)
    {
      end++;
    }
    else if(a[end] == 0)
    {
      if(a[start] == 0)
      {
        c--;
        start++;
      }
      else
      {
        start++;
      }
    }
  }
}
int win = (end-start);
  if(ans < win)
  {
    ans = win;
    si = start;
    se = end-1;
  }
  cout<<ans<<endl;
for(int i=0;i<n;i++)
{
  if(i >= si && i <= se)
  {
    cout<<1<<" ";
  }
  else
  {
    cout<<a[i]<<" ";
  }
}
 return 0;  
}
