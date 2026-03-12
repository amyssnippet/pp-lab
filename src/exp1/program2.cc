#include <iostream>

using namespace std;

class Shape {
public:
    virtual void calculateAndDisplayArea() const {
        cout << "Area of generic shape\n";
    }
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}
    void calculateAndDisplayArea() const override {
        cout << "Rectangle Area: " << (length * width) << "\n";
    }
};

class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r) : radius(r) {}
    void calculateAndDisplayArea() const override {
        cout << "Circle Area: " << (3.14159f * radius * radius) << "\n";
    }
};

int main() {
    float r, l, w;

    cout << "Enter length and width of the rectangle: ";
    cin >> l >> w;
    Shape* shapePointer1 = new Rectangle(l, w);

    cout << "Enter radius of the circle: ";
    cin >> r;
    Shape* shapePointer2 = new Circle(r);

    cout << "\n  Results   \n";
    shapePointer1->calculateAndDisplayArea();
    shapePointer2->calculateAndDisplayArea();

    delete shapePointer1;
    delete shapePointer2;

    return 0;
}