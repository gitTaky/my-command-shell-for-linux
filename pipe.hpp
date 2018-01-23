#ifndef __PIPE_HPP__
#define __PIPE_HPP__

#include <cassert>
#include <utility>
#include <unistd.h>
#include <fcntl.h>
#include "my_exceptions.hpp"
#include <cstdio>
#include <iostream>

class Pipe{
public:
  explicit Pipe(int n):pipeline(NULL),size((n - 1)*2){
    assert(n > 0);
    pipeline = new int[(n - 1)*2];
    status = new int[(n - 1)*2];
    for(int i = 0; i < size; i = i + 2){
      if(pipe2(pipeline + i, O_DIRECT) == -1){
	perror("pipe open");
	//throw exception
	throw pipe_create_failure();
      }
      status[i] = 1;
      status[i+1] = 1;
    }
  }
  explicit Pipe(Pipe &rhs):pipeline(NULL), size(rhs.size){
    pipeline = new int[rhs.size];
    status = new int[rhs.size];
    
    for(int i = 0; i < rhs.size; i++){
      pipeline[i] = rhs.pipeline[i];
      status[i] = rhs.status[i];
      status[i] = rhs.status[i];
    }
  }
  Pipe& operator=(Pipe &rhs){
    Pipe temp(rhs);
    std::swap(pipeline, temp.pipeline);
    std::swap(size, temp.size);
    std::swap(status, temp.status);

    return (*this);
  }
  ~Pipe(){
    //    for(int i = 0; i < size; i++){
    //closePipe(i);
    //}
    delete[] pipeline;
    delete[] status;
  }

  bool closePipe(int i) throw() {
    if(status[i] == 1){
      if(close(pipeline[i]) == -1){
	perror("pipe close");
	return false;
      }
      else{
	status[i] = 0;   //closed
	return true;
      }
    }
    std::cerr << "double close" << std::endl;
    return false;
  }

  int operator[](int i){
    assert(i >= 0 && i < size);
    return pipeline[i];
  }

  void closeAll(){
    for(int i = 0; i < size; i++){
      closePipe(i);
    }
  }

  int getSize() const {
    return size;
  }
private:
  int *pipeline;
  int *status;
  int size;
};

#endif
