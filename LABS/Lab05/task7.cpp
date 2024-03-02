/*
Programmer: Hafsa Rashid
Student ID: 23K-0064
*/
#include <iostream>
#include <vector>

using namespace std;

class MenuItem {
public:
    MenuItem(string name, double price) : name_(name), price_(price) {}

    string getName() const {
        return name_;
    }

    double getPrice() const {
        return price_;
    }

private:
    string name_;
    double price_;
};

class Menu {
public:
    void addItem(const MenuItem& item) {
        menuItems_.push_back(item);
    }

    void removeItem(const string& name) {
        for (auto it = menuItems_.begin(); it != menuItems_.end(); ++it) {
            if (it->getName() == name) {
                menuItems_.erase(it);
                break;
            }
        }
    }

    void displayMenu() const {
        for (const auto& item : menuItems_) {
            cout << "Name: " << item.getName() << ", Price: " << item.getPrice() << endl;
        }
    }

    const MenuItem& getMenuItemByName(const string& name) const {
        for (const auto& item : menuItems_) {
            if (item.getName() == name) {
                return item;
            }
        }
        throw runtime_error("Menu item not found.");
    }

private:
    vector<MenuItem> menuItems_;
};

class Order {
public:
    void addItem(const MenuItem& item) {
        orderItems_.push_back(item);
    }

    void removeItem(const string& name) {
        for (auto it = orderItems_.begin(); it != orderItems_.end(); ++it) {
            if (it->getName() == name) {
                orderItems_.erase(it);
                break;
            }
        }
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto& item : orderItems_) {
            total += item.getPrice();
        }
        return total;
    }

private:
    vector<MenuItem> orderItems_;
};

class Payment {
public:
    Payment(double amount) : amount_(amount) {}

    double getAmount() const {
        return amount_;
    }

private:
    double amount_;
};

class RestaurantOrderingSystem {
public:
    void placeOrder(const Order& order, const Payment& payment) {
        orders_.push_back(order);
        payments_.push_back(payment);
    }

    void displayOrders() const {
        for (const auto& order : orders_) {
            cout << "Order Total: " << order.calculateTotal() << endl;
        }
    }

    void displayPayments() const {
        for (const auto& payment : payments_) {
            cout << "Payment Amount: " << payment.getAmount() << endl;
        }
    }

private:
    vector<Order> orders_;
    vector<Payment> payments_;
};

int main() {
    Menu menu;
    menu.addItem(MenuItem("Pasta", 20.0));
    menu.addItem(MenuItem("Fries", 18.0));
    menu.addItem(MenuItem("Spicy chicken", 30.0));
    menu.displayMenu();

    Order order;
    order.addItem(menu.getMenuItemByName("Pasta"));
    order.addItem(menu.getMenuItemByName("Fries"));
    order.addItem(menu.getMenuItemByName("Spicy chicken"));

    cout << "Order Total: " << order.calculateTotal() << endl;

    Payment payment(order.calculateTotal());
    cout << "Payment Amount: " << payment.getAmount() << endl;

    RestaurantOrderingSystem orderingSystem;
    orderingSystem.placeOrder(order, payment);
    orderingSystem.displayOrders();
    orderingSystem.displayPayments();

    return 0;
}

