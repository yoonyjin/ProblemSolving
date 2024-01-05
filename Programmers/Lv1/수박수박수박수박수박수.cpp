#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while (1 < n) {
        answer += "수박";
        n -= 2;
    }
    if (1 == n) // n이 홀수
    {
        answer += "수";
    }
    return answer;
}