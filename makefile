##############################################################################
#
# Makefile for Final Project of CMPT 135 Spring 2021, SFU Surrey.
#
# Commands for this makefile that can be typed at the command line:
#
#   make
#      Build the executable program a4_main_test. 
#
#   make -j
#      Build a4_main_test possibly a little quickly. The "-j" option tells
#      make to try to use multiple CPUs when compiling two, or more, files.
#
#   make clean
#      Delete a4_main_test, and all the .o object files.
#
#   make <name>
#      Compiles a specific file, where <name> is the name of one of the rules
#      listed in the makefile below, i.e. a4, a4_main, or cmpt_trace.
#
##############################################################################

# Set the C++ compiler options:
#   -std=c++17 compiles using the C++17 standard (or at least as 
#    much as is implemented by the compiler, e.g. for g++ see
#    http://gcc.gnu.org/projects/cxx0x.html)
#   -Wall turns on all warnings
#   -Wextra turns on even more warnings
#   -Werror causes warnings to be errors 
#   -Wfatal-errors stops the compiler after the first error
#   -Wno-sign-compare turns off warnings for comparing signed and 
#    unsigned numbers
#   -Wnon-virtual-dtor warns about non-virtual destructors
#   -g puts debugging info into the executables (makes them larger)
CPPFLAGS = -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g

final_main_test: person_info.o database.o menu.o
	g++ -o final_main_test person_info.o database.o menu.o

person_info:
	g++ -c $(CPPFLAGS) person_info.cpp

database:
	g++ -c $(CPPFLAGS) database.cpp

menu:
	g++ -c $(CPPFLAGS) menu.cpp

clean:
	rm -f final_main_test person_info.o database.o menu.o