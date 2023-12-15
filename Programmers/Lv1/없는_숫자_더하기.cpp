#include <string>
#include <vector>
#include <algorithm>

// 주석 : 새 풀이
// 특정 배열 혹은 컨테이너의 누적 합 구하는 accumulate 함수 포함된 라이브러리
 //#include <numeric>

using namespace std;

//int solution(vector<int> numbers) {
//    return 45 - accumulate(numbers.begin(), numbers.end(), 0);
//}

// 처음 풀이
int solution(vector<int> numbers) {
    int answer = 0;
    vector<int>::iterator iter;
    iter = numbers.begin();

    sort(numbers.begin(), numbers.end());
    for (int i = 0; i <= 9; i++)
    {
        if (i != *iter)
        {
            answer += i;
            continue;
        }
        if (iter != numbers.end() - 1)
        {
            iter++;
        }
    }
    return answer;
}