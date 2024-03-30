#include <iostream>
using namespace std;

class DarazPersonData {
protected:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zip;
    string phone;

public:
    // Setter functions
    void setLastName(string lastName) {
        this->lastName = lastName;
    }
    void setFirstName(string firstName) {
        this->firstName = firstName;
    }
    void setAddress(string address) {
        this->address = address;
    }
    void setCity(string city) {
        this->city = city;
    }
    void setState(string state) {
        this->state = state;
    }
    void setZip(string zip) {
        this->zip = zip;
    }
    void setPhone(string phone) {
        this->phone = phone;
    }

    // Getter functions
    string getLastName() {
        return lastName;
    }
    string getFirstName() {
        return firstName;
    }
    string getAddress() {
        return address;
    }
    string getCity() {
        return city;
    }
    string getState() {
        return state;
    }
    string getZip() {
        return zip;
    }
    string getPhone() {
        return phone;
    }
};

class DarazCustomerData : public DarazPersonData {
protected:
    int customerNumber;
    int loyaltyPoints;

public:
    // Setter functions
    void setCustomerNumber(int customerNumber) {
        if (customerNumber < 0) {
            cout << "Error: Invalid customer number! Please enter a positive number." << endl;
        } else {
            this->customerNumber = customerNumber;
        }
    }
    void setLoyaltyPoints(int loyaltyPoints) {
        if (loyaltyPoints < 0) {
            cout << "Error: Invalid loyalty points! Please enter a positive number." << endl;
        } else {
            this->loyaltyPoints = loyaltyPoints;
        }
    }

    // Getter functions
    int getCustomerNumber() {
        return customerNumber;
    }
    int getLoyaltyPoints() {
        return loyaltyPoints;
    }
};

class DarazLoyaltyProgram : public DarazCustomerData {
public:
    void addLoyaltyPoints(int addPoints) {
        if (addPoints < 0) {
            cout << "Error: Invalid input! Loyalty points cannot be added with a negative value." << endl;
            return;
        }
        cout << "Loyalty points added: " << addPoints << endl;
        setLoyaltyPoints(getLoyaltyPoints() + addPoints);
    }

    void redeemLoyaltyPoints(int subtractPoints) {
        if (subtractPoints < 0) {
            cout << "Error: Invalid input! Loyalty points cannot be subtracted with a negative value." << endl;
            return;
        }
        if (getLoyaltyPoints() >= subtractPoints) {
            cout << "Redeeming loyalty points for discounts: " << subtractPoints << endl;
            setLoyaltyPoints(getLoyaltyPoints() - subtractPoints);
        } else {
            cout << "Error: Insufficient loyalty points for redemption." << endl;
        }
    }

    void displayLoyaltyPoints() {
        cout << "Total loyalty points: " << getLoyaltyPoints() << endl << endl;
    }
};

int main() {
    cout << "Name: Hafsa Rashid" << endl << "Student ID: 23K-0064"<<endl;
    cout<<"\n";
    DarazLoyaltyProgram c1;
    c1.setFirstName("Hafsa");
    cout << "First name: " << c1.getFirstName() << endl;
    c1.setLastName("Rashid");
    cout << "Last name: " << c1.getLastName() << endl;
    c1.setAddress("Malir");
    cout << "Address: " << c1.getAddress() << endl;
    c1.setCity("Karachi");
    cout << "City: " << c1.getCity() << endl;
    c1.setState("Sindh");
    cout << "State: " << c1.getState() << endl;
    c1.setZip("2345");
    cout << "Zip: " << c1.getZip() << endl;
    c1.setPhone("0300-123456");
    cout << "Phone number: " << c1.getPhone() << endl;

    c1.setCustomerNumber(64);
    c1.setLoyaltyPoints(12);
    c1.displayLoyaltyPoints();

    c1.addLoyaltyPoints(66);
    c1.displayLoyaltyPoints();

    c1.redeemLoyaltyPoints(32);
    c1.displayLoyaltyPoints();
    return 0;
}
