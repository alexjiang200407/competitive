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
#include <numeric>
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
#define heap_array(t,sz) make_unique<t[]>(sz); 
#define heap_array_fill(a,sz,v) fill(a.get(),a.get()+sz,v); 

const ll MOD=1e9+7;
ll madd(ll a, ll b) { return (a + b) % MOD; }

const int directions[4][2]={-1,0,0,-1,0,1,1,0};

const int N=1e5+5;
int n,t,a[N],b[N],l,r;

/**
 * SOLUTION:
 * We just sort the array from the left and right side and then output the minimum
 */
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin>>t;
    while(t--)
    {
        cin>>n>>l>>r;
        for_n(0,n,i)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        
        sort(b+l-1,b+n);
        sort(a,a+r,greater<int>());

        cout<<min(accumulate(b+l-1,b+r,0ll),accumulate(a+l-1,a+r,0ll))<<'\n';
    }

    return 0;
}
