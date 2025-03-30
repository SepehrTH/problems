#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int n, m;

	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	cin >> m;
	int b[m];
	for(int i = 0; i < m; i++)
		cin >> b[i];

	sort(a, a+n);
	sort(b, b+m);

	int minmn = min(m, n);
	
	int counter = 0;

	if(n == minmn)
	{
		for(int i = 0; i < minmn; i++)
		{
			int tmp = a[i];
			for(int j = 0; j < m; j++)
			{
				if(abs(b[j] - a[i]) == 1 || b[j] == a[i])
				{
					counter++;
					b[j] = -5;
					a[i] = -5;
					break;
				}
			}
		}
	}

	else if(m == minmn)
	{
		for(int i = 0; i < minmn; i++)
		{
			int tmp = b[i];
			for(int j = 0; j < n; j++)
			{
				if(abs(b[i] - a[j]) == 1 || b[i] == a[j])
				{
					counter++;
					a[j] = -5;
					b[i] = -5;
					break;
				}
			}
		}
	}

	cout << counter;

	return 0;
}