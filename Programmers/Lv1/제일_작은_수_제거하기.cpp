#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (1 >= arr.capacity())
    {
        answer.push_back(-1);
    }
    else
    {
        answer = arr;
        answer.erase(min_element(answer.begin(), answer.end()));
    }
    return answer;
}

void main() {
    solution({4, 3, 2, 1});
}