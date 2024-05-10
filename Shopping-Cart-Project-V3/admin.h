/* 
 * File:   admin.h
 * Author: Anthony
 *
 * Created on May 6, 2024, 4:35 AM
 */

#ifndef ADMIN_H
#define ADMIN_H

#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdio>

#include "pop.h"
#include "user.h"

class Admin
{
    private:
        User users[50];
        Item items[100];
        Item list[50];  // Holds items in a category for editing/deleting
        std::string tempNm;
        int choice;
        int userIndex;
        int itemIndex;
        int listIndex;
        int catNum;
        bool end;
        float total;
        
    public:
        Admin();
        void accMenu();
        void itemMenu();
        void prntAcc();
        void editAcc();
        void delAcc();
        void addAcc();
        void loadAccs();
        void loadItems();
        void prntStore();
        void prntCat(int);
        void editItem();
        void delItem();
        void addItem();
        void printSales();
        void saveAccs();
        void saveItems();
};


#endif /* ADMIN_H */