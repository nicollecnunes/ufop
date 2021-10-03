#include <iostream>
#include "RelogioFriend.h"

int main()
{
    Relogio R;
    R.setHora(12, 34, 27);
    R.printHora();
    
    alteraHMS(R);
    R.printHora();
    return 0;
}