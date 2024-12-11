#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
#include <tuple>
#include <map>

using namespace std;

typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long> vl;
typedef string str;
typedef pair<int, int> pii;
typedef pair<long, long> pllll;

#define all(a) a.begin(), a.end()
#define Debug(x) cout << #x " = " << (x) << '\n'
#define for_n(s, e, i) for (ll i = s; i < e; i++)
#define for_e(e,of) for (auto& e : of)
#define pb push_back
#define SZ(_n) (ll)_n.size()

const ll MOD=1e9+7;
ll madd(ll a, ll b) { return (a + b) % MOD; }

const int directions[4][2]={-1,0,0,-1,0,1,1,0};
const int N=4e3+5;
int n,t;
str s1,s2,s3;

int dp[N][N];

int solve(int i, int j)
{
    if(i+j>=SZ(s3))
        return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    if(i>=SZ(s1))
    {
        return dp[i][j]=solve(i,j+1)+(s2[j]!=s3[i+j]);
    }
    if(j>=SZ(s2))
    {
        return dp[i][j]=solve(i+1,j)+(s1[i]!=s3[i+j]);
    }
    int l=solve(i+1,j)+(s1[i]!=s3[i+j]);
    int r=solve(i,j+1)+(s2[j]!=s3[i+j]);
    return dp[i][j]=min(l,r);
}

signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2>>s3;
        n=s3.size();
        for_n(0,n,i) for_n(0,n,j) dp[i][j]=-1;
        cout<<solve(0,0)<<'\n';
    }
    
    return 0;
}
