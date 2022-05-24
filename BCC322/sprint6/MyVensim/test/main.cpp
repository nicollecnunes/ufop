#include "unit/unit_Flow.hpp"
#include "unit/unit_System.hpp"
#include "unit/unit_Model.hpp"
#include "unit/unit_Handlebody.hpp"
#include "functional/functional_tests.hpp"

#include <iostream>
#include <assert.h>

#ifdef DEBUGING
	extern int numHandleCreated;
	extern int numHandleDeleted;
	extern int numBodyCreated;
	extern int numBodyDeleted;
#endif

using namespace std;

int main(){
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

    run_unit_tests_Handlebody();

    exponentialFuncionalTest();

    logisticalFuncionalTest();

    complexFuncionalTest();

    return true;
}