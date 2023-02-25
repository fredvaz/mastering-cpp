#include "IDatabaseConnection.hpp"
#include <iostream>

//

IDatabaseConnection::IDatabaseConnection(std::string serverAddress) : mServerAddress{serverAddress}
{
}

void IDatabaseConnection::connect()
{
  std::cout << "Connecting to database server " << mServerAddress << "\n";
  // initialize real DB connection

  // Lecture 53: Callbacks
  if(mOnConnect!=nullptr)
  {
    std::cout << "Callback was set\n";
    // mOnConnect(); 
    mOnConnect(5, 6); 
  }
}

void IDatabaseConnection::disconnect()
{
 std::cout << "Disconnecting from database\n";
 // close the real connection
}

// Lecture 53: Callbacks
void IDatabaseConnection::setOnConnect(Callback onConnect)
{
  mOnConnect = onConnect;
}