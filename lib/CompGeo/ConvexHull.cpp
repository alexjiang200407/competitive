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
#define double long double
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
const double EPS=1e-10;


struct pt
{
    int x,y;
    pt(int x, int y): x(x),y(y) {}
    pt operator-(pt b) const {
        return pt(x - b.x, y - b.y);
    }
};


bool zero(double x) {
  return fabs(x) <= EPS;
}

double cross(pt a, pt b) {
  return a.x*b.y - a.y*b.x;
}


// true if left or straight
// sometimes useful to instead return an int
// -1, 0 or 1: the sign of the cross product
bool ccw(pt a, pt b, pt c) {
  return cross(b - a, c - a) >= 0;
}

vector<pt> half_hull(vector<pt> pts) {
  vector<pt> res;
  for (int i = 0; i < pts.size(); i++) {
    // ccw means we have a left turn; we don't want that
    while (res.size() >= 2 &&
           ccw(pts[i], res[res.size()-1], res[res.size()-2])) {
      res.pop_back();
    }
    res.push_back(pts[i]);
  }
  return res;
}

vector<pt> convex_hull(vector<pt> pts) {
  sort(pts.begin(), pts.end());
  vector<pt> top = half_hull(pts);

  reverse(pts.begin(), pts.end());
  vector<pt> bottom = half_hull(pts);
  
  top.pop_back();
  bottom.pop_back();
  vector<pt> res(top.begin(), top.end());
  res.insert(res.end(), bottom.begin(), bottom.end());
  return res;
}
