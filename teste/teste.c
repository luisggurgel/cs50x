#include <stdio.h>

int main()
{
    int size;
    scanf("%d", &size);
    int matriz[size][size];
    int soma = 0;
    int soma_temporaria = 0;
    int num;

    //povoando matriz
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            scanf("%d", &num);
            matriz[i][j] = num;
        }
    }

    //verificando se linhas sao todas iguais
    for(int i = 0; i < size; i++)
    {
        soma += matriz[0][i];
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            soma_temporaria += matriz[i][j];
        }
        if(soma_temporaria != soma)
        {
            printf("-1");
            return 1;
        }
        else
        {
            soma_temporaria = 0;
        }

    }
    //verificando se todas as colunas sao iguais
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            soma_temporaria += matriz[j][i];
        }
        if(soma_temporaria != soma)
        {
            printf("-1");
            return 1;
        }
        else
        {
            soma_temporaria = 0;
        }
    }
    //verificando se todas as diagonais sao iguais
    soma_temporaria = 0;
    int soma_temporaria1 = 0;
    for(int i = 0; i < size; i++)
    {
        soma_temporaria += matriz[i][i];
    }
    for(int j = size-1; j >= 0; j--)
    {
        soma_temporaria1 += matriz[j][j];
    }
    if (soma_temporaria != soma_temporaria1)
    {
        printf("-1");
        return 1;
    }

    printf("%d", soma);
    return 0;
}
