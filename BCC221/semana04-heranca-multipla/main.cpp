#include <iostream>
#include "Cilindro.h"

using namespace std;

int main()
{
	Cilindro obj(5,8), obj2;
    
    cout << obj;
    cout<< "area: " << obj.calculaArea();
    cout<<"\nvolume: " <<obj.calculaVolume();

    obj2.set(4,6);
    cout<<obj2;
    cout<< "area: " << obj2.calculaArea();
    cout<<"\nvolume: " <<obj2.calculaVolume();

	return 0;
}