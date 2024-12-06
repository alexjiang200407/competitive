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
struct pt
{
    int x,y,v;
};
const int N=1e5;
pt a[N];


void compress()
{
    vector<pair<pt, ll>> coord_and_idx;

    for_n(0, n, i) coord_and_idx.push_back({ a[i] , i });
    sort(all(coord_and_idx),[](const pair<pt,ll> l, const pair<pt,ll> r){ return l.first.x<r.first.x; });

    ll j = 0;
    a[coord_and_idx[0].second].x = 0;
    for_n(1,n,i)
    {
        if (coord_and_idx[i-1].first.x<coord_and_idx[i].first.x)
            j++;
        a[coord_and_idx[i].second].x=j;
    }
    sort(all(coord_and_idx), [](const pair<pt,ll> l, const pair<pt,ll> r){ return l.first.y<r.first.y; });

    j = 0;
    a[coord_and_idx[0].second].y = 0;
    for_n(1,n,i)
    {
        if (coord_and_idx[i-1].first.y<coord_and_idx[i].first.y)
            j++;
        a[coord_and_idx[i].second].y=j;
    }
}
