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

/**
 * SOLUTION:
 * 
 * We must recognise there are 3 possible states for each column
 * 1. We chose the top row 
 * 2. We chose the bottom row
 * 3. We chose both rows
 * 
 * The first state occurs when the top row is larger as we want to maximise the sum.
 * The second state occurs when the bottom row is larger
 * The third state can only occur once
 * 
 * Since the third state can occur once, we loop through each column and consider if it is
 * the 'both' column. We calculate the sum if it is the both column which is given by the
 * max sum if we only chose a single row per column plus the min row for the 'both' column.
 * We then maximise the sum across all columns considered.
 * 
 */


const int N=5005;
int n,t;

int a[N][2];
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        cin>>n;
        for_n(0,n,i)
        {
            cin>>a[i][0];
        }
        for_n(0,n,i)
        {
            cin>>a[i][1];
        }

        int total=0;
        for_n(0,n,i)
        {
            total+=max(a[i][0],a[i][1]);
        }

        int ans=-1e11;
        for_n(0,n,i)
        {
            int sum=min(a[i][0],a[i][1])+total;
            ans=max(ans,sum);
        }
        cout<<ans<<'\n';
    }
    return 0;
}


/**
 * 1 2  0 1 -1 -4
 * 1 2 -1 4  2 -3
 */

/**
 *  0 1 2 1 -1 -4
 * -1 1 2 4  2 -3
 */