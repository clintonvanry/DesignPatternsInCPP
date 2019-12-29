#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

// inner factory solves the friend usage in simple factory
// does not break OCP
// inner factory can use outer class and outer class 

class Point
{
	class PointFactory
	{
		PointFactory() = default;;
		public:
			static Point NewCartesian(float x, float y)
			{
				return { x,y };
			}
			static Point NewPolar(float r, float theta)
			{
				return { r * cos(theta), r * sin(theta) };
			}
	};
	
	// constructor
	Point(float x, float y) : m_x(x), m_y(y)
	{

	}
public:
	float m_x, m_y;

	friend std::ostream& operator << (std::ostream& os, const Point& point)
	{
		os << "X: " << point.m_x << " Y: " << point.m_y << std::endl;
		return os;
	}

	static PointFactory Factory;
};



int main()
{
    std::cout << "Hello World!\n";

	// if you want the PointFactory public then access via this route
	//auto pointPolar = Point::PointFactory::NewPolar(5, M_PI_4);
	//auto pointCartesian = Point::PointFactory::NewCartesian(5, 3);

	auto pointPolar = Point::Factory.NewPolar(5, M_PI_4);
	auto pointCartesian = Point::Factory.NewCartesian(5, 3);


	std::cout << "Polar:" << std::endl;
	std::cout << pointPolar << std::endl;
	std::cout << "Cartesian:" << std::endl;
	std::cout << pointCartesian << std::endl;
}
