#include <string>
#include <vector>

#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int width = 0, length = 0;
    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1])
            swap(sizes[i][0], sizes[i][1]);
        // 처음 풀이
        if (width < sizes[i][0])
            width = sizes[i][0];
        if (length < sizes[i][1])
            length = sizes[i][1];
    }
    answer = width * length;
    return answer;
}

void main() {
    solution({ {60, 50}, {30, 70}, {60, 30}, {80, 40} });
}