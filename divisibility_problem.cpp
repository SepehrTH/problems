#include <iostream>

using namespace std;

int main()
{
	int t, a, b, tmp;
	cin >> t;

	while(t > 0)
	{
		cin >> a >> b;

		if (a % b == 0)
			cout << 0 << endl;

		else
		{
			tmp = (a/b + 1) * b;
			cout << tmp - a << endl;
		}
		t--;
	}

	return 0;
}