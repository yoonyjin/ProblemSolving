#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	bool arr[10001] = { 0 };
	int T, N;

	cin >> T;
	for (int c = 0; c < T; c++)
	{
		cin >> N;
		for (int j = 2; j <= sqrt(N); j++)
		{
			if (arr[j] != 1)
				for (int k = 2; k * j <= N; k++)
					arr[k * j] = 1;
		}

		for (int i = N / 2; i > 1; i--)
		{
			if (!arr[i] && !arr[N - i])
			{
				cout << i << " " << N - i << "\n";
				break;
			}
		}
	}
}