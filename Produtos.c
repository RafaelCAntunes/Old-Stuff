#include <stdio.h>

typedef struct
{
    int codigo;
    float custo;
    float transporte;
    float margem;
    float venda;
} t_produto;

float precoVenda(t_produto p)
{
    return (p.custo + p.transporte)*(1+p.margem);
}

int main()
{
    t_produto v[10];
    int i;
    // Recebe os 10 produtos..
    for(i=0; i<10; i++)
    {
        printf("Produto: ");
        scanf("%i %f %f %f", &v[i].codigo, &v[i].custo, &v[i].transporte, &v[i].margem);
        v[i].venda = precoVenda(v[i]);
    }
    for(i=0; i<10; i++)
    {
        printf("Produto: %i\nVenda: R$ %.2f\n", v[i].codigo, v[i].venda);
    }
    return 0;
}
