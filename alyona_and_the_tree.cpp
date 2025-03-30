#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef vector<pii > vpii;

#define MP make_pair
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

const int maxn = 1e5+10;
int n, ans = 0, a[maxn], mark[maxn], h[maxn], sub[maxn];
ll na[10000][10000];
vi adj[maxn];

void dfs(int v)
{
    mark[v] = 1;
    for(auto u: adj[v])
    {
        if(mark[u] == 0)
        {
            h[u] = h[v] + na[u][v];
            sub[v] += sub[u];
            dfs(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i < n; i++)
    {
        int u, v, num;
        cin >> u >> num;
        v = i+1;
        adj[v].pb(u);
        adj[u].pb(v);
        na[v][u] = na[u][v] = num;
    }
    dfs(1);
    for(int u = 1; u <= n; u++)
    {
        if(h[u] > a[u])
        {
            ans += 1;
        }
    }

    cout << ans;
    return 0;
}
