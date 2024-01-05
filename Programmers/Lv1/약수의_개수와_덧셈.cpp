#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int count = left;
    int n = 0; //제곱근
    vector<int> vec;
    while (count <= right)
    {
        n = sqrt(count);
        for (int i = 1; i <= n; i++)
        {
            if (0 == count % i)
            {
                vec.push_back(i);
                vec.push_back(count / i);
            }
        }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    if (0 == vec.size() % 2) // 약수 개수가 짝수면 더하고
    {
        answer += count;
    }
    else // 홀수면 뺀다
    {
        answer -= count;
    }
    vec.clear();
    count++;
    }
    return answer;
}

void main() {
    cout << solution(10, 15);
}