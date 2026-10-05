#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define LIMITE_PESO 2.0 // acima deste peso (kg), o frete é o mais caro
#define PRAZO_SUL 5
#define PRAZO_SUDESTE 3
#define PRAZO_NORTE 10
#define PRAZO_NORDESTE 7

int codigo;
char nome[50];
float peso, preco;
int regiao;
float frete, total;

int diaCompra, mesCompra, anoCompra, horaCompra, minutoCompra;
int diaEntrega, mesEntrega, anoEntrega;

// ENTRADA DOS DADOS DO PRODUTO

void lerProduto()
{
    do
    {
        printf("Digite o código: ");
        scanf("%d", &codigo);

        if (codigo <= 0)
        {
            printf("Código inválido! Digite um número maior que 0.\n");
        }

    } while (codigo <= 0);

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nome);

    do
    {
        printf("Digite o peso do produto em KG: ");
        scanf("%f", &peso);

        if (peso <= 0)
        {
            printf("Peso inválido! Digite um valor maior que 0.\n");
        }

    } while (peso <= 0);

    do
    {
        printf("Digite o preço do produto em R$: ");
        scanf("%f", &preco);

        if (preco <= 0)
        {
            printf("Preço inválido! Digite um valor maior que 0.\n");
        }

    } while (preco <= 0);

    do
    {
        printf("Local de entrega: [1] Sul [2] Sudeste [3] Norte [4] Nordeste\n");
        printf("Escolha: ");
        scanf("%d", &regiao);

        if (regiao < 1 || regiao > 4)
        {
            printf("Opção inválida! Escolha um número de 1 a 4.\n");
        }

    } while (regiao < 1 || regiao > 4);
}

// DATA E HORA DA COMPRA

// Verifica se o ano é bissexto
int anoBissexto(int ano)
{
    if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Retorna a quantidade de dias do mês
int diasNoMes(int mes, int ano)
{
    int dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && anoBissexto(ano))
    {
        return 29;
    }

    return dias[mes - 1];
}

int dataValida(int dia, int mes, int ano)
{
    if (ano > 0 && mes >= 1 && mes <= 12 && dia >= 1 && dia <= diasNoMes(mes, ano))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int horaValida(int hora, int minuto)
{
    if (hora >= 0 && hora <= 23 && minuto >= 0 && minuto <= 59)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void lerDataHora()
{
    do
    {
        printf("Digite a data da compra (dd/mm/aaaa): ");
        scanf(" %d/%d/%d", &diaCompra, &mesCompra, &anoCompra);

        if (!dataValida(diaCompra, mesCompra, anoCompra))
        {
            printf("Data inválida. Tente novamente.\n");
        }

    } while (!dataValida(diaCompra, mesCompra, anoCompra));

    do
    {
        printf("Digite a hora da compra (hh:mm): ");
        scanf(" %d:%d", &horaCompra, &minutoCompra);

        if (!horaValida(horaCompra, minutoCompra))
        {
            printf("Hora inválida. Tente novamente.\n");
        }

    } while (!horaValida(horaCompra, minutoCompra));
}

// FRETE E PRAZO POR REGIÃO

float calcularFrete(int regiao, float peso)
{
    float frete = 0.0;

    switch (regiao)
    {
    case 1:
        if (peso <= LIMITE_PESO)
        {
            frete = 30.0;
        }
        else
        {
            frete = 50.0;
        }
        break;

    case 2:
        if (peso <= LIMITE_PESO)
        {
            frete = 25.0;
        }
        else
        {
            frete = 45.0;
        }
        break;

    case 3:
        if (peso <= LIMITE_PESO)
        {
            frete = 35.0;
        }
        else
        {
            frete = 55.0;
        }
        break;

    case 4:
        if (peso <= LIMITE_PESO)
        {
            frete = 40.0;
        }
        else
        {
            frete = 60.0;
        }
        break;
    }

    return frete;
}

int prazoEntrega(int regiao)
{
    switch (regiao)
    {
    case 1:
        return PRAZO_SUL;

    case 2:
        return PRAZO_SUDESTE;

    case 3:
        return PRAZO_NORTE;

    case 4:
        return PRAZO_NORDESTE;
    default:
        return 0;
    }
}

void mostrarRegiao(int regiao)
{
    switch (regiao)
    {
    case 1:
        printf("Região Sul[1]");
        break;

    case 2:
        printf("Região Sudeste[2]");
        break;

    case 3:
        printf("Região Norte[3]");
        break;

    case 4:
        printf("Região Nordeste[4]");
        break;
    }
}

// TOTAL DA COMPRA

float calcularTotal(float preco, float frete)
{
    return preco + frete;
}

// DATA DE ENTREGA

/* Calcula a data prevista de entrega
 * A DATA DA ENTREGA SEMPRE SERÁ POSTERIOR A DATA DA COMPRA, POIS O PRAZO JA FOI DEFINIDO NO INICIO DO PROGRAMA, E AS VARIAVEIS DE DATA DA ENTREGA
 * RECEBEM A DATA DA COMPRA E SOMA O PRAZO DE ACORDO COM A REGIAO. NÃO TENDO RISCO DE A DATA DA COMPRA SER POSTERIOR A DATA DA ENTREGA
 */
void calcularDataEntrega(int prazo)
{
    int i;

    diaEntrega = diaCompra;
    mesEntrega = mesCompra;
    anoEntrega = anoCompra;

    for (i = 0; i < prazo; i++)
    {
        diaEntrega++;

        if (diaEntrega > diasNoMes(mesEntrega, anoEntrega))
        {
            diaEntrega = 1;
            mesEntrega++;

            if (mesEntrega > 12)
            {
                mesEntrega = 1;
                anoEntrega++;
            }
        }
    }
}

// RESUMO DA COMPRA

void exibirResumo()
{
    printf("\n\n===========================================\n");
    printf("Resumo da compra\n");
    printf("----------------\n");
    printf("Código do produto: %d\n", codigo);
    printf("Nome do produto: %s\n", nome);
    printf("Peso do produto: %.2f kg\n", peso);
    printf("Preço do produto: R$ %.2f\n", preco);

    printf("Região de entrega: ");
    mostrarRegiao(regiao);
    printf("\n");

    printf("Valor do frete: R$ %.2f\n", frete);

    printf("Data da compra: %02d/%02d/%04d às %02d:%02d\n", diaCompra, mesCompra, anoCompra, horaCompra, minutoCompra);
    printf("Entrega prevista: %02d/%02d/%04d\n", diaEntrega, mesEntrega, anoEntrega);

    printf("\nTotal a PAGAR: R$ %.2f\n", total);
    printf("===========================================\n");
}

// PROCESSAMENTO DE UMA COMPRA

void processarCompra()
{
    lerProduto();
    lerDataHora();
    frete = calcularFrete(regiao, peso);
    total = calcularTotal(preco, frete);
    calcularDataEntrega(prazoEntrega(regiao));
    exibirResumo();
}

// FUNÇÃO PRINCIPAL

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    char continuar;

    do
    {
        processarCompra();

        printf("Deseja fazer outra compra? [S/N]: ");
        scanf(" %c", &continuar);
        if (continuar == 's' || continuar == 'S')
        {
            system("CLS");
        }

    } while (continuar == 's' || continuar == 'S');

    printf("\n\n---------------------");
    printf("\n<<< VOLTE SEMPRE >>>\n");
    printf("---------------------\n\n");

    return 0;
}
