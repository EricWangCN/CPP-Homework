#include"CGraph.h"

using namespace std;

int main()
{
    CGraph graph;
    graph.setName("my_graph");
    cout << "graph's name is " << graph.getName().get_string() << endl;
    cout << "graph's perimeter is " << graph.perimeter() << endl;
    cout << "graph's area is " << graph.area() << endl;

    double R = 10;
    cout << "R = " << R << endl;
    CCircle circle(R);
    circle.setName("my_circle");
    cout << "circle's name is " << circle.getName().get_string() << endl;
    cout << "circle's perimeter is " << circle.perimeter() << endl;
    cout << "circle's area is " << circle.area() << endl;

    double Len = 20, Width = 10;
    cout << "Len = " << Len << " and Width = " << Width << endl;
    CRectangle rectangle(Len, Width);
    rectangle.setName("my_rectangle");
    cout << "rectangle's name is " << rectangle.getName().get_string() << endl;
    cout << "rectangle's perimeter is " << rectangle.perimeter() << endl;
    cout << "rectangle's area is " << rectangle.area() << endl;
}