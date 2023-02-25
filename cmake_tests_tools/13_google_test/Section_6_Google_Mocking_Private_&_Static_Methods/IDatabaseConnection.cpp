#include "IDatabaseConnection.hpp"
#include <iostream>

//

unsigned IDatabaseConnection::connectionCount = 0;

IDatabaseConnection::IDatabaseConnection(std::string serverAddress, HelperClass *hc) 
  : mServerAddress{serverAddress}, mHelper{hc}
{
    // increaseConnectionCount();
    hc->increaseConnectionCount(); 
    //  will be calling the increased connection method of the helper class and not out of the database
    // connection class directly.
}

void IDatabaseConnection::connect()
{
  std::cout << "Connecting to database server " << mServerAddress << "\n";
  // initialize real DB connection

  // Lecture 53: Callbacks
  // if(mOnConnect!=nullptr)
  // {
  //   std::cout << "Callback was set\n";
  //   mOnConnect(5, 6);
  // }

  onConnect(); // Lecture 54: Mocking Private and Static Methods
}

void IDatabaseConnection::disconnect()
{
  std::cout << "Disconnecting from database\n";
  // close the real connection
}

// Lecture 53: Callbacks
void IDatabaseConnection::setOnConnect(Callback onConnect)
{
  // mOnConnect = onConnect;
}

void IDatabaseConnection::increaseConnectionCount()
{
  connectionCount++;
  std::cout << "Connection count: " << connectionCount << "\n";
}

void HelperClass::increaseConnectionCount()
{
  IDatabaseConnection::increaseConnectionCount();
}