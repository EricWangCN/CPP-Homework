#include "swimpool.h"

int main() {
    CGraph * pGraph = new CRectangle;
    std::cout << pGraph->area() << std::endl;
    delete(pGraph);
    CCircle * p_c = new CCircle("circle", 3);
    CRectangle * p_r = new CRectangle("rect", 4, 7.5);
    CTriangle * p_t = new CTriangle("triangle", 3, 4, 5);

    CSwimPool pool(p_c);
    std::cout << "Area: " << pool.area()  << "\tPerimeter: " << pool.perimeter()  << std::endl;
    CSwimPool pool1(p_r);
    std::cout << "Area: " << pool1.area() << "\tPerimeter: " << pool1.perimeter() << std::endl;
    CSwimPool pool2(p_t);
    std::cout << "Area: " << pool2.area() << "\tPerimeter: " << pool2.perimeter() << std::endl;

    std::ofstream out("data.txt");

    out << "3\n";
    out << "1\n";
    pool.write_text(out);
    out << "2\n";
    pool1.write_text(out);
    out << "3\n";
    pool2.write_text(out);
    out.close();

    std::ifstream in("data.txt");
    int num;
    in >> num;
    CSwimPool ** pPool = new CSwimPool*[num];
    int type;
    for (int i = 0; i < num; i++) {
        in >> type;
        in.get();
        switch (type) {
            case 1:
                pGraph = new CCircle;
                break;
            case 2:
                pGraph = new CRectangle;
                break;
            case 3:
                pGraph = new CTriangle;
                break;
        }
        pPool[i] = new CSwimPool(pGraph);
        pPool[i]->read_text(in);
    }
    for (int i = 0; i < num; ++i) {
        std::cout << "Area: " << pPool[i]->area() << "\tPerimeter: " << pPool[i]->perimeter() << '\n';
    }
    for (int i = 0; i < num; i++) {
        std::cout << i << ":\n";
        delete pPool[i];
    }
    std::cout << "LAST\n";
    delete[] pPool;

    return 0;
}