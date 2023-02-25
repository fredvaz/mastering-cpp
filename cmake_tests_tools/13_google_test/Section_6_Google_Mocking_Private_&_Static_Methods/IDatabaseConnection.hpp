#pragma once

#include <string>
#include <vector>
#include <functional>

#include "Employee.hpp"

//

// This class is to help to manipulate the connectionCount
class HelperClass
{
private:
  virtual void increaseConnectionCount();
  friend class IDatabaseConnection;
};

// interface because we might subclass it
// example: IOracleDatabaseConnectionManager, ISQLDatabaseConnectionManager
class IDatabaseConnection
{
public:
  using Callback = std::function<void(int, int)>; // Lecture 53: Callbacks
  
  IDatabaseConnection(std::string serverAddress, HelperClass *hc); // member of the Helper Class
  

  virtual float getSalary(int id) const = 0; // SELECT * FROM employees WHERE id=...
  virtual void updateSalary(int id, float newSalary) = 0;

  virtual std::vector<Employee> getSalariesRange(float low) const = 0; //just greater than low
  virtual std::vector<Employee> getSalariesRange(float low, float high) const = 0;

  virtual void connect();
  virtual void disconnect();

  // Lecture 53: Callbacks
  void setOnConnect(Callback onConnect);

  // Lecture 54: Mocking Private and Static Methods
private:
  virtual void onConnect(){}; // Empty definition/implementation / To mock it, has to be virtual
  static void increaseConnectionCount(); // static method
  static unsigned connectionCount;
  HelperClass *mHelper; // member type of the Helper Class to pass it in the in this Class

protected:
  std::string mServerAddress;
  // Callback mOnConnect; // Lecture 53: Callbacks
  friend class HelperClass;

};
