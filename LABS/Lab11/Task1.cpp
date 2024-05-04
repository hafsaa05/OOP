/*
Name: Hafsa Rashid
Student ID: 23K-0064
*/
#include <iostream>
using namespace std;

template <typename T>
class convert {
protected:
    T val1;
    T val2;

public:
    convert(T val1) : val1(val1), val2(0) {}

    virtual void compute() = 0;

    T getVal2() const {
        return val2;
    }
};

template <typename T>
class l_to_g : public convert<T> {
public:
    l_to_g(T val1) : convert<T>(val1) {}

    void compute() override {
        this->val2 = this->val1 * 0.264172;
    }
};

template <typename T>
class f_to_c : public convert<T> {
public:
    f_to_c(T val1) : convert<T>(val1) {}

    void compute() override {
        this->val2 = (this->val1 - 32) * 0.5556;
    }
};

int main() {
    convert<double> *c1 = new l_to_g<double>(2.6);
    c1->compute();
    cout << "2.6 Liters = " << c1->getVal2() << " Gallons" << endl;
    delete c1;

    convert<double> *c2 = new f_to_c<double>(89.0);
    c2->compute();
    cout << "89.0 Fahrenheit = " << c2->getVal2() << " Celsius" << endl;
    delete c2;

    return 0;
}
