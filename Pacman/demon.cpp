#include "demon.h"



	//לבנות לו קונסטרקורררר שמקבל את הערך הדיפןלטיבי ומחפש איפה למקם כמו הפקמן
/*
demon::demon(vertex v) :
	m_demon{v}
{
	
}*/
//---------------------------

demon::demon() 
{
}
//---------------------------------------
//seting the vertex
void demon::set_vertex(vertex new_v)
{
	m_demon = new_v;
}
//------------------------------
//getting the vertex
vertex demon::get_vertex() const
{
	return m_demon;
}
//---------------------------
//getting the char
char  demon::getChar() const
{
	return m_d;
}
//-----------------------------
//get the previos char
char demon::getPreviosPath() const
{
	return m_previos_path;
}
//--------------------------------
//seting the previos char
void demon:: setPreviosPath(char c)
{
	m_previos_path = c;
}
//--------------------------------
// setting the demon
void demon::set_defult_demons(int i, int size)
{ 
	if (i == 0)
		m_demon={ 0,0 };	
	
	else if (i == 1)
		m_demon = { 0, (size - 1.0) };
	else if (i == 2)
		m_demon = { (size - 1.0) , (size - 1.0) };
	else if (i == 3)
		m_demon = { (size - 1.0) , 0 };

}
//-------------------------------------
// set the privios
void demon::setPrevios(char c)
{
	m_previos_path = c;
}





