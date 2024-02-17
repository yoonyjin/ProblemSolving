#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer, tmp;
    int i, j, k;

    for (auto& count : commands) {
        i = count[0] - 1;
        j = count[1] - 1;
        k = count[2] - 1;
        tmp.assign(array.begin() + i, array.begin() + j + 1);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k]);
    }
    return answer;
}