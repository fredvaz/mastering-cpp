#include "LibraryCode.hpp"

#include <vector>
#include <stdexcept>

std::vector<int> generateNumbers(int n, int limit)
{
  std::vector<int> result;
  if(limit <= 0)
  {
    throw std::runtime_error("Argument must be >= 0");
  }
  for(int i=0; i<n; i++)
  {
    result.push_back(i % limit);
  }
  return result;
}
