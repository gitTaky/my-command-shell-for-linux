#ifndef __CWD_HPP__
#define __CWD_HPP__

#include <unistd.h>

class Cwd{
public:
  Cwd():data(NULL){}
  const char* get(){
    data = getcwd(NULL, 0);
    return data;
  }
  ~Cwd(){
    if(data){
      free(data);
    }
  }
private:
  char *data;
};

#endif
