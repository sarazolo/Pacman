include "Rectangle.h"

// costractor thet getting array
Rectangle::Rectangle(const Vertex vertices[2]):
	Rectangle(vertices[0], vertices[1])
{
}
// costractor thet getting 2 vertex
Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight):
	Rectangle(bottomLeft.m_x, bottomLeft.m_y, topRight.m_x, topRight.m_y)
{
}
// // costractor thet getting 4 double
Rectangle::Rectangle(double x0, double y0, double x1, double y1):
	 m_bottomLeft{ x0,y0 },m_topRight{ x1,y1 }
	
{
	 if (!m_topRight.isHigherThan(m_bottomLeft) || !m_topRight.isRighterThan(m_bottomLeft)
		 ||! m_bottomLeft.isValid() ||! m_topRight.isValid())
	 {
		 m_topRight.m_x = 10;
		 m_topRight.m_y = 10;
		 m_bottomLeft.m_x = 0;
		 m_bottomLeft.m_y = 0;
	 }	 
}

////enlarge the rectangle with factor size
bool Rectangle::scale(double factor)
{
	Vertex newTop, newBottom;
	Vertex center = getCenter();
	newTop.m_x = m_topRight.m_x + (factor-1)*(m_topRight.m_x-center.m_x);
	newTop.m_y = m_topRight.m_y + (factor - 1)*(m_topRight.m_y - center.m_y);
	newBottom.m_x = m_bottomLeft.m_x + (factor-1)*(m_bottomLeft.m_x-center.m_x);
	newBottom.m_y = m_bottomLeft.m_y + (factor - 1)*(m_bottomLeft.m_y - center.m_y);

	if (newTop.isHigherThan(newBottom) && newTop.isRighterThan(newBottom) && newTop.isValid() && newBottom.isValid())
	{
		m_bottomLeft = newBottom;
		m_topRight = newTop;
		return true;
	}
	return false;

}

//draw the Rectangle with board
void Rectangle::draw(Board& board) const
{
	Vertex m_topLeft, m_bottomRight;
	m_topLeft.m_x = m_bottomLeft.m_x;
	m_topLeft.m_y = m_topRight.m_y;
	m_bottomRight.m_x = m_topRight.m_x;
	m_bottomRight.m_y = m_bottomLeft.m_y;

	
	board.drawLine(m_topLeft, m_topRight);
	board.drawLine(m_topRight, m_bottomRight);
	board.drawLine(m_bottomRight, m_bottomLeft);
	board.drawLine(m_bottomLeft, m_topLeft);
}
//draw a rectangle around the rectangle
Rectangle Rectangle::getBoundingRectangle() const
{
	return (Rectangle (m_bottomLeft, m_topRight));
}
// the area of the rectangle
double Rectangle::getArea() const
{
	
	return (getWidth()*getHeight());
}
// the Perimete of the rectangle
double Rectangle::getPerimeter() const
{
	return (getWidth()*2+getHeight()*2);
}

// the top Right vertex of the rectangle
Vertex Rectangle::getTopRight()const 
{ 
	return m_topRight;
}

// the Bottom Left vertex of the rectangle
Vertex Rectangle::getBottomLeft()const
{	
	return m_bottomLeft;
}
// the Width of the rectangle
double Rectangle::getWidth() const
{
	return (m_topRight.m_x - m_bottomLeft.m_x);
}
// the Height of the rectangle
double Rectangle::getHeight() const
{
	return(m_topRight.m_y - m_bottomLeft.m_y);
}
// the Center vertex  of the rectangle
Vertex Rectangle::getCenter() const
{
	Vertex center;
	center.m_x = (m_topRight.m_x + m_bottomLeft.m_x)/2;
	center.m_y = (m_topRight.m_y + m_bottomLeft.m_y)/2;
	return center;
}
	
Rectangle::~Rectangle( )
{
}

