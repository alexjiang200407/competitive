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

using namespace std;

typedef long long ll;
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

const ll MOD=1e9+7;
ll madd(ll a, ll b) { return (a + b) % MOD; }

const int directions[4][2]={-1,0,0,-1,0,1,1,0};

int n;

/*
 * matrix mult
 * 0,0 top left
 */
// Implementation for square matrices.

// 
struct Array2D {
  int n;
  vector<vector<long long>> v;
  // Assume these have been implemented.
  Array2D(int _n) : n(_n) {
    v.resize(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        v[i].push_back(0);
  };

  Array2D operator*(const Array2D &o) const
  {
    Array2D res(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
        {
          res.v[i][j] += (v[i][k] * o.v[k][j])%MOD;
          res.v[i][j]%=MOD;
        }

    return res;
  };

  static Array2D getIdentity(int n) {
    Array2D res(n);
    for (int i = 0; i < n; i++)
      res.v[i][i] = 1;
    return res;
  }
  
  Array2D operator^(long long k) const {
    Array2D res = Array2D::getIdentity(n);
    Array2D a = *this;
    while (k) { // building up in powers of two
      if (k&1) res = res*a;
      a = a*a;
      k /= 2;
    }
    return res;
  }
};
