CFLAGS = -std=c99 -g -Wall -Werror
#COVFLAGS = -fprofile-arcs -ftest-coverage
GCC = gcc $(CFLAGS) $(COVFLAGS)
OBJS = mathProb.o main.o

proj: $(OBJS)
	$(GCC) $(OBJS) -o proj

main.o: main.c
	$(GCC) -c main.c -o main.o

mathProb.o: mathProb.h mathProbc
	$(GCC) -c mathProb.c -o mathProb.o




# "make test" will run the three input files
test: proj
	-./proj

test1: proj3
	-./proj3 Inputs/map5x5.txt Inputs/query5x5.txt




clean:
	/bin/rm -f *.o
	/bin/rm -f testgen
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f main proj clock
