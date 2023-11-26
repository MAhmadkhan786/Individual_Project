all: ./a.out

compRun:
	g++ -std=c++11 -pedantic *.cpp -o r.out
	
debug:
	g++ -g -O0 -Wall -Wextra -std=c++11 -pedantic *.cpp -o d.out;
	#./d.out

run: clean compRun; ./r.out

clean:
	rm -f *.out
