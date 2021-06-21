#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <mutex>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Score.h"
using namespace std;

Score score(0, 0);
mutex m;

void RandomPlayerTurn(int* player)
{

	int* r = new int;
	srand((int)r);
	delete r;
	*player = rand() % 2;

}

void RandomPlayerHit(Player* player, bool* end)
{

	int* r = new int;
	m.lock();
	srand((int)r);
	delete r;
	player->SetHit(rand() % 101);
	m.unlock();

	cout << "Hits : " << player->GetHit();
	if (player->GetPlayer() == 0)
	{
		cout << " Player X ";
	}

	else
	{
		cout << " Player Y ";
	}

	if (player->GetPlayer() <= 50)
	{
		if (player->GetPlayer() == 0)
		{
			score.AddScoreY();
		}
		else
		{
			score.AddScoreX();
		}
		cout << "Tidak terkena pukulan" << endl;

		*end = true;
	}

	else
	{
		cout << "Terkena pukulan" << endl;
	}

	this_thread::sleep_for(1s);

}

int main()
{

	srand(time(0));
	Player playerX(0);
	Player playerY = playerX;

	int game = 1;
	while (score.playerXscore() < 10 && score.playerYscore() < 10)
	{
		int giliran;
		thread RandomFirst(RandomPlayerTurn, &giliran);
		RandomFirst.join();
		bool GameFinish = false;

		cout << "===  ROUND " << game << "  ===" << endl;
		while (GameFinish == false)
		{
			if (giliran == 0)
			{
				cout << "Player X First" << endl;

				thread playerXthread(RandomPlayerHit, &playerX, &GameFinish);
				playerXthread.join();

				if (GameFinish == true)
				{
					game++;
					break;
				}

				thread playerYthread(RandomPlayerHit, &playerY, &GameFinish);
				playerYthread.join();

				if (GameFinish == true)
				{
					game++;
					break;
				}
			}

			else if (giliran == 1)
			{
				cout << "Player Y First" << endl;

				thread playerYthread(RandomPlayerHit, &playerY, &GameFinish);
				playerYthread.join();

				if (GameFinish == true)
				{
					game++;
					break;
				}

				thread playerXthread(RandomPlayerHit, &playerX, &GameFinish);
				playerXthread.join();

				if (GameFinish == true)
				{
					game++;
					break;
				}
			}
		}
	}

	cout << "\nTotal Score : " << endl;
	if (score.playerXscore() >= 10)
	{
		cout << "Player X : " << score.playerXscore() << "—" << score.playerYscore() << "\nPLAYER X WIN !!" << endl;
	}

	else
	{
		cout << "Player Y : " << score.playerYscore() << "—" << score.playerXscore() << "\nPLAYER Y WIN !!" << endl;
	}

	return 0;

}