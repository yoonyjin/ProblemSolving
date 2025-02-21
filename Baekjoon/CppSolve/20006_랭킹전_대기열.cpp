#include <iostream>
#include <vector>
#include <algorithm>

// �Ǽ�) string�� std::string�̱� ������, using namespace std;�� �� ������ ����� ��
using namespace std;

struct Player
{
	int level = 0;
	string name = "";
};

struct Room
{
	vector<Player> players = vector<Player>();
	int PlayerLimit = 0;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p = 0, m = 0, l = 0;
	string n = "";
	vector<Player> WaitingPlayers;
	vector<Room> Rooms;

	// 1 <= p(�÷��̾��), m(���� ����) <= 300
	cin >> p >> m;

	for (int i = 0; i < p; i++)
	{
		Player newplayer;
		// 1 <= l(����) <= 500
		// 1 <= �г���(�ҹ���) <= 16
		cin >> newplayer.level >> newplayer.name;
		WaitingPlayers.push_back(newplayer);
	}
	
	// �÷��̾� �� �������� �濡 �Ҵ��ϱ�
	for (int i = 0; i < WaitingPlayers.size(); i++)
	{
		bool IsEntered = false;
		
		// ù �� ����
		if (0 != Rooms.size())
		{
			for (int j = 0; j < Rooms.size(); j++)
			{
				// ���� �̴�
				if (m > Rooms[j].players.size())
				{
					// �ش� ���� ù��° �÷��̾�� ���� ���̰� -10 ~ +10 ������ ���
					if (WaitingPlayers[i].level >= (Rooms[j].players[0].level - 10)
						&& WaitingPlayers[i].level <= (Rooms[j].players[0].level + 10))
					{
						Rooms[j].players.push_back(WaitingPlayers[i]);
						IsEntered = true;
						break;
					}
				}
			}
		}

		// ���� 0���ų�, �� ���� ���� ���
		if (!IsEntered)
		{
			Room room;
			room.PlayerLimit = m;
			room.players.push_back(WaitingPlayers[i]);
			Rooms.push_back(room);
		}
	}

	for (auto& room : Rooms)
	{
		// sort(����, ��, ���Լ�) -> ���Լ� : �ΰ��� ��Ҹ� ����
		// �����Լ� ���� ����
		// ���� : [](�Ű�����) { ���� }
		// ex) bb < aa �� -> b�� �� �����Ƿ� false �� swap
		sort(room.players.begin(), room.players.end(),
			[](const Player& a, const Player& b) { return a.name < b.name; });

		if (room.PlayerLimit == room.players.size())
		{
			cout << "Started!\n";
		}
		else
		{
			cout << "Waiting!\n";
		}

		for (const auto& player : room.players)
		{
			cout << player.level << ' ';
			cout << player.name << '\n';
		}
	}

	return 0;
}