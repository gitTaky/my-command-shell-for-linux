#ifndef __SHELL__
#define __SHELL__

#include "varMap.hpp"
#include "command.hpp"
#include "cwd.hpp"

class MyShell{
public:
  void exeOneLine();
private:
  void showPWD();
  VarMap variables;
};

#endif
