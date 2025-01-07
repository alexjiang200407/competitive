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

const ll MOD=1e9+7;
ll madd(ll a, ll b) { return (a + b) % MOD; }

const int directions[4][2]={-1,0,0,-1,0,1,1,0};

int n,abc[3];
const int N=4005;
int dp[N];
bool used[N];

/**
 * SOLUTION:
 * 
 */
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>abc[0]>>abc[1]>>abc[2];
    used[n]=true;

    for(int i=n; i>=0; i--)
    {
        if(!used[i]) continue;
        for_n(0,3,j)
        {
            if(i-abc[j]<0) continue;
            dp[i-abc[j]]=max(dp[i-abc[j]],dp[i]+1);
            used[i-abc[j]]=true;
        }
    }
    cout<<dp[0]<<'\n';
    return 0;
}
