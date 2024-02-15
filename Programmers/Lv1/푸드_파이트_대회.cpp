#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string first = "";
    for (int i = 1; i < food.size(); i++)
    {
        if (1 == food[i] % 2)
            food[i]--;
        first.append((food[i] / 2), i + '0');
    }
    answer = first + '0';
    reverse(first.begin(), first.end());
    answer += first;
    return answer;
}