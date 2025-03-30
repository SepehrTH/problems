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

const int maxn = 305;
int n, k = 0, a[maxn], mark[maxn];
vi adj[maxn];
vi p;
vi path = {1};

void dfs(int v, int par, int en)
{
    
    if(v == en)
    {
        path.insert(path.end() ,ALL(p));
        return;
    }
    for(int u: adj[v])
        if(u != par)
        {
            p.pb(u);
            dfs(u, v, en);
        }
    p.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int u, v, i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(int i = 2; i <= n; i++)
        if(adj[i].size() == 1)
            k++;

    a[0] = 1;
    for(int i = 1; i <= k; i++)
    {
        p.clear();
        cin >> a[i];
        dfs(a[i-1], -1, a[i]);
    }
    p.clear();
    dfs(a[k], -1, 1);

    if(path.size() > 2*n -1)
        prnt(-1);
    else
        VecPrnt(path);

    return 0;
}