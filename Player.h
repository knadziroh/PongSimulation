#ifndef Player_h
#define Player_h
#include <iostream>
using namespace std;

class Player
{

private:
	float hit;
	enum player
	{
		playerX = 0,
		playerY = 1
	}currentPlayer;

public:
	float GetHit();
	float SetHit();
	Player(int r);
	Player(Player& clone);
	player getPlayer()
	{
		return currentPlayer;
	}

};

Player::Player(int r)
{
	if (r == 0)
	{
		currentPlayer = playerX;
	}
	else
	{
		currentPlayer = playerY;
	}
	hit = 0;
}

float Player::SetHit()
{
	float H;
	hit = H;
}

float Player::GetHit()
{
	return hit;
}

#endif // !Player_h
