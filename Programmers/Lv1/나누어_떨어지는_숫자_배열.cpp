#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++)
    {
        if (0 == arr[i] % divisor)
        {
            answer.push_back(arr[i]);
        }
    }
    
    if (answer.empty())
    {
        answer.push_back(-1);
    }
    sort(answer.begin(), answer.end());
    
    return answer;

    // 다른 풀이 참고
// -1로 1개의 원소를 초기화한 벡터 임시객체를 리턴
// return answer.empty() ? vector<int>(1, -1) : answer;
}