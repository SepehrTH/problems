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

const int maxn = 1e5+5;
int n, m, timer, mark[maxn], in[maxn], low[maxn];
vi adj[maxn];
set<int> ans;

void dfs(int v, int p)
{
    mark[v] = 1;
    in[v] = low[v] = timer;
    timer++;
    int children = 0;
    for (int u : adj[v])
    {
        if (u == p) continue;
        if (mark[u])
        {
            low[v] = min(low[v], in[u]);
        }
        else 
        {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] >= in[v] && p!=-1)
                ans.insert(v);
            children++;
        }
    }
    if(p == -1 && children > 1)
        ans.insert(v);
}

int main()
{
    timer = 0;
    cin >> n >> m;
    for(int u, v, i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 0; i < n; i++)
    {
        if (!mark[i])
            dfs (i, -1);
    }
    set<int>::iterator it;
    for (it = ans.begin(); it != ans.end(); it++)
        prnt(*it);
}