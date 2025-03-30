#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int maxn = 3e5+100;
int n, m, t, ans, col[maxn], P[maxn], cnt[2];
vector<int> adj[maxn];
bool flag;


void dfs(int v, bool c)
{
    col[v] = c;
    cnt[c]++;
    for(auto u: adj[v])
    {
        if(col[u] == col[v])
        {
            flag = false;
            return;
        }
        if(col[u] == -1)
            dfs(u, 1-c);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    P[0] = 1;
    for (int i = 1 ; i < maxn ; i++)
		P[i] = (P[i - 1] * 2) % MOD;

    cin >>  t;
    while(t--)
    {
        
        cin >> n >> m;
        for(int i = 0; i <= n; i++)
            adj[i].clear();
        for (int i = 0 ; i < m ; i++)
        {
            int u, v;
			cin >> u >> v;
			adj[u].push_back(v), adj[v].push_back(u);
		}

        // memset(col, -1, sizeof(col));
        for(int i = 0; i <= n; ++i) col[i] = -1;
        ans = 1;
        for(int i = 1; i <= n; i++)
        {
            if(col[i] != -1)
                continue;
            flag = true;
            cnt[0] = 0;
            cnt[1] = 0;
            dfs(i, 0);
            if(flag == false)
            {
                cout << 0 << "\n";
                break;
            }
            ans = (long long)ans * (P[cnt[0]] + P[cnt[1]]) % MOD;
            
        }
        if(flag)
            cout << ans << "\n";
    }
}