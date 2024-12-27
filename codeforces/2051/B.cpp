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
 * We just calculate the days required until the last round using division.
 * Then we calculate the leftover and check if a, b and c are required.
 */
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        int abc[3];
        cin>>n>>abc[0]>>abc[1]>>abc[2];
        int mod=abc[0]+abc[1]+abc[2];
        int days=n/mod*3;
        int leftover=n%mod;
        int i=0;
        while(leftover>0)
        {
            leftover-=abc[i++];
        }
        days+=i;
        cout<<days<<'\n';
    }
    return 0;
}
