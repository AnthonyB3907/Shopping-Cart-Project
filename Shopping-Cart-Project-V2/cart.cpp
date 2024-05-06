#include <c++/iosfwd>
#include <c++/bits/ios_base.h>

#include "cart.h"


Cart::Cart(std::string username)
{
    this->username = username;
    this->itemCount = 0;
    this->shopState = false;
    this->input = 0;
    this->filename = username + ".bin";
}

void Cart::loadCart()
{
    std::fstream cartFile;
    
    cartFile.open(filename, std::ios::binary | std::ios::in | std::ios::out);
    
    if (!cartFile)
    {
        std::cout << "Error opening filename in Cart()" << std::endl;
    }
    else if (cartFile) // checks if username.bin is empty
    {
        cartFile.seekg(0L, std::ios::end);
        int numBytes = cartFile.tellg();
        
        if (numBytes == 0)
        {
            this->shopState = false;
            return;
        }
    }
    
    cartFile.seekg(0L, std::ios::beg);
    
    // keeps reading item data into userCart until no more to write or somehow more than 50 items
    while (itemCount < 50 && cartFile.read(reinterpret_cast<char*>(&userCart[itemCount]), sizeof(Item)))
        itemCount++;
    
    cartFile.close();
}

void Cart::cartMenu()
{
    float total = 0.0;
    
    if (itemCount == 0)
    {
        std::cout << std::setw(6) << " " << "[Your cart is empty!]" << std::endl;
        shopState = false;
        return;
    }
    
    printCart();
    
    std::cout << std::setw(6) << " " << "[1] Checkout [2] Edit Cart [3] Return : ";
    std::cin >> input;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << std::endl;
    
    if (input == 1)
        checkout();
    else if (input == 2)
    {
        std::cout << std::setw(6) << " " << "[1] Change Quantity [2] Delete an Item : ";
        std::cin >> input;
        
        if (input == 1)
            changeQuant();
        else
            deleteItem();
    }
    else
        return;
}

void Cart::addCart(Item* list, int itemNum, int quant)
{
    // itemCount will = the first empty record in userCart before increment
    userCart[itemCount] = list[itemNum - 1];
    userCart[itemCount].quantity = quant;
    itemCount++;
    saveCart();
}

void Cart::saveCart()
{
    // overwrite cart data
    std::fstream cartFile(filename, std::ios::binary | std::ios::out);
    
    if (!cartFile)
    {
        std::cout << "Error opening username.bin in saveCart()";
        return;
    }
    
    // itemCount - 1 = amount of items in userCart
    cartFile.write(reinterpret_cast<char*>(&userCart), (itemCount) * sizeof(Item));
    
    cartFile.close();
}

void Cart::deleteItem()
{
    int input = 0;
    char choice;
    bool flag = true;
    
    printCart();
    
    while (flag)
    {
        std::cout << "Enter item number to delete: ";
        std::cin >> input;

        if (input == itemCount)
            itemCount--;
        else
        {
            for (int i = input - 1; i < itemCount - 1; i++)
                userCart[i] = userCart[i + 1];

            itemCount--;
        }

        saveCart();
        
        std::cout << std::setw(6) << " " << "Item successfully deleted!" << std::endl;
        std::cout << std::setw(6) << " " << "Delete another item? (y/n): ";
        std::cin >> choice;
        choice = tolower(choice);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (choice == 'y')
            continue;
        else
            flag = false;
        
    }
}

void Cart::changeQuant()
{
    int input = 0;
    int quant = 0;
    
    printCart();
    
    std::cout << std::setw(6) << " " <<  "Enter item number: ";
    std::cin >> input;
    
    std::cout << std::setw(6) << " " <<  "Enter new quantity: ";
    std::cin >> quant;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    userCart[input - 1].quantity = quant;
    
    saveCart();
}

void Cart::printCart()
{
    float total = 0.0;
    
    std::cout << std::setw(6) << " " << " ___________" << std::endl;
    std::cout << std::setw(6) << " " << "| Your Cart |" << std::endl;
    std::cout << std::setw(6) << " " << "------------------------------------------------" << std::endl;
    
    for (int i = 0; i < itemCount; i++)
    {
        std::string nums = "[" + std::to_string(i + 1) + "]";
        std::string quants = "x" + std::to_string(userCart[i].quantity);
        float totalItem = userCart[i].price * userCart[i].quantity;
        
        std::cout << std::setw(6) << " " 
                  << std::setw(5) << std::left << nums
                  << std::setw(27) << std::left << userCart[i].name
                  << std::setw(5) << std::right << quants
                  << std::setw(5) << std::right 
                  << "$" << std::fixed << std::setprecision(2) << totalItem 
                  << std::endl << std::endl;
        
        total += totalItem;
    }
    
    std::cout << std::setw(6) << " " << "Total: [$" << total << "]" << std::endl << std::endl;
}

void Cart::checkout()
{
    char input;
    
    printCart();
    
    std::cout << std::setw(6) << " " << "Confirm checkout? (y/n): ";
    std::cin >> input;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (input == 'y')
    {
        std::cout << std::setw(6) << " " << "Checkout successful! Thank you for shopping" << std::endl;
        shopState = true;
        saveSale();
        std::fstream flush(filename, std::ios::binary | std::ios::out);
        flush.close();
    }
    else
        return;
}

void Cart::saveSale() // append - will just be a record of sales
{
    std::fstream sales("sales.bin", std::ios::binary | std::ios::out | std::ios::app);
    
    sales.write(reinterpret_cast<char*>(&userCart), (itemCount) * sizeof(Item));
    
    sales.close();
}

bool Cart::getState()
{
    return shopState;
}