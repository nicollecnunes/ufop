#include "Circulo.h"
#include "Retangulo.h"

using namespace std;

class Cilindro : public Circulo, public Retangulo
{
    public:
        Cilindro(int=0, int=0);
        ~Cilindro();
         
        int calculaArea();
        int calculaVolume();

        void set(int, int);

        friend ostream& operator<<(ostream&, const Cilindro&);
};