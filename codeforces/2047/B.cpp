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

const int N=15;
int n,t;
char s[N];
int cnt[30];
int occ[30];

/**
 * Solution:
 * 
 * Count character occurences then set one of the least common
 * characters to the most common character
 * 
 * Example:
 * 
 * For input aaabbc, we set the character c to a since a is the
 * most common character and c is the least common character
 * 
 * Explanation:
 * 
 * This works because the distinct permutations is given by the
 * n!/(cnt['a']!*cnt['b']!*...*cnt['z']!). Therefore to minimize we 
 * subtract one from the smallest non-zero count and add it to the largest
 * count (as this will increase the denominator minimizing the permutations).
 */

signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        cin>>s;

        int mn=1e9,mx=-1e9;
        int mnIdx=0,mxIdx=0;

        for_n(0,n,i)
        {
            cnt[s[i]-'a']++;
            occ[s[i]-'a']=i;
        }

        for_n(0,30,i)
        {
            if(!cnt[i]) continue;
            
            if(cnt[i]<mn)
            {
                mnIdx=i;
                mn=cnt[i];
            }
            if(cnt[i]>=mx)
            {
                mxIdx=i;
                mx=cnt[i];
            }
        }

        s[occ[mnIdx]]=mxIdx+'a';
        cout<<s<<'\n';        
    }
    return 0;
}
