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

/**
 * SOLUTION:
 * 
 * We use a segment tree to store the count of vertices on either side of a vertical line.
 * Then we iterate through every possible x value to maximise the minimum count of the grouping created by the
 * a vertical line that intersects a horizontal line at x. We try this for all x values.
 * 
 */

int n,t;

struct Node
{
    int left=0,right=0;

    void add(int delta)
    {
        left+=delta;
        if(delta<0) right-=delta;
    }

    Node operator+(const Node& n) const
    {
        Node ret;
        ret.left=left+n.left;
        ret.right=right+n.right;
        return ret;
    }

    int minCnt() { return min(left,right); }
};

struct SegTree
{
    Node n;
    SegTree* l=nullptr;
    SegTree* r=nullptr;

    ~SegTree()
    {
        delete l;
        delete r;
    }

    void insert(int l, int r, int p, int c=1)
    {
        n.add(c);
        if(r-l==1) return;

        int mid=(l+r)/2;
        if(p<mid)
        {
            if(!this->l) this->l=new SegTree();
            this->l->insert(l,mid,p,c);
        }
        else
        {
            if(!this->r) this->r=new SegTree();
            this->r->insert(mid,r,p,c);
        }
    }

    Node leftNode()
    {
        if(l) return l->n;
        return Node();
    }

    Node rightNode()
    {
        if(r) return r->n;
        return Node();
    }

    void erase(int l, int r, int p)
    {
        insert(l,r,p,-1);
    }
};
struct pt
{
    int x,y;
    bool operator<(const pt& rhs) { return x<rhs.x; }
};

const int N=1e5+5,INF=1e9+5;
pt a[N];
int mx=0;
int ans[2];


bool f(int l, int r, SegTree* tree, Node nodeL, Node nodeR)
{
    if(!tree) return false;
 
    bool updated=false;

    int mid=(l+r)/2;
    Node newLeft=tree->leftNode()+nodeL;
    Node newRight=tree->rightNode()+nodeR;

    int mn=min(newLeft.minCnt(),newRight.minCnt());
    if(mn>mx)
    {
        mx=mn;
        ans[1]=mid;
        updated=true;
    }

    if(mn==newLeft.minCnt())
    {
        if(f(mid,r,tree->r,newLeft,nodeR)) return true;
    }
    else
    {
        if(f(l,mid,tree->l,nodeL,newRight)) return true;
    }

    return updated;
}


signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        mx=0;
        memset(ans,0,sizeof(ans));

        SegTree rt;
        cin>>n;
        for_n(0,n,i)
        {
            cin>>a[i].x>>a[i].y;
            rt.insert(-INF,INF,a[i].y); 
        }
        sort(a,a+n);
        int i=0;
        while(i<n)
        {
            int j=i+1;
            for(;j<n&&a[j].x==a[i].x;j++);

            if(f(-INF,INF,&rt,{},{})) ans[0]=a[i].x;
            
            for(;i<j;i++) rt.erase(-INF,INF,a[i].y);
        }
        cout<<mx<<'\n'
            <<ans[0]<<' '<<ans[1]<<'\n'
        ;
    }


    return 0;
}
