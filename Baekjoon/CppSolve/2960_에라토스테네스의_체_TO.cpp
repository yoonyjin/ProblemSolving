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

    // map 삭제 O(logN)
    // list 삭제 O(1) <--
    list<int> Nums;
    int Count = 0;      // 삭제된 숫자 개수
    int DeleteNum = 0;  // 마지막으로 삭제된 값

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
        //iter가 가리키는 값 삭제하고, 그 다음 값을 가리키게 함
        iter = Nums.erase(iter);
        ++Count;

        if (Count == K) // K번째 삭제된 숫자라면 출력 후 종료
        {
            cout << DeleteNum;
            return 0;
        }

        // iter 값 erase 이후 시점에 Deliter 정의
        list<int>::iterator DelIter = iter;
        while (DelIter != Nums.end())
        {
            // 맨 앞 소수와 그 배수들을 삭제
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