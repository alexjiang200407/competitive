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

const int LAYERS = 105;
int n,t;
int pieces[LAYERS];

/**
 * Solution:
 * 
 * 
 * 
 */

signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    {
        int width=3;
        pieces[1]=1;
        for_n(2,LAYERS,i)
        {
            pieces[i]=width*width-((width-2)*(width-2));
            width+=2;
        }
    }
    
    cin>>t;
    while(t--)
    {
        int ans=0;
        cin>>n;
        int layer=1;
        int total=0;
        for_n(0,n,i)
        {
            int cnt; cin>>cnt;
            total+=cnt;
            while(total>0)
            {
                total-=pieces[layer++];
            }
            if(total==0) ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
