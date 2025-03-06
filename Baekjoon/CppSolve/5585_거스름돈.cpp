#include <iostream>
#include <vector>

// https://www.acmicpc.net/problem/5585

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> yen = { 500, 100, 50, 10, 5, 1 };

	int pay, count = 0;
	cin >> pay;
	pay = 1000 - pay;

	int idx = 0;
	while (0 != pay)
	{
		while (pay < yen[idx])
		{
			idx++;
		}
		pay -= yen[idx];
		count++;
	}

	cout << count;

	return 0;
}