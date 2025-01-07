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

int n;

const int N=1e6+5;
bool prime[N];
void sieve()
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.


    for (int p = 2; p * p <= N; p++) {
        // If prime[p] is not c
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
}

int a[(int)1e5+5];

signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    fill(prime,prime+N,true);
    prime[1]=false;
    sieve();
    cin>>n;
    for_n(0,n,i)
    {
        cin>>a[i];
    }
    for_n(0,n,i)
    {
        int sq=sqrt(a[i]);
        if(sq*sq==a[i])
        {
            if(prime[sq])
            {
                cout<<"YES"<<'\n';
                continue;
            }
        }
        cout<<"NO"<<'\n';
    }


    return 0;
}
