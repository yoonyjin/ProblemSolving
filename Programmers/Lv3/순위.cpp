#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 플로이드와샬 알고리즘
// 하나씩 최단거리 갱신하는 알고리즘
// a, b, c 경로가 있고
// a->c : 7, a->b : 2, b->c :3 이면
// a->c   를 5로 갱신시키는 방식
// 이 문제에서는 a가 b를 이기고, b가 c를 이겼으면 a가 c를 이김
int solution(int& n, vector<vector<int>> results)
{
    int answer = 0;
    // 2차원 bool 배열 만들고
    vector<vector<bool>> graph(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j)
            graph[i][j] = false;
    }

    // 승리로 초기화
    for (int i = 0; i < results.size(); ++i) 
    {
        graph[results[i][0] - 1][results[i][1] - 1] = true;
    }

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            for (int k = 0; k < n; ++k) 
            {
                if (true == graph[j][i] && true == graph[i][k])
                    graph[j][k] = true;
            }
        }
    }

    // 행,열 true개수가 n-1 일때 카운트
    for (int i = 0; i < n; ++i) 
    {
        int count = 0;

        for (int j = 0; j < n; ++j) 
        {
            if (graph[i][j] == true)
                ++count;
            if (graph[j][i] == true)
                ++count;
        }

        if (count == n - 1)
            ++answer;
    }
    return answer;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> Res;
    solution(n, Res);
    return 0;
}