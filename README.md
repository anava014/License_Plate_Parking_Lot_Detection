# License_Plate_Parking_Lot_Detection

prerequisites needed:
SQLite - sudo apt-get install sqlite3 libsqlite3-dev

GCC g++ 4.7 and C++11 enabled Compiler

OpenALPR - https://github.com/openalpr/openalpr (Installation instructions depends on OS) Because this c++ program runs a shell command, it is only neccesary to install OpenALPR as a program that runs directly on the shell. The program will be open to run it appropriatetly. 

To run: 
make run

Important files:
In current directory, live.jpeg is the image that is being processed by the entire program.

The directory images has 8 images in which the user can use to sample the parking lot database input.

To copy a file, easiest method is with cp command: "cp images/image2.jpeg live.jpeg" from current directory.