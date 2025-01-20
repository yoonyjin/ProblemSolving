#include <iostream>
#include <vector>

using namespace std;

// 예시용
// n * n = n^2 이므로 최고차항의 차수는 2가 됨
int MenOfPassion(vector<int>& A, int n)
{
	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum += (A[i] * A[j]); // 코드 1;
		}
	}
	cout << "sum : " << sum << "\n";
	return sum;
}

int main()
{
	// 500,000의 제곱은 2500억이므로 int 자료형의 범위를 벗어남.
	// 따라서 int가 아닌 long long 으로 선언하자
	//int input = 0;
	long long input = 0;
	vector<int> arr(500000, 1);
	cin >> input;

	//MenOfPassion(arr, 500000);
	cout << input * input << "\n" << 2;
	return 0;
}