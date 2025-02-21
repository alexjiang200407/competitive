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
#define clr(arr) memset(arr,0,sizeof(arr))

const ll MOD=1e9+7;
ll madd(ll a, ll b) { return (a + b) % MOD; }

const int directions[4][2]={-1,0,0,-1,0,1,1,0};

const int N=105;
int n,t;

/**
 * SOLUTION:
 * Lets consider the case that causes an invalid sequence
 * 101: Which is invalid because the middle number must be equal to the number on the left (as it is set to 1) 
 * but also the number on the right as it is 1 as well.
 * 
 * So we just scan the string to find any instances of 101
 */
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        str s;
        cin>>n;

        for_n(0,n-2,i)
        {
            int a; cin>>a;
            s+=a+'0';
        }

        cout<<(s.find("101") == str::npos? "YES" : "NO")<<'\n';
    }

    return 0;
}
