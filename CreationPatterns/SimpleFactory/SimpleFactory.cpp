#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

enum class PointType
{
	cartesian,
	polar
};

class PointFactoryMethod
{
public:
	float m_x, m_y;
	static PointFactoryMethod NewCartesian(float x, float y)
	{
		return { x,y };
	}
	static PointFactoryMethod NewPolar(float r, float theta)
	{
		return { r*cos(theta), r*sin(theta) };
	}
	
	friend std::ostream &operator << (std::ostream& os, const PointFactoryMethod& point)
	{
		os << "X: " << point.m_x << " Y: " << point.m_y << std::endl;
		return os;
	}

	friend class PointFactory; // violation of OCP and makes pointfactroy work
private:
	// constructor
	PointFactoryMethod(float x, float y): m_x(x), m_y(y)
	{
		
	}
};

class PointFactory
{
public:
	static PointFactoryMethod NewCartesian(float x, float y)
	{
		return { x,y };
	}
	static PointFactoryMethod NewPolar(float r, float theta)
	{
		return { r * cos(theta), r * sin(theta) };
	}
};

int main()
{
    std::cout << "Hello World!\n";

	auto pointPolar = PointFactoryMethod::NewPolar(5, M_PI_4);
	auto pointCartesian = PointFactoryMethod::NewCartesian(5, 3);

	std::cout << "Polar:" << std::endl;
	std::cout << pointPolar << std::endl;
	std::cout << "Cartesian:" << std::endl;
	std::cout << pointCartesian << std::endl;


	auto pointFactoryCartesian = PointFactory::NewCartesian(5, 3);
	std::cout << pointFactoryCartesian << std::endl;

	
	return 0;
}

