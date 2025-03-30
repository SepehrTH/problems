#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll maxn = 4e4;

int main()
{
    ios_base::sync_with_stdio(0);

    ll n, a, b, c;
	cin >> n >> a >> b >> c;

    ll m = 0;
    for(ll i = 0; i*a <= n; i++)
    {
        for(ll j = 0; j*b <= n; j++)
        {
            ll t = n - i*a - j*b;
            if(t%c == 0 && t > 0)
                m = max(m, t/c +i+j);
            else if(t == 0)
                m = max(m, i+j);
        }
    }

    cout << m;

    return 0;
}