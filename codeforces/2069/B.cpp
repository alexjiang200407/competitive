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
#include <unordered_map>
#include <memory>

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
#define clr(arr) memset(arr,0,sizeof(arr))
#define heap_array(t,sz) make_unique<t[]>(sz); 
#define pb push_back

const ll MOD=1e9+7;
ll madd(ll a, ll b) { return (a + b) % MOD; }

const int N=705;
const int directions[2][2]={0,1,1,0};

int n,m,t,c;

class Array2D {
private:
    int rows, cols;
    unique_ptr<int[]> data;

public:
    Array2D(int r, int c) : rows(r), cols(c), data(make_unique<int[]>(r*c)) {}

    int& operator()(int r, int c) { return data[r*cols+c]; }
    const int& operator()(int r, int c) const { return data[r*cols+c]; }
};

/**
 * SOLUTION:
 * The answer is simply the sum number of adjacencies for each color (subtracting the color
 * with most adjacencies) and then add to colors - 1.
 */
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        c=0;        
        cin>>n>>m;
        auto a=Array2D(n+1,m+1);
        unordered_map<int,int> colorIdx;

        auto hasColor=heap_array(int,n*m+5);
        auto hasAdj=heap_array(int,n*m+5);
        auto adjC=make_unique<int[]>(n*m+5);

        for_n(0,n,i)
            for_n(0,m,j)
                cin>>a(i,j);

        for_n(0,n,i)
        {
            for_n(0,m,j)
            {
                hasColor[a(i,j)-1]=1;
                for_e(dir,directions)
                {
                    if(i+dir[0]<0||i+dir[0]>=n||j+dir[1]<0||j+dir[1]>=m) continue;
                    if(a(i,j)==a(i+dir[0],j+dir[1]))
                    {
                        hasAdj[a(i,j)-1]=1;
                    }
                }
            }
        }
        int ans=0;
        int mx=-1e10;
        for_n(0,n*m+5,i)
        {
            ans+=hasColor[i]+hasAdj[i];
            mx=max(mx,hasAdj[i]);
        }
        cout<<(ans-1-mx)<<'\n';
    }

    return 0;
}
