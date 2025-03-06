#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

//https://www.acmicpc.net/problem/21275
using namespace std;

// 거듭제곱 진법 변환방식 )
// : Dn * base^n + Dn-1 * base^n-1 + ... D0 * base^0
// - 작은 자리(우측)부터 처리
// - 최악 : O(N^2)까지도 나올 수 있음
// -> 연산량 증가, 거듭제곱 연산,

// 누적 진법 변환방식 )
// : value = value * base + digit
// - 큰 자리(왼쪽)부터 처리
// - 최악 : O(N)
// -> 단순 곱셈+덧셈 연산, 거듭제곱 방식보다 빠름

long long ConvertDecimal(const string& str, int base)
{
	long long Value = 0;

	for (const char& c : str)
	{
		// 문자를 숫자로 변환
		int Digit = (isdigit(c)) ? (c - '0') : (c - 'a' + 10);
		Value = Value * base + Digit;
	}
	return Value;
}

// 2진수 : 0,1
// 10진수 : 0~9
// -> 따라서, 구한 최댓값보다 1 큰 값이 가능한 최소 진법
// ex) 입력값이 23 : 최댓값이 '3', 최소 4진법 이상인 수가 된다

int GetMinBase(const string& str)
{
	char MaxDigit = '0';

	for (const char& c : str)
	{
		// 더 큰 값이 나오면 대입
		if (c > MaxDigit)
			MaxDigit = c;
	}

	// 가장 큰 값이 숫자인 문자라면, -'0'로 숫자변환 -> +1한 진법 반환
	// 가장 큰 값이 숫자가 아닌 문자라면, -'a'로 숫자변환 -> +11한 진법 반환
	// => a~z : 10~35 이므로 소문자가 나왔다면 10을 더해줘야 함
	return (isdigit(MaxDigit)) ? (MaxDigit - '0' + 1) : (MaxDigit - 'a' + 11);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// (X, A, B) 로 
	// 가능한 조합 한 개면	X, A, B		출력
	// 가능한 조합 여러개면	Multiple	출력
	// 가능한 조합이 없다면	Impossible	출력

	// X(10진수), A, B
	// XA (X->A진법)
	// XB (X->B진법)
	long long X = 0;
	string s_XA, s_XB;
	
	// AValue (X값, {진법, 카운트})
	unordered_map<long long, vector<int>> AValue;
	// Answer {A진법, B진법}
	vector<pair<int, int>> Answer;

	cin >> s_XA >> s_XB;
	// 2 <= n <= 36
	// s_XA, s_XB를 (n->10) 변환시킨 값이 일치하는 경우 찾기
	
	for (int ABase = GetMinBase(s_XA); ABase <= 36; ABase++)
	{
		long long CalX = ConvertDecimal(s_XA, ABase);

		AValue[CalX].push_back(ABase);
	}

	for (int BBase = GetMinBase(s_XB); BBase <= 36; BBase++)
	{
		long long CalX = ConvertDecimal(s_XB, BBase);

		if (AValue.count(CalX))
		{
			for (int ABase : AValue[CalX])
			{
				if (ABase == BBase) continue;
				Answer.push_back({ ABase, BBase });
				X = CalX;
			}
		}
	}

	if (Answer.empty())
		cout << "Impossible";

	else if (Answer.size() > 1)
		cout << "Multiple";
	
	else
		cout << X << " " << Answer[0].first << " " << Answer[0].second;

	return 0;
}