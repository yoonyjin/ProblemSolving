#include <iostream>
#include <vector>

using namespace std;

// 입력값 n을 통해 i 를 구한 후, 배열 A의 i번째 원소를 반환
// n은 1~500,000 사이 수.
// n 값이 몇이든 '코드1'은 '항상 1회'만 출력됨
// 따라서 시간복잡도 O(1), 수행 시 최고차항의 차수는 '항상 0'

int MenOfPassion(vector<int>& A, int N) {
    int i = N / 2;
    return A[i]; // 코드1
}

int main()
{
    vector<int> A(500000, 1);

    int input = 0;
    cin >> input;

    MenOfPassion(A, input); // 이걸 몇번 하든 출력값은 똑같음

    cout << 1 << "\n" << 0;

    return 0;
}