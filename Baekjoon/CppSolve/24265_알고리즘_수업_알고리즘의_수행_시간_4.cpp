#include <iostream>
#include <vector>

using namespace std;

// ���ÿ�
// n * n = n^2 �̹Ƿ� �ְ������� ������ 2�� ��

long long MenOfPassion(vector<int>& A, int n)
{
	long long sum = 0;
	
	// i ���� : 1 ~ (n-1) (== �迭ũ�Ⱑ n)
	// ����Ƚ�� : i 1�϶� -> j 6��, 2�϶� 5��, 3�϶� 4�� .... 6�϶� 1��. 
	// => 1���� n-1 ������ �� : n-1 * (1 + n-1)/2 = (n * n-1)/2 (n:7�� ��� '�� 21��' ����) 
	// ������ �ְ������� 2��
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			sum += (A[i] * A[j]); // �ڵ� 1;
		}
	}
	cout << "sum : " << sum << "\n";
	return sum;
}

int main()
{
	long long input = 0;
	vector<int> arr(500000, 1);
	cin >> input;

	//MenOfPassion(arr, 500000);
	cout << input * (input -1) / 2 << "\n" << 2;
	return 0;
}