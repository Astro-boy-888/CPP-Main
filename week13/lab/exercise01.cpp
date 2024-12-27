#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x, y;    
public:
    Point();
    Point(double newX, double newY) ;

    Point(const Point& p);

    double getX() const;
    double getY() const;
};
Point::Point()
{
    this->x = 0;
    this->y = 0;
}
Point::Point(double newX, double newY)
{
    this->x = newX;
    this->y = newY;
}
Point::Point(const Point& p) 
{
    this->x = p.x;
    this->y = p.y;
}

double Point::getX() const {
    return this->x;
}

double Point::getY() const {
    return this->y;
}

class Line
{
private:
    Point p1, p2;
    double distance;
public:
    Line(Point xp1, Point xp2);
    Line(const Line& q);
    double getDistance() const;
};
Line::Line(Point xp1, Point xp2)
{
    this->p1 = xp1;
    this->p2 = xp2;
    this->distance = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
}
Line::Line(const Line& q)
{
    this -> p1 = q.p1;
    this -> p2 = q.p2;
    this -> distance = q.distance;
}
double Line::getDistance() const
{
    return this->distance;
}

int main()
{
    Point a(8, 9),b(1,2);
    Point c = a;
    cout << "point a: x = " << a.getX() << ", y = " << a.getY() << endl;
    cout << "point b: x = " << b.getX() << ", y = " << b.getY() << endl;
    cout << "point c: x = " << c.getX() << ", y = " << c.getY() << endl;
    cout << "------------------------------------------" << endl;
    Line line1(a, b);
    cout << "line1's distance:" << line1.getDistance() << endl;
    Line line2(line1);
    cout << "line2's distance:" << line2.getDistance() << endl;
    return 0;
}
