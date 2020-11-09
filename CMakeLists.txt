all: oop_exercise_04

oop_exercise_04: main.o
	g++ main.o  -o oop_exercise_04

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o oop_exercise_04