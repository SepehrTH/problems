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

const int maxn = 405;
int n, m, a, t[maxn][maxn], h[maxn], mark[maxn];
vi adj[maxn];
queue<int> q;

void bfs(int b)
{
    q.push(1);
    mark[1] = 1;
    h[1] = 0;
    while(q.size() > 0)
    {
        int v = q.front();
        q.pop();
        for(int u: adj[v])
        {
            if(!mark[u] && (t[v][u] == b || t[u][v] == b))
            {
                mark[u] = 1;
                q.push(u);
                h[u] = h[v] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            adj[i].pb(j);

    a = 1;
    for(int u, v, i = 0; i < m; i++)
    {
        cin >> u >> v;
        t[u][v] = 1;
        t[v][u] = 1;
        if((u == 1 && v == n) || (u == n && v == 1))
            a = 0;
    }

    bfs(a);

    if(mark[n] == 0)   prnt(-1);
    else    prnt(h[n]);
    return 0;
}