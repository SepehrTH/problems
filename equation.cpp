#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n)
{
	int m;  
 	m=n/2;  
 	for(int i = 2; i <= m; i++)  
 	{  
    	if(n % i == 0)  
     	{  
        	return false;
    	}  
  	}  

   return true;
}

int main()
{
	int n, a, b;
	bool s = false;
	cin >> n;
	
	a = 4;
	b = a + n;
	while(!s)
	{
		if (!is_prime(a) && !is_prime(b))
			s = true;
		a++;
		b++;
	}
	cout << b - 1 << " " << a - 1;

	return 0;
}