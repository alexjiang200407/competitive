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
#include <stack>

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

const int directions[4][2]={-1,0,0,-1,0,1,1,0};

#define N 1000000

/*
 * tarjan 1
 */

vi edges[N];

// we will number the vertices in the order we see them in the DFS
int dfs_index[N];
// for each vertex, store the smallest number of any vertex we see
// in its DFS subtree
int lowlink[N];

// explicit stack
stack<int> s; // #include <stack>
bool in_stack[N];

// arbitrarily number the SCCs and remember which one things are in
int scc_counter;
int which_scc[N];

void connect(int v) {
  // a static variable doesn't get reset between function calls
  static int i = 1;
  // set the number for this vertex
  // the smallest numbered thing it can see so far is itself
  lowlink[v] = dfs_index[v] = i++;
  s.push(v);
  in_stack[v] = true;

  // continued

/*
 * tarjan 2
 */

  for (auto w : edges[v]) { // for each edge v -> w
    if (!dfs_index[w]) {  // w hasn't been visited yet
      connect(w);
      // if w can see something, v can too
      lowlink[v] = min(lowlink[v], lowlink[w]);
    }
    else if (in_stack[w]) {
      // w is already in the stack, but we can see it
      // this means v and w are in the same SCC
      lowlink[v] = min(lowlink[v], dfs_index[w]);
    }
  }
  // v is the root of an SCC
  if (lowlink[v] == dfs_index[v]) {
    ++scc_counter;
    int w;
    do {
      w = s.top(); s.pop();
      in_stack[w] = false;
      which_scc[w] = scc_counter;
    } while (w != v);
  }
}

int n,m;
int main()
{
  cin>>n>>m;
  for_n(0,m,i)
  {
    int a,b;
    cin>>a>>b;
    edges[a].push_back(b);
  }

  for_n(1,n+1,i)
  {
    if(!which_scc[i]) connect(i);
  }

  for_n(1,n+1,i)
  {
    cout<<which_scc[i]<<' ';
  }
  return 0;
}