#include <iostream>
#include <list>

// https://www.acmicpc.net/problem/2960
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    // map ���� O(logN)
    // list ���� O(1) <--
    list<int> Nums;
    int Count = 0;      // ������ ���� ����
    int DeleteNum = 0;  // ���������� ������ ��

    for (int i = 2; i <= N; i++)
    {
        Nums.push_back(i);
    }

    //for (list<int>::iterator iter = Nums.begin(); iter != Nums.end(); iter++)
  
    while (!Nums.empty())
    {
        list<int>::iterator iter = Nums.begin();
        int Prime = *iter;
    
        DeleteNum = *iter;
        //iter�� ����Ű�� �� �����ϰ�, �� ���� ���� ����Ű�� ��
        iter = Nums.erase(iter);
        ++Count;

        if (Count == K) // K��° ������ ���ڶ�� ��� �� ����
        {
            cout << DeleteNum;
            return 0;
        }

        // iter �� erase ���� ������ Deliter ����
        list<int>::iterator DelIter = iter;
        while (DelIter != Nums.end())
        {
            // �� �� �Ҽ��� �� ������� ����
            if (0 == *DelIter % Prime)
            {
                DeleteNum = *DelIter;
                DelIter = Nums.erase(DelIter);
                ++Count;

                if (K == Count)
                {
                    cout << DeleteNum;
                    return 0;
                }
            }
            else
            {
                ++DelIter;
            }
        }
    }

    cout << DeleteNum;

    return 0;
}