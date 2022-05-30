output:
	g++ -shared ./src/lib/*.cpp -o ./bin/myvensim.dll -fPIC
	g++ ./test/functional/*.cpp ./test/unit/utils/*.cpp ./bin/myvensim.dll -o ./bin/main_funcional.exe 
	g++ ./test/unit/*.cpp ./test/unit/utils/*.cpp ./bin/myvensim.dll -o ./bin/main_unitario.exe 

tf:
	./bin/main_funcional.exe

tu:
	./bin/main_unitario.exe


