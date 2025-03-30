#include <bits/stdc++.h>

using namespace std;

int main()
{
	
	int a, b, c, m;
	cin >> a >> b >> c;

	m = min(a, min(b/2,c/4));
	cout << m + 2*m + 4*m;

	return 0;
}
