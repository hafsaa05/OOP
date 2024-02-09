#include<iostream>
using namespace std;
class BoardMarker{
	private:
	string brand;
    string color;
    bool refillable;
    bool inkStatus;
    
    public:
    //setters
    	void setB(string newB) {
        brand = newB;
    }

    void setCol(string newCol) {
        color = newCol;
    }

    void setRefillable(bool isR) {
        refillable = isR;
    }

    void setInkStatus(bool newInk) {
        inkStatus = newInk;
    }
    //Getters:
	string getB() {
        return brand;
    }

    string getCol() {
        return color;
    }

    bool isR(){
        return refillable;
    }

    bool isInkDepleted() {
        return !inkStatus;
    }
    // Writing method
    void write(){
        if (inkStatus) {
            cout << "This " << color << " board marker is writing." <<endl;
        } else {
            cout << "The ink is depleted." <<endl;
        }
    }
// Refill method
    void refill() {
        if (refillable) {
            cout << "Refilling board marker." << std::endl;
            inkStatus = true;
        } else {
            cout << "The marker cant be refilled." << std::endl;
        }
    }
};
int main() {
    BoardMarker m1("Zoro", "black", true);
    std::cout << "brand: " << ma1.getBrand() << " ,color: " << m1.getColor() << " ,refillable: " << m1.isRefillable() <<endl;

    m1.write(); 
    m1.setInkStatus(false);
    m1.write();  
    m1.refill();  
    BoardMarker m2("Dollar", "blue", false);
    m2.refill();  

    return 0;
}
