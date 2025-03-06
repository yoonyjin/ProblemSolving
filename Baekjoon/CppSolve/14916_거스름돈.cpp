#include <iostream>

// https://www.acmicpc.net/problem/14916

using namespace std;

int Change(int n)
{
	int Count = 0;
	while (1 < n)
	{
		if (5 <= n)
		{
			Count = n / 5;
			n %= 5;

			if (0 != n % 2)
			{
				n += 5;
				Count--;
			}
		}

		if (2 <= n)
		{
			Count += n / 2;
			n %= 2;
		}
	}

	if (0 == n)
		return Count;
	else
		return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	cout << Change(n);

	return 0;
}