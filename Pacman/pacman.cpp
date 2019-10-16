#include "pacman.h"


pacman::pacman()
{}
//---------------------------------------
//setting the pacman
void pacman::set_vertex( vertex new_v)
{
	_m_p=new_v;
}
//------------------------------
//get the vertex of the pacman
vertex pacman::get_vertex() const
{
	return _m_p;
}
//---------------------------
// get the char of the pacman
char  pacman::getChar() const
{
	return _m_pac;
}


