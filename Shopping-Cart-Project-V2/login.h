/* 
 * File:   login.h
 * Author: Anthony
 *
 * Created on April 24, 2024, 2:22 PM
 */

#ifndef LOGIN_H
#define LOGIN_H

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
        Login();
        void createAdmin();
        void accLogin();
        void newLogin();
        void newData();
        std::string getUser();
        
};

#endif /* LOGIN_H */