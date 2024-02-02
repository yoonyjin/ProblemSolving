#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> lowerVec(26, -1);
    int idx = 0;

    for (int i = 0; i < s.size(); i++)
    {
        idx = s[i] - 97;
        if (-1 == lowerVec[idx])
            answer.push_back(-1);
        else
            answer.push_back(i - lowerVec[idx]);
        lowerVec[idx] = i;
    }
    return answer;
}