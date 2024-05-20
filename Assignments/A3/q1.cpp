#include<iostream>
#include<string>
using namespace std;

class Medicine {
private:
    string name;
    string formula;
    string manufactureDate;
    string expirationDate;
    double retailPrice;

public:
    Medicine(string name, string formula, string manufacture, string expiration, double price)
        : name(name), formula(formula), manufactureDate(manufacture), expirationDate(expiration), 
        retailPrice(price) {}

    // Getter methods
    string GetName() { return name; }
    string GetFormula() { return formula; }
    string GetManufactureDate() { return manufactureDate; }
    string GetExpirationDate() { return expirationDate; }
    double GetRetailPrice() { return retailPrice; }

    // Setter methods
    void SetName(string name) { this->name = name; }
    void SetFormula(string formula) { this->formula = formula; }
    void SetManufactureDate(string manufacture) { this->manufactureDate = manufacture; }
    void SetExpirationDate(string expiration) { this->expirationDate = expiration; }
    void SetRetailPrice(double price) { this->retailPrice = price; }

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Formula: " << formula << endl;
        cout << "Manufacture Date: " << manufactureDate << endl;
        cout << "Expiration Date: " << expirationDate << endl;
        cout << "Retail Price: " << retailPrice << "$" << endl;
    }

    bool operator==(const Medicine& obj) {
        return expirationDate == obj.expirationDate;
    }
};

class Tablet : public Medicine {
private:
    double SucroseLevel;

public:
    Tablet(string name, string formula, string manufacture, string expiration, double price, 
    double SucroseLevel)
        : Medicine(name, formula, manufacture, expiration, price), SucroseLevel(SucroseLevel) {}

    void display() override {
        Medicine::display();
        cout << "Sucrose Level: " << SucroseLevel << endl;
    }
};

class Capsule : public Medicine {
private:
    float AbsorptionPercentage;

public:
    Capsule(string name, string formula, string manufacture, string expiration, double price, float absPer)
        : Medicine(name, formula, manufacture, expiration, price), AbsorptionPercentage(absPer) {}

    void display() override {
        Medicine::display();
        cout << "Absorption Percentage: " << AbsorptionPercentage << endl;
    }
};

class Syrup : public Medicine {
public:
    Syrup(string name, string formula, string manufacture, string expiration, double price)
        : Medicine(name, formula, manufacture, expiration, price) {}

    void display() override {
        Medicine::display();
    }
};

class Pharmacist {
public:
    void Search_Medicine(const string formula, Medicine* meds[], int n) {
        for (int i = 0; i < n; ++i) {
            if (meds[i]->GetFormula() == formula) {
                meds[i]->display();
            }
        }
    }
};

class Counter {
private:
    double Revenue;

public:
    Counter(double Revenue) : Revenue(Revenue) {}

    void Search_Medicine(const string name, Medicine* meds[], int size) {
        for (int i = 0; i < size; ++i) {
            if (meds[i]->GetName() == name) {
                meds[i]->display();
            }
        }
    }

    void Update_Revenue(double revenue) {
        Revenue += revenue;
        cout << "Total Revenue: " << Revenue <<"$" << endl;
    }
};

int main() {
    cout << "Name: Hafsa Rashid" << endl << "Student ID: 23K-0064" << endl;
    cout<<"\n"; 
    Medicine med("Disprin", "C9H8O4", "29-4-2024", "29-4-2026", 30.5);
    Tablet tab("Flagyl", "C6H9N3O3", "20-5-2024", "20-5-2026", 45.99, 0.9);
    Capsule cap("Vitamin-E", "C29H50O2", "12-5-2024", "12-5-2026", 23.56, 60);
    Syrup syr("Calpol", "C8H9NO2", "22-5-2024", "22-5-2026", 56.87);

    Medicine* meds[] = { &med, &tab, &cap, &syr };
    int n = 4;

    Pharmacist p1;
    p1.Search_Medicine("C6H9N3O3", meds, n);

    Counter c1(0);
    c1.Search_Medicine("Calpol", meds, n);
    c1.Update_Revenue(4500);

    return 0;
}
