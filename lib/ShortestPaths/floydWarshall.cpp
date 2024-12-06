#include <vector>
using namespace std;
#define INF 100000000
#define N 100000
#define M 100000

int n = 1000;

struct edge {
  int u, v, w; // u -> v of weight w
  edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
  edge() = default;
};

vector<int> dist[N];
edge edges[M];

void floyd_warshall() {
  // the distance between everything is infinity
  for (int u = 0; u < N; ++u)
    for (int v = 0; v < N; ++v)
      dist[u][v] = INF;

  // update the distances for every directed edge
  for (edge e : edges)
  {
    if(dist[e.u][e.v]<e.w) continue;
    // each edge u -> v with weight w
    dist[e.u][e.v] = e.w;
  }

  // every vertex can reach itself
  for (int u = 0; u < n; ++u)
    dist[u][u] = 0;

    // INDEXED FROM 0, if starting at 1 change i=1 and i<=n
  for (int i = 0; i < n; i++)
    for (int u = 0; u < n; u++)
      for (int v = 0; v < n; v++)
        // dist[u][v] is the length of the shortest path from u to v using only
        // 0 to i-1 as intermediate vertices now that we're allowed to also use
        // i, the only new path that could be shorter is u -> i -> v
        dist[u][v] = min(dist[u][v], dist[u][i] + dist[i][v]);
}

int main(void) {}