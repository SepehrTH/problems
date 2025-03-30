#include <iostream>

using namespace std;

int main()
{
	int n, sum;
	cin >> n;
	string p[n];

	for(int i = 0; i < n; i++)
		cin >> p[i];

	sum = 0;
	for(int i = 0; i < n; i++)
	{
		if (p[i] == "Tetrahedron")
			sum += 4;
		else if (p[i] == "Cube")
			sum += 6;
		else if (p[i] == "Octahedron")
			sum += 8;
		else if (p[i] == "Dodecahedron")
			sum += 12;
		else if (p[i] == "Icosahedron")
			sum += 20;
	}

	cout << sum;
	return 0;
}
