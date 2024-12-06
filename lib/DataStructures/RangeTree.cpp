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

template <typename T>
class RangeTree
{
public:
    void init(ll n)
    {
        tree = new T[n];
    }

    T query(int qL, int qR, int i = 1, int cL = 0, int cR = n) const
    {
        if (cL == qL && cR == qR) return tree[i];
        int mid = (cL + cR) / 2;
        if (qL < mid && qR > mid) return aggregate(
            query(qL, min(qR, mid), i * 2, cL, mid),
            query(max(qL, mid), qR, i * 2 + 1, mid, cR)
        );
        if (qL < mid) return query(qL, min(qR, mid), i * 2, cL, mid);
        return query(max(qL, mid), qR, i * 2 + 1, mid, cR);
    }
    
    void update(int p, T v, int i = 1, int cL = 0, int cR = n)
    {
        if (cR - cL == 1)
        {
            tree[i] = v;
            return;
        }

        int mid = (cL + cR) / 2;
        if (p < mid) update(p, v, i * 2, cL, mid);
        else update(p, v, i * 2 + 1, mid, cR);
        tree[i] = aggregate(tree[i*2], tree[i*2+1]);
    }
    
    virtual T aggregate(T left, T right) const = 0;

private:
    T* tree;
};

template <typename T>
class SumTree : public RangeTree<T>
{
    virtual T aggregate(T left, T right) const override
    {
        return left + right;
    }
};

template <typename T>
class MaxTree : public RangeTree<T>
{
    virtual T aggregate(T left, T right) const override
    {
        return max(left, right);
    }
};

template <typename T, typename T1 = std::pair<T, T>>
class IncreasingTree : public RangeTree<T1>
{
    virtual T1 aggregate(T1 left, T1 right) const override
    {
        if (left.first && right.first)
            if (left.second <= right.first)
                return make_pair(left.first, right.second);
        return { 0, 0 };
    }
};


template <typename T, typename T1 = std::pair<T, T>>
class DecreasingTree : public RangeTree<T1>
{
    virtual T1 aggregate(T1 left, T1 right) const override
    {
        if (left.first && right.first)
            if (left.second >= right.first)
                return make_pair(left.first, right.second);
        return { 0, 0 };
    }
};


/*
 * range tree query
 */

// the number of additional nodes created can be as high as the next power of two up from N (2^17 = 131,072)
int tree[1<<18];

int n; // actual length of underlying array

// query the sum over [qL, qR) (0-based)
// i is the index in the tree, rooted at 1 so children are 2i and 2i+1
// instead of explicitly storing each node's range of responsibility [cL,cR), we calculate it on the way down
// the root node is responsible for [0, n)
int query(int qL, int qR, int i = 1, int cL = 0, int cR = n) {
  // the query range exactly matches this node's range of responsibility
  if (cL == qL && cR == qR)
    return tree[i];
  // we might need to query one or both of the children
  int mid = (cL + cR) / 2;
  int ans = 0;
  // query the part within the left child [cL, mid), if any
  if (qL < mid) ans = query(qL, min(qR, mid), i * 2, cL, mid);
  // query the part within the right child [mid, cR), if any
  if (qR > mid) ans = max(ans,query(max(qL, mid), qR, i * 2 + 1, mid, cR));
  return ans;
}

/*
 * range tree update
 */

// p is the index in the array (0-based)
// v is the value that the p-th element will be updated to
// i is the index in the tree, rooted at 1 so children are 2i and 2i+1
// instead of explicitly storing each node's range of responsibility [cL,cR), we calculate it on the way down
// the root node is responsible for [0, n)
void update(int p, int v, int i = 1, int cL = 0, int cR = n) {
  if (cR - cL == 1) {
    // this node is a leaf, so apply the update
    tree[i] = v;
    return;
  }
  // figure out which child is responsible for the index (p) being updated
  int mid = (cL + cR) / 2;
  if (p < mid)
    update(p, v, i * 2, cL, mid);
  else
    update(p, v, i * 2 + 1, mid, cR);
  // once we have updated the correct child, recalculate our stored value.
  tree[i] = max(tree[i*2],tree[i*2+1]);
}

