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
int n,t,k,a[N];

/**
 * SOLUTION:
 * This is a greedy algorithm. We simply just count all the number occurrences and choose the
 * least chosen numbers and shift them to the last group. We do so until there is only one group left
 * or we run out of shifts. Then we return the number of groups.
 */
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        map<int,int> counter;

        cin>>n>>k;
        for_n(0,n,i) 
        {
            cin>>a[i];
            counter[a[i]]++;
        }
        
        multiset<int> s;
        for_e(a,counter)
        {
            s.insert(a.second);
        }

        while(s.size()>1)
        {
            int i = *s.begin();
            if(k<i) break;
            k-=i;
            s.extract(s.begin());
        }

        cout<<s.size()<<'\n';
    }
    
    return 0;
}
