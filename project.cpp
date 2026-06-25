#include <iostream>
#define TAX_RATE 0.12 

int main() {

    std::cout << "*********Project Sales and Inventory******************\n";

    std::cout << "*   Welcome to the Product Sales and Inventory      *\n";
    std::cout << "*   Analysis Program!                               *\n";

    std::cout << "*****************************************************\n\n";

    std::cout << "This program helps store owners track inventory and sales efficiently. 📊\n";
    std::cout << "Reminder: C++ is a compiled language, meaning it must be compiled before execution. ⚙️\n\n";
    
    // Declaring Variables
    std::string productName;
    int productCategory;
    int initialInventoryQuantity;
    float productPricePerUnit;
    int numberOfItemsSold;

    
    std::cout << "Enter Product Name (single word): ";
    std::cin >> productName;
    
    std::cout << "Enter Product Category (1 to 5): ";
    std::cin >> productCategory;
    
    std::cout << "Enter Initial Inventory Quantity: ";
    std::cin >> initialInventoryQuantity;
    
    std::cout << "Enter Product Price per Unit: ";
    std::cin >> productPricePerUnit;
    
    std::cout << "Enter Number of Items Sold: ";
    std::cin >> numberOfItemsSold;

    
    int newInventory = initialInventoryQuantity - numberOfItemsSold; // Compound assignment
    float totalSales = numberOfItemsSold * productPricePerUnit;
    std::string inventoryStatus = (newInventory < 10) ? "Low Inventory" : "Sufficient Inventory";

    int a = 5;       // Direct initialization
    double b {9.68}; // List initialization
    std::string c = "Abel"; 
    int d;
    d = 71; 

    auto salesHelper = totalSales;
    decltype(initialInventoryQuantity) extraInventory = 90;

    
    const float taxRate = 0.12;

    
    if (productCategory >= 1 && productCategory <= 5) {
        std::cout << "Valid product category.\n";
        switch (productCategory) {
            case 1: 
            std::cout << "Category 1: Electronics\n"; 
            break;
            case 2: 
            std::cout << "Category 2: Groceries\n"; 
            break;
            case 3: 
            std::cout << "Category 3: Clothing\n"; 
            break;
            case 4: 
            std::cout << "Category 4: Stationery\n"; 
            break;
            case 5: 
            std::cout << "Category 5: Miscellaneous\n"; 
            break;
        }
    } else {
        std::cout << "Invalid product category. Please enter a category between 1 and 5.\n";
    }

    
    std::cout << "\n*********************** Receipt ***********************\n";

    std::cout << "Item #   Price\n";
    std::cout << "--------------------------------------\n";
    for (int i = 1; i <= numberOfItemsSold; ++i) {
        std::cout << "Item " << i << "   $" << productPricePerUnit << '\n';
    }
    std::cout << "-----------------------------\n";
    std::cout << "Total: $" << totalSales << '\n';
    
    std::cout << "********************** Thank you for shopping! **********************\n";

   
    std::cout << "\nTax Rate (Preprocessor): " << TAX_RATE << '\n';
    std::cout << "Tax Rate (const variable): " << taxRate << '\n';
    std::cout << "\n--- Product Summary ---\n";
    std::cout << "Product Name: " << productName << '\n';
    std::cout << "Category: " << productCategory << '\n';
    std::cout << "Initial Inventory: " << initialInventoryQuantity << '\n';
    std::cout << "Product Price: $" << productPricePerUnit << '\n';
    std::cout << "Items Sold: " << numberOfItemsSold << '\n';
    std::cout << "New Inventory: " << newInventory << '\n';
    std::cout << "Total Sales: $" << totalSales << '\n';
    std::cout << "Inventory Status: " << inventoryStatus << '\n';

    std::cout << "\n--- Helper Variables ---\n";
    std::cout << "Sales Helper (auto): $" << salesHelper << '\n';
    std::cout << "Extra Inventory (decltype): " << extraInventory << '\n';

    return 0;
}