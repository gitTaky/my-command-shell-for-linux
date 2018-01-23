#ifndef __PID_HPP__
#define __PID_HPP__

#include <sys/types.h>
#include <utility>
#include <cassert>

class Pid{
public:
  Pid(int n):cpid(new pid_t[n]),size(n){}
  Pid(Pid &rhs):cpid(NULL),size(rhs.size){
    cpid = new pid_t[size];
    for(int i = 0; i < size; i++){
      cpid[i] = rhs.cpid[i];
    }
  }
  Pid& operator=(Pid &rhs){
    Pid temp(rhs);
    std::swap(cpid, temp.cpid);
    std::swap(size, temp.size);

    return (*this);
  }
  ~Pid(){
    delete[] cpid;
  }
  pid_t& operator[](int i){
    assert(i >= 0 && i < size);
    return cpid[i];
  }
private:
  int *cpid;
  int size;
};

#endif
