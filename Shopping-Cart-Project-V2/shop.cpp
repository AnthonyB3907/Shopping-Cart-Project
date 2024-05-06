#include "shop.h"

Shop::Shop(std::string username)
{
    this->username = username;
    
    std::cout << std::setw(23) << " " << "Welcome, " << this->username << std::endl;
    
    startShop();
    
}

void Shop::startShop()
{
    Cart cart(this->username);
    cart.loadCart();
    endShop = false;
    std::string input = "";
    
    while (!endShop)
    {
        printStore();
        
        std::cout << std::setw(6) << " " << "Enter category number or type 'c' to view cart: ";
        std::getline(std::cin, input);
        std::cout << std::endl;
        
        if (input == "c" || input == "C")
        {
            cart.cartMenu();
            endShop = cart.getState();
        }
        else
        {
            std::istringstream convert(input);
            convert >> catNum;
            
            viewCat(cart);
        }
    }
}

void Shop::printStore()
{
    std::cout << std::endl;
    std::cout << std::setw(20) << " " << " ________________" << std::endl;
    std::cout << std::setw(20) << " " << "| Anthony's Shop |" << std::endl;
    std::cout << std::setw(20) << " " << "|________________|" << std::endl;
    std::cout << std::setw(20) << " " << "|   Categories   |" << std::endl;
    std::cout << std::setw(6) << " " << "----------------------------------------------" << std::endl;

    std::cout << std::setw(6) << " " << "| 1." << std::setw(11) << "Grocery" << std::setw(11) << "| 2.";
    std::cout << std::setw(16) << "House Supplies" << std::setw(4) << "|" << std::endl;
    std::cout << std::setw(6) << " " << "----------------------------------------------" << std::endl;
    std::cout << std::setw(6) << " " << "| 3." << std::setw(14) << "Pet Supplies" << std::setw(8) << "| 4.";
    std::cout << std::setw(13) << "Furniture" << std::setw(7) << "|" << std::endl;
    std::cout << std::setw(6) << " " << "----------------------------------------------" << std::endl;
    std::cout << std::setw(6) << " " << "| 5." << std::setw(10) << "Tools" << std::setw(12) << "| 6.";
    std::cout << std::setw(11) << "Movies" << std::setw(9) << "|" << std::endl;
    std::cout << std::setw(6) << " " << "----------------------------------------------" << std::endl;
    std::cout << std::setw(6) << " " << "| 7." << std::setw(15) << "Computer Parts" << std::setw(7) << "| 8.";
    std::cout << std::setw(14) << "Video Games" << std::setw(6) << "|" << std::endl;
    std::cout << std::setw(6) << " " << "----------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void Shop::viewCat(Cart& cart)
{
    std::fstream itemFile;
    std::string input;
    int itemNum;
    int quant;
    Item list[SIZE];
    
    endCat = false;
    
    itemFile.open("items.bin", std::ios::binary | std::ios::in);
    
    if (!itemFile)
    {
        std::cout << "Error opening items.bin in viewCat()";
        return;
    }
    
    fillList(itemFile, list, catNum);
    
    while (!endCat)
    {
        printCat(list, SIZE, catNum);
        
        std::cout << std::setw(6) << " " 
                  << "Enter item number, 'c' to view cart, or 'r' to return to categories: ";
        std::getline(std::cin, input);
        std::cout << std::endl;
        
        if (input == "c" || input == "C")
        {
            cart.cartMenu();
            endCat = cart.getState();
        }
        else if (input == "r" || input == "R")
            return;
        else
        {
            std::istringstream convert(input);
            convert >> itemNum;
            
            std::cout << std::setw(6) << " " 
                      << "Enter quantity (Max 50) (0 to return to list): ";
            std::cin >> quant;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            
            if (quant == 0)
                continue;
            else
            {
                char choice;
                
                cart.addCart(list, itemNum, quant);
                
                std::cout << std::setw(6) << " " 
                          << "Add another item from this category? (y/n) : ";
                std::cin >> choice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                std::cout << std::endl;
                
                choice = tolower(choice);
                
                if (choice == 'y')
                    continue;
                else if (choice == 'n')
                    endCat = true;
            }
        }
    }
    
    itemFile.close();
}

void Shop::fillList(std::fstream& itemFile, Item* list, int catNum)
{
    int index = 0;
    
    // loops until 10 items found or end of file reached
    // if the user selected category = the category read from file, increment and keep data
    while (index < SIZE && itemFile.read(reinterpret_cast<char*>(&list[index]), sizeof(Item)))
    {
        if (list[index].category == catNum)
            index++;
    }
}

void Shop::printCat(const Item* list, const int SIZE, int catNum)
{
    std::string catNames[8] = {"Grocery", "House Supplies", "Pet Supplies", "Furniture",
                               "Tools", "Movies", "Computer Parts", "Video Games"};
    
    std::cout << "\n\n";
    std::cout << std::setw(7) << " " << catNames[catNum - 1] << std::endl;
    std::cout << std::setw(6) << " " << "------------------------------------------" << std::endl;
    
    for (int i = 0; i < SIZE; i++)
    {
        std::string nums = "[" + std::to_string(i + 1) + "]";
        
        std::cout << std::setw(6) << " " 
                  << std::setw(5) << std::left << nums
                  << std::setw(27) << std::left << list[i].name
                  << std::setw(5) << std::right 
                  << "$" << std::fixed << std::setprecision(2) << list[i].price 
                  << std::endl << std::endl;
    }
    
    std::cout << std::endl;
}