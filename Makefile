#makefile

#Variables
COMPILE = g++
FLAGS = -g -W -Wall -Werror -ansi -pedantic
OBJS = LicPlateCV.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

LicPlateCV.o: LicPlateCV.cpp LicPlateCV.h
	$(COMPILE) $(FLAGS) -c LicPlateCV.cpp

run:
	make
	clear
	./a.out

clean:
	rm -rf *~ *.o a.out a.out.dSYM .DS_Store
