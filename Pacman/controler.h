#pragma once
#include "level.h"
#include <conio.h> 
#include <iostream>
#include <cstdlib>     

const int KB_ESCAPE = 27;

const int SPECIAL_KEY = 224;

// special keys
const int KB_UP = 72;
const int KB_DOWN = 80;
const int KB_LEFT = 75;
const int KB_RIGHT = 77;
class controler
{
public:
	controler();
	void movePac(level & the_level, int x, int y, vector <string>mat, vertex p);
	bool checkWall(int x, int y, vector <string>) const;
	bool checkDemon(int x, int y, vector <string> mat) const;
	void moveDemon(level& the_level);
	void relocation(level & the_level, int x, int y, vector <string>mat, vertex p, int);
	level move(level);
	vector<level> read_the_boards();
	void setSquare(level &the_level, int);
	//void loadLevel(controler the_level);
	bool chekPack(int x, int y, vector <string> mat);
	void print_all(level lev)const;
private:
	vector <level> m_levels;
};

