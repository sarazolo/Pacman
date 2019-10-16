#pragma once
#include "vertex.h"
#include "board.h"

class pacman
{

public:
	pacman();
	void set_vertex(vertex);
	vertex get_vertex() const;
	char getChar() const;

private:
		
		vertex _m_p;
		char _m_pac='@' ;

};

