#pragma once

#include <string>
#include <vector>
#include <functional>

#include "Employee.hpp"

//

// interface because we might subclass it
// example: IOracleDatabaseConnectionManager, ISQLDatabaseConnectionManager
class IDatabaseConnection
{
public:
  // using Callback = std::function<void()>; // Lecture 53: Callbacks
  using Callback = std::function<void(int, int)>; 
  
  IDatabaseConnection(std::string serverAddress);
  
  virtual float getSalary(int id) const = 0; // SELECT * FROM employees WHERE id=...
  virtual void updateSalary(int id, float newSalary) = 0;

  virtual std::vector<Employee> getSalariesRange(float low) const = 0; //just greater than low
  virtual std::vector<Employee> getSalariesRange(float low, float high) const = 0;

  virtual void connect();
  virtual void disconnect();

  // Lecture 53: Callbacks
  void setOnConnect(Callback onConnect);

protected:
  std::string mServerAddress;
  Callback mOnConnect; // Lecture 53: Callbacks

};
