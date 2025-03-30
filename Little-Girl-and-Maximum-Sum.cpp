#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAXN = 2e5 + 5;
ll n, q, l, r, sum;
ll a[MAXN], a2[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	cin >> n >> q;
	for(ll i = 0; i < n; ++i)
		cin >> a[i];
	
	sort(a, a+n);
	
	for(ll i = 0; i < q; ++i) {
		cin >> l >> r;
		a2[l-1]++;
		a2[r]--;
	}
	
	for(ll tmp, s = 0, i = 0; i <= n; ++i) {
		tmp = a2[i];
		a2[i]+=s;
		s+=tmp;
	}
	sort(a2, a2+n);
	
	sum = 0;
	for(ll i = n-1; i >= 0; --i){
		sum += (a[i]*a2[i]);
	}
	cout << sum;
	
	return 0;
}