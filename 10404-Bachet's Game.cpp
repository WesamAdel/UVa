#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef pair<int,int>       ii;
typedef pair<ll,ll>         pll;
typedef pair<double,double> dd;

typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<ii>          vii;
typedef vector<pll>         vpll;
typedef vector<string>      vs;

#define umap            unordered_map
#define uset            unordered_set

#define OO              1e18
#define oo              1e9
#define EPS             1e-9

#define Read            freopen("in.txt", "r", stdin)
#define Write           freopen("out.txt", "w", stdout)

#define clr(a)          memset(a,0,sizeof a)
#define clr_dp(a)       memset(a,-1,sizeof a)
#define all(v)          v.begin(),v.end()
#define sz(v)           (int) v.size()
#define lop(i,n)        for(int i=0;i<n;++i)
#define lop1(i,n)       for(int i=1;i<n;++i)
#define loop(i,l,r)     for(int i=l;i<=r;++i)
#define pb              push_back
#define f               first
#define s               second 
#define mp              make_pair

#define sc(x)           scanf("%d",&x)
#define sc2(x,y)        scanf("%d %d",&x,&y)
#define sc3(x,y,z)      scanf("%d %d %d",&x,&y,&z)
#define sc_ll(x)        scanf("%I64d",&x)
#define sc2_ll(x,y)     scanf("%I64d %I64d",&x,&y)
#define sc3_ll(x,y,z)   scanf("%I64d %I64d %I64d",&x,&y,&z)
#define pf1(x)          printf("%d\n",x)

#define r_arr(a,n)		lop(i,n) cin>>a[i]
#define r_grid(a,n,m)	lop(i,n) lop(j,m) cin>>a[i][j]

#define TEST			cout<<"HERE\n"
#define cnt_ones(x) 	__builtin_popcount(x)

int n,m,moves[12];
bool state[1000005];

int main (){
#ifndef ONLINE_JUDGE
   Read;
#endif
	
	while(cin>>n>>m){
		r_arr(moves,m);
		clr(state);
		
		state[0] = 0;
		loop(i,1,n){ 
			lop(j,m){
				int last = i-moves[j];
				state[i] |= ( (last>=0) && !state[last] )? 1 : 0;
			}
		}
		
		printf("%s wins\n", (state[n])?"Stan":"Ollie");
	}
	
    return 0;
}




















