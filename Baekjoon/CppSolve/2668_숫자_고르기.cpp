#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

// dfs�� ������ memset���� �湮���� �ʱ�ȭ�ؾ� �ϴµ�
// vector<bool>�� memset �� �ż� ���ù迭 ���
int N;
bool visited[101] = { false };  // �湮 ����
bool finished[101] = { false }; // Ž�� �Ϸ� ����
int nums[101] = { 0 };
vector<int> path;   // ���� dfs ���
set<int> answer;

void dfs(int start) 
{
    // ���� ��� �湮ǥ���ϰ� ��ο� �߰�
    visited[start] = true;
    path.push_back(start);

    // ���� ��尡 �湮 ���̸� dfs,
    int next = nums[start];
    if (!visited[next]) 
        dfs(next);

    // �̹� �湮�ߴµ� ���� Ž�� ���̶�� ����ŬO
    else
    {
        if (!finished[next]) 
        {
            // ����Ŭ ����~�� ��带 answer�� �߰�����
            vector<int>::iterator it = find(path.begin(), path.end(), next);
            while (it != path.end()) 
            {
                answer.insert(*it);
                ++it;
            }
        }
    }

    // �� ����� dfs Ž�� �����ϰ� ��ο��� ����
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
        // ù° �� : �ε���
        // ��° �� : �Է°�
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
