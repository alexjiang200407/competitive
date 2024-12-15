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
 
const int N=1005;
int n,c[N],f[N];
vector<pii> ans;
set<int> nums;

/**
 * Solution:
 * 
 * We process the numbers in the order of the final. So if the final arrangement is 2 1 3
 * we first consider 2 and then 1 and then 3. Each number will be overtaken by all remaining
 * numbers smaller than it and then will overtake the all remaining numbers to retain its position.
 * 
 * So for the numbers 2 1 3 we first consider 2.
 * Then we push to the answer, 3 2.
 * 
 * Now that all numbers lesser than 2 are processed we 'go back' and put 2 into the first position
 * We push 2 3 and then 2 1. 2 is now finished
 * 
 * The arrangement is now 2 1 3
 * 
 * Now we consider the 1 3 part.
 * 
 * 3 is smaller than 1 so 3 can overtake 1.
 * Then we go back again and 1 overtakes 3 to retain 2nd position.
 * 
 */
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n;
    for_n(1,n+1,i)
    {
        int v; cin>>v;
        c[v]=i;
        f[i]=v;
        nums.insert(i);
    }

    for(int i=1;i<=n;i++)
    {
        auto it=nums.upper_bound(f[i]);
        while(it!=nums.end())
        {
            // if(c[f[i]]>c[*it]) break;
            ans.pb({*it,f[i]});
            it++;
        }
        nums.erase(f[i]);
        auto rit=nums.rbegin();
        while(rit!=nums.rend())
        {
            ans.pb({f[i],*rit});
            rit++;
        }
    }

    cout<<ans.size()<<'\n';
    for_e(a,ans) cout<<a.first<<' '<<a.second<<'\n';
 
    return 0;
}