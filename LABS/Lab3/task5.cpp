#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class StationeryShop
{
private:
    string itemList[100];
    double itemPrices[100] = {0.0};
    int itemQuantities[100] = {0};  // Added array for item quantities in stock
    int itemCount;

public:
    // Constructor
    StationeryShop()
    {
        itemCount = 0;
    }

    void addItem(const string& itemName, double price, int initialQuantity)
    {
        if (itemCount < 100)
        {
            itemList[itemCount] = itemName;
            itemPrices[itemCount] = price;
            itemQuantities[itemCount] = initialQuantity;
            itemCount++;
            cout << itemName << " added successfully.\n";
        }
        else
        {
            cout << "Maximum number of items added. Cannot add more items.\n";
        }
    }

    void displayItemsPrices() const
    {
        cout << "List of all items with prices: \n";
        for (int i = 0; i < itemCount; i++)
        {
            cout << "Item " << i + 1 << ": " << itemList[i] << " Price: $ " << itemPrices[i] << "\n";
        }
    }

    void displayItemsList() const
    {
        cout << "List of all items: \n";
        for (int i = 0; i < itemCount; i++)
        {
            cout << "Item " << i + 1 << ": " << itemList[i] << "\n";
        }
    }

    void modifyPrice(const string& itemName, double newPrice)
    {
        int flag = 0;
        for (int i = 0; i < itemCount; i++)
        {
            if (itemList[i] == itemName)
            {
                itemPrices[i] = newPrice;
                cout << "Price of " << itemList[i] << " updated!\n";
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "Item not found in the list.\n";
        }
    }

    void generateReceipt(const int itemsPurchased[], const int quantities[]) const
    {
        double totalAmount = 0.0;
        cout << "Receipt: \n";
        for (int i = 0; i < itemCount; i++)
        {
            if (itemsPurchased[i] != 0)
            {
                cout << "Item: " << itemList[itemsPurchased[i] - 1] << " Quantity: " << quantities[i] << "\n";
                totalAmount += itemPrices[itemsPurchased[i] - 1] * quantities[i]; // Calculation of the final sum
            }
        }
        cout << "Total Amount = $" << fixed << setprecision(2) << totalAmount << "\n";
    }

    void displayTotalInventory() const
    {
        cout << "Total Inventory: \n";
        for (int i = 0; i < itemCount; i++)
        {
            cout << "Item " << i + 1 << ": " << itemList[i] << " Quantity in Stock: " << itemQuantities[i] << "\n";
        }
    }
};

int main()
{
    StationeryShop myShop;
    int menu;
    do   {
        cout << "\nStationery Shop Menu:\n";
        cout << "1. Add Items\n";
        cout << "2. Display List of Items\n";
        cout << "3. Modify Price of an Item\n";
        cout << "4. Display Items with Prices\n";
        cout << "5. Generate Receipt\n";
        cout << "6. Display Total Inventory\n";  // New option
        cout << "Any other number to exit the shop.\n";
        cout << "Enter menu number: ";
        cin >> menu;

        string itemName;
        double price;

        int quantities[100] = {0};        // To store the quantity of individual items purchased by the customer
        int purchasedItems[100] = {0};   // To store the index values of the items purchased by the customer

        switch (menu)
        {
        case 1:
            cout << "Enter name of the item: ";
            cin.ignore();
            getline(cin, itemName);
            cout << "Enter price of the item: $";
            cin >> price;

            int initialQuantity;
            cout << "Enter initial stock quantity: ";
            cin >> initialQuantity;

            myShop.addItem(itemName, price, initialQuantity);
            break;
        case 2:
            myShop.displayItemsList();
            break;
        case 3:
            cout << "Enter name of the item you would like to update its price: ";
            cin.ignore();
            getline(cin, itemName);
            cout << "Enter new price of the item: $";
            cin >> price;

            myShop.modifyPrice(itemName, price);
            break;
        case 4:
            myShop.displayItemsPrices();
            break;
        case 5:
            int itemIndex, quantity;

            // Loop to keep asking what things the customer wants to buy again and again.
            while (true)
            {
                cout << "Enter item index number (press 0 to stop): ";
                cin >> itemIndex;
                if (itemIndex == 0)
                {
                    break;
                }
                cout << "Enter quantity of item: ";
                cin >> quantity;
                purchasedItems[itemIndex - 1] = itemIndex;
                quantities[itemIndex - 1] = quantity;
            }

            myShop.generateReceipt(purchasedItems, quantities); // Generate receipt
            break;
        case 6:
            myShop.displayTotalInventory();
            break;
        default:
            cout << "Shop is closing now.\n";
            break;
        }
    } while (menu >= 1 && menu <= 6);

    return 0;
}
