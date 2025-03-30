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
#define mod 1000000007LL
#define VecPrnt(v) FOR(J,0,v.size()) cout<<v[J]<<" "; cout<<endl
#define endl "\n"
#define PrintPair(x) cout<<x.first<<" "<<x.second<<endl
#define ArrPrint(a,st,en) for(int J=st; J<=en; J++) cout<<a[J]<<" "; cout<<endl;

/* Direction Array */

// int fx[]={1,-1,0,0};
// int fy[]={0,0,1,-1};
// int fx[]={0,0,1,-1,-1,1,-1,1};
// int fy[]={-1,1,0,0,1,1,-1,-1};

const int maxn = 205;
int n, a, mark[maxn], h[maxn], maxh = -1, mx = -1;
vi adj[maxn];
vpii edge;

void dfs(int v, int d, int par, int h)
{
    if(maxh < h)
    {
        maxh = h;
        mx = v;
    }

    for(auto u: adj[v])
    {
        if(u != d && u != par)
        {
            dfs(u, d, v, h+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int u, v, i = 0; i < n; i++)
    {
        cin >> u >> v;
        edge.pb(MP(u, v));
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans = 0;
    int a = 1;
    for(auto e: edge)
    {
        a = 1;
        maxh = 0;
        mx = 0;
        h[e.F] = 0;
        // debug(e.F, e.S);
        dfs(e.F, e.S, -1, 0);
        maxh = 0;
        h[mx] = 0;
        // debug("mx ", mx);
        dfs(mx, e.S, -1, 0);
        a *= maxh;
        // prnt(maxh);

        mx = 0;
        maxh = 0;
        h[e.S] = 0;
        // debug(e.S, e.F);        
        dfs(e.S, e.F, -1, 0);
        // debug("mx ", mx);
        maxh = 0;
        h[mx] = 0;
        dfs(mx, e.F, -1, 0);
        a *= maxh;
        // prnt(maxh);

        ans = max(ans, a);
    }

    prnt(ans);

    return 0;
}
