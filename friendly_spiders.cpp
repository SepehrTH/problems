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
//
const int maxn = 3e5 + 10;
int n, s, t, a[maxn + 1], mark[maxn + 1], visited[maxn * 2+1], h[maxn*2+1], par[maxn*2+1];
vi prime;
vi adj[2 * maxn + 1];
queue<int> q;

void gharbal(int l)
{
    mark[0] = mark[1] = 1;
    for(int i = 2; i <= l; i++)
        if(mark[i] == 0)
        {
            prime.pb(i);
            for(int j = i+i; j <= l; j+=i)
            {
				mark[j] = 1;
			}
        }
}

void bfs(int root)
{
    q.push(root);
    h[root] = 0;
    visited[root] = 1;
    while(q.size())
    {
        int v = q.front();
  //      cout << v << endl;
        q.pop();
        for(int u : adj[v])
        {
          //   cout << v <<" " << u << endl;
            if(!visited[u])
            {
                visited[u] = 1;
                q.push(u);
                h[u] = h[v] + 1;
                par[u] = v;
        //        cout <<"&&&&" << v << " " << u << endl;
            }
        }
    }
//     cout << "FIN" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
//    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];



    cin >> s >> t;
    
    if(s==t)
    {
        prnt(1);
        prnt(s);
        return 0;
    }
    if(__gcd(a[s],a[t])>1)
    {
        prnt(2);
        cout << s << " " << t;
        return 0;
    }

    gharbal(maxn);



    bool flag;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 1)
            continue;
        flag = false;
        //cout << a[i] << "***"<< endl;
        for(int p : prime)
        {
    
            if(p*p > a[i] && adj[i].size() == 0)
            {
                flag = true;
                break;
            }
            if(p * p > a[i])
                break;

           // cout << a[i] << " " << p << endl;
            if(a[i]%p == 0)
            { // ????
                adj[i].pb(maxn+p) , adj[maxn+p].pb(i);
              //  cout << i << " " << maxn + p << endl;
                while(a[i]%p==0)
                    a[i] = a[i] / p;
            }
        }
        if(a[i] > 1)
            adj[i].pb(maxn+a[i]), adj[maxn+a[i]].pb(i);
    }

    //for(int xx : adj[4])
      //  cout <<"(*(*&^*&%*&% "<< xx << " ";

    //for(int i = 1; i <= n; i++)
      //  cout << i << " " << par[i] << endl;



    bfs(s);

    // for(int i = 1; i <= n; i++)
        // cout << i << " " << par[i] << endl;

    vi ans;
    int x = t;
    while(x)
    {
        //cout <<"$$$$"<< x << " " << par[x] << flush << endl;
        ans.pb(x);
        if(s == x)
            break;

        //cout << "^^^" << par[x] << flush <<endl;
        x = par[x];
    }
    if(ans.size()==1)
    {
        prnt(-1);
        return 0;
    }
    reverse(ALL(ans));

    prnt(h[t]/2+1);
    for(int i : ans)
        if(i < maxn)    cout << i << " ";

    return 0;
}
