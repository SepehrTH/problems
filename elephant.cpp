#include <iostream>

using namespace std;

int main()
{
	int x, step;
	cin >> x;

	for (int i = 5; i >= 1; i--)
	{
		step += x/i;
		x %= i;
	}
/*
	step += x/5;
	x %= 5;

	step += x/4;
	x %= 4;

	step += x/3;
	x %= 3;

	step += x/2;
	x %= 2;

	step += x/1;
*/
	cout << step;


	return 0;
}