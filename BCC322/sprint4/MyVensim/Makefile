ifeq ($(OS),Windows_NT) 
CLEAN = del bin\*.dll bin\*.exe bin\*.out bin\*.o
else
CLEAN = rm -rf bin/*.dll bin/*.exe bin/*.out bin/*.o bin/unit_tests.dll
endif

api_lib = ./bin/Model.dll ./bin/System.dll ./bin/Flow.dll

all-functional: libs FunctionalTests.dll
all-unit: libs UnitTests.dll
libs: System.dll Flow.dll Model.dll
run-functional: all-functional
run-unit: all-unit

System.dll:
	g++ -c ./src/System.cpp -o ./bin/System.dll -Wall

Flow.dll:
	g++ -c ./src/Flow.cpp -o ./bin/Flow.dll -Wall

Model.dll:
	g++ -c ./src/Model.cpp -o ./bin/Model.dll -Wall

FlowTestUnit.dll:
	g++ -c test/unit/utils/FlowTestUnit.cpp -o ./bin/FlowTestUnit.dll -Wall

FunctionalTests.dll: 
	g++ $(api_lib) test/functional/main.cpp test/functional/functional_tests.cpp  -o bin/functional_tests.dll

UnitTests.dll: FlowTestUnit.dll
	g++ test/unit/*.cpp $(api_lib) ./bin/FlowTestUnit.dll test/unit/utils/mem_usage.cpp -o bin/unit_tests.dll

run-functional:
	./bin/functional_tests.dll

run-unit:
	./bin/unit_tests.dll

clean:
	@echo "clean project"
	$(CLEAN)
	@echo "clean completed"
