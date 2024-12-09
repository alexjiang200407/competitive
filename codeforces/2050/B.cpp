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

const int N=2e5+5;
int a[N];
int n,t;


signed main(void)
{
    // ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        int sum=0;
        cin>>n;
        for_n(0,n,i)
        {
            cin>>a[i];
            sum+=a[i];
        }
        
        if(sum%n!=0)
        {
            cout<<"NO"<<'\n';
            continue;
        }

        int needed=sum/n;

        for(int i=2;i<n;i++)
        {
            if(a[i-2]>needed)
            {
                a[i]+=a[i-2]-needed;
                a[i-2]=needed;
                // Debug(a[i]);
            }
            else if(a[i-2]<needed)
            {
                a[i]-=needed-a[i-2];
                a[i-2]=needed;
                // Debug(a[i]);
            }
        }


        bool flag=true;
        for_n(0,n,i)
        {
            // Debug(a[i]);
            if(a[i]!=needed)
            {
                cout<<"NO"<<'\n';
                flag=false;
                break;
            }
        }


        if(flag)
        cout<<"YES"<<'\n';

    }

    return 0;
}
