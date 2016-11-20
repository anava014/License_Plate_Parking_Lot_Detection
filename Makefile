#makefile

#Variables
COMPILE = g++
FLAGS = -g -W -Wall -Werror -ansi -pedantic
OBJS = LicPlateCV.o Database.o Citations.o CurrentCars.o

#Targets

all: main.cpp $(OBJS) 
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS) -l sqlite3

LicPlateCV.o: LicPlateCV.cpp LicPlateCV.h
	$(COMPILE) $(FLAGS) -c LicPlateCV.cpp

Database.o: Database.cpp Database.h
	$(COMPILE) $(FLAGS) -c Database.cpp

Citations.o: Citations.cpp Citations.h
	$(COMPILE) $(FLAGS) -c Citations.cpp

CurrentCars.o: CurrentCars.cpp CurrentCars.h
	$(COMPILE) $(FLAGS) -c CurrentCars.cpp

run:
	make
	clear
	./a.out

clean:
	rm -rf *~ *.o a.out a.out.dSYM .DS_Store
