#pragma once
#include "Employee.hpp"
#include "IDatabaseConnection.hpp"

#include <map>
#include <vector>
#include <string>

class EmployeeManager
{
public:
  EmployeeManager(IDatabaseConnection *dbConnection);
  ~EmployeeManager();

  void setSalary(int employeeId, float newSalary);
  float getSalary(int employeeId) const;
  
  std::map<std::string,float> getSalariesGreater(float low) const;
  std::map<std::string,float> getSalariesBetween(float low, float high) const;
  
private:
  std::map<std::string, float> vectorToMap(std::vector<Employee> const& employees) const;

private:
  IDatabaseConnection  *mDbConnection;
};
