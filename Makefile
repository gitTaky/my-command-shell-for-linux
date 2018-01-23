SCRS=$(wildcard *cpp)
OP=-Wall -Werror -pedantic --std=gnu++98
myShell: $(SCRS) command.hpp my_exceptions.hpp mytype.hpp varMap.hpp cwd.hpp arguVector.hpp proInfo.hpp pipe.hpp pid.hpp shell.hpp
	g++ $(OP) -ggdb3 -o myShell $(SCRS)
