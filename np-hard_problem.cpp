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

const int maxn = 2e5;
ll n, m, mark[maxn];
ll color[maxn];
bool flag = true;
vi adj[maxn];
vi s1, s2;

bool dfs(int v, int c)
{
    color[v] = c;
    if(c)
        s1.pb(v);
    else
        s2.pb(v);
    for(auto u: adj[v])
    {
        if(color[u]==c)
        {
            flag = false;
            return false;
        }
        if(color[u]==-1)
        {
            dfs(u, 1-color[v]);
        }
    }
    return flag;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int u, v, i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fill(color, color+n+10, -1);

    for(int i = 1; i <= n; i++)
    {
        if(color[i]==-1)
        {
            bool check = dfs(i, 0);
            if(!check)
            {
                cout << -1;
                return 0;
            }
        }
    }

    cout << s1.size() << endl;
    for(auto i: s1)
        cout << i << " ";
    cout << endl;
    cout << s2.size() << endl;
    for(auto i: s2)
        cout << i << " ";

    return 0;
}