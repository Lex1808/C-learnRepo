#include <iostream>
#include <string>

class Shape {
    protected:
        std::string color;
        bool filled;

    public:
       std::string getColor(void) {
            return color;
        }
        void setColor(std::string& sColor) {
            color = sColor;
        }
        bool isFilled(void) {
            if (filled == 1) {
                return true;                    
            }
            return false;
        }
        void setFilled(bool isFilled) {
            filled = isFilled;
        }
        Shape(const std::string& color, bool filled): color(color), filled(filled) {}

        virtual std::string toString() {
            return "Shape: color = " + color + ", filled = " + (filled ? "true" : "false");
        }

};
class Circle: public Shape {
    private:
        double radius;
    public:
        Circle(const std::string& color, bool filled, double radius): Shape(color, filled), radius(radius) {}
        std::string toString() override {
            return "Circle color = " + color + ", filled: " + (filled ? "true": "false") + ", radius = " + std::to_string(radius);
        }
};
class Rectangle: public Shape {
    private:
        double width;
        double height;
    public:
        Rectangle(const std::string& color, bool filled, double width, double height): Shape(color, filled), width(width), height(height) {}
        std::string toString() override {
            return "Rectangle color = " + color + ", filled: " + (filled ? "true": "false") + ", width = " + std::to_string(width) + ", height = " + std::to_string(height);   
        }
};

int main() {
    Circle circle("Red", true, 12.5);
    Rectangle rectangle("Blue", false, 15.4, 10.2);

    std::cout << circle.toString() << std::endl;
    std::cout << rectangle.toString() << std::endl;

    return 0;
}

    
