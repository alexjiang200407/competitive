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

const int N=205;
int n,t,a[N];
ull dp[N];

/**
 * SOLUTION:
 * We solve this problem using DP which holds the current amount of solutions at each index.
 * For each index we calculate the amount of solutions by going back and seeing which groups can
 * be formed. A group can be formed if side A*2>B and B*2>A. If this state is greater than 2 at any point
 * we return.
 */
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        cin>>n;
        for_n(0,n,i) cin>>a[i];

        bool exit=false;
        for_n(0,n,i)
        {
            if(i==0) dp[i]=1;
            else dp[i]=dp[i-1];

            if(dp[i]>=2)
            {
                cout<<"YES"<<'\n';
                exit=true;
                break;
            }

            int j=i-1;
            while(j>=0&&a[j]*2>a[i]&&a[j]<a[i]*2)
            {
                dp[i]+=dp[j];
                j--;
            }
        }
        if(exit) continue;
        cout<<(dp[n-1] < 2 ? "NO" : "YES")<<'\n';
    }
    
    return 0;
}
