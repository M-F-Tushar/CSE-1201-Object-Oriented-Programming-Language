/*
Pr.1 [15 Marks]

Suppose Chandpur Science and Technology has an on-campus field! The authority of the University wants the field will be surrounded 
by a flower garden. But there is no space left for the garden outside the field area, so the authority decided to take an equal width 
area from all around the field. Now, consider there is a class area to calculate the area of the field. You are thinking about inheriting 
two classes gardenArea and fieldArea from the area class to calculate the area of the flower garden and the area of the leftover field respectively.
 So, implement your imagination considering any inclusions on this problem.
*/
// Pr1_Area.cpp
#include <iostream>
using namespace std;

class Area {
protected:
    double length, width;
public:
    Area(double l=0, double w=0) : length(l), width(w) {}
    double totalArea() const { return length * width; }
};

class FieldArea : public Area {
    double border; // width of garden taken from around
public:
    FieldArea(double l, double w, double b) : Area(l,w), border(b) {}
    double leftoverField() const {
        double L = length - 2*border;
        double W = width  - 2*border;
        if (L <= 0 || W <= 0) return 0.0;
        return L * W;
    }
};

class GardenArea : public Area {
    double border;
public:
    GardenArea(double l, double w, double b) : Area(l,w), border(b) {}
    double gardenArea() const {
        double inner = FieldArea(length, width, border).leftoverField();
        return totalArea() - inner;
    }
};

int main() {
    double L=30, W=20, border=2; // example
    FieldArea field(L,W,border);
    GardenArea garden(L,W,border);
    cout << "Total area: " << L*W << "\n";
    cout << "Leftover field area: " << field.leftoverField() << "\n";
    cout << "Garden area: " << garden.gardenArea() << "\n";
    return 0;
}
