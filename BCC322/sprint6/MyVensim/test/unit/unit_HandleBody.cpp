#include <iostream>
#include <assert.h>
#include "../../src/System.h"

#ifdef DEBUGING
	extern int numHandleCreated;
	extern int numHandleDeleted;
	extern int numBodyCreated;
	extern int numBodyDeleted;
#endif

void unit_test_Handlebody(){
    cout << "[HB] - Teste handlebody" << endl;   

    {
        SystemHandle *s1 = new SystemHandle (120);
        SystemHandle *s2 = new SystemHandle (140);

        s1 = s2;

        cout << s1->getValue() << endl;
        cout << s2->getValue() << endl;


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