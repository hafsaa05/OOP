#include<iostream>
using namespace std;

// Define a struct for the product
struct Product {
    int id;
    string name;
    double price;
    int quantity;
};

// Function that enables the addition of a new product to the system.
void addProduct(Product products[], int& numProducts, int productId, const string& productName, double productPrice, int productQuantity) {
    products[numProducts].id = productId;
    products[numProducts].name = productName;
    products[numProducts].price = productPrice;
    products[numProducts].quantity = productQuantity;
    numProducts++;
}

// Function that takes a product ID as input and displays detailed information about the product.
void display(const Product& product) {
    cout << "Product ID: " << product.id << endl;
    cout << "Name: " << product.name << endl;
    cout << "Price: " << product.price << endl;
    cout << "Quantity: " << product.quantity << endl;
}

// Function that allows the update of product information.
void updateProductInfo(Product products[], int numProducts, int targetProductId, double newProductPrice, int newProductQuantity) {
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == targetProductId) {
            products[i].price = newProductPrice;
            products[i].quantity = newProductQuantity;
            break;
        }
    }
}

int main() {
    const int maxProducts = 100;
    Product products[maxProducts];
    int numProducts = 0;

    addProduct(products, numProducts, 1, "Product1", 20.0, 50);
    addProduct(products, numProducts, 2, "Product2", 30.0, 40);

    for (int i = 0; i < numProducts; i++) {
        cout << "Product " << i + 1 << " details:" << endl;
        display(products[i]);
    }

    updateProductInfo(products, numProducts, 1, 25.0, 60);

    cout << "After updating Product 1 details:" << endl;
    display(products[0]);

    return 0;
}
