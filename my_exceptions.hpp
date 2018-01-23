#ifndef __MY_EXCEPTIONS_HPP__
#define __MY_EXCEPTIONS_HPP__

#include <exception>
#include <iostream>

class not_find: public std::exception{};

class redirect_failure: public std::exception{};

class command_error: public std::exception{
public:
  virtual const char* what() const throw() { return "unexpect token 'newline'"; };
};

class command_exit: public std::exception{};

class pipe_create_failure: public std::exception{};

class execve_failure: public std::exception{};

class fork_failure: public std::exception{};
#endif
