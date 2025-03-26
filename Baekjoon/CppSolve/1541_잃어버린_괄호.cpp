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

	/* '-' 가 나오면, 그 뒤 문자를 전부 - 로 바꾸면 최솟값 */
	for (int i = 0; i <= input.size(); ++i)
	{
		// 숫자X
		if ('-' == input[i] || '+' == input[i] || (i == input.size()))
		{
			// 앞에 '-'가 나왔으면 빼주기
			if (IsMinus)
			{
				sum -= stoi(num);
			}
			// '-'가 안 나왔으면 더해주기
			else
			{
				sum += stoi(num);
			}
			num = "";

			if ('-' == input[i])
				IsMinus = true;
		}
		// 숫자O
		else
		{
			num += input[i];
		}
	}

	cout << sum;
	return 0;
}