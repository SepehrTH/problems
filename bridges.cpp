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

bool mark[maxn],is[maxn];
int dp[maxn],h[maxn];
pair<int,int> edge[maxn];
vector<pair<int,int> > adj[maxn];
 
void dfs(int v,int parent,int index)
{
    dp[v]=h[v];
    mark[v]=true;
    for(int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i].first;
        int ind=adj[v][i].second;
        if(!mark[u]){
            h[u]=h[v]+1;
            dfs(u,v,ind);
            dp[v]=min(dp[v],dp[u]);
        }
        else
        {
            if(u!=parent)
            {
                dp[v]=min(dp[v],h[u]);
            }
        }
    }
    if(v!=1)
    {
        if(dp[v]==h[v])
        {
            is[index]=true;
        }
    }
    return;
}
 
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        edge[i]=make_pair(u,v);
        adj[u].push_back(make_pair(v,i));
        adj[v].push_back(make_pair(u,i));
    }
    dfs(1,0,0);
    for(int i=0;i<m;i++)
    {
        if(is[i])
        {
            cout<<edge[i].first<<" "<<edge[i].second<<endl;
        }
    }
    return 0;
}