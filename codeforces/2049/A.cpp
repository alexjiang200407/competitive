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

const int N=55;
int n,a[N],t;


/**
 * SOLUTION:
 * 1. The amount of operations will always be less than 2 because we 
 *    can always replace the entire array with the minimum excluded number and then
 *    replace the minimum excluded number with 0.
 * 2. However, there are cases where the minimum operations are lesser. These include
 *    the case where there is only 1 group in total (consecutive non-zero numbers), or when
 *    the entire array is already 0s. We simply check for these cases as well.
 */
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for_n(0,n,i) cin>>a[i];

        int groups=0;
        for(int i=0;i<n;)
        {
            for(;i<n&&a[i]==0;i++);
            if(i<n) groups++;
            for(;i<n&&a[i]!=0;i++);
        }
        cout<<min(groups,2ll)<<'\n';
    }


    return 0;
}
