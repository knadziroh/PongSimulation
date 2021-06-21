#pragma once

class Score
{
	
private:
	int scoreX = 0, scoreY = 0;

public:
	Score(int, int);
	int playerXscore();
	int playerYscore();
	void SetScore(int, int);
	void AddScoreX();
	void AddScoreY();

};

Score::Score(int x, int y)
{
	scoreX = x;
	scoreY = y;
}

int Score::playerXscore()
{
	return scoreX;
}

int Score::playerYscore()
{
	return scoreY;
}

void Score::SetScore(int x, int y)
{
	scoreX = x;
	scoreY = y;
}

void Score::AddScoreX()
{
	scoreX++;
}

void Score::AddScoreY()
{
	scoreY++;
}
