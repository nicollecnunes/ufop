/*Nicolle Canuto Nunes - 20.1.4022 - 
 *Questão 4*/

#include <stdio.h>

int main(){
    int x, y;
    int i=1;
    int j=1;
    printf("Digite a linha em que o Bispo se encontra:");
    scanf("%d", &x);
    printf("Digite a coluna em que o Bispo se encontra:");
    scanf("%d", &y);

    printf("\t1\t2\t3\t4\t5\t6\t7\t8\n");
    printf("------------------------------------------------------\n");
    while (i<9){
        printf("%d|\t", i);

        for (int j = 1; j < 9; j++){
            if ((i + j == x + y) ||( y - x == j - i)){
                printf("X\t");
            }else{
                printf("-\t");
            }

        }
        printf("\n");
        i++;
    }
    return 0;
}