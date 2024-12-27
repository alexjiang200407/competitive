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

int n,t;

/**
 * SOLUTION:
 * For each integer we count the possible integer pairs. To do this in O(n log(n)) time
 * we use a sorted vector to query the possible integers for each other integer. An interesting
 * pair exists with the current integer if it is between total-y-current_integer and total-x-current_integer.
 * We make sure to pop the back of the vector each iteration since we don't want to double count. We terminate
 * when there is only one integer left in the vector.
 */
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        vector<int> s;
        int x,y;
        cin>>n>>x>>y;
        s.reserve(n);
        int total=0;
        for_n(0,n,i)
        {
            int a; cin>>a;
            s.push_back(a);
            total+=a;
        }
        sort(all(s));
        int sum=0;
        while(s.size()>1)
        {
            int end=*s.rbegin();
            s.pop_back();
            sum+=distance(lower_bound(all(s),total-y-end),upper_bound(all(s),total-x-end));
        }
        cout<<sum<<'\n';
    }
    return 0;
}
