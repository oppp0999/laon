#include <iostream>
#include <vector>

class Shape {
    public :
        virtual double area() const = 0;
};

class Rectangle : public Shape {
    private:
        double width;
        double height;

    public:
        Rectangle(double w, double h) : width(w), height(h){}

        double area() const override{
            return width * height;
        }
};

class Circle : public Shape {
    private :
        double radius;

    public :
        Circle(double r) : radius(r) {}

        double area() const override{
            return 3.14 * radius * radius;
        }
};

void printAreas(const std::vector<Shape*>& shapes){
    for(const auto shape : shapes){
        std::cout << "Area :" << shape->area() << std::endl;
    }
}

int main(){
    Rectangle rec(3,4);
    Circle cir(2);

    std::vector<Shape*>& shapes;
    shapes.push_back(&rec);
    shapes.push_back(&cir);

    printAreas(shapes);

    return 0;
}