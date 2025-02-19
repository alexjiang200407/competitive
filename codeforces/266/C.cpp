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

const int N=5e5+5;
int n;
int a[N],pre[N],cnt[N];
int sum;

signed main(void)
{
    // ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    cin>>n;

    for_n(0,n,i)
    {
        cin>>a[i];
        sum+=a[i];
    }

    if(sum%3!=0)
    {
        cout<<0<<'\n';
        return 0;
    }
    int req=sum/3;

    pre[0]=a[0];
    for(int i=1;i<n;i++)
    {
        pre[i]=pre[i-1]+a[i];
    }

    int ways=0,count=0;
    for_n(0,n-1,i)
    {
        if(pre[i]==2*req)
        {
            ways += count;
        }
        if(pre[i]==req)
        {
            count++;
        }
    }


    cout<<ways<<'\n';

    return 0;
}
