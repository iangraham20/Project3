all:
	g++ -std=c++11 main.cpp NIShell.cpp Path.cpp Prompt.cpp -o program
	./program

clean:
	rm  program
	