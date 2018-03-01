// Name : Client.h

// Author : ZhenShu Jin

// Date : 2017-06-22

// Description : This is a file including a class which

// Copyright : Group 10

#ifndef CLIENT_H
#define CLIENT_H

#include "Funcbase.h"
#include "jiyi.h"
#include "Graph.h"
#include "Database.h"
#include "ManageWords.h"
#include "NewFrame.h"
#include "Referdic.h"
#include "WordNode.h"
#include "Viewfunc.h"
#include <iostream>

// Client -- A class made for Strategy pattern, including menu for clients.

class Client
{
public:
    Client();
    ~Client();
    void setStrategy(Funcbase*);   // set strategy for clients
    void Menu();                   // menu function for clients
private:
    Funcbase *_funcbase;           // define a pointer for virtual base class in order to use some useful functions such as exit system.
};

#endif
