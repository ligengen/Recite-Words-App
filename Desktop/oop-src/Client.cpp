#include "Client.h"

Client::Client() : _funcbase(NULL)
{

}

Client::~Client()
{

}

// Summary : set strategy for clients.

// Parameters : Funcbase * funcbase

void Client::setStrategy(Funcbase* funcbase)
{
    this->_funcbase = funcbase;
}

// Summary : menu function that clients can choose the function that they want.

void Client::Menu()
{
    this->_funcbase->initialize();
}
