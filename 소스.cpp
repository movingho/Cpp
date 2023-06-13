#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
    void paint() {
        draw();
    }
    virtual void draw() {
        cout << "Shape::draw() called" << endl;
    }
};

class Circle : public Shape {
public:
    virtual void draw() {
        cout << "Circle::draw() called" << endl;
    }
};

class Rectangle : public Shape {
public:
    virtual void draw() {
        cout << "Rectangle::draw() called" << endl;
    }
};

class Triangle : public Shape {
public:
    virtual void draw() {
        cout << "Triangle::draw() called" << endl;
    }
};

template<typename T>
void myprint(T& obj) {
    obj.paint();
}

int main() {
    string shape;
    cout << "도형을 입력하세요>>";
    getline(cin, shape);

    if (shape == "Circle") {
        Shape* pShape1 = new Circle();
        myprint(*pShape1);
        delete pShape1;
    }
    else if (shape == "Rectangle") {
        Shape* pShape2 = new Rectangle();
        myprint(*pShape2);
        delete pShape2;
    }
    else if (shape == "Triangle") {
        Shape* pShape3 = new Triangle();
        myprint(*pShape3);
        delete pShape3;
    }
    else {
        cout << "도형을 잘못 입력했습니다. 다시 입력 바랍니다.";
    }

    return 0;
}
