#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BOGOCoupon {
public:
    string coupon_code;
    int valid_from;
    int valid_until;
    string restaurant_code;

    BOGOCoupon(string code, int from, int until, string restaurant)
        : coupon_code(code), valid_from(from), valid_until(until), restaurant_code(restaurant) {}

    bool is_valid(int current_day, const string& res_code) const {
        return current_day >= valid_from && current_day <= valid_until && restaurant_code == res_code;
    }
};

class Restaurant {
private:
    string restaurant_name;
    string location;
    string menu_list[5];
    float price_list[5];
    vector<string> valid_coupon_codes_list;
    mutable float sum; 

public:
    Restaurant(string name, string loc, initializer_list<string> menu, initializer_list<float> prices)
        : restaurant_name(name), location(loc), sum(0.0) {
        int i = 0;
        for (const auto& item : menu) {
            menu_list[i++] = item;
        }

        i = 0;
        for (const auto& price : prices) {
            price_list[i++] = price;
        }
    }

    void display_menu() const {
        cout << "Menu for " << restaurant_name << " (" << location << "):" << endl;
        for (int i = 0; i < 5; i++)
            cout << "[" << i << "]: " << menu_list[i] << " - $" << price_list[i] << endl;
    }

    void generate_bill(const int* quantity) const {
        sum = 0;
        cout << "\nBill for " << restaurant_name << ":" << endl;
        for (int i = 0; i < 5; i++) {
            if (quantity[i] != 0) {
                cout << "Item name: " << menu_list[i] << "\tQuantity: " << quantity[i] << " \tPrice: $" << price_list[i] * quantity[i] << endl;
                sum += (price_list[i] * quantity[i]);
            }
        }
        cout << "The total bill is: $" << sum << endl;
    }

    int apply_discount() const {
        int count = 0;
        for (const string& coupon : valid_coupon_codes_list) {
            for (const string& otherCoupon : valid_coupon_codes_list) {
                if (coupon == otherCoupon) count++;
            }

            if (count >= 2) {
                // applying a discount based on the count of valid coupons
                float discount = 0.1;  // 10% discount
                cout << "Discounted: $" << discount * sum << endl;
                return 1;
            }
        }
        return 0;
    }

    void add_coupon_code(const string& coupon_code) {
        valid_coupon_codes_list.push_back(coupon_code);
    }

    string getRestaurantName() const {
        return restaurant_name;
    }
};

class User {
private:
    string name;
    int age;
    long mobile_number;
    vector<string> coupons_list;
    vector<string> redeemed_coupons_list;

public:
    User(string name, int age, long mobile)
        : name(name), age(age), mobile_number(mobile) {}

    void accumulate_coupon(const string& coupon) {
        coupons_list.push_back(coupon);
    }

    bool has_valid_coupon(const Restaurant& restaurant, const string& item) const {
        for (const string& coupon : coupons_list) {
            if (coupon.find(restaurant.getRestaurantName()) != string::npos && coupon.find(item) != string::npos) {
                return true;
            }
        }
        return false;
    }

    bool redeem_coupon(const Restaurant& restaurant, const string& item, const string& coupon_code) {
        if (has_valid_coupon(restaurant, item)) {
            redeemed_coupons_list.push_back(coupon_code);
            return true;
        }
        return false;
    }
};

int main() {
    cout << "Programmer: Hafsa Rashid" << endl << "Student ID: 23K-0064" << endl << endl;
    Restaurant foodHaven("Food Haven", "City Center", {"Sushi", "Pad Thai", "Mango Tango"}, {500.0, 250.0, 387.50});
    Restaurant pixelBites("Pixel Bites", "Cyber Street", {"Binary Burger", "Quantum Quinoa", "Data Donuts"}, {670.0, 560.0, 899.99});

    User user("Alice", 25, 123456789);

    foodHaven.display_menu();
    pixelBites.display_menu();

    int quantityFoodHaven[] = {1, 0, 0, 0, 0}; 
    foodHaven.generate_bill(quantityFoodHaven);

    int quantityPixelBites[] = {2, 0, 0, 0, 0};
    pixelBites.generate_bill(quantityPixelBites);

    foodHaven.add_coupon_code("FH-BOGO-12345");
    foodHaven.apply_discount();

    string orderedItemPixelBites = "Binary Burger";
    string couponCodePixelBites = "PB-BOGO-67890";

    if (user.has_valid_coupon(pixelBites, orderedItemPixelBites)) {
        user.redeem_coupon(pixelBites, orderedItemPixelBites, couponCodePixelBites);
        cout << "Coupon redeemed successfully!" << endl;
    }

    return 0;
}
