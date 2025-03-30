#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef vector<pii > vpii;

#define MP make_pair
#define F first
#define S second
#define REVERSE(a) reverse (a.begin(), a.end())
#define ALL(a) a.begin(), a.end()
#define ms(x,y) memset (x, y, sizeof (x))
#define pb push_back
#define debug(a,b) cout<<a<<": "<<b<<endl
#define Debug cout<<"Reached here"<<endl
#define prnt(a) cout<<a<<"\n"
#define VecPrnt(v) for(auto i: v) cout<<i<<" "; cout<<endl
#define endl "\n"
#define PrintPair(x) cout<<x.first<<" "<<x.second<<endl
#define ArrPrint(a,st,en) for(int J=st; J<=en; J++) cout<<a[J]<<" "; cout<<endl;

/* Direction Array */

// int fx[]={1,-1,0,0};
// int fy[]={0,0,1,-1};
// int fx[]={0,0,1,-1,-1,1,-1,1};
// int fy[]={-1,1,0,0,1,1,-1,-1};

const int maxn = 2e5 + 5;
ll t, n, ans, dp[maxn], l[maxn], r[maxn];
vi adj[maxn];

void dfs(int v, int par)
{
    for(int u: adj[v])
    {
        if(u != par)
        {
            dfs(u, v);
            dp[v] += dp[u];
        }
    }
    dp[v] = min(r[v], dp[v]);
    if(dp[v] < l[v])
    {
        dp[v] = r[v];
        ans++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int v, i = 2; i <= n; i++)
        {
            cin >> v;
            adj[i].pb(v);
            adj[v].pb(i);
        }
        for(int i = 1; i <= n; i++)
            cin >> l[i] >> r[i];

        ans = 0;
        dfs(1, 0);
        prnt(ans);
        for(int i = 0; i <= n; i++)
            adj[i].clear(), dp[i] = 0;

    }


    return 0;
}