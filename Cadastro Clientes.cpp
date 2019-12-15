
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <strings.h>


void menu()
{
	printf("=====================\n");
	printf("|  BEM VINDO AO MENU |\n");
	printf("=====================\n");
	printf("- Para efetuar novos cadastros digite 1\n- Para visualizar cadastros ja existentes digite 2\n- Para sair digite 0\n");
}
void agendalota()
{
	printf("=====================\n");
	printf("|   Agenda lotada!   |\n");
	printf("=====================\n");
}
void agendavaz()
{
	printf("=====================\n");
	printf("|   Agenda Vazia!    |\n");
	printf("=====================\n");
}
main()
{
	struct registro_pessoa{
		int cod;
		char nom[50];
		char tel[12];
		char end[100];
	};
	
	int agendal, resp, op, i;
	struct registro_pessoa reg[5];
	
	agendal = 0;
	
	do
	{
		system("cls");
		menu();
		scanf("%d", &op);
		switch(op)
		{
			case 1:
				system("cls");
				printf("=================================\n");
				printf("Voce escolheu a opcao 1(Cadastro)\n");
				printf("=================================\n");
				if(agendal==1)
				{
					agendalota();
				}
				if(agendal==0)
				{
					for(i=0; i<5; i++)
					{
						fflush(stdin);
						reg[i].cod = 100+i;
						printf("Digite o nome: \n");
						gets(reg[i].nom);
						fflush(stdin);
						printf("Digite o telefone: \n");
						gets(reg[i].tel);
						fflush(stdin);
						printf("Digite o endereco: \n");
						gets(reg[i].end);
						fflush(stdin);
						printf("====================\n");
						agendal = 1;
					}
				}
				break;
			case 2:
				if(agendal==0)
				{
					fflush(stdin);
					system("cls");
					printf("=================================\n");
					printf("Voce escolheu a opcao 2(Visualizar)\n");
					printf("=================================\n");
					agendavaz();
				}
				if(agendal==1)
				{
					for(i=0; i<5; i++)
					{
						printf("Codigo: %d \n", reg[i].cod);
						printf("Nome: %s \n", reg[i].nom);
						printf("Telefone: %s \n", reg[i].tel);
						printf("Endereco: %s \n", reg[i].end);
						printf("========================== \n");
					}
				}
				break;
			case 0:
				exit(0);
				break;
			default:
				system("cls");
				printf("=================================\n");
				printf("Opcao Invalida (error404notfound)\n");
				printf("=================================\n");
		}
		printf("Para voltar ao menu pressione 1, caso contrario tecle outra tecla\n");
		scanf("%d", &resp);
	}while(resp==1);
	return (0);
}
