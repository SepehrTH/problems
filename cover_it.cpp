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

const int maxn = 2e5 + 5;
int t, n, m, mark[maxn];
vi adj[maxn];
vi s[2];

void dfs(int v, bool b)
{
    mark[v] = 1;
    s[b].pb(v);
    for(int u : adj[v]) {
        if(!mark[u]) {
            dfs(u, 1-b);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        for (int u, v, i = 0 ; i < m ; i++){
            cin >> u >> v;
            adj[u].pb(v), adj[v].pb(u);
        }
        dfs(1, 0);
        if(s[1].size()<s[0].size()) {
            prnt(s[1].size());
            for(int i : s[1])
                cout << i << " ";
        }
        
        else {
            prnt(s[0].size());
            for(int i : s[0])
                cout << i << " ";
        }
        cout << endl;
        s[0].clear(), s[1].clear();
        for(int i = 0; i <= n; i++) {
            mark[i] = 0;
            adj[i].clear();
        }
    }

    return 0;
}
