#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string input = "";
	cin >> input;
	bool IsMinus = false;
	int sum = 0;
	string num = "";

	/* '-' �� ������, �� �� ���ڸ� ���� - �� �ٲٸ� �ּڰ� */
	for (int i = 0; i <= input.size(); ++i)
	{
		// ����X
		if ('-' == input[i] || '+' == input[i] || (i == input.size()))
		{
			// �տ� '-'�� �������� ���ֱ�
			if (IsMinus)
			{
				sum -= stoi(num);
			}
			// '-'�� �� �������� �����ֱ�
			else
			{
				sum += stoi(num);
			}
			num = "";

			if ('-' == input[i])
				IsMinus = true;
		}
		// ����O
		else
		{
			num += input[i];
		}
	}

	cout << sum;
	return 0;
}