#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "vertex.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;

class board
{
public:
	board();
	void read_the_board();
	void add_line(string line);
	void print_the_board() const;
	vertex find_the_empty(vertex, vertex);
	int get_size() const;
	void set_vertex(char ,int i, int j);
	char get_char( int i, int j) const;
	double distance(const vertex& v1, const vertex& v2) const;
	vector <string> get_matrix() const;
	char checkPreviosChar(int, int) const;
	void eraseBoard();
	
private:
	vector <string> _m_matrix;	
	int _m_size;
	

};

