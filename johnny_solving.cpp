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

const int maxn = 5e5 + 3;
ll n, m, k, maxh, mx, mark[maxn], h[maxn], par[maxn];
vi adj[maxn];
vi leaves;

void dfs(int v, int p)
{
    
    mark[v] = 1;
    h[v] = h[p] + 1;
    if (h[v] > maxh)
    {
        mx = v;
        maxh = h[v];
    }
    par[v] = p;
    bool leaf = 1;
    for(auto u : adj[v])
    {
        if(mark[u]) continue;
        leaf = 0;
        dfs(u, v);
    }
    if(leaf) leaves.push_back(v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    for(int u, v, i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    
    if (maxh >= n/k)
    {
        prnt("PATH");
        prnt(maxh);
        int x = mx;
        while(x)
        {
            cout << x << " ";
            x = par[x];
        }

        return 0;
    }
    prnt("CYCLES");
    int cnt = 0;
    for(auto v : leaves)
    {
        if(cnt == k) break;
        vector <int> gr;
        for(auto u : adj[v])
        {
            if(u == par[v]) continue;
            if(gr.size() >= 2) break;
            gr.push_back(u);
        }
        int a = gr[0], b = gr[1];
        if((h[v] - h[a] + 1)%3)
        {
            prnt(h[v] - h[a] + 1);
            int x = v;
            while(x)
            {
                cout << x << " ";
                if(x == a) break;
                x = par[x];
            }
            cout << "\n";
            cnt++;
        }
        else if((h[v] - h[b] + 1)%3)
        {
            prnt(h[v] - h[b] + 1);
            int x = v;
            while(x)
            {
                cout << x << " ";
                if(x == b) break;
                x = par[x];
            }
            cout << "\n";
            cnt++;
        }
        else
        {
            if(h[a] > h[b]) swap(a, b);
            prnt(h[b] - h[a] + 2);
            cout << v << " ";
            int x = b;
            while(x)
            {
                cout << x << " ";
                if(x == a) break;
                x = par[x];
            }
            cout << "\n";
            cnt++;
        }
    }

    return 0;
}