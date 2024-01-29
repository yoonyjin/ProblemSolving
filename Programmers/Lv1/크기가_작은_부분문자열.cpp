#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    string sub;
    for (int i = 0; i < t.size() - p.size() + 1; i++)
    {
        sub = t.substr(i, p.size());
        if (p >= sub)
            answer++;
    }
    return answer;
}