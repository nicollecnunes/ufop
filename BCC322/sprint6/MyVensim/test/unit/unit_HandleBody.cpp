#include <iostream>
#include <assert.h>
#include "../../src/include/SystemImpl.hpp"

#ifdef DEBUGING
	extern int numHandleCreated;
	extern int numHandleDeleted;
	extern int numBodyCreated;
	extern int numBodyDeleted;
#endif

void unit_test_Handlebody(){
    cout << "[Handlebody] - Teste handlebody" << endl;   

    {
        SystemHandle *s1 = new SystemHandle ("s1", 10.0);
        SystemHandle *s2 = new SystemHandle ("s2", 10.0);

        s1 = s2;

        cout << s1->getName() << endl;
        cout << s2->getName() << endl;


        delete s1;
        
        #ifdef DEBUGING
            cout << "Created handles: "  << numHandleCreated << endl;
            cout << "Deleted handles: "  << numHandleDeleted << endl;
            cout << "Created bodies: "  << numBodyCreated << endl;
            cout << "Deleted bodies: "  << numBodyDeleted << endl;
        #endif


        #ifdef DEBUGING
        assert(numHandleCreated == (numHandleDeleted+1)); 
        assert(numBodyCreated == numBodyDeleted);
        #endif
    }

    cout << "passed" << endl;
}

void run_unit_tests_Handlebody(){
    unit_test_Handlebody();
}