/* 
 * File:   cart.h
 * Author: Anthony
 *
 * Created on May 1, 2024, 1:43 PM
 */

#ifndef CART_H
#define CART_H

#include <iomanip>
#include <cctype>

#include "pop.h"

class Cart
{
    private:
        Item userCart[50];
        bool shopState;
        int itemCount;
        int input;
        std::string username;
        std::string filename;
        
    public:
        Cart(std::string); 
        void loadCart();
        void cartMenu();
        void addCart(Item*, int, int); 
        void saveCart(); 
        void deleteItem(); 
        void changeQuant(); 
        void printCart(); 
        void checkout(); 
        void saveSale(); 
        bool getState(); 
        
};

#endif /* CART_H */

