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

const int N=1e5+5;
int n,t,k,ans[N];


/**
 * SOLUTION:
 * 
 * We simply distribute the smallest numbers every k elements so that the smallest
 * possible elements are always chosen.
 * 
 * 
 */
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int j=1;
        for(int i=k;i<=n;i+=k)
        {
            ans[i]=j++;
        }
        for(int i=1;i<=n;i++)
        {
            if(i%k!=0) ans[i]=j++;
        }

        for_n(1,n+1,i) cout<<ans[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
