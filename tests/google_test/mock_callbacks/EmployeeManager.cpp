#include "EmployeeManager.hpp"
#include <map>

EmployeeManager::EmployeeManager(IDatabaseConnection *dbConnection): mDbConnection{dbConnection}
{
  mDbConnection->connect();
}

EmployeeManager::~EmployeeManager()
{
  mDbConnection->disconnect();
}


float EmployeeManager::getSalary(int employeeId) const
{
 return mDbConnection->getSalary(employeeId); 
}
  
void EmployeeManager::setSalary(int employeeId, float newSalary)
{
  mDbConnection->updateSalary(employeeId, newSalary);
}
  
std::map<std::string, float> EmployeeManager::vectorToMap(std::vector<Employee> const& employees) const
{
  std::map<std::string, float> result;
  for(Employee const& employee : employees)
  {
      result[employee.name] = employee.salary;
  }
  return result;
}

std::map<std::string,float> EmployeeManager::getSalariesGreater(float low) const
{
  return vectorToMap(mDbConnection->getSalariesRange(low));
  
}
std::map<std::string,float> EmployeeManager::getSalariesBetween(float low, float high) const
{
  return vectorToMap(mDbConnection->getSalariesRange(low, high));
}
