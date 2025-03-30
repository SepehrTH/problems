#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef vector<pii > vpii;

#define MP make_pair
#define fr first
#define sc second
#define SORT(a) sort (a.begin(), a.end())
#define REVERSE(a) reverse (a.begin(), a.end())
#define ALL(a) a.begin(), a.end()
#define PI acos(-1)
#define ms(x,y) memset (x, y, sizeof (x))
#define inf 1e9
#define INF 1e16
#define pb push_back
#define MAX 100005
#define debug(a,b) cout<<a<<": "<<b<<endl
#define Debug cout<<"Reached here"<<endl
#define prnt(a) cout<<a<<"\n"
#define mod 1000000007LL
#define itrALL(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define lc ((node)<<1)
#define rc ((node)<<1|1)
#define VecPrnt(v) FOR(J,0,v.size()) cout<<v[J]<<" "; cout<<endl
#define endl "\n"
#define PrintPair(x) cout<<x.first<<" "<<x.second<<endl
#define EPS 1e-9
#define ArrPrint(a,st,en) for(int J=st; J<=en; J++) cout<<a[J]<<" "; cout<<endl;

/* Direction Array */

// int fx[]={1,-1,0,0};
// int fy[]={0,0,1,-1};
// int fx[]={0,0,1,-1,-1,1,-1,1};
// int fy[]={-1,1,0,0,1,1,-1,-1};

const int maxn = 1e5+5;
int n, m, mark[maxn];
vi adj[maxn];
vi ans;
vector<vi> b;

void dfs(int v, int count)
{
    mark[v] = 1;
    for(auto u: adj[v])
    {
        if(!mark[u] && !b[v][u])
        {
            b[v][u] = 1;
            ans.pb(v);
            ans.pb(u);
            dfs(u, count);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    // cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    b.resize(n, vector<int>(n));
    for(int i = 0 ,u , v; i < m; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(m%2)
    {
        cout << "No solution" << endl;
        return 0;
    }
    dfs(1, 0);

    for(int i = 0; i < ans.size(); i++)
    {
        if(i > 0 && i%2!=0)
        {
            cout << ans[i];
        }
        else if((i+1)%4 == 0)
            cout << endl;
    }
    return 0;
}