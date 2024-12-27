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

const int N=105;
int n,a[N],b[N],t,diff[N];

/**
 * SOLUTION:
 * We proceed using greedy.
 * Since we can choose any training day for Monocarp we want to choose all days that result in a
 * positive difference.
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
        for_n(0,n,i) cin>>b[i];

        for_n(0,n-1,i) diff[i]=a[i]-b[i+1];
        diff[n-1]=a[n-1];

        int sum=0;
        for_n(0,n,i)
        {
            if(diff[i]>0) sum+=diff[i];
        }
        cout<<sum<<'\n';
    }
    return 0;
}
