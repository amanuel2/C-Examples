#include <iostream>
#include <string>
#include <math.h>

const double PI = 3.14159265358979323846;
double squareNum(double n1){ return(n1*n1); }
class Shape {
public:
    Shape(std::string name_) {
        name = name_;
    }

    std::string getName() { return name; }

    void setName(std::string name_) {
        name = name_;
    }

    //Virtual Functions are basically intiated
    //function by parent class. You actually
    //define them in the child classes...
    //Pure Virtual Function makes the class
    // a abstract base class.. So it cant be
    //intiated, only inherited...
    virtual double getArea() = 0;

protected:
    std::string name;
};

class Circle : public Shape {
    double radius;
public:
    Circle(std::string n, double r) : Shape(n) {
        radius = r;
    }

    double getRadius() {
        return radius;
    }

    void setRadius(double radius_) {
        radius_ = radius;
    }

    virtual double getArea() {
            return((PI) * (squareNum(radius)));
    };
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(std::string name, double length_, double width_) : Shape(name) {
        length = length_;
        width = width_;
    }

    void setLength(double length_) { length = length_; }

    void setWidth(double width_) { width = width_; }

    double getLength() { return length; }

    double getWidth() { return width; }

    virtual double getArea(){ return(width*length); }

};

class Triangle : public Shape {
    double base,width;
    std::string name;

public:
    Triangle(std::string name_ , double base_, double width_) : Shape(name_){
        base = base_; width = width_; name = name_;
    }
    double getBase(){return base;}
    double getWidth(){return width;}
    void setBase(double base_){base = base_;}
    void setWidth(double width_) {width = width_;}
    std::string getName(){return name;}

    virtual double getArea(){
        return(( base * width)/2);
    }
};

int main() {
/*
    Circle c("Circle1", 2);
    c.setName("CIRCLE1");
    std::cout << "Circle1 name " << c.getName() << " Circle radius " << c.getRadius() << std::endl;

    Rectangle rect1("rect1", 2, 2);
    rect1.setName("RECT1");
    rect1.setLength(5);

    std::cout << "Rectangle name " << rect1.getName() << " , Rectangle lengtj " << rect1.getLength()
    << " Rectangle width " << rect1.getWidth() << std::endl;


    Triangle trng1("triangle1",12,14);
    trng1.setBase(20);
    trng1.setWidth(30);
    std::cout << "TRIANGLE WIDTH : " << trng1.getWidth() << " TRIANGLE BASE : " << trng1.getBase()
            << "TRIANGLE NAME : " << trng1.getName() <<std::endl;

    std::cout << "**** AREAS *****" <<std::endl << "TRIANGLE : " << trng1.getArea() << std::endl
                << " RECTANGLE: " << rect1.getArea() << std::endl << "CIRCLE : " << c.getArea()
                    <<std::endl;
*/

    Shape* shape[3] = {
            new Circle("CIRCLE2",4),
            new Rectangle("RECT2" , 5,5),
            new Triangle("TRIANGLE3" , 6,6)
    };

    for(int i=0;i<3;i++){
        std::cout << "Shape " <<i << " area" << shape[i]->getArea() << std::endl;
    }
    return 0;
}
