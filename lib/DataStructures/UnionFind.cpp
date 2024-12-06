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
#define N 100

struct UnionFind
{
    ll parent[N];
    ll size[N];

    void init(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void join(int x, int y)
    {
        // join roots
        x = root(x); y = root(y);
        // test whether already connected
        if (x == y)
            return;
        // size heuristic
        // hang smaller subtree under root of larger subtree
        if (size[x] < size[y])
        {
            parent[x] = y;
            size[y] += size[x];
        }
        else
        {
            parent[y] = x;
            size[x] += size[y];
        }
    }

    /*
    * union find path compression
    */

    int root(int x)
    {
        // only roots are their own parents
        // otherwise apply path compression
        return parent[x] == x ? x : parent[x] = root(parent[x]);
    }
};