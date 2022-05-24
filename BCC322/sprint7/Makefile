ifeq ($(OS),Windows_NT) 
CLEAN = del bin\*.dll bin\*.exe bin\*.out bin\*.o
else
CLEAN = rm -rf bin/*.dll bin/*.exe bin/*.out bin/*.o bin/unit_tests.dll
endif

api:
	g++ -shared src/lib/SystemImpl.cpp src/lib/FlowImpl.cpp src/lib/ModelImpl.cpp -o bin/api.dll -Lbin -fPIC -Wl,-rpath,bin

all-functional:
	g++ test/functional/main.cpp test/functional/functional_tests.cpp -Lbin -lapi -o bin/functional_tests -Wl,-rpath,bin

all-unit:
	g++ test/unit/main.cpp test/unit/utils/mem_usage.cpp test/unit/utils/FlowTestUnit.cpp test/unit/unit_Handlebody.cpp test/unit/unit_Model.cpp test/unit/unit_System.cpp test/unit/unit_Flow.cpp -Lbin -lapi -o bin/unit_tests -Wl,-rpath,bin

run-functional:
	bin/functional_tests.exe

run-unit:
	bin/unit_tests.exe

clean:
	@echo "clean project"
	$(CLEAN)
	@echo "clean completed"
