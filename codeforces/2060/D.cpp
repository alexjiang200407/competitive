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
#define clr(arr) memset(arr,0,sizeof(arr))
#define pb push_back

const ll MOD=1e9+7;
ll madd(ll a, ll b) { return (a + b) % MOD; }

const int directions[4][2]={-1,0,0,-1,0,1,1,0};

const int N=2e5+5;
int n,t,a[N];

/**
 * SOLUTION:
 * We proceed greedily. Since we want the items on the left to be smaller
 * we always try to subtract the following value if it is greater than the current
 * item.
 */
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        
        for_n(0,n,i)
        {
            cin>>a[i];
        }

        for_n(0,n,i)
        {
            if(a[i]<=a[i+1])
            {
                a[i+1]-=a[i];
                a[i]=0;
            }
        }
        cout<<(is_sorted(a,a+n)?"YES":"NO")<<'\n';
    }
    return 0;
}
