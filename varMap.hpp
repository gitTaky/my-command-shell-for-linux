#ifndef __VARMAP_HPP__
#define __VARMAP_HPP__

#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <unistd.h>

class ValPair{
public:
  std::string val;
  bool isExported;
  ValPair():val(),isExported(false){}
  ValPair(const std::string &value):val(value), isExported(false){}
};

typedef std::map<std::string, ValPair> varMap_t;

class VarMap: public varMap_t{
public:
  VarMap():varMap_t(){
    std::string env, var;
    size_t delPos;
    char * const * envp = environ;
    for(int i = 0; envp[i] != NULL; i++){
      env = envp[i];
      delPos = env.find("=");
      var = env.substr(0, delPos);
      setVar(var, env.substr(delPos+1));
      setExport(var);
    }
  }
  void setVar(const std::string &var, const std::string &value);
  void setExport(const std::string &var);
  void isExport(const std::string &var) const;
  bool isExist(const std::string &var) const;
  std::string getValue(const std::string &var);
  std::string searchPath(const std::string &program);

private:
  std::string searchFile(std::string &path, const std::string &program) const;
};

#endif
