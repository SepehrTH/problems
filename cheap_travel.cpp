#include <iostream>

using namespace std;

int main()
{
	int n, m, a, b, sum = 0;
	cin >> n >> m >> a >> b;

	if (m * a <= b)
        cout << n * a;
    else
        cout << (n/m) * b + min((n%m) * a, b);     // check mikonim bebinim ke age arzoontare ye speacial begirim


	return 0;
}
