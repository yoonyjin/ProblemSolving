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

    // ���� �� ���� �������� ��ȸ 
    // �� �������� �ݴ�� ��� ���� ���� �������� ��ȸ
    for (int col = 0; col < 15; col++)
    {
        for (int row = 0; row < 5; row++)
        {
            // ���ڿ�ũ�� �ʰ����� ���� ���� == ���� ��ŵ
            if (Vec[row].size() - 1 >= col)
            {
                cout << Vec[row][col];
            }
        }
    }

    return 0;
}