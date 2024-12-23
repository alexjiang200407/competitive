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

const int N=505;
int n,t;
char s[N];

/**
 * SOLUTION:
 * There are only 4 possible variations if . is not allowed:
 * 
 * Here are the matchings in regex format:
 * 
 * 1. [s]+p: any number of s followed by a single p
 * 2. s[p]+: any number of p preceded by a single s
 * 3. [p]+: all p
 * 4. [s]+: all s
 * 
 * 3 and 4 are obvious, they can be achieved by a sort and reversed sort of numbers
 * 1 to n respectively. 1 and 2 are basically 3 and 4 because when s is the first
 * character it must equal to 1 due to the given rules. Likewise when p is the last
 * character, it must be 1. 
 */


bool match(char ch, int start=0, int end=n)
{
    for_n(start,end,i)
    {
        if(s[i]!=ch&&s[i]!='.')
        {
            return false;
        }
    }
    return true;
}

signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        if(match('p',1,n)||match('s',0,n-1)) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}
