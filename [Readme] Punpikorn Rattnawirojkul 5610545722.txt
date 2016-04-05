Punpikorn Rattnawirojkul 5610545722

==== Readme ====
1. compile the librarie
g++ -c SyllableReader.cpp -o SyllableReader.o

2. compile main class by including the object library files
g++ -o main main.cpp SyllableReader.o -liconv

3. run the main and including the full path of .dat file
./main <full path of .dat file>
