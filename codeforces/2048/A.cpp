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
#include <string>

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
 * 
 * Removing a consecutive 33 can be mathematically represented as:
 * x*10^(p+2)+33*10^p+y-(33*10^p+99*10^p)
 * 
 * Since 33*10^p+99*10^p is divisble by 33 this means that removing consecutive 33s is essentially
 * just subtracting 33 a number of times. Therefore if the original number is not divisible by 33
 * in the first place it will never be able to reach 0.
 * 
 */

signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%33==0) cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
    }
    return 0;
}
