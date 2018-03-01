// Name : NewFrame.h

// Author : ZhenShu Jin

// Date : 2017-06-22

// Description : This is a file including a class which we can use to memorize my vocabulary.

// Copyright : Group 10

#ifndef NEWFRAME_H
#define NEWFRAME_H

#include "WordNode.h"
#include "DataBase.h"
#include "Funcbase.h"
#include <fstream>
#include <stdlib.h>
#include <unistd.h>

// NewFrame -- This is a subclass fo funcbase, also a strategy for clients.

class NewFrame : public Funcbase
{
public:
    NewFrame();
    ~NewFrame();
    void initialize();      // initialize the class
    void browseDic();       // browse vocabulary in dictionary
    void RemindMe();        // function of reminding vocalbulary
    void Pause();           // pause
    void Pause(int);
    void Mnemonics();       // mnemonic function
    void search(string);    // subfunction of void Mnemonics()
    void exam();            // exam function
    void exercise();        // exercise vocabulary
    void readfile();        // read vocabulary from files
private:
    DataBase dataBase;      // database for "dic.txt"
    DataBase dataBase2;     // database for "alreadylearnt.txt"
};

#endif
