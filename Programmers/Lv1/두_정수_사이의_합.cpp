#include <string>
#include <vector>

using namespace std;

//// 맨 처음 풀이
//long long solution(int a, int b) {
//    long long answer = 0;
//    
//    int A = a < b ? a : b;
//    int B = a < b ? b : a;
//
//    for (int i = A; i <= B; i++)
//    {
//        answer += i;
//    }
//    return answer;
//}

// 가우스 덧셈 공식 활용
// (수의 개수) * (처음 수 + 마지막 수) /2
long long solution(int a, int b) {
	return (long long)(a + b) * (abs(a - b) + 1) / 2;
}