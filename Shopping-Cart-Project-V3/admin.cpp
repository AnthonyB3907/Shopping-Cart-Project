#include "admin.h"

Admin::Admin()
{
    loadAccs();
    loadItems();
    
    end = false;
    
    while (!end)
    {
        std::cout << std::endl;
        std::cout << std::setw(6) << " " << "  Admin Control" << std::endl;
        std::cout << std::setw(6) << " " << "-----------------" << std::endl;
        std::cout << std::setw(6) << " " << "[1] Accounts" << std::endl;
        std::cout << std::setw(6) << " " << "[2] Items" << std::endl;
        std::cout << std::setw(6) << " " << "[3] View Sales" << std::endl;
        std::cout << std::setw(6) << " " << "[4] Log Out" << std::endl;
        std::cout << std::setw(6) << " " << "\nEnter menu number: ";
        std::cin >> choice;

        if (choice == 1)
        {
            accMenu();
            continue;
        }
        else if (choice == 2)
        {
            itemMenu();
            continue;
        }
        else if (choice == 3)
        {
            int input;
            printSales();
            std::cout << std::setw(6) << " " << "[1] Admin Control  [2] Exit : ";
            std::cin >> input;
            
            if (input == 1)
                continue;
            else if (input == 2)
                end = true;
        }
        else
            end = true;
        
        loadAccs();
        loadItems();
    }  
}

void Admin::accMenu()
{
    while (true)
    {
        std::cout << std::endl;
        std::cout << std::setw(6) << " " << "  Accounts" << std::endl;
        std::cout << std::setw(6) << " " << "-----------------" << std::endl;
        std::cout << std::setw(6) << " " << "[1] View Accounts" << std::endl;
        std::cout << std::setw(6) << " " << "[2] Admin Control" << std::endl;
        std::cout << std::setw(6) << " " << "\nEnter menu number: ";
        std::cin >> choice;
        
        if (choice == 1)
        {
            int input;
            prntAcc();
            
            std::cout << std::setw(6) << " " 
                      << "[1] Edit  [2] Add  [3] Delete  [4] Admin Control: ";
            std::cin >> input;
            
            if (input == 1)
                editAcc();
            else if (input == 2)
                addAcc();
            else if (input == 3)
                delAcc();
            else
                break;
        }
        else
            break;
    }
    
}

void Admin::itemMenu()
{
    while (true)
    {
        std::cout << std::endl;
        std::cout << std::setw(6) << " " << "  Items" << std::endl;
        std::cout << std::setw(6) << " " << "-----------------" << std::endl;
        std::cout << std::setw(6) << " " << "[1] View Items" << std::endl;
        std::cout << std::setw(6) << " " << "[2] Admin Control" << std::endl;
        std::cout << std::endl;
        std::cout << std::setw(6) << " " << "Enter menu number: ";
        std::cin >> choice;
        
        if (choice == 1)
        {
            int input;
            prntStore();
            
            std::cout << std::setw(6) << " " << "Enter category number: ";
            std::cin >> catNum;
            
            prntCat(catNum);
            
            std::cout << std::setw(6) << " " 
                      << "[1] Edit  [2] Add  [3] Delete  [4] Admin Control : ";
            std::cin >> input;
            
            if (input == 1)
                editItem();
            else if (input == 2)
                addItem();
            else if (input == 3)
                delItem();
            else
                break;
        }
        else
            break;
    }
}

void Admin::prntAcc()
{
    std::cout << std::endl;
    std::cout << std::setw(6) << " " << "  Users" << std::endl;
    std::cout << std::setw(6) << " " << "-----------------" << std::endl;
    
    for (int i = 0; i < userIndex; i++)
    {
        std::cout << std::setw(6) << " " << users[i].usern << std::endl;
    }
}

void Admin::editAcc()
{
    std::string name = "";
    std::string pass = "";
    int input;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << std::setw(6) << " " << "Enter username of the account you want to edit: ";
    std::getline(std::cin, name);
    
    for (int i = 0; i < userIndex - 1; i++)
    {
        if (users[i].usern == name)
        {
            pass = users[i].passw;
            break;
        }
    }
    
    std::cout << std::setw(6) << " " << "[1] Change username  [2] Change password: ";
    std::cin >> input;
    
    if (input == 1)
    {
        std::string newUser = "";
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::cout << std::setw(6) << " " << "Enter new username for " << name << ": ";
        std::getline(std::cin, newUser);
        
        for (int i = 0; i < userIndex - 1; i++)
        {
            if (users[i].usern == name)
            {
                strcpy(users[i].usern, newUser.c_str());
                break;
            }
        }
        
        std::cout << std::setw(6) << " " << "Username updated" << std::endl;
        
        std::string oldFile = name + ".bin";
        std::string newFile = newUser + ".bin";
        
        std::rename(oldFile.c_str(), newFile.c_str());
        
        saveAccs();
    }
    else
    {
        std::string newPass = "";
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::cout << std::setw(6) << " " << "Enter new password for " << name << ": ";
        std::getline(std::cin, newPass);
        
        for (int i = 0; i < userIndex - 1; i++)
        {
            if (users[i].passw == pass)
            {
                strcpy(users[i].passw, newPass.c_str());
                
                std::cout << "users[i].passw after changing: " 
                          << users[i].passw << std::endl; // DEBUG
                break;
            }
        }
        
        std::cout << std::setw(6) << " " << "Password updated" << std::endl;
        
        saveAccs();
    }
}

void Admin::delAcc()
{
    std::string name = "";
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << std::setw(6) << " " 
              << "Enter username of the account you want to delete: ";
    std::getline(std::cin, name);

    if (users[userIndex - 1].usern == name)
        userIndex--;
    else
        for (int i = 0; i < userIndex; i++)
        {
            if (users[i].usern == name)
            {
                for (int j = i; i < userIndex; i++)
                {
                    strcpy(users[j].usern, users[j + 1].usern);
                    strcpy(users[j].passw, users[j + 1].passw);
                }
                
                userIndex--;
                break;
            }
        }
    
    saveAccs();
}

void Admin::addAcc()
{
    std::string name = "";
    std::string pass = "";
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << std::setw(6) << " " << "Enter username for new account: ";
    getline(std::cin, name);
    std::cout << std::setw(6) << " " << "Enter password for new account: ";
    getline(std::cin, pass);
    
    strcpy(users[userIndex].usern, name.c_str());
    strcpy(users[userIndex].passw, pass.c_str());
    
    // create file for new user - will be used for cart data
    std::fstream itemFile;
    std::string filename = name + ".bin";
    
    itemFile.open(filename, std::ios::binary | std::ios::out);
    if (!itemFile)
    {
        std::cout << "Error opening filename in addAcc()";
        return;
    }
    
    itemFile.close();
    
    userIndex++;
    
    saveAccs();
}

void Admin::loadAccs()
{
    std::fstream userFile("user.bin", std::ios::binary | std::ios::in);
    
    userIndex = 0;
    
    while(userFile.read(reinterpret_cast<char*>(&users[userIndex]), sizeof(User)))
        userIndex++;
    
    userFile.close();
}

void Admin::loadItems()
{
    std::fstream itemFile("items.bin", std::ios::binary | std::ios::in);
    
    itemIndex = 0;
    
    while(itemFile.read(reinterpret_cast<char*>(&items[itemIndex]), sizeof(Item)))
        itemIndex++;
    
    itemFile.close();
}

void Admin::prntStore()
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

void Admin::prntCat(int catNum)
{
    std::string catNames[8] = {"Grocery", "House Supplies", "Pet Supplies", "Furniture",
                               "Tools", "Movies", "Computer Parts", "Video Games"};
    
    std::cout << "\n\n";
    std::cout << std::setw(7) << " " << catNames[catNum - 1] << std::endl;
    std::cout << std::setw(6) << " " << "------------------------------------------" << std::endl;
    
    std::fstream itemFile;
    
    itemFile.open("items.bin", std::ios::binary | std::ios::in);
    
    if (!itemFile)
    {
        std::cout << "Error opening items.bin in prntCat()";
        return;
    }
    
    listIndex = 0;
    
    // if the user selected category = the category read from file, increment and keep data
    while (itemFile.read(reinterpret_cast<char*>(&list[listIndex]), sizeof(Item)))
    {
        if (list[listIndex].category == catNum)
            listIndex++;
    }
    
    for (int i = 0; i < listIndex; i++)
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

void Admin::editItem()
{
    int num;
    
    std::cout << std::setw(6) << " " << "Enter item number from the list to edit: ";
    std::cin >> num;
    
    tempNm = list[num - 1].name;
    std::cout << std::endl;
    std::cout << std::setw(6) << " " << list[num - 1].name << std::endl;
    std::cout << std::setw(6) << " " << "-----------------" << std::endl;
    std::cout << std::setw(6) << " " << "Category: "
              << list[num - 1].category << std::endl;
    std::cout << std::setw(6) << " " << "Price: "
              << list[num - 1].price << std::endl;
    
    std::cout << std::setw(6) << " " 
              << "[1] Edit name  [2] Edit price" << std::endl;
    std::cin >> num;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (num == 1)
    {
        std::string newN;
        std::cout << std::setw(6) << " " << "Enter new item name: ";
        std::getline(std::cin, newN);
        
        for (int i = 0; i < itemIndex; i++)
        {
            if (tempNm == items[i].name)
                strcpy(items[i].name, newN.c_str());
        }
    }
    else if (num == 2)
    {
        float tempNum = 0.0;
        
        std::cout << std::setw(6) << " " << "Enter new item price: ";
        std::cin >> tempNum;
        
        for (int i = 0; i < itemIndex; i++)
        {
            if (tempNm == items[i].name)
                items[i].price = tempNum;
        }
    }
    
    std::cout << std::setw(6) << " " << "Changes saved" << std::endl;
    
    saveItems();
}

void Admin::delItem()
{
    int num;
    
    std::cout << std::setw(6) << " " << "Enter item number from the list to delete: ";
    std::cin >> num;
    
    tempNm = list[num - 1].name;
    
    if (items[itemIndex - 1].name == tempNm)
        itemIndex--;
    else
        for (int i = 0; i < itemIndex; i++)
        {
            if (items[i].name == tempNm)
            {
                for (int j = i; j < itemIndex; j++)
                {
                    strcpy(items[j].name, items[j + 1].name);
                    items[j].category = items[j + 1].category;
                    items[j].price = items[j + 1].price;
                    items[j].quantity = items[j + 1].quantity;
                }

                itemIndex--;
                break;
            }
        }
    
    saveItems();
    
    std::cout << std::setw(6) << " " << "Changes saved" << std::endl;
}

void Admin::addItem()
{
    float price = 0.0;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << std::setw(6) << " " << "Enter item name for the new item: ";
    std::getline(std::cin, tempNm);
    
    strcpy(items[itemIndex].name, tempNm.c_str());
    items[itemIndex].category = catNum;
    items[itemIndex].quantity = 0;
    std::cout << std::setw(6) << " " << "Enter price for the new item: ";
    std::cin >> items[itemIndex].price;
    
    itemIndex++;
    
    saveItems();
    
    std::cout << std::setw(6) << " " << "Item added" << std::endl;
}

void Admin::printSales()
{
    Item sales[100];
    int salesCount = 0;
    total = 0.0;
    
    std::fstream salesFile("sales.bin", std::ios::binary | std::ios::in);
    
    while(salesFile.read(reinterpret_cast<char*>(&sales[salesCount]), sizeof(Item)))
        salesCount++;
    
    std::cout << std::endl;
    std::cout << std::setw(6) << " " << "Sales" << std::endl;
    std::cout << std::setw(6) << " " 
              << "------------------------------------------------" << std::endl;
    
    for (int i = 0; i < salesCount; i++)
    {
        std::string nums = "[" + std::to_string(i + 1) + "]";
        std::string quants = "x" + std::to_string(sales[i].quantity);
        float totalItem = sales[i].price * sales[i].quantity;
        
        std::cout << std::setw(6) << " " 
                  << std::setw(5) << std::left << nums
                  << std::setw(27) << std::left << sales[i].name
                  << std::setw(5) << std::right << quants
                  << std::setw(5) << std::right 
                  << "$" << std::fixed << std::setprecision(2) << totalItem 
                  << std::endl << std::endl;
        
        total += totalItem;
    }
    
    std::cout << std::setw(6) << " " << "Total: [$" 
              << total << "]" << std::endl << std::endl;
    
    salesFile.close();
}

void Admin::saveAccs()
{
    std::fstream accFile("user.bin", std::ios::binary | std::ios::out);
    
    accFile.write(reinterpret_cast<char*>(&users), (userIndex) * sizeof(User));
    
    accFile.close();
}

void Admin::saveItems()
{
    std::fstream itemFile("items.bin", std::ios::binary | std::ios::out);
    
    itemFile.write(reinterpret_cast<char*>(&items), (itemIndex) * sizeof(Item));
    
    itemFile.close();
}