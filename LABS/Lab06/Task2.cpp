/*
Programmer: Hafsa Rashid
Student ID" 23K-0064
*/
#include<iostream>
#include<cstdlib> 
using namespace std;

class Image {
private:
    int width;
    int height;
    int* data;

public:
    Image(int w, int h, int* imgData): width(w), height(h) {
        int size = width * height;
        data = new int[size];
        // Copying provided image data
        for (int i = 0; i < size; ++i) {
            data[i] = imgData[i];
        }
    }

    Image(const Image& obj): width(obj.width), height(obj.height) {
        int size = width * height;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = obj.data[i];
        }
    }

    ~Image() {
        delete[] data;
    }

    void display() {
        cout << "Image Data:" << endl;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cout << data[i * width + j] << "\t";
            }
            cout << endl;
        }
    }

    void updateData() {
        for (int i = 0; i < width * height; ++i) {
            if (data[i] <= 0) {
                data[i] = rand() % 255 + 1; 
            }
        }
    }
};

int main() {
    int originalData[6] = {10, 0, -5, 20, 0, 15};

    Image original(2, 3, originalData);

    Image copied = original;

    cout << "Original Image:" << endl;
    original.display();

    cout << "\nCopied Image:" << endl;
    copied.display();

    original.updateData();
    copied.updateData();

    cout << "\nOriginal Image after updating data:" << endl;
    original.display();

    cout << "\nCopied Image after updating data:" << endl;
    copied.display();

    return 0;
}
