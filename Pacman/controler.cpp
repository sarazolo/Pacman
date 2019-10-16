#include "controler.h"



controler::controler()
{

	m_levels = read_the_boards(); //reads the board fro the text


	for (int i = 0; i < m_levels.size(); i++)
	{
		if (i != 0) //we are not in the firat level
		{
			m_levels[i].get_score().theNextLevelScore(m_levels[i - 1].get_score().getScore()+50*(i-1));
			m_levels[i].get_score().theNextLevelLife(m_levels[i - 1].get_score().get_num_of_life());
		}

		print_all(m_levels[i]);// print the board

		//the term we can play
		while (m_levels[i].get_score().get_num_of_life() != 0 && m_levels[i].get_score().get_num_of_cookies() != 0)
		{
			m_levels[i] = move(m_levels[i]);
			print_all(m_levels[i]); // print the board
		}
	}

	system("cls");
	cout << "game overrrrr" << endl;


}
//-----------------------------------------
//read the board out of file
vector <level> controler::read_the_boards()
{
	vector<level> levels;
	ifstream inp;

	inp.open("pacman.txt");
	if (!inp.is_open())
	{
		cerr << "can't open file" << endl;
		exit(EXIT_FAILURE);
	}
	string line;
	int level_counter = 0;
	while (getline(inp, line))
	{
		level_counter++;
		board b;
		Score s;

		int size = atoi(line.c_str());//the size of matrix

		for (int i = 0; i < size; i++) {
			getline(inp, line);//get the line from text doc
			b.add_line(line);//put in all the lines to build the matrix
		}

		levels.push_back(level(b, level_counter));//put in our level the board that we built

	}

	return levels;//return the vector of levels
}
//------------------------------------------------
// move the all game
level controler::move(level  the_level)
{
	int x = the_level.get_pacman().get_vertex()._m_x;
	int y = the_level.get_pacman().get_vertex()._m_y;
	vector <string> mat = the_level.get_board().get_matrix();
	int c = _getch();
	switch (c)
	{

	case KB_UP:
	{
		vertex p{ x - 1,y };

		if (!checkWall(x - 1, y, mat))//checks if there a wall in the next step
		{
			if (!checkDemon(x - 1, y, mat)) //checks if there demon in the next step
			{
				movePac(the_level, x, y, mat, p);// move the pacman
				moveDemon(the_level); // move the demon
			}
			else //we step on demon
			{
				the_level.loadLevel(the_level.get_board(), the_level.get_num_of_level());
				the_level.get_score().dec_num_of_lifes();
				//loadLevel(the_level);
			}
		}
		break;
	}
	case KB_DOWN:
	{
		vertex p1{ x + 1,y };
		if (!checkWall(x + 1, y, mat))//checks if there a wall in the next step
		{
			if (!checkDemon(x + 1, y, mat))//checks if there demon in the next step
			{
				movePac(the_level, x, y, mat, p1);// move the pacman
				moveDemon(the_level); // move the demon
			}
			else//we step on demon
			{
				the_level.loadLevel(the_level.get_board(), the_level.get_num_of_level());
				the_level.get_score().dec_num_of_lifes();
			}		
		}
		break;
	}
	case KB_LEFT:
	{
		vertex p2{ x,y - 1 };
		if (!checkWall(x, y - 1, mat))//checks if there a wall in the next step
		{
			if (!checkDemon(x, y - 1, mat))//checks if there demon in the next step
			{
				movePac(the_level, x, y, mat, p2);// move the pacman
				moveDemon(the_level); // move the demon
			}
			else//we step on demon
			{
				the_level.loadLevel(the_level.get_board(), the_level.get_num_of_level());
				the_level.get_score().dec_num_of_lifes();
			}
		}
		break;
	}
	case KB_RIGHT:
	{
		vertex p2{ x,y + 1 };
		if (!checkWall(x, y + 1, mat))//checks if there a wall in the next step
		{
			if (!checkDemon(x, y + 1, mat))//checks if there demon in the next step
			{
				movePac(the_level, x, y, mat, p2);// move the pacman
				moveDemon(the_level); // move the demon
			}
			else //we step on demon
			{
				the_level.loadLevel(the_level.get_board(), the_level.get_num_of_level());
				the_level.get_score().dec_num_of_lifes();
			}
		}
		break;
	}
	}

	return the_level;



}
//------------------------------------------------------------
//this function moves the pacman
void controler::movePac(level & the_level, int x, int y, vector <string>mat, vertex p)
{
	the_level.get_board().set_vertex(' ', x, y);

	if (mat[p._m_x][p._m_y] == '*')
	{
		the_level.get_score().dec_num_of_cookies();
		the_level.get_score().calculate_score(the_level.get_num_of_level() - 1);

	}
	the_level.get_pacman().set_vertex(p);
	the_level.get_board().set_vertex('@', p._m_x, p._m_y);
}


//--------------------------------------------------------------
//checks if the next step is a wall
bool controler::checkWall(int x, int y, vector <string> mat) const
{
	if (mat[x][y] == '#' || mat[x][y] == '%')//אם הבורד במקום שאנו בודקים שווה לקיר אז תחזיר false
		return true;
	return false;
}
//----------------------------------------------------------
//checks if the next step is a Demon
bool controler::checkDemon(int x, int y, vector <string> mat) const
{
	if (mat[x][y] == '%')//אם הבורד במקום שאנו בודקים שווה לקיר אז תחזיר false
		return true;
	return false;
}
//------------------------------------------------------------
//move the demon
void controler::moveDemon(level& the_level)
{
	int numOfDemon;
	the_level.get_num_of_level() - 1 > 4 ? numOfDemon = 4 : numOfDemon = the_level.get_num_of_level() - 1;

	srand((unsigned)time(NULL));

	vector <string> mat = the_level.get_board().get_matrix();

	for (int i = 0; i < numOfDemon; i++)
	{
		int x = the_level.get_demon(i).get_vertex()._m_x;
		int y = the_level.get_demon(i).get_vertex()._m_y;

		bool isLegal = true;


		while (isLegal)
		{
			int move = rand() % 4;
			switch (move)
			{
			case 0:
			{

				vertex p{ x - 1,y };

				if (checkWall(x - 1, y, the_level.get_board().get_matrix())) //checks if there a wall in the next step
					break;
				if (chekPack(x - 1, y, the_level.get_board().get_matrix())) //checks if there a pacman in the next step
				{
					setSquare(the_level, numOfDemon);
					the_level.loadLevel(the_level.get_board(), the_level.get_num_of_level());
					the_level.get_score().dec_num_of_lifes();
					return;
				}

				relocation(the_level, x, y, mat, p, i);
				isLegal = false;

				break;
			}
			case 1:
			{
				vertex p1{ x + 1,y };
				if (checkWall(x + 1, y, the_level.get_board().get_matrix())) //checks if there a wall in the next step
					break;
				if (chekPack(x + 1, y, the_level.get_board().get_matrix()))
				{

					setSquare(the_level, numOfDemon);
					the_level.loadLevel(the_level.get_board(), the_level.get_num_of_level());
					the_level.get_score().dec_num_of_lifes();

					return;
				}

				relocation(the_level, x, y, mat, p1, i);
				isLegal = false;
				break;
			}
			case 2:
			{
				vertex p2{ x ,y + 1 };
				if (checkWall(x, y + 1, the_level.get_board().get_matrix())) //checks if there a wall in the next step
					break;
				if (chekPack(x, y + 1, the_level.get_board().get_matrix())) //checks if there a pacman in the next step
				{
					setSquare(the_level, numOfDemon);
					the_level.loadLevel(the_level.get_board(), the_level.get_num_of_level());
					the_level.get_score().dec_num_of_lifes();
					return;
				}

				relocation(the_level, x, y, mat, p2, i);
				isLegal = false;
				break;
			}
			case 3:
			{
				vertex p3{ x ,y - 1 };
				if (checkWall(x, y - 1, the_level.get_board().get_matrix())) //checks if there a wall in the next step
					break;
				if (chekPack(x, y - 1, the_level.get_board().get_matrix())) //checks if there a pacman in the next step
				{
					setSquare(the_level, numOfDemon);
					the_level.loadLevel(the_level.get_board(), the_level.get_num_of_level());
					the_level.get_score().dec_num_of_lifes();

					return;
				}
				relocation(the_level, x, y, mat, p3, i);
				isLegal = false;
				break;
			}

			}
		}
	}
}

//-----------------------------------------------------------
// relocate the player
void controler::relocation(level & the_level, int x, int y, vector <string>mat, vertex p, int i)
{
	char temp_c = the_level.get_board().get_char(p._m_x, p._m_y);

	the_level.get_board().set_vertex(the_level.get_demon(i).getPreviosPath(), x, y);
	the_level.get_demon(i).set_vertex(p);
	the_level.get_board().set_vertex('%', p._m_x, p._m_y);
	the_level.get_demon(i).setPreviosPath(temp_c);


}
//-----------------------------------------
//check if there is a pacman
bool controler::chekPack(int x, int y, vector <string> mat)
{
	if (mat[x][y] == '@')//אם הבורד במקום שאנו בודקים שווה לקיר אז תחזיר false
		return true;
	return false;
}
//-------------------------------------------
//print the all board
void controler::print_all(level lev) const
{

	system("cls");
	lev.get_board().print_the_board();
	lev.get_score().print_the_score();
	cout << "level : " << lev.get_num_of_level() << endl;
	cout << "life: " << lev.get_score().get_num_of_life() << endl;
	cout << "cookie: " << lev.get_score().get_num_of_cookies() << endl;
}
//---------------------------------------------------
//return the privios char that we had on the board
void controler::setSquare(level &the_level, int numOfDemon)
{
	for (int i = 0; i < numOfDemon; i++)
		the_level.get_board().set_vertex(the_level.get_demon(i).getPreviosPath(),
			the_level.get_demon(i).get_vertex()._m_x,
			the_level.get_demon(i).get_vertex()._m_y);
}