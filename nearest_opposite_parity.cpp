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
int n, a[maxn], ans[maxn];
vi adj[maxn];
queue <int> q;

void bfs ()
{
	while (q.size()){
		int v = q.front();
		q.pop();
		for (auto u : adj[v])
			if (ans[u] == -1 and (a[u] & 1) == (a[v] & 1))
				q.push(u),
				ans[u] = ans[v] + 1;
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;

	for (int i = 1 ; i <= n ; i++)
		cin >> a[i], ans[i] = -1;
    for (int i = 1 ; i <= n ; i++) {
        int l = i - a[i], r = i + a[i];
        bool b = a[i] & 1;
        if (1 <= l){
		    adj[l].pb(i);
		    if (b != (a[l] & 1))
			    ans[i] = 1;
	    }
	    if (r <= n){
		    adj[r].pb(i);
		    if (b != (a[r] & 1))
			    ans[i] = 1;
	    }
	    if (ans[i] == 1)
		    q.push(i);
    }

    bfs();
	for (int i = 1 ; i <= n ; i++)
		cout << ans[i] << ' ';

    return 0;
}
