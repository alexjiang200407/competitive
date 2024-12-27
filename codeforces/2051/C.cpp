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

const int N=3e5+5;
int n,t,a[N],b[N];

/**
 * SOLUTION:
 * Cases to consider:
 * 1. if k<n-1 then at least 2 of the questions wont be answered so all question sets cannot be answered
 * 2. If k==n then all the questions can be answered so all the question sets can be answered
 * 3. If k==n-1 then all but one of the question sets can be answered 
 */
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        memset(b,0,sizeof(b));
        int m,k;
        cin>>n>>m>>k;
        for_n(0,m,i) cin>>a[i];
        for_n(0,k,i)
        {
            int idx; cin>>idx;
            b[idx-1]=true;
        }

        if(k<n-1)
        {
            for_n(0,m,i)
            cout<<0;
            cout<<'\n';
            continue;
        }

        if(k==n)
        {
            for_n(0,m,i)
            cout<<1;
            cout<<'\n';
            continue;
        }

        int missing;
        for_n(0,n,i)
        {
            if(!b[i])
            {
                missing=i+1;
                break;
            }
        }

        for_n(0,m,i)
        {
            if(a[i]==missing) cout<<1;
            else cout<<0;
        }
        cout<<'\n';
    }
    return 0;
}
