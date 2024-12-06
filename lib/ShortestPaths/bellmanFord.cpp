#include <vector>
using namespace std;
#define INF 100000000

/*
 * bellman ford relax
 */

struct edge {
  int u, v, w; // u -> v of weight w
  edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

int n=1000;

vector<int> dist(n);
vector<edge> edges;

// global relaxation: try to relax every edge in the graph
// returns whether any distance was updated
bool relax() {
  bool relaxed = false;
  for (edge e : edges) {
    // we don't want to relax an edge from an unreachable vertex
    if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
      relaxed = true;
      dist[e.v] = dist[e.u] + e.w;
    }
  }
  return relaxed;
}



/*
 * bellman ford main
 */

// Puts distances from source vertex 0 in dist
// Returns true if there is a negative cycle, false otherwise.
// NOTE: You can't trust the dist array if this function returns True.
bool bellman_ford() {
  fill(dist.begin(), dist.end(), INF);
  dist[0] = 0;
  // V-1 global relaxations
  // if no updates are made in an entire round, we can early exit
  // SPFA optimises this further
  for (int i = 0; i < n - 1; i++)
    if (!relax()) break;

  // there is a negative cycle iff any edge can be relaxed further
  // therefore try a Vth global relaxation
  // true if any changes made, false otherwise
  // can micro-optimise by early exiting when the first change is made
  return relax();
}

int main(void)
{
  
}