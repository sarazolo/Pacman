#pragma once
#include "board.h"
#include "pacman.h"
#include "demon.h"
#include "score.h"
class level
{

public:
	
	level(board& b, int level_number);
	board& get_board() ;
	pacman& get_pacman() ;
	Score& get_score() ;
	demon &get_demon(int i) ;
	int & get_num_of_level() ;
	int & inc_num_of_level();
	void loadLevel(board & bord, int level_number);


private:
	board m_b;
	int m_level_number=1;
	pacman m_pac;
	demon m_demons[4];
	Score m_score;



};

