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


/*
 * segment segment intersection
 */

typedef pair<pt, pt> seg;

bool collinear(seg ab, seg cd) { // all four points collinear
  pt a = ab.first, b = ab.second, c = cd.first, d = cd.second;
  return zero(cross(b - a, c - a)) &&
         zero(cross(b - a, d - a));
}

double sq(double t) { return t * t; }

double dist(pt p, pt q) { return sqrt(sq(p.x - q.x) + sq(p.y - q.y)); }

bool intersect(seg ab, seg cd) {
  pt a = ab.first, b = ab.second, c = cd.first, d = cd.second;
  
  if (collinear(ab, cd)) {
    double maxDist = max({dist(a, b), dist(a, c), dist(a, d),
                          dist(b, c), dist(b, d), dist(c, d)});
    return maxDist < dist(a, b) + dist(c, d) + EPS;
  }

  // only finds proper intersections
  // for non-proper, have ccw return an int
  // then return whether both products of ccws are <= 0
  return ccw(a, b, c) != ccw(a, b, d) &&
         ccw(c, d, a) != ccw(c, d, b);
}

/*
 * polygon area trapezoidal
 */

double area(vector<pt> pts) {
  double res = 0;
  int n = pts.size();
  for (int i = 0; i < n; i++) {
    //     (a        + b             ) * h/2 (/2 moved to the end)
    res += (pts[i].y + pts[(i+1)%n].y) * (pts[(i+1)%n].x - pts[i].x);
    // sometimes, h will be negative, which means we subtract area
  }
  return res/2.0;
}

/*
 * polygon area cross product
 */

double area(vector<pt> pts) {
  double res = 0;
  int n = pts.size();
  for (int i = 1; i < n-1; i++) {
    // i = 0 and i = n-1 are degenerate triangles, OK to omit
    // e.g. if i = 1 is ABC, and i = 2 is ACD, then i = 0 is AAB
    res += cross(pts[i] - pts[0], pts[i+1] - pts[0]);
  }
  return res/2.0;
}



