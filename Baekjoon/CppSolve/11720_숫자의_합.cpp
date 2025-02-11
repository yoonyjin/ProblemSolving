#include <iostream>
#include <string>

// 250210 윤여진
// 숫자 : 0~9
// 입력 : 숫자 N개
// 출력 : N개의 숫자의 합

// 숫자 0 ~ 9 : 아스키코드 48 ~ 57 이므로 0(==48) 빼줘서 정수변환
using std::cout;
using std::string;

int main()
{
	int N = 0, Sum = 0;
	std::string Nums;
	std::cin >> N;
	std::cin >> Nums;

	for (int i = 0; i < N; i++)
	{
		Sum += (Nums[i] - '0');
	}
	cout << Sum;

	return 0;
}