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
str s;

/**
 * SOLUTION:
 * We proceed using greedy. We select the longest possible sequence starting with
 * 1 and ending with 1 and then swap the digits. Then we loop again until the array is
 * all 0s.
 */
signed main(void)
{
    // ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>s;

        int c=0;
        while(true)
        {
            int i=0;
            while(i<(ll)s.size()&&s[i]!='1') i++;

            if(i==(ll)s.size())
            {
                cout<<c<<'\n';
                break;
            }

            vi to_swap = {i++};
            int current=0;
            for(;i<(ll)s.size();i++)
            {
                if(s[i]==current+'0')
                {
                    current=!current;
                    to_swap.push_back(i);
                }
            }
            // Debug(*to_swap.rbegin());
            if(s[*to_swap.rbegin()]=='0')
            {
                to_swap.pop_back();
            }

            for_e(idx,to_swap)
            {
                s[idx]=!(s[idx]-'0')+'0';
            }
            // Debug(s);
            c++;
        }
    }


    return 0;
}
