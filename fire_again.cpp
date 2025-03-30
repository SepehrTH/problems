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

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
// int fx[]={0,0,1,-1,-1,1,-1,1};
// int fy[]={-1,1,0,0,1,1,-1,-1};

const int maxn = 2005;
int n, m, k, maxh, mark[maxn][maxn], h[maxn][maxn];
queue <pii> q;
pii ans;


void bfs()
{
    while(q.size()>0)
    {
        pii v = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int x = v.F + fx[i];
            int y = v.S + fy[i];
            if(x > n || x < 1 || y > m || y < 1)    continue;
            else if(!mark[x][y])
            {
                mark[x][y] = 1;
                q.push(MP(x, y));
                h[x][y] = h[v.F][v.S] + 1;
                if(h[x][y] > maxh)
                {
                    maxh = h[x][y];
                    ans = MP(x, y);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> n >> m >> k;
    for(int a, b, i = 0; i < k; i++)
    {
        cin >> a >> b;
        mark[a][b] = 1;
        q.push(MP(a, b));
        h[a][b] = 0;
        ans = MP(a, b);
    }

    bfs();
    
    cout << ans.F << " " << ans.S;

    return 0;
}