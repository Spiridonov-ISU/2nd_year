#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>

using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point(int _x, int _y)
    {
        this->x = _x;
        this->y = _y;
    }
    int GetX() { return x; }
    int GetY() { return y; }
};

class Figure
{
public:
	virtual double GetArea() = 0;
	virtual double GetPerimeter() = 0;
};

class Circle : public Figure
{
private:
    double radius;
public:
    Circle(double r)
    {
        this->radius = r;
    }

    double GetArea()
    {
        return radius * radius * 3.14;
    }

    double GetPerimeter()
    {
        return 2 * 3.14 * radius;
    }
};

class Rectangle : public Figure
{
private:
    double width;
    double height;
public:
    Rectangle(double w, double h)
    {
        this->width = w;
        this->height = h;
    }

    double GetArea()
    {
        return width * height;
    }

    double GetPerimeter()
    {
        return width * 2 + height * 2;
    }
};

class Triangle : public Figure
{
private:
    double A;
    double B;
    double C;
public:
    Triangle(double a, double b, double c)
    {
        this->A = a;
        this->B = b;
        this->C = c;
    }

    double GetArea() {
        double p = this->GetPerimeter() / 2;
        return sqrt(p * (p - this->A) * (p - this->B) * (p - this->C));
    }

    double GetPerimeter()
    {
        return A + B + C;
    }
};

class Poligon : public Figure
{
private:
    vector<Point> points;
public:
    Poligon(vector<Point> p)
    {
        this->points = p;
    }

    double GetArea()
    {
        double area = 0;
        int j = points.size() - 1;
        for (int i = 0; i < points.size(); i++) {
            area += (points[j].GetX() + points[i].GetX()) * (points[j].GetY() - points[i].GetY());
            j = i;
        }
        return abs(area / 2);
    }

    double GetPerimeter()
    {
        double perimeter = 0;
        int m, n;
        for (int i = 1; i < points.size() - 1; i++) {
            Point a = points[i];
            Point b = points[i + 1];
            m = a.GetX() - b.GetX();
            n = a.GetY() - b.GetY();
            perimeter += sqrt(abs(m * m - n * n));
        }
        return perimeter;
    }
};

int main()
{
    vector<Figure*> figures;
    Rectangle* r = new Rectangle(2, 2);
    Circle* c = new Circle(1);
    Triangle* t = new Triangle(5, 5, 3.3);

    vector<Point> points;
    points.push_back(Point(1, 1));
    points.push_back(Point(5, 4));
    points.push_back(Point(6, 1));
    points.push_back(Point(3, 2));
    Poligon* p = new Poligon(points);

    figures.push_back(r);
    figures.push_back(c);
    figures.push_back(t);
    figures.push_back(p);

    double s_area = 0;
    for (int i = 0; i < figures.size(); i++)
    {
        s_area += figures[i]->GetArea();
    }

    cout << s_area << endl;

    ifstream file("text.txt");
    if (file.is_open())
    {
        int n;
        file >> n;
        int x, y;
        vector<Point> points_f;
        for (int i = 0; i <= n; i++) 
        {
            file >> x;
            file >> y;
            points_f.push_back(Point(x, y));
        }
        Poligon pF(points_f);
        cout << "Area: " << pF.GetArea() << " " << "Perimeter: " << pF.GetPerimeter() << endl;
        file.close();
    }

    return 0;
}