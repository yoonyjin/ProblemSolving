#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> Vec;
    string str = "";

    for (int i = 0; i < 5; i++)
    {
        cin >> str;
        Vec.push_back(str);
    }

    // 보통 각 행을 기준으로 순회 
    // 이 문제에선 반대로 모든 행의 열을 기준으로 순회
    for (int col = 0; col < 15; col++)
    {
        for (int row = 0; row < 5; row++)
        {
            // 문자열크기 초과범위 접근 방지 == 공백 스킵
            if (Vec[row].size() - 1 >= col)
            {
                cout << Vec[row][col];
            }
        }
    }

    return 0;
}