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

const int maxn = 1e5+5;
int n, c[maxn], mark[maxn];
vi adj[maxn];
vpii ed;

bool ok;

void dfs(int v, int par, int r)
{
    if (par != r and c[v] != c[par])
        ok = false;
    for(auto u: adj[v])
    {
        if(u!=par)
            dfs(u, v, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int u, v, i = 0; i < n-1; i++)
    {
        cin >> u >> v;
        ed.pb(MP(u, v));
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bool flag = true;
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
        if(c[i] != c[i-1] && i > 1 && flag==true) flag = false;
    }
    if(flag)
    {
        cout << "YES\n" << 1;
        return 0;
    }

    for(auto e: ed)
    {
        if(c[e.F] != c[e.S])
        {
            ok = true;
            c[0] = c[e.S];
            dfs (e.F, e.F, e.F);
            if(ok)
            {
                cout << "YES\n" << e.F;
                return 0;
            }
            ok = true;
            c[0] = c[e.S];
            dfs (e.S, e.S, e.S);
            if(ok)
            {
                cout << "YES\n" << e.S;
                return 0;
            }
            else
            {
                cout << "NO";
                return 0;
            }
        }
    }
    

    return 0;
}