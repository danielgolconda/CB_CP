#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
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

unordered_map <int,char> mp;
void c_p_c()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
vector<string> ans;
void solve(string curr,string s,int idx,int n)
{
	if(idx == n)
	{
		ans.push_back(curr);
		return ;
	}
	else
	{
		if(idx < n-1)
		{
			string p = "";
			p+=s[idx];	
			int on = stoi(p);
			p+=s[idx+1];
			int tw = stoi(p);
			if(tw > 26)
			{
				solve(curr+mp[on],s,idx+1,n);
			}
			else
			{
				solve(curr+mp[on],s,idx+1,n);
				solve(curr+mp[tw],s,idx+2,n);
			}
		}
		else
		{
			string p = "";
			p+=s[idx];	
			int on = stoi(p);
			solve(curr+mp[on],s,idx+1,n);
		}

	}
	return ;
}
int32_t main()
{
  c_p_c();
  string s;
  cin >> s;
 char x = 'a';
 for(int i=1;i<=26&&x<='z';i++,x++)
 {
 	mp[i] = x;
 }
 
 solve("",s,0,s.size());
 cout<<"[";
 for(int i=0;i<ans.size();i++)
 {
 	if(i == ans.size()-1)
 	{
 		cout<<ans[i];	
 	}
 	else
 	{
 		cout<<ans[i]<<", ";	
 	}
 }
 cout<<"]";
 cout<<endl;
  return 0;
}

