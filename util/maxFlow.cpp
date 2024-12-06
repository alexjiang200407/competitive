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
#define INF 1e18

/**
 * INPUT:
 * 1st line n,m where n is node count and m is edge count
 * Next m lines describe edges
 */


/*
 * dinic 1
 */

struct FlowNetwork {
    vector<vector<ll>> adjMat, adjList;
    // level[v] stores dist from s to v
    // uptochild[v] stores first non-useless child.
    vector<int> level, uptochild;
 
    FlowNetwork (int _n) {
        // adjacency matrix is zero-initialised
        adjMat.resize(_n);
        for (int i = 0; i < _n; i++)
            adjMat[i].resize(_n);
        adjList.resize(_n);
        level.resize(_n);
        uptochild.resize(_n);
    }
 
    void add_edge (int u, int v, ll c) {
        // add to any existing edge without overwriting
        adjMat[u][v] += c;        
        adjMat[v][u] += c;        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
 
    void flow_edge (int u, int v, ll c) {
        adjMat[u][v] -= c;
        adjMat[v][u] += c;
    }

    void print_edges()
    {
        for(size_t i=0; i<adjList.size(); i++)
        {
            auto edges=adjList[i];
            for_e(edge,edges)
            {
                cout<<i<<' '<<edge<<' '<<adjMat[i][edge]<<'\n';
            }
        }
    }
 
/*
 * dinic 2
 */
 
    // constructs the level graph and returns whether the sink is still reachable
    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            uptochild[u] = 0; // reset uptochild
            for (int v : adjList[u])
                if (adjMat[u][v] > 0) {
                    if (level[v] != -1) // already seen
                        continue;
                    level[v] = level[u] + 1;
                    q.push(v);
                }
        }
        return level[t] != -1;
    }
 
/*
 * dinic 3
 */
 
    // finds an augmenting path with up to f flow.
    ll augment(int u, int t, ll f) {
        if (u == t) return f; // base case.
        // note the reference here! we increment uptochild[u], i.e. walk through u's neighbours
        // until we find a child that we can flow through
        for (int &i = uptochild[u]; (size_t)i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if (adjMat[u][v] > 0) {
                // ignore edges not in the BFS tree.
                if (level[v] != level[u] + 1) continue;
                // revised flow is constrained also by this edge
                ll rf = augment(v,t,min(f, adjMat[u][v]));
                // found a child we can flow through!
                if (rf > 0) {
                    flow_edge(u,v,rf);
                    return rf;
                }
            }
        }
        level[u] = -1;
        return 0;
    }
 
/*
 * dinic 4
 */
 
    ll dinic(int s, int t) {
        ll res = 0;
        while (bfs(s,t))
            for (ll x = augment(s,t,INF); x; x = augment(s,t,INF))
                res += x;
        return res;
    }
};

int n,m;
FlowNetwork fn(100);
int main(void)
{
    cin>>n>>m;
    for_n(0,m,i)
    {
        int a,b,c; cin>>a>>b>>c;
        a--; b--;
        fn.add_edge(a,b,c);
    }
    cout<<fn.dinic(0,n-1)<<'\n';
}