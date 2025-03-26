#include <iostream>
using namespace std;

int main()
{
	int N, ans = 0;
	cin >> N;
	// ex) N = 11, ans = 2
	ans += N / 5;
	while (ans >= 0)
	{	
		// (11 - 2*5) %3 == 1
		// (11 - 1*5) %3 == 0
		if ((N - ans * 5) % 3 == 0)
		{
			// 1 + (11 - 1*5) / 3;
			cout << ans + (N - ans * 5) / 3;
			return 0;
		}
		// ans-- : 2 -> 1
		ans--;
	}
	cout << -1;
}