#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

// dfs할 때마다 memset으로 방문여부 초기화해야 하는데
// vector<bool>은 memset 안 돼서 원시배열 사용
int N;
bool visited[101] = { false };  // 방문 여부
bool finished[101] = { false }; // 탐색 완료 여부
int nums[101] = { 0 };
vector<int> path;   // 현재 dfs 경로
set<int> answer;

void dfs(int start) 
{
    // 현재 노드 방문표시하고 경로에 추가
    visited[start] = true;
    path.push_back(start);

    // 다음 노드가 방문 전이면 dfs,
    int next = nums[start];
    if (!visited[next]) 
        dfs(next);

    // 이미 방문했는데 아직 탐색 중이라면 사이클O
    else
    {
        if (!finished[next]) 
        {
            // 사이클 시작~끝 노드를 answer에 추가해줌
            vector<int>::iterator it = find(path.begin(), path.end(), next);
            while (it != path.end()) 
            {
                answer.insert(*it);
                ++it;
            }
        }
    }

    // 현 노드의 dfs 탐색 종료하고 경로에서 삭제
    finished[start] = true;
    path.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        // 첫째 줄 : 인덱스
        // 둘째 줄 : 입력값
        cin >> nums[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        memset(visited, false, sizeof(visited));
        memset(finished, false, sizeof(finished));
        dfs(i);
    }

    cout << answer.size() << '\n';
    for (const int& n : answer)
        cout << n << '\n';


    return 0;
}
