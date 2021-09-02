/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 2*/

#include <stdio.h>
#include <math.h>

int main(){
	int n=0,a=1, si=+1;
	double pi=0, s=0;
	scanf ("%d",&n);
    for(int i=0; i<n; i++){
    	s = s + (si * (1/(pow(a,3))));
    	a = a+2;
    	si = si * -1; 	
    }
    pi = cbrt(s*32);
    printf("Pi: %lf\n", pi);

    return 0;
}