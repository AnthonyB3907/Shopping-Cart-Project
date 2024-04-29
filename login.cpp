#include "login.h"
#include "pop.h"

Login::Login() // DONE
{
    flag = false;
    int choice = 0;
    
    Pop();
    createAdmin();
    
    std::cout << "Welcome to Anthony's Shop!" << std::endl;
    std::cout << "Type 1 to log in or 2 to register a new account" << std::endl;
    std::cin >> choice;
    
    if (choice == 1)
        accLogin();
    else if (choice == 2)
        newLogin();
    
}

void Login::createAdmin() // DONE
{
    std::fstream admin;
    
    std::strcpy(user.usern, "admin");
    std::strcpy(user.passw, "adminpass");
    
    admin.open("admin.bin", std::ios::binary | std::ios::out);
    
    if (!admin)
    {
        std::cout << "Error creating admin.bin" << std::endl;
        return;
    }
    
    admin.write(reinterpret_cast<char*>(&user), sizeof(User));
    
    admin.close();
}

void Login::accLogin() // DONE
{
    std::cout << "\nEnter Username" << std::endl;
    std::cin >> user.usern;
    std::cout << "Enter Password" << std::endl;
    std::cin >> user.passw;
    
    std::string tempU = user.usern;
    std::string tempP = user.passw;

    if (tempU == "admin" && tempP == "adminpass")
    {    
        std::cout << "Admin Trigger in accLogin" << std::endl; // DEBUG
        //Admin();
        return;
    }
    
    // ios::in by itself reads from the start. if file doesnt exist, error
    std::fstream logins;
    logins.open("user.bin", std::ios::in | std::ios::binary);
    if (!logins)
    {
        std::cout << "No user accounts exist" << std::endl;
        std::cout << "Register a new account" << std::endl;
        newLogin();
        return;
    }
    
    flag = false;
    
    while (!flag)
    {
        User temp;
        
        logins.clear();
        logins.seekg(0, std::ios::beg);
        
        tempU = user.usern;
        tempP = user.passw;
        
        while (!logins.eof())
        {
            logins.read(reinterpret_cast<char*>(&temp), sizeof(User));
            
            if (temp.usern == tempU && temp.passw == tempP) // compare temp to string to avoid login bug
            {
                flag = true;
                std::cout << "Login Successful!" << std::endl;
                std::cout << "loadData triggered in accLogin" << std::endl; // DEBUG
                return;                                                     // DEBUG
                //loadData(user);
            }
        }
    
        if (!flag)
        {
            std::cout << "Username or Password Not Found" << std::endl;
            std::cout << "\nEnter Username" << std::endl;
            std::cin >> user.usern;
            std::cout << "Enter Password" << std::endl;
            std::cin >> user.passw;
        }
    }
    
    logins.close();
}

void Login::newLogin() // DONE
{
    std::fstream newLog;
    int count = 0;
    
    flag = false;
    
    while(!flag) // loops until file is opened succesfully. file created if it doesnt exist
    {
        // ios::in by itself reads from the start. if file doesnt exist, error
        newLog.open("user.bin", std::ios::in | std::ios::binary);
        if (!newLog)
        {
            newLog.open("user.bin", std::ios::out | std::ios::binary);
            newLog.close();
            flag = false;
        }
        else if (newLog)
        {
            flag = true;
            newLog.close();
        }
    }
    
    flag = false;
    
    std::cout << "\nEnter New Username" << std::endl;
    std::cin >> user.usern;
    std::cout << "Enter New Password" << std::endl;
    std::cin >> user.passw;
    
    std::string tempU = user.usern;
    std::string tempP = user.passw;
    
    while (!flag)
    {
        User temp;
        
        newLog.open("user.bin", std::ios::binary | std::ios::in);
        
        tempU = user.usern;
        tempP = user.passw;
        count = 0;
        
        while (!newLog.eof()) // adds 1 to count if entered uname matches existing uname
        {
            newLog.read(reinterpret_cast<char*>(&temp), sizeof(User));
            
            if (temp.usern == tempU)
                count++;
        }
        
        newLog.close();
        
        if (count == 0) // count 0 means entered uname isnt taken
        {
            // opens binary file for writing. data written to the end of the file
            newLog.open("user.bin", std::ios::binary | std::ios::out | std::ios::app);
            
            if (!newLog)
            {
                std::cout << "Error opening user.bin in newLogin() for writing" << std::endl;
                return;
            }
            
            newLog.write(reinterpret_cast<char*>(&user), sizeof(User));
            newLog.close();
            
            std::cout << "Account " << user.usern << " created!" << std::endl;
            flag = true;
            std::cout << "Login Successful!" << std::endl;
            std::cout << "newData triggered in newLogin" << std::endl; // DEBUG
            return;                                                    // DEBUG
            // newData(user);
        }
        else if (count > 0)
        {
            std::cout << "Username already exists" << std::endl;
            std::cout << "\nEnter a Different Username" << std::endl;
            std::cin >> user.usern;
            std::cout << "Enter Password" << std::endl;
            std::cin >> user.passw;
        }
    }
}

/*void Login::loadData()
{
    // load items file and cart data
    return;
}

void Login::newData()
{
    // load items file and create cart for new user
    return;
}*/