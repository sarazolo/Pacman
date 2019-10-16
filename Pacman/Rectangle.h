#pragma once
#include "Vertex.h"
#include "macros.h"
#include "Board.h"
class Rectangle
{
public:

	
	Rectangle(const Vertex ver[2]);//send array
	Rectangle(const Vertex& , const Vertex& );//send 2 vertex
	Rectangle(double x0, double y0, double x1, double y1);//send 4 double
	
	Vertex getTopRight()const;//get the top right
	Vertex getBottomLeft()const;//get the bottom left
	double getWidth() const;//get the width
	double getHeight() const;//get the height
	void draw(Board& board) const;//draw the Rectangle with board
	double getArea() const;//area
	double getPerimeter() const;//perimeter of Rectangle
	Rectangle getBoundingRectangle() const;//draw a rectangle around the rectangle
	Vertex getCenter() const;//get center of rectangle
	bool scale(double factor);//enlarge the rectangle with factor size
	


	~Rectangle();

private:
	Vertex m_topRight, m_bottomLeft;
};

