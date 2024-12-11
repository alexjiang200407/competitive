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

const int N=2e5+5;
int n,t;

struct pt
{
    int v,i;
    bool operator<(const pt& rhs) const { return v-i>rhs.v-rhs.i; }
    bool operator==(const pt& rhs) const { return v==rhs.v&&i==rhs.i; }
    pt(int v, int i): v(v),i(i) {}
};

struct cmpPt
{
    bool operator()(const pt& lhs, const pt& rhs) const
    {
        return lhs.i<rhs.i;
    }
};

signed main(void)
{
    // ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        str s;
        str ans;
        cin>>s;
        int i=0;

        multiset<pt> nums;
        map<int,int> map;
        for_e(ch,s)
        {
            nums.insert(pt(ch-'0',i));
            map[i]=ch-'0';
            i++;
        }
        n=s.size();

        for_n(0,n,j)
        {
            auto it=nums.begin();
            if(it->i!=j)
            {
                nums.extract(pt(map[j],j));
                swap(map[it->i],map[j]);
                map[j]-=it->i-j;
                int tmp=it->i;
                nums.insert(pt(map[tmp],tmp));
            }
            nums.erase(it);
        }
        for_e(d,map)
        {
            cout<<d.second;
        }
        cout<<'\n';
    }


    return 0;
}
