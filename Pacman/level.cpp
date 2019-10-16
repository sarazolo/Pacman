#include "level.h"
#include <iostream>
#include <cstdlib>     
#include <conio.h> 


//constractor
level::level(board& b, int level_number) :
	m_b(b), m_level_number(level_number)
{
	loadLevel(m_b, m_level_number);
	
}
//----------------------------------
//getting  the board
board& level::get_board() 
{
	return m_b;
}
//-----------------------------
//getting the pacman
pacman &level::get_pacman() 
{
	return m_pac;
}
//----------------------------------
// get the demon
demon &level::get_demon(int i) 
{
	return m_demons[i];
}
//-----------------------
//get the score
Score &level::get_score() 
{
	return m_score;
}
//----------------------
// getting the num of the level
int& level::get_num_of_level() 
{
	return m_level_number;
}
//-----------------------------
// increasing the nyum of the level
int & level::inc_num_of_level()
{
	int x = m_level_number + 1;
	return x;
}
//----------------------------
// loading from begging the level
void level ::loadLevel(board & m_b, int level_number)
{
	
	//system("cls");
	m_b.eraseBoard();
	vertex center = { (m_b.get_size() - 1) / 2,(m_b.get_size() - 1) / 2 };
	vertex bottom_left = { 0,0 };
	//set the pacman
	m_pac.set_vertex(m_b.find_the_empty(center, bottom_left));

	m_b.set_vertex(m_pac.getChar(), m_pac.get_vertex()._m_x, m_pac.get_vertex()._m_y);//מכניס את הצורה	
	m_score.num_of_cookies_at_start(m_b);
	for (int i = 0; i < m_level_number - 1 && i<4; i++)
	{
		//set the deamon
		m_demons[i].set_defult_demons(i, m_b.get_size());
		vertex newP=m_b.find_the_empty(m_demons[i].get_vertex(), center);
		char c=m_b.checkPreviosChar(newP._m_x,newP._m_y);
		m_demons[i].setPrevios(c);
		m_demons[i].set_vertex(newP);
		m_b.set_vertex(m_demons[i].getChar(), m_demons[i].get_vertex()._m_x, m_demons[i].get_vertex()._m_y);

	}
}

//-------------------------------------------------------*/





	



