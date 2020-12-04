#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Point.h"
#include "Poligon.h"

using namespace std;

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