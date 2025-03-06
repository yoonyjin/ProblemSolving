#include <iostream>
#include <vector>
// https://www.acmicpc.net/problem/21920
using namespace std;

int Gcd(int a, int b)
{
	if (b == 0) return a;
	return Gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 2 <= N <= 500,000
	// 2 <= X <= 1,000,000
	int N, X;
	cin >> N;
	vector<int> Vec;
	vector<int> Disjoint;

	for (int i = 0; i < N; i++)
	{
		// 2 <= num <= 1,000,000
		int num;
		cin >> num;
		Vec.push_back(num);
	}

	cin >> X;
	
	double Count = 0, Sum = 0;

	for (const int& n : Vec)
	{
		if (1 == Gcd(X, n))
		{
			Count++;
			Sum += n;
		}
	}

	/* ����/��� ������ 10-6���� ����Ѵ�. */
	/* �� �Ҽ��� 6��° �ڸ����� ����ؾ� �� */
	cout << fixed;
	cout.precision(6);
	cout << Sum / Count;

	return 0;
}