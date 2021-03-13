hepsi : derle calistir

derle:
	g++ -I ./include/ -o ./lib/DosyaIslemler.o -c ./src/DosyaIslemler.cpp
	g++ -I ./include/ -o ./lib/Root.o -c ./src/Root.cpp
	g++ -I ./include/ -o ./bin/program.exe ./lib/DosyaIslemler.o ./lib/Root.o ./src/main.cpp
	
calistir:
	./bin/program.exe