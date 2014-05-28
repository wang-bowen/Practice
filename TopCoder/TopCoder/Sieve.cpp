#include <iostream>
#include <fstream>

using namespace std;

bool* sieve(int n)
{
	//n is the largest number; 
	//the array will be n+1 size from 0 to n.
	bool *prime = new bool[n + 1];
	for (int k = 0; k < n + 1; k++)*(prime + k) = true;
	prime[0] = false;
	prime[1] = false;
	int m = sqrt(n);

	for (int k = 2; k <= m; k++)
	{
		if (!prime[k])continue;
		for (int j = k*k; j <= n; j += k)
		{
			prime[j] = false;
		}

	}

	return prime;
	//returns a boolean array from 0-n; true if prime.
}

int main()
{
	int n;
	cin >> n;
	bool *b = sieve(n);
	ofstream out;
	out.open("primes.txt");

	for (int k = 0; k <= n; k++)
	{
		out << k << " is " << (b[k] ? "prime" : "not prime") << ".\n";
	}
	out.close();

	delete[] b;
	return 0;
}

