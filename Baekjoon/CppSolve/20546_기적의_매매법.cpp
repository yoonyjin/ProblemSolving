#include <iostream>

struct Who
{
	int Money = 0;
	int BuyQuantity = 0;
};

void Buy(Who& who, const int& price)
{
	// �������� ����
	if (who.Money < price) return;

	int PlusQuantity = (who.Money / price);
	who.BuyQuantity += PlusQuantity;
	who.Money -= (PlusQuantity * price);
}

void Sell(Who& who, const int& price)
{
	// �� �� ������ ����
	if (who.BuyQuantity == 0) return;

	int PriceReturn = (who.BuyQuantity * price);
	who.BuyQuantity = 0;
	who.Money += PriceReturn;
}

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	Who JH;
	Who SM;

	int Money = 0;
	cin >> Money;
	JH.Money = Money;
	SM.Money = Money;
	
	int UpStack = 0, DownStack = 0;
	int YesterDay = 0, Today = 0;
	
	// 2�ְ��� �ְ� (14��)
	for (int i = 0; i < 14; i++)
	{
		cin >> Today;
		
		// 2�������� ������
		if (1 <= i)
		{
			if (YesterDay > Today)
			{
				UpStack = 0;
				DownStack++;
			}
			else if (YesterDay < Today)
			{
				DownStack = 0;
				UpStack++;
			}
		}

		// ���� : Money�� Price���� ���ų� Ŀ���� ���� �����ż�
		if (JH.Money >= Today)
		{
			Buy(JH, Today);
		}

		// ���� : 33 �ŸŹ�, 
		// 3�� ���� ��� �� 3������ �����ŵ�
		// 3�� ���� �϶� �� 3���� �����ż�
		// 4�� �̻� ���/�϶��� ���ɼ��� ����ϱ�
		if (3 <= UpStack)
			 Sell(SM, Today);

		else if (3 <= DownStack)
			Buy(SM, Today);

		// �ŷ� �������� ������������ ����
		YesterDay = Today;
	}

	// ���� WIN	
	if (JH.Money + Today * JH.BuyQuantity
			> SM.Money + Today * SM.BuyQuantity)
		cout << "BNP";

	// ���� WIN
	else if (JH.Money + Today * JH.BuyQuantity
		< SM.Money + Today * SM.BuyQuantity)
		cout << "TIMING";

	else
		cout << "SAMESAME";

	return 0;
}