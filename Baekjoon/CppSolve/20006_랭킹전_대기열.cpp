#include <iostream>
#include <vector>
#include <algorithm>

// 실수) string은 std::string이기 때문에, using namespace std;를 맨 위에서 해줘야 함
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

	// 1 <= p(플레이어수), m(방의 정원) <= 300
	cin >> p >> m;

	for (int i = 0; i < p; i++)
	{
		Player newplayer;
		// 1 <= l(레벨) <= 500
		// 1 <= 닉네임(소문자) <= 16
		cin >> newplayer.level >> newplayer.name;
		WaitingPlayers.push_back(newplayer);
	}
	
	// 플레이어 다 들어왔으면 방에 할당하기
	for (int i = 0; i < WaitingPlayers.size(); i++)
	{
		bool IsEntered = false;
		
		// 첫 방 생성
		if (0 != Rooms.size())
		{
			for (int j = 0; j < Rooms.size(); j++)
			{
				// 정원 미달
				if (m > Rooms[j].players.size())
				{
					// 해당 방의 첫번째 플레이어와 레벨 차이가 -10 ~ +10 사이인 경우
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

		// 방이 0개거나, 들어갈 방이 없는 경우
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
		// sort(시작, 끝, 비교함수) -> 비교함수 : 두개의 요소를 비교함
		// 람다함수 만들어서 정렬
		// 람다 : [](매개변수) { 본문 }
		// ex) bb < aa 비교 -> b가 더 작으므로 false 및 swap
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