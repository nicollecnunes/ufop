#ifndef UnitFunctionsH
#define UnitFunctionsH
#ifdef __cplusplus
extern "C"
{
#endif

__declspec (dllexport) const int GetAnswerOfLife();

        __declspec (dllexport) ISystem *getOrigin(void) const;

        __declspec (dllexport) void setOrigin(ISystem *origin);
        __declspec (dllexport) ISystem *getTarget(void) const;
        __declspec (dllexport) void setTarget(ISystem *target);
        __declspec (dllexport) double getValue() const;
        __declspec (dllexport) void setValue(double value);

        __declspec (dllexport) void run(double start = 0, double end = 0, double increment = 0);

        
        
        __declspec (dllexport) void add(IFlow *flow = NULL);

        
        
        __declspec (dllexport) void add(ISystem *system = NULL);

        __declspec (dllexport) void setValue(double value);

        __declspec (dllexport) double getValue() const;


#ifdef __cplusplus
}
#endif

#endif