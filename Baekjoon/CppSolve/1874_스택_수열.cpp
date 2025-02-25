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
        // 입력 : 3, 2 1 3
        // '1' < 2 -> '+'

        // 현재 가리키는 값이, 입력받은 값보다 작거나 같으면
        // 스택에 현재값 집어넣고, 현재값 +1 업데이트
        while (CurNum <= Num)
        {
            Nums.push(CurNum);
            Cals.push_back('+');
            CurNum++;
        }

        // 스택 맨 위의 값이 입력받은 값과 같다면 pop
        if (Nums.top() == Num)
        {
            Nums.pop();
            Cals.push_back('-');
        }
        // 스택 맨 위의 값이 입력값보다 작으면 리턴(오름차순 지켜야돼서)
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