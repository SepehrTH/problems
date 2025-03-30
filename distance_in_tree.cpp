#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const ll MAXN = 5e4 + 40, MAXK = 5e2 + 20;
ll n, k, ans, dp[MAXN][MAXK];
vector<ll> adj[MAXN];

void dfs (ll v, int p)
{
	dp[v][0] = 1;
	for (auto u : adj[v])
		if (u != p)
        {
			dfs (u, v);
			for (ll i = 0 ; i < k ; i++)
				ans += dp[v][i] * dp[u][k - i - 1];
			for (ll i = 1 ; i <= k ; i++)
				dp[v][i] += dp[u][i - 1];
		}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for (ll u, v, i = 0 ; i < n - 1 ; i++)
	{
        cin >> u >> v,
		adj[u].pb(v),
		adj[v].pb(u);
    }
	dfs(1, -1);
	cout << ans;

    return 0;
}