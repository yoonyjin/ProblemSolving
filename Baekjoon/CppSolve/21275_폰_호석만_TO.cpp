#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

//https://www.acmicpc.net/problem/21275
using namespace std;

// �ŵ����� ���� ��ȯ��� )
// : Dn * base^n + Dn-1 * base^n-1 + ... D0 * base^0
// - ���� �ڸ�(����)���� ó��
// - �־� : O(N^2)������ ���� �� ����
// -> ���귮 ����, �ŵ����� ����,

// ���� ���� ��ȯ��� )
// : value = value * base + digit
// - ū �ڸ�(����)���� ó��
// - �־� : O(N)
// -> �ܼ� ����+���� ����, �ŵ����� ��ĺ��� ����

long long ConvertDecimal(const string& str, int base)
{
	long long Value = 0;

	for (const char& c : str)
	{
		// ���ڸ� ���ڷ� ��ȯ
		int Digit = (isdigit(c)) ? (c - '0') : (c - 'a' + 10);
		Value = Value * base + Digit;
	}
	return Value;
}

// 2���� : 0,1
// 10���� : 0~9
// -> ����, ���� �ִ񰪺��� 1 ū ���� ������ �ּ� ����
// ex) �Է°��� 23 : �ִ��� '3', �ּ� 4���� �̻��� ���� �ȴ�

int GetMinBase(const string& str)
{
	char MaxDigit = '0';

	for (const char& c : str)
	{
		// �� ū ���� ������ ����
		if (c > MaxDigit)
			MaxDigit = c;
	}

	// ���� ū ���� ������ ���ڶ��, -'0'�� ���ں�ȯ -> +1�� ���� ��ȯ
	// ���� ū ���� ���ڰ� �ƴ� ���ڶ��, -'a'�� ���ں�ȯ -> +11�� ���� ��ȯ
	// => a~z : 10~35 �̹Ƿ� �ҹ��ڰ� ���Դٸ� 10�� ������� ��
	return (isdigit(MaxDigit)) ? (MaxDigit - '0' + 1) : (MaxDigit - 'a' + 11);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// (X, A, B) �� 
	// ������ ���� �� ����	X, A, B		���
	// ������ ���� ��������	Multiple	���
	// ������ ������ ���ٸ�	Impossible	���

	// X(10����), A, B
	// XA (X->A����)
	// XB (X->B����)
	long long X = 0;
	string s_XA, s_XB;
	
	// AValue (X��, {����, ī��Ʈ})
	unordered_map<long long, vector<int>> AValue;
	// Answer {A����, B����}
	vector<pair<int, int>> Answer;

	cin >> s_XA >> s_XB;
	// 2 <= n <= 36
	// s_XA, s_XB�� (n->10) ��ȯ��Ų ���� ��ġ�ϴ� ��� ã��
	
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