#ifndef __ARGUVECTOR_HPP__
#define __ARGUVECTOR_HPP__

#include "mytype.hpp"
#include <string>
#include <cassert>
#include "varMap.hpp"

class ArguVector : public arguVector_t{
public:
  explicit ArguVector():arguVector_t(),cmd(){}
  std::string getArgu(size_t i){
    assert(i >= 0 && i < size());
    return cmd.substr((*this)[i].first, (*this)[i].second - (*this)[i].first);
  }
  void parsePath(VarMap &variables){
    std::string program = getArgu(0);
    (*this)[0].first = cmd.size();
    cmd += variables.searchPath(program);
    (*this)[0].second = cmd.size();
      
  }
  std::string cmd;
};


#endif
