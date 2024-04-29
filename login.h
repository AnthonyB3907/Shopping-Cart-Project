/* 
 * File:   login.h
 * Author: Anthony
 *
 * Created on April 24, 2024, 2:22 PM
 */

#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "pop.h"

struct User
{
    char usern[40];
    char passw[40];
};

class Login
{
    private:
        User user;
        bool flag;
        
    public:
        Login(); // DONE
        void createAdmin(); // DONE
        void accLogin(); // DONE
        void newLogin(); // DONE
        void loadData(User& user);
        void newData(User& user);
        
};

#endif /* LOGIN_H */