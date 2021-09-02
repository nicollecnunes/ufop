#include <stdio.h>
#include <math.h>
int checacpf(long cpf){
    int num, tot=0, pot=10, resto=0, v1, v2;
    long aux=cpf;
    while (pot>1){
        num = (cpf/(pow(10,pot)));
        cpf = cpf - (num*pow(10,pot));
        tot = tot + num * pot;
        pot--;
        
    }
    resto = (tot*10)%11;
    if (resto==10){
        resto = 0;
    }

    v1 = (cpf - (cpf%10))/10;

    if (v1==resto){
        pot = 10;
        int x = 11;
        tot=0;
            while (pot>0 && x>=2){
            num = (aux/(pow(10,pot)));
            aux = aux - (num*pow(10,pot));
            tot = tot + num * x;
            x--;
            pot--;
        }
        resto = (tot*10)%11;
        v2 = cpf%10;
        if (resto == v2){
            return 1;
        }

    }else{
        return 0;
    }
    
}

int main(){
    long cpf;
    printf("Digite o CPF: \n");
    scanf("%ld",&cpf);
    if (checacpf(cpf)){
        printf("este cpf é VÁLIDO\n");
    }else{
        printf("este cpf é INVÁLIDO\n");
    }
    return 0;
}