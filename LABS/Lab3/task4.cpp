#include<iostream>
using namespace std;

class Smartphone {
    string brand;
    string model;
    string DR; // Display Resolution
    int RAM;
    int ROM;
    int storage;

public:
    void BrandSetter(string b) {
        brand = b;
    }

    string BGetter() {
        return brand;
    }

    void modelSetter(string m) {
        model = m;
    }

    string MGetter() {
        return model;
    }

    void DRSetter(string d) {
        DR = d;
    }

    string DRGetter() {
        return DR;
    }

    void RAMSetter(int r) {
        RAM = r;
    }

    int RAMGetter() {
        return RAM;
    }

    void ROMSetter(int R) {
        ROM = R;
    }

    int ROMGetter() {
        return ROM;
    }

    void StorageSetter(int s) {
        storage = s;
    }

    int SGetter() {
        return storage;
    }

    // Creating member functions
    void PhoneCall(string num) {
        cout << "Connecting to: " << num << endl;
    }

    void SMS(string num) {
        string msg;
        cout << "Type the message: ";
        cout << endl;
        cout << "Message successfully sent to: " << num << endl;
    }

    void WIFI(string wifi) {
        cout << "Connecting to your wifi: " << wifi << endl;
    }

    void browse(string browser) {
        cout << "Browsing on " << browser << " with your " << brand << " " << model << endl;
    }
};

int main() {
    Smartphone s1;
    s1.BrandSetter("Samsung");
    s1.modelSetter("A20s");
    s1.DRSetter("1080x2400 pixels");
    s1.RAMSetter(128);
    s1.ROMSetter(8);
    s1.StorageSetter(64);

    cout << "Details for first phone:" << endl;
    cout << "Brand: " << s1.BGetter() << endl;
    cout << "Model: " << s1.MGetter() << endl;
    cout << "Display Resolution: " << s1.DRGetter() << endl;
    cout << "RAM: " << s1.RAMGetter() << "GB" << endl;
    cout << "ROM: " << s1.ROMGetter() << "GB" << endl;
    cout << "Storage: " << s1.SGetter() << "GB" << endl;

    s1.PhoneCall("123456789");
    s1.SMS("123456789");
    s1.WIFI("PTCL-BB");
    s1.browse("Google Chrome");

    // Creating another object s2
    Smartphone s2;
    s2.BrandSetter("Apple");
    s2.modelSetter("iPhone 12");
    s2.DRSetter("2532x1170 pixels");
    s2.RAMSetter(256);
    s2.ROMSetter(64);
    s2.StorageSetter(128);

    cout << "\nDetails for second phone :" << endl;
    cout << "Brand: " << s2.BGetter() << endl;
    cout << "Model: " << s2.MGetter() << endl;
    cout << "Display Resolution: " << s2.DRGetter() << endl;
    cout << "RAM: " << s2.RAMGetter() << "GB" << endl;
    cout << "ROM: " << s2.ROMGetter() << "GB" << endl;
    cout << "Storage: " << s2.SGetter() << "GB" << endl;

    s2.PhoneCall("987654321");
    s2.SMS("987654321");
    s2.WIFI("MyHomeNetwork");
    s2.browse("Safari");

    return 0;
}
