/* 
 * File:   shop.h
 * Author: Anthony
 *
 * Created on May 1, 2024, 1:39 PM
 */

#ifndef SHOP_H
#define SHOP_H

#include <sstream>

#include "cart.h"

class Shop
{
    private:
        const int SIZE = 10;
        bool endShop;
        bool endCat;        // no cats were harmed with this variable
        int catNum;
        std::string username;
        
    public:
        Shop(std::string);
        void startShop();
        void printStore(); // categories are hardcoded
        void viewCat(Cart&);
        void fillList(std::fstream&, Item*, int);
        void printCat(const Item*, const int, int);
};



#endif /* SHOP_H */

