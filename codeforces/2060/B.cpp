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
#define clr(arr) memset(arr,0,sizeof(arr))
#define pb push_back

const ll MOD=1e9+7;
ll madd(ll a, ll b) { return (a + b) % MOD; }

const int directions[4][2]={-1,0,0,-1,0,1,1,0};

int n,m,t;
vector<pii> cards;

/**
 * SOLUTION:
 * We sort all the cards. This will determine the order in which the cards must be played.
 * If all cards are unique, we are already done. We just need to then check if a card distrupts
 * the required order. If it does we will exit
 */
signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cards.clear();

        for_n(0,n,i)
        {
            for_n(0,m,j)
            {
                int a; cin>>a;
                cards.pb({a, i});
            }
        }
        

        sort(all(cards));
        vi order(n,-1);

        bool valid=true;
        int prev=-1;
        int i=0;
        for_e(card,cards)
        {
            if(card.first>prev)
            {
                if(order[i%n]!=-1&&order[i%n]!=card.second)
                {
                    valid=false;
                    break;
                }
                order[i%n]=card.second;
            }
            prev=card.first;
            i++;
        }
        if(!valid)
        {
            cout<<-1<<'\n';
            continue;
        }

        for_e(a,order) cout<<a+1<<' ';
        cout<<'\n';
    }
    return 0;
}
