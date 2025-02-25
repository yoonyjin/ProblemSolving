#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<char> Cals;
    stack<int> Nums;
    int n = 0, CurNum = 1;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int Num;
        cin >> Num;
        
        // ex) '1' 2 3
        // �Է� : 3, 2 1 3
        // '1' < 2 -> '+'

        // ���� ����Ű�� ����, �Է¹��� ������ �۰ų� ������
        // ���ÿ� ���簪 ����ְ�, ���簪 +1 ������Ʈ
        while (CurNum <= Num)
        {
            Nums.push(CurNum);
            Cals.push_back('+');
            CurNum++;
        }

        // ���� �� ���� ���� �Է¹��� ���� ���ٸ� pop
        if (Nums.top() == Num)
        {
            Nums.pop();
            Cals.push_back('-');
        }
        // ���� �� ���� ���� �Է°����� ������ ����(�������� ���Ѿߵż�)
        else
        {
            cout << "NO";
            return 0;
        }
    }

    for (const char& c : Cals)
    {
        cout << c << "\n";
    }
    return 0;
}