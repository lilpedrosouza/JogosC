#include <stdio.h>
#include <locale.h> //coloca acentua��o
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
	printf("       |_|_|nnnn nnnn|_|_|     Jogo da Adivinha��o!\n");
	printf("       |\" \" |  |_|  |\"  \" |                    \n");
	printf("       |____| ' _ ' |_____|                        \n");
	printf("            \\__|_|__/                             \n");
	printf("\n\n");

	// Variaveis que ser�o usadas mais a frente
	int chute;
	int acertou;
	int nivel;
	int totaldetentativas;

	// define quantidade de pontos inicial
	double pontos = 1000;

	// Gerando um numero secreto aleatorio
	srand(time(0));					  // fun��o que deixa os n�meros sempre diferentes
	int numerosecreto = rand() % 100; // pega o resto da divis�o de 'rand' fazendo n�merosecreto ser == 0 a 99

	printf("Qual o n�vel de dificuldade?\n");
	printf("(1) F�cil (2) M�dio (3) Dif�cil\n\n");
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
		printf("Chute um n�mero: \n");
		scanf("%d", &chute);

		if (chute < 0)
		{
			printf("Voc� n�o pode chutar n�meros negativos\n");
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
			printf("\nSeu chute foi maior do que o n�mero secreto!\n\n");
		}
		else
		{
			printf("\nSeu chute foi menor do que o n�mero secreto!\n\n");
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
		printf("\nParab�ns! Voc� acertou!\n");
		printf("Voc� fez %2.f pontos. At� a pr�xima!\n\n", pontos);
	}
	else
	{

		printf("     \\|/ ____ \\|/      \n");
		printf("      @~/  ,. \\~@       \n");
		printf("     /_( \\___/ )_\\     \n");
		printf("        \\___U_/         \n");

		printf("\nVoc� perdeu! Mas na pr�xima tenho certeza que vai conseguir!\n\n");
	}
	system("pause");
}