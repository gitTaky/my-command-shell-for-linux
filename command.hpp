#ifndef __ARGULIST_HPP__
#define __ARGULIST_HPP__

#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include "my_exceptions.hpp"
#include "mytype.hpp"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "varMap.hpp"
#include "arguVector.hpp"
#include "proInfo.hpp"
#include "pipe.hpp"
#include "pid.hpp"

class Command{
public:
  arguVector_t getArguList(std::string &command);
  void getCommand();
  void evalVars(VarMap &variables);
  //  std::vector<ProInfo>
  //Infos getInfo()
  void exeCommand(VarMap &variables);
  //getExeInfo();
private:
  std::string command;
  
  size_t getWordEnd(std::string &command, size_t pos, const char* delim = " ");
  ArguVector split(std::string &command);
  bool varValidCheck(std::string &var);
  void exeProcess(const std::vector<ProInfo> &infos);
  void redirect(const std::string &file, int fd, int flag, mode_t mode);
  size_t skipSpace(const std::string &command, size_t pos);
  void newProcess(const ProInfo &info, int num, Pipe &pipelines, Pid &cpids);
  std::vector<ProInfo> makeInfos(VarMap &variables);
  void parseRedir(std::string &command, std::string &fd, const char *token);
  void eraseRedirAll(std::string &command, const char *token);
  void cd(std::string newpwd, VarMap &variables);
  void cmdCd(VarMap &variables);
  void cmdSet(VarMap &variables);
  void cmdExport(VarMap &variables);
};

#endif
