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

const int maxn = 2e5+10;
int n, p[maxn], mark[maxn], root = 0, ans = 0;
vi adj[maxn];

void dfs(int v)
{
    mark[v] = 1;
    for(auto u: adj[v])
    {
        if(u == v)
        {
            if(root != v)
            {
                p[v] = root;
                ans++;
            }
        }
        else if(!mark[u])
            dfs(u);

        else if(mark[u] == 1)
        {
            ans++;
            if(root == 0)
                root = v;
            p[v] = root;
        }
    }
    mark[v] = 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
        if(p[i]==i && root==0)
            root = i;
        adj[i].pb(p[i]);
        // adj[p[i]].pb(i);
    }

    for(int i = 1; i <= n; i++)
        if(!mark[i])
            dfs(i);

    cout << ans << endl;
    for(int i = 1; i <= n; i++)
        cout << p[i] << " ";
    return 0;
}
