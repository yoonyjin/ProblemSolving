#include <iostream>
#include <vector>
#include <string>

using namespace std;

// �÷��̵�ͼ� �˰���
// �ϳ��� �ִܰŸ� �����ϴ� �˰���
// a, b, c ��ΰ� �ְ�
// a->c : 7, a->b : 2, b->c :3 �̸�
// a->c   �� 5�� ���Ž�Ű�� ���
// �� ���������� a�� b�� �̱��, b�� c�� �̰����� a�� c�� �̱�
int solution(int& n, vector<vector<int>> results)
{
    int answer = 0;
    // 2���� bool �迭 �����
    vector<vector<bool>> graph(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j)
            graph[i][j] = false;
    }

    // �¸��� �ʱ�ȭ
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

    // ��,�� true������ n-1 �϶� ī��Ʈ
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