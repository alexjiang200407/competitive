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
int n,t,a[N];


/**
 * Solution:
 * Basically we need to keep moving a number to the back until the number is the smallest available number
 * 
 * For example 100 200 3 1 200 300
 * We would first push back 100, 200 and 3 and when we reach 1, we stop
 * and start choosing again with the elements to its right
 * 
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
        vector<int> ans;
        multiset<int> s;
        cin>>n;
        for_n(0,n,i) 
        {
            cin>>a[i];
            s.insert(a[i]);
        }
        for_n(0,n,i)
        {
            int mn=*s.begin();
            
            if(a[i]==mn)
            {
                ans.pb(mn);
            }
            else
            {
                ans.pb(a[i]+1);
                s.insert(a[i]+1);
            }
            s.extract(a[i]);
        }
        sort(all(ans));
        for_e(num,ans) cout<<num<<' ';
        cout<<'\n';
    }
    return 0;
}
