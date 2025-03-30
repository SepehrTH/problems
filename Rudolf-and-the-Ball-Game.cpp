#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int maxn = 1005;
ll t, n, m, x, r[maxn];
char c[maxn];
set<ll> val;
set<ll> v;

void solve()
{
    val.clear();
    cin >> n >> m >> x;
    cin >> r[0] >> c[0];
    
    if(c[0] == '0') val.insert((x+r[0]-1)%n+1);
    else if(c[0] == '1') val.insert((x + (n+(-1*r[0]))-1)%n+1);
    else if(c[0] == '?') {
        val.insert((x + r[0]-1)%n+1);
        val.insert((x + (n + (-1*r[0]))-1)%n+1);
    }
    
    for(ll i = 1; i < m; i++) {
        cin >> r[i] >> c[i];
        v.clear();
        for(ll u : val) {
            if(c[i] == '0') v.insert((u+r[i]-1)%n+1);
            else if(c[i] == '1') v.insert((u + n + (-1*r[i])-1)%n+1);
            else if(c[i] == '?') {
                v.insert((u+r[i]-1)%n+1);
                v.insert((u + n + (-1*r[i])-1)%n+1);
            }
        }
        val.clear();
        for(ll u: v) {
            if(u == 0)  val.insert(n);
            else  val.insert(u);
        }
    }
    cout << val.size() << "\n";
    for(ll u: val) {
        if(u==0)  cout << n << " ";
        else cout << u << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
