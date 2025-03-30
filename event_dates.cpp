#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<pair<ll, ll>, ll> p[101];
int used[10000007];
int ans[101];

int main()
{
    int n;
    ll r, l;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> r >> l;
        p[i].first.first = r;
        p[i].first.second = l;
        p[i].second = i;
    }

    sort(p, p+n);

    for(ll i = n-1; i >= 0; i--)
    {
        for(ll j = p[i].first.second; j >= p[i].first.first; j--)
        {
            if(used[j] == 0)
            {
                // cout << "yes" << endl;
                used[j] = 1;
                ans[p[i].second] = j;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}