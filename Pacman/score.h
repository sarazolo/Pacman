#pragma once
#include "board.h"
class Score
{
public:
	Score();
	void num_of_cookies_at_start(board b);
	void calculate_score(int num_of_demons);
	void theNextLevelScore(int previosScore);
	void theNextLevelLife(int );
	void dec_num_of_cookies();
	void dec_num_of_lifes();
	int get_num_of_life() const;
	int get_num_of_cookies() const;
	void print_the_score() const;
	int getScore() const;


private:
	int the_score = 0;
	int num_of_cookie;
	int num_of_life = 3;
};

