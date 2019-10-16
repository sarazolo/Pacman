#include "score.h"



Score::Score()
{
}
//---------------------------------------
//caculate the number of the cookie in the begging of level
void Score::num_of_cookies_at_start(board b)
{
	int counter = 0;

	vector <string> new_b = b.get_matrix();
	for (int i=0; i<new_b.size(); i++)
		for (int j = 0; j < new_b.size(); j++)
		{
			if (new_b[i][j] == '*')
				counter++;
		}
	
	num_of_cookie = counter;
}
//----------------------------------------------
//calculate the score of the game
void Score::calculate_score(int num_of_demons)
{
	the_score += ((num_of_demons+1) * 2);
	
}
//---------------------------------------------
//decreasing the number of the cookie
void Score::dec_num_of_cookies()
{
	num_of_cookie--;
}
//------------------------------
//decreasing the number of life the player have
void Score:: dec_num_of_lifes()
{
	num_of_life--;
}
//--------------------------------
// getting the num of the lifes
int Score::get_num_of_life() const
{
	return num_of_life;
}
//---------------------------------
// getting the num of the cookies
int Score::get_num_of_cookies() const
{
	return num_of_cookie;
}
//--------------------------------
//print the score
void Score::print_the_score() const
{
	cout <<"points:"<< the_score<< endl;
}
//------------------------------
// calculate the score of the next level
void Score::theNextLevelScore(int previosScore)
{
	the_score += previosScore;
}
//---------------------------------
// calculate the life of the next level
void Score::theNextLevelLife(int previosLive)
{
	num_of_life = previosLive;
}
//-----------------------------------
int Score::getScore() const
{
	return the_score;
}





