#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define F first
#define S second
#define pb push_back

const int MAXN = 2e5+50;

ll n, m, ans[MAXN], l[MAXN], r[MAXN], b[MAXN];
vector<pair<ll, pair<int, int> > > e;
set<pair<ll, ll> > q;


int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n - 1; i++)
    {
        e.pb(make_pair(l[i + 1] - r[i], make_pair(-1, i)));
        e.pb(make_pair(r[i + 1] - l[i], make_pair(1, i)));
    }

    for (int i = 0; i < m; i++)
        e.pb(make_pair(b[i], make_pair(0, i)));
    sort(e.begin(), e.end());

    for (auto t : e)
    {
        if (t.second.first == -1)
            q.insert(make_pair(r[t.second.second + 1] - l[t.second.second], t.second.second));
        else if (t.second.first == 1)
            q.erase(make_pair(r[t.second.second + 1] - l[t.second.second], t.second.second));
        else if (sz(q))
        {
            int i = q.begin()->second;
            ans[i] = t.second.second + 1;
            q.erase(q.begin());
        }
    }


    return 0;
}