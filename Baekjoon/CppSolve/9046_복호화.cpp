#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
// 250211 윤여진
// 입력 : 테스트케이스 수 T (1 <= T <= 20)
// 출력 : 각 테스트케이스별 결과
// ? : 소문자만인건지 대문자 포함인건지 모르겠음

// 알파벳 a ~ z : 아스키코드 97 ~ 122
//using namespace std;
using std::cin;
using std::cout;
using std::string;

int main()
{
	int T;
	string Problem[20];
	cin >> T;
	// 개행문자 제거
	// 이거 안 했더니 테스트케이스별 문자열 입력받을때 1회를 개행문자로 처리해버림
	cin.ignore();
	
	for (int i = 0; i < T; i++)
	{
		string Problem;
		getline(cin, Problem);
		int alphabets[26] = { 0 };
		int MaxCount = 0;
		char MaxChar = '?';
		bool IsUnique = true;

		for (char C : Problem)
		{
			if (isalpha(C))
			{
				// 대문자라면 소문자로 변환 후 인덱스 계산함
				int idx = tolower(C) - 'a';
				if (0 <= idx && idx < 26)
				{
					alphabets[idx]++;

					if (alphabets[idx] > MaxCount)
					{
						MaxCount = alphabets[idx];
						MaxChar = 'a' + idx;
						IsUnique = true;
					}
					else if (alphabets[idx] == MaxCount)
					{
						IsUnique = false;
					}
				}
			}
		}

		if (IsUnique)
			cout << MaxChar;
		else
			cout << "?";
		cout << '\n';
	}
	return 0;
}