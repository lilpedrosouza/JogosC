#include <stdio.h>
#include <locale.h> //coloca acentuação
#include <stdlib.h>
#include <time.h>

#define NUMERO_DE_TENTATIVAS 3

int main()
{
	setlocale(LC_ALL, "portuguese");

	printf("\n\n");
	printf("               P                                   \n");
	printf("           P  /_\\  P                              \n");
	printf("          /_\\_|_|_/_\\                            \n");
	printf("      n_n | ||. .|| | n_n         Bem-vindo ao     \n");
	printf("       |_|_|nnnn nnnn|_|_|     Jogo da Adivinhação!\n");
	printf("       |\" \" |  |_|  |\"  \" |                    \n");
	printf("       |____| ' _ ' |_____|                        \n");
	printf("            \\__|_|__/                             \n");
	printf("\n\n");

	// Variaveis que serão usadas mais a frente
	int chute;
	int acertou;
	int nivel;
	int totaldetentativas;

	// define quantidade de pontos inicial
	double pontos = 1000;

	// Gerando um numero secreto aleatorio
	srand(time(0));					  // função que deixa os números sempre diferentes
	int numerosecreto = rand() % 100; // pega o resto da divisão de 'rand' fazendo númerosecreto ser == 0 a 99

	printf("Qual o nível de dificuldade?\n");
	printf("(1) Fácil (2) Médio (3) Difícil\n\n");
	printf("Escolha: ");

	scanf("%d", &nivel);

	switch (nivel)
	{
	case 1:
		totaldetentativas = 20;
		break;
	case 2:
		totaldetentativas = 15;
		break;
	default:
		totaldetentativas = 6;
		break;
	}

	for (int i = 1; i <= totaldetentativas; i++)
	{

		printf("-> Tentativa %d de %d\n", i, totaldetentativas);
		printf("Chute um número: \n");
		scanf("%d", &chute);

		if (chute < 0)
		{
			printf("Você não pode chutar números negativos\n");
			i--;
			continue;
		}

		acertou = chute == numerosecreto;

		if (acertou)
		{
			break;
		}
		else if (chute > numerosecreto)
		{
			printf("\nSeu chute foi maior do que o número secreto!\n\n");
		}
		else
		{
			printf("\nSeu chute foi menor do que o número secreto!\n\n");
		}
		// calcula a quantidade de pontos
		double pontosperdidos = abs(chute - numerosecreto) / 2.0;
		pontos = pontos - pontosperdidos;
	}
	printf("\n");
	if (acertou)
	{
		printf("             00000000000               \n");
		printf("         0000000000000000000           \n");
		printf("       000000  000000000  000000       \n");
		printf("     000000      00000      000000     \n");
		printf("   00000000  #   00000   #  00000000   \n");
		printf("  0000000000    0000000    0000000000  \n");
		printf(" 0000000000000000000000000000000000000 \n");
		printf(" 0000000000000000000000000000000000000 \n");
		printf(" 0000  0000000000000000000000000  0000 \n");
		printf("  0000  00000000000000000000000  0000  \n");
		printf("   0000  000000000000000000000  0000   \n");
		printf("    0000   00000000000000000  0000     \n");
		printf("     000000   000000000    000000      \n");
		printf("       000000            000000        \n");
		printf("           0000000000000000            \n");
		printf("\nParabéns! Você acertou!\n");
		printf("Você fez %2.f pontos. Até a próxima!\n\n", pontos);
	}
	else
	{

		printf("     \\|/ ____ \\|/      \n");
		printf("      @~/  ,. \\~@       \n");
		printf("     /_( \\___/ )_\\     \n");
		printf("        \\___U_/         \n");

		printf("\nVocê perdeu! Mas na próxima tenho certeza que vai conseguir!\n\n");
	}
	system("pause");
}