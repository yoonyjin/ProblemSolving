#include <iostream>
#include <vector>

using namespace std;

// ���ÿ�
// n * n = n^2 �̹Ƿ� �ְ������� ������ 2�� ��
int MenOfPassion(vector<int>& A, int n)
{
	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum += (A[i] * A[j]); // �ڵ� 1;
		}
	}
	cout << "sum : " << sum << "\n";
	return sum;
}

int main()
{
	// 500,000�� ������ 2500���̹Ƿ� int �ڷ����� ������ ���.
	// ���� int�� �ƴ� long long ���� ��������
	//int input = 0;
	long long input = 0;
	vector<int> arr(500000, 1);
	cin >> input;

	//MenOfPassion(arr, 500000);
	cout << input * input << "\n" << 2;
	return 0;
}