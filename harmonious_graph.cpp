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
#define SORT(a) sort (a.begin(), a.end())
#define REVERSE(a) reverse (a.begin(), a.end())
#define ALL(a) a.begin(), a.end()
#define PI acos(-1)
#define ms(x,y) memset (x, y, sizeof (x))
#define pb push_back
#define debug(a,b) cout<<a<<": "<<b<<endl
#define Debug cout<<"Reached here"<<endl
#define prnt(a) cout<<a<<"\n"
#define mod 1000000007i
#define VecPrnt(v) FOR(J,0,v.size()) cout<<v[J]<<" "; cout<<endl
#define endl "\n"
#define PrintPair(x) cout<<x.first<<" "<<x.second<<endl
#define ArrPrint(a,st,en) for(int J=st; J<=en; J++) cout<<a[J]<<" "; cout<<endl;

/* Direction Array */

// int fx[]={1,-1,0,0};
// int fy[]={0,0,1,-1};
// int fx[]={0,0,1,-1,-1,1,-1,1};
// int fy[]={-1,1,0,0,1,1,-1,-1};

const int maxn = 2e5+5;
int n, m, color = 0, mi, ma, ans = 0, mark[maxn];
vpii P;
vi adj[maxn];

void dfs (int v)
{
    mi = min (mi, v);
    ma = max (ma, v);
    mark[v] = 1;
    for (auto u : adj[v])
        if (!mark[u])
            dfs (u);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for (int u, v, i = 0 ; i < m; i++)
    {
        cin >> u >> v,
        adj[u].pb(v),
        adj[v].pb(u);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!mark[i])
        {
            mi = i;
            ma = i;
            dfs(i);
            P.pb(MP(mi, ma));
            // cout << mi << " " << ma << " color: " << color <<endl;
            color++;
        }
    }
    SORT(P);
    int R = -1;
    for(auto &v: P)
    {
        if(v.F < R)
            ans++;
        R = max(R, v.S);
    }
    cout << ans;

    return 0;
}