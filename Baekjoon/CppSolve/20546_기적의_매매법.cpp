#include <iostream>

struct Who
{
	int Money = 0;
	int BuyQuantity = 0;
};

void Buy(Who& who, const int& price)
{
	// 돈없으면 리턴
	if (who.Money < price) return;

	int PlusQuantity = (who.Money / price);
	who.BuyQuantity += PlusQuantity;
	who.Money -= (PlusQuantity * price);
}

void Sell(Who& who, const int& price)
{
	// 팔 게 없으면 리턴
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
	
	// 2주간의 주가 (14일)
	for (int i = 0; i < 14; i++)
	{
		cin >> Today;
		
		// 2일차부터 계산시작
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

		// 준현 : Money가 Price보다 같거나 커지는 순간 전량매수
		if (JH.Money >= Today)
		{
			Buy(JH, Today);
		}

		// 성민 : 33 매매법, 
		// 3일 연속 상승 시 3일차에 전량매도
		// 3일 연속 하락 시 3일차 전량매수
		// 4일 이상 상승/하락할 가능성도 고려하기
		if (3 <= UpStack)
			 Sell(SM, Today);

		else if (3 <= DownStack)
			Buy(SM, Today);

		// 거래 끝났으면 어제가격으로 대입
		YesterDay = Today;
	}

	// 준현 WIN	
	if (JH.Money + Today * JH.BuyQuantity
			> SM.Money + Today * SM.BuyQuantity)
		cout << "BNP";

	// 성민 WIN
	else if (JH.Money + Today * JH.BuyQuantity
		< SM.Money + Today * SM.BuyQuantity)
		cout << "TIMING";

	else
		cout << "SAMESAME";

	return 0;
}