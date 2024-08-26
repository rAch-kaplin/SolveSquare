CC = g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code \
        -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions \
        -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op \
        -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 \
        -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE


all: do.exe

do.exe: RunTests.o compareDoubles.o printRoots.o SolveSquare1.o main.o
	$(CC) $(CFLAGS) RunTests.o compareDoubles.o printRoots.o SolveSquare1.o main.o -o do

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o
	
SolveSquare1.o: SolveSquare1.cpp
	$(CC) $(CFLAGS) -c SolveSquare1.cpp -o SolveSquare1.o

RunTests.o: RunTests.cpp
	$(CC) $(CFLAGS) -c RunTests.cpp -o RunTests.o

printRoots.o: printRoots.cpp 
	$(CC) $(CFLAGS) -c printRoots.cpp -o printRoots.o

compareDoubles.o: compareDoubles.cpp 
	$(CC) $(CFLAGS) -c compareDoubles.cpp -o compareDoubles.o

clean:
	rm *.o
