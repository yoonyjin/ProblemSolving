#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    int remain;

    while (n >= 10)
    {
        remain = n % 10;
        answer.push_back(remain);
        n /= 10;
    }
    answer.push_back(n);
    return answer;
}