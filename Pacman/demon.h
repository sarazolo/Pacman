#pragma once
#include "vertex.h"
class demon
{
public:
	//demon(vertex);
	demon();
	void set_vertex(vertex);
	void setPrevios(char);
	vertex get_vertex() const;
	char getChar() const;
	void set_defult_demons(int i, int);
	char getPreviosPath() const;
	void setPreviosPath(char);
	
private:
	vertex m_demon;
	char m_d = '%';
	char m_previos_path ='*';
};

