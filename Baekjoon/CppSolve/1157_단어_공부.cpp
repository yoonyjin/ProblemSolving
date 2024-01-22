#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int alpabet[26] = { 0 };
	int max = 0, index = 0, count = 0;
	string S;

	cin >> S;
	//카운팅
	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] < 97)
			alpabet[S[i] - 65]++; //대문자
		else
			alpabet[S[i] - 97]++; //소문자
	}

	//가장 많이 사용한 알파벳 알아내기
	for (int i = 0; i < 26; i++)
	{
		if (max < alpabet[i])
		{
			max = alpabet[i];
			index = i;
		}
	}

	//? 혹은 최대 사용 알파벳 출력
	for (int i = 0; i < 26; i++)
	{
		if (max == alpabet[i]) count++;
	}
	if (count > 1) cout << "?";
	else cout << (char)(index + 65);
}