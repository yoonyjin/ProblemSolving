#include <iostream>

using namespace std;

int main()
{
	int N, M;
	int arr[101] = { 0 };
	cin >> N >> M;
	while (M--)
	{
		int i, j, k;
		cin >> i >> j >> k;
		for (int n = i; n <= j; n++)
			arr[n] = k;
	}
	for (int i = 1; i <= N; i++)
		cout << arr[i] << " ";
}