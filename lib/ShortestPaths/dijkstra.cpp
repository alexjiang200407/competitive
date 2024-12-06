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
#define int ll
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

const int N = 1e5+5;

typedef pair<int, int> edge; // (distance, vertex)
vector<edge> edges[N];
int dist[N];
bool seen[N];
priority_queue<edge, vector<edge>, greater<edge>> pq;

void dijkstra (int s) {
  fill(seen,seen+N,false);
  pq.push(edge(0, s)); // distance to s itself is zero
  while (!pq.empty()) {
    // choose (d, v) so that d is minimal
    // i.e. the closest unvisited vertex
    edge cur = pq.top();
    pq.pop();
    int v = cur.second, d = cur.first;
    if (seen[v]) continue;

    dist[v] = d;
    seen[v] = true;

    // relax all edges from v
    for (edge nxt : edges[v]) {
      int u = nxt.second, weight = nxt.first;
      if (!seen[u])
        pq.push(edge(d + weight, u));
    }
  }
}

int n,m;
signed main(void)
{
    cin>>n>>m;
    for_n(0,m,i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edges[a-1].push_back({c,b-1});
    }

    dijkstra(0);

    for_n(0,n,i)
    cout<<dist[i]<<' ';
    cout<<'\n';
}