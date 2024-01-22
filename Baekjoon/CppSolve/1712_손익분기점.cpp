#include <iostream>
using namespace std;

int main(void) {

	int A = 0; //고정비용
	int B = 0; //가변비용
	int C = 0; //노트북 가격
	int BEP = 0; //손익분기점, 총 수입>총 비용 지점

	cin >> A >> B >> C;
	if (B >= C)
	{
		cout << "-1";
	}
	else
	{
		BEP = A / (C - B) + 1;
		cout << BEP;
	}
}