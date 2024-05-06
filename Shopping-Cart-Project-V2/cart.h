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
        Cart(std::string); // load cart data from username.bin into UserCart
                    // if empty, cart is empty, say nothing is in it
                // print cart then ask if they want to checkout if there are items in it
                // or edit cart
                    // delete or change quantity - call relevant functions
        
        void loadCart();
        
        void cartMenu();
        
        void addCart(Item*, int, int); // add data to UserCart and call saveCart
        
        void saveCart(); // save current UserCart to binary file
                            // will use username.bin fstream
        
        void deleteItem(); // print cart, ask item num to delete, delete item then save cart
                            // overwrite the current cart data in the file
        
        void changeQuant(); // just change UserCart.quantity then save cart
                            // overwrite the current cart data in the file
        
        void printCart(); // print up to itemCount
        
        void checkout(); // call saveSale once user checks out
        
        void saveSale(); // save UserCart, can calculate and show totals in admin
        
        bool getState(); // return this->shopState, should be false if user doesnt check out
        
};

#endif /* CART_H */

