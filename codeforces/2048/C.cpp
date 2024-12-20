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

const int N=5005;
int n,t;

bitset<N> s1;

template<std::size_t N>
bool operator<(const std::bitset<N>& x, const std::bitset<N>& y)
{
    for (int i = N-1; i >= 0; i--) {
        if (x[i] ^ y[i]) return y[i];
    }
    return false;
}

signed main(void)
{
    // ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

    cin>>t;
    while(t--)
    {
        cin>>s1;
        bitset<N> tmp=s1,mx=s1;
        int ans[2];
        int m=0;
        while(tmp!=0)
        {
            m++;
            tmp>>=1;
        }
        int i,sz;
        bool flag=true;
        for(i=m-2;i>=0;i--)
        {
            if(!s1.test(i))
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<"1 1 1 "<<m<<'\n';
            continue;
        }
        
        sz=i+1;
        bitset<N> msk;
        for_n(0,sz,j)
        {
            msk<<=1;
            msk|=1;
        }
        for_n(sz,m,j) msk<<=1;
        for_n(0,m-sz,j)
        {
            bitset<N> s2=(s1&msk)>>(m-sz-j);
            msk>>=1;
            s2^=s1;
            if(mx<s2)
            {
                mx=s2;
                ans[0]=j+1; ans[1]=j+sz;
            }
        }
        cout<<ans[0]<<' '<<ans[1]<<' '<<1<<' '<<m<<'\n';
        // cout<<mx<<'\n';
    }
    return 0;
}
