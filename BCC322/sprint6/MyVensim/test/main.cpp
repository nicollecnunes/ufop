#include "functional/functional_tests.h"

#include "unit/unit_System.H"
#include "unit/unit_Flow.H"
#include "unit/unit_Model.H"

#include <iostream>

#define DEBUGING
#ifdef DEBUGING
    int numHandleCreated = 0;
	int numHandleDeleted = 0;
	int numBodyCreated = 0;
	int numBodyDeleted = 0;
#endif

using namespace std;

int main(){
    run_exponentialFuncionalTest();
    run_logisticalFuncionalTest();
    run_complexFuncionalTest();

    run_unit_tests_System();
    #ifdef DEBUGING
        cout << "Created handles: "  << numHandleCreated << endl;
        cout << "Deleted handles: "  << numHandleDeleted << endl;    
        cout << "Created bodies: "  << numBodyCreated << endl;
        cout << "Deleted bodies: "  << numBodyDeleted << endl;
    #endif

    #ifdef DEBUGING
        assert(numHandleCreated == numHandleDeleted);
        assert(numBodyCreated == numBodyDeleted);
    #endif

    run_unit_tests_Flow();
    #ifdef DEBUGING
        cout << "Created handles: "  << numHandleCreated << endl;
        cout << "Deleted handles: "  << numHandleDeleted << endl;    
        cout << "Created bodies: "  << numBodyCreated << endl;
        cout << "Deleted bodies: "  << numBodyDeleted << endl;
    #endif

    #ifdef DEBUGING
        assert(numHandleCreated == numHandleDeleted);
        assert(numBodyCreated == numBodyDeleted);
    #endif

    run_unit_tests_Model();
     #ifdef DEBUGING
        cout << "Created handles: "  << numHandleCreated << endl;
        cout << "Deleted handles: "  << numHandleDeleted << endl;    
        cout << "Created bodies: "  << numBodyCreated << endl;
        cout << "Deleted bodies: "  << numBodyDeleted << endl;
    #endif

    #ifdef DEBUGING
        assert(numHandleCreated == numHandleDeleted);
        assert(numBodyCreated == numBodyDeleted);
    #endif

    return true;
}
