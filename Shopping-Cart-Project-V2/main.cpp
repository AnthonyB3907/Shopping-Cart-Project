/* 
 * File:   main.cpp
 * Author: Anthony
 *
 * Created on April 24, 2024, 10:15 AM
 */

#include <cstdlib>
#include "login.h"
#include "shop.h"


int main(int argc, char** argv) {
    
    std::cout << std::fixed << std::setprecision(2);
    
    Login login;
    
    std::string account = login.getUser();
    
    Shop shop(account);
    
    return 0;
}

