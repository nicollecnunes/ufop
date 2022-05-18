#ifndef UNIT_FLOW
#define UNIT_FLOW

#include "../../src/Flow.h"
#include "../../src/Model.h"
#include "../../src/System.h"

    class FlowTest : public Flow
    {
        public:
            /*!
                Construtor padrão
            */
            FlowTest() : Flow(){}

            /*!
                Metodo run especializado com a equação do fluxo exponencial
            */
            double run() {
                return 0.01 * getOrigin()->getValue();
            }
    };

    void unit_Flow_constructor(void);

    void unit_Flow_setOrigin_getOrigin(void);
    void unit_Flow_setTarget_getTarget(void);
    void unit_Flow_setValue_getValue(void);

    void unit_Flow_run(void);
    
    void unit_Flow_assignmentOperator(void);
    void run_unit_tests_Flow(void);
#endif