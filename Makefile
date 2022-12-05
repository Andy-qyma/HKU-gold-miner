instruction.o: instruction.cpp instruction.h
				g++ -c $<
				
initialization.o: initialization.cpp initialization.h
				g++ -c $<
				
routine.o: routine.cpp routine.h
		g++ -c $<
		
main.o: main.cpp instruction.h initialization.h routine.h
		g++ -c $<
		
main: main.o instruction.o initialization.o routine.o
		g++ $^ -o $@
		
clean:
		rm -f instruction.o initialization.o routine.o main.o main
		
.PHONY: clean
