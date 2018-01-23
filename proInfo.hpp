#ifndef __PROINFO_HPP__
#define __PROINFO_HPP__

#include "mytype.hpp"
#include <string>
#include "arguVector.hpp"

class ProInfo{
public:
  ProInfo(ArguVector &argus, std::string _fd0, std::string _fd1, std::string fd2);
  ProInfo(const ProInfo &rhs);
  ProInfo& operator=(const ProInfo &rhs);
  ~ProInfo();
  
  char** arguList;
  std::string fd0;
  std::string fd1;
  std::string fd2;
};

#endif
