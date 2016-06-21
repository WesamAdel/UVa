#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int>   ii;
typedef long long       ll;
typedef vector<int>     vi;
typedef vector<ii> 	    vii;

#define Read            freopen("in.txt", "r", stdin)
#define Write           freopen("out.txt", "w", stdout)

#define oo              1e9
#define OO              1e18

#define clr(a)          memset(a,0,sizeof a)
#define all(v)          v.begin(),v.end()
#define sz(v)           (int) v.size()
#define rev(v)          reverse(all(v))

#define pb              push_back
#define fi              first
#define se              second
#define mp              make_pair
#define mt              make_tuple

#define lop(i,a,n)      for(int i=a;i<n;++i)
#define pol(i,a,n)      for(int i=n-1;i>=a;--i)

#define sc              scanf
#define pf              printf
#define pfn             printf("\n")

#define debug(args...)  {dbg,args; cerr << endl;}
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
} dbg;


ll gcd(ll a, ll b){return((b == 0)?a:gcd(b,a%b));}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}

int dp [2015][2015];
char ans [2015][2015];
string ans_val [2015][2015];
char c[2015][2015];

string trace(string s){
    int i = 0, j = sz(s) -1;
    bool odd = 0;
    string ret = "";
    while(i<=j){
        if(ans[i][j] == 0 || i==j){
            ret += c[i][j];
            if(i == j) odd = 1;
            ++i; --j;
        }else if(ans[i][j] == 1)
            ++i;
        else if(ans[i][j] == 2)
            --j;
    }
    int n = sz(ret);
    string sub_ret = ret.substr(0,odd?n-1:n);
    rev(sub_ret);
    return ret+sub_ret;
}

string solve(string s){
    clr(ans);
    memset(dp, -1, sizeof dp);
    int n = sz(s);
    lop(i,0,n)
        lop(j,0,n){
            if(i == j) dp[i][j] = 1, ans_val[i][j] = c[i][j] = s[i];
            else if(i > j) dp[i][j] = 0, ans_val[i][j] = "";
            else ans_val[i][j] = "";
        }

    pol(i,0,n)
        lop(j,i+1,n){
            if(s[i] == s[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
                ans[i][j] = 0;
                ans_val[i][j] = s[i] + ans_val[i+1][j-1];
                c[i][j] = s[i];
            }
            if(dp[i+1][j] > dp[i][j] || (dp[i+1][j] == dp[i][j] && ans_val[i+1][j] < ans_val[i][j]) ){
                dp[i][j] = dp[i+1][j];
                ans[i][j] = 1;
                ans_val[i][j] = ans_val[i+1][j];
                c[i][j] = c[i+1][j];
            }
            if(dp[i][j-1] > dp[i][j] || (dp[i][j-1] == dp[i][j] && ans_val[i][j-1] < ans_val[i][j]) ){
                dp[i][j] = dp[i][j-1];
                ans[i][j] = 2;
                ans_val[i][j] = ans_val[i][j-1];
                c[i][j] = c[i][j-1];
            }

        }
        return trace(s);
}

int main(){
#ifndef ONLINE_JUDGE
	Read;
    //Write;
#endif
    string s;
    while(cin>>s)
        cout << solve(s) << endl;
    return 0;
}
















