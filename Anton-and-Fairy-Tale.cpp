#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    ll val;
    
    if(n <= m) {
        cout << n;
        return 0;
    }
    
    ll l = 0, r = 2e9;
    ll av, s;
    s = m+1;
    n-=m;
    while(l < r) {
        av = (l+r)/2;
        val = av*(av+1)/2;
        if(val >= n)  r = av;
        else  l = av+1;
    }
    cout << l+m;

    return 0;
}
