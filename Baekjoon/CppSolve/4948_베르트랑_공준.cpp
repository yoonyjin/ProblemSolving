#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N;
	int count = 0;
	bool arr[246913] = { 0 };
	arr[0] = arr[1] = 1; // 0, 1Àº ¼Ò¼ö ¾Æ´Ô

	while (1)
	{
		cin >> N;
		if (!N)
			break;
		for (int j = 2; j <= sqrt(2 * N); j++)
		{
			if (arr[j] == 1)
				continue;
			for (int k = 2; k * j <= 2 * N; k++)
				arr[k * j] = 1;
		}

		for (int i = N + 1; i <= 2 * N; i++)
		{
			if (arr[i] != 1)
				count++;
		}
		cout << count << "\n";
		count = 0;
	}
}