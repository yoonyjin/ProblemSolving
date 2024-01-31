#include <string>
#include <vector>

#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int width = 0, height = 0;
    for (int i = 0; i < sizes.size(); i++)
    {
        // 처음 풀이
        //if (sizes[i][0] < sizes[i][1])
        //    swap(sizes[i][0], sizes[i][1]);
        //if (width < sizes[i][0])
        //    width = sizes[i][0];
        //if (height < sizes[i][1])
        //    height = sizes[i][1];

        // max() 활용
        width = max(width, min(sizes[i][0], sizes[i][1]));
        height = max(height, max(sizes[i][0], sizes[i][1]));
    }
    return width * height;
}