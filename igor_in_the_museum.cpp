#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 30;
int n, m, k, mark[maxn][maxn], cnt[maxn*maxn], co[maxn][maxn];
int G[] = {1, -1, 0, 0};
int H[] = {0, 0, 1, -1};
int c = 0;
string t[maxn];

bool ok (int x, int y)
{
	return (x >= 0 and y >= 0 and x < n and y < m and !mark[x][y]);
}

void dfs(int x, int y, int count)
{
	mark[x][y] = 1;
	co[x][y] = count;
	for (int i = 0 ; i < 4 ; i++)
	{
		int nx = x + G[i];
		int ny = y + H[i];
		if(ok(nx, ny))
		{
			if (t[nx][ny] == '*')
				cnt[count]++;
			else
				dfs(nx, ny, count);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> t[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(t[i][j] == '.' && mark[i][j] == 0)
            {
            	dfs(i, j, c++);
            }
        }
    }
    int x, y;
    while (k--)
    {
		cin >> x >> y;
		cout << cnt[co[x-1][y-1]] << '\n';
	}

	return 0;
}