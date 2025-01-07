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
// #define int ll
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

int l,r,t;
/**
 * SOLUTION:
 * https://codeforces.com/blog/entry/138119
 */
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        int k=31-__builtin_clz(l ^ r);
        int a=l|((1<<k)-1),b=a+1,c=(a==l?r:l);
        cout<<a<<" "<<b<<" "<<c<<"\n";
    }

    return 0;
}
