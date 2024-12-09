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

const int N=1e5+5;
int n,t;
int cnt[10];

signed main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>t;

    while(t--)
    {
        fill(cnt,cnt+10,0);
        int dp[20][3];
        int sum=0;
        str s;
        cin>>s;

        memset(dp,0,sizeof(dp));

        for_e(ch,s)
        {
            int digit=ch-'0';
            cnt[digit]++;
            sum+=digit;
        }
        int mul=ceil((double)sum/9.0);
        int nxt=9*mul;
        if(nxt%2!=sum%2) nxt+=9;
        int req=nxt-sum;

        dp[0][2]=true;
        for_n(2,req+1,i)
        {
            if(dp[i-2][2]&&dp[i-2][0]<cnt[2])
            {
                dp[i][0]=dp[i-2][0]+1;
                dp[i][1]=dp[i-2][1];
                dp[i][2]=true;
            }
            else if(i>=6&&dp[i-6][2]&&dp[i-6][1]<cnt[3])
            {
                dp[i][1]=dp[i-6][1]+1;
                dp[i][0]=dp[i-6][0];
                dp[i][2]=true;
            }
        }

        if(dp[req][2]) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    
    return 0;
}
