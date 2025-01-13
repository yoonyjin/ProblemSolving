#include <iostream>
#include <vector>

using namespace std;

// n 범위 : 1 ~ 500,000
// 배열의 크기 : 500,000
// 코드1 수행횟수 : 500,000
// n 값이 몇이든 '코드1'은 'n'회 수행함.
// '코드1'의 수행 시간은 'n'(배열 크기, 상수)에 비례함
int MenOfPassion(vector<int>& A, int n) {
    int sum = 0;
    for (int i = 1; i = n; i++)
    {
        sum += A[i]; // 코드1
    }
    return sum;
}

int main()
{
    //vector<int> A(500000, 1);
    int input = 0;
    cin >> input;

    //MenOfPassion(A, input);
    cout << input << "\n" << 1;
    return 0;
}