#include <iostream>
#include <string>

// 250210 ������
// ���� : 0~9
// �Է� : ���� N��
// ��� : N���� ������ ��

// ���� 0 ~ 9 : �ƽ�Ű�ڵ� 48 ~ 57 �̹Ƿ� 0(==48) ���༭ ������ȯ
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