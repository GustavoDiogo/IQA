#include<stdio.h>
#include<stdlib.h> // Inclui essa library para utilizar a função abs

double raizq(double x)
{
        double v1 = 1.0; // Valor inicial.
        double v2 = 0; // Valor para sobreposição.
        do
        {
                v2 = (v1+(x/v1))/2;
                v1 = (v2 + (x/v2))/2;
                v2 = (v1+(x/v1))/2;
                v1 = (v2 + (x/v2))/2;


        } while (abs(v1 - v2) > 0);
        // O programa entrará em loop e ele fará as equações e as sobreposições até que a condição seja falsa/menor que 0.
        //
        // A equação mais simplificada e menos precisa para este código é:
        // v2=v1
        // v1=(v1(x/v1))/2
        //
        // Exemplo: Raiz de 2
        // v1=1 (valor inicial)
        // v1=(1+(2/1))/2
        // v1=3/2
        // v1=1,5 (valor posterior)
        // 1,5-v2= 0,5
        // v2 = 1(valor inicial)
        // 1,5-1 = 0,5
        // 0,5>0 = VERDADEIRO
        //
        // LOOP com a sobreposição novamente.
        // v1=1,5
        // v1=(1,5+(2/1,5))/2
        // v1=1,41
        // 1,41-v2
        // v2=1,5(valor anterior)
        // 1,41-1,5= -0,09
        // -0,09>0 = FALSO
        //
        // Portanto o valor mais aproximado é 1,5 para raiz de 2 na equação simplificada.
        // Mas basta repetir a equação base de v1=(v1/x/v1))/2 em v2 e para aumentar a precisão.
        // Assim ficará:
        // v2=(v1+(x/v1))/2
        // v1=(v2(x/v2))/2
        // A precisão aumentou e se repetir está equação mais duas vezs como feito no código chegará na precisão máxima.
        // Assim o programa trabalhará com muito mais casas decimais.
        // Não se deve colocar mais que quatro equações, senão o valor impresso perderá precisão, irá imprimir um valor mais baixo do que deveria.

        return v1;
}
int main(void)
{
        double n;
        scanf("%lf", &n);
        if (n<0) // O programa não consegue calcular raízes negativas, pois a função só será executada (v1-v2)>0 for verdadeiro e parará quando (v1-v2)>0 for falso.
                //Se a função começar com valor negativo, logo a função será falsa e parará de executar.
        {
        printf("Impossível calcular número negativo.\n");
        }
        else if(n==0)
        {
        printf("0\n");
        }
        else
        {
        printf("%.2lf\n", raizq(n));
        }
return 0.0;
}
