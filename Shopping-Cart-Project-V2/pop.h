/* 
 * File:   pop.h
 * Author: Anthony Bliss
 *
 * Created on April 24, 2024, 10:17 AM
 */

#ifndef POP_H
#define POP_H

#include <string>
#include <fstream>
#include <iostream>
#include <limits>

struct Item
{
    int category;
    float price;
    char name[40];
    int quantity;
};

class Pop // DONE
{
    private:
        bool flag;
    
    public:
        Pop();
};

#endif /* POP_H */

// pop will create the file of base items for the store
// this file can be used by another class to display items and categories
// pop is only for initialization

// should only fill the file with items if it is being created for the first time
// otherwise it will overwrite any changes made by admin