#include <iostream>
#include <vector>

using namespace std;

// 예시용
// n * n = n^2 이므로 최고차항의 차수는 2가 됨

long long MenOfPassion(vector<int>& A, int n)
{
	long long sum = 0;
	
	// i 범위 : 1 ~ (n-1) (== 배열크기가 n)
	// 수행횟수 : i 1일때 -> j 6번, 2일때 5번, 3일때 4번 .... 6일때 1번. 
	// => 1부터 n-1 까지의 합 : n-1 * (1 + n-1)/2 = (n * n-1)/2 (n:7일 경우 '총 21번' 수행) 
	// 어차피 최고차항은 2임
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			sum += (A[i] * A[j]); // 코드 1;
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