#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include <locale.h>


void menu();

void inserir();

void excluir();

void editar();

void consulta();

void buscaNome ();

void loginSenha();


struct produto{

	char nome[50];

	char tipo[50];

	float preco;

	int quant;

	int cod;

};


typedef struct produto cadastro;


char continua = 's';

int tam = 0, i = 0;

cadastro *ptr = (cadastro*)malloc(0);

		

int main(){

	setlocale(LC_ALL, "Portuguese");

	int escolM;

	

	loginSenha();	

	

	while (escolM != 6){

	    menu();

		scanf("%i",&escolM);

		switch (escolM){

			case 1:

				inserir();

				break;

			case 2:

				excluir();

				break;

			case 3:

				editar();

				break;

			case 4:

			    consulta();

				break;

			case 5:

				buscaNome();

				break;

		}

	}

	

}


void inserir(){

	continua = 's';

	while(continua != 'n')

	{

		tam++;

		ptr = (cadastro*)realloc(ptr,tam*sizeof(cadastro));

		printf("Digite o nome do produto:\n");

		scanf("%s",&ptr[i].nome);

		printf("Digite o tipo do produto:\n");

		scanf("%s",&ptr[i].tipo);

		printf("Digite o pre�o do produto:\n");

		scanf("%f",&ptr[i].preco);

		printf("Digite o estoque do produto:\n");

		scanf("%i",&ptr[i].quant);

		printf("Digite o c�digo do produto:\n");

		scanf("%i",&ptr[i].cod);

		i++;

		

		printf("Deseja cadastrar outro? (s/n)\n");

		scanf(" %c",&continua);

		printf("\n");

	}

	

    system("cls");

	printf("\n");

    printf("Cadastros Realizados:\n");

    

	for (i=0; i < tam; i++)

	{

		printf("-------------------------\n");

		printf("Nome do produto: %s\n",ptr[i].nome);

		printf("Tipo do produto: %s\n",ptr[i].tipo);

        printf("pre�o do produto: %.2f\n",ptr[i].preco);

        printf("Quantidade do produto: %i\n",ptr[i].quant);

        printf("C�digo do produto: %i\n",ptr[i].cod);

		printf("-------------------------");

		printf("\n");

		printf("\n");

	}

}


void excluir (){

	int exclui = 0;

	char lixo[50];

	

	printf("Digite o c�digo do produto a ser excluido: \n");

	scanf("%i",&exclui);

	

	for (i=0; i<tam; i++)

	{

		if (ptr[i].cod == exclui)

		{

		    strcpy(ptr[i].nome,"");

		    strcpy(ptr[i].tipo,"");

		    ptr[i].preco = 0;

		    ptr[i].quant = 0;

		    ptr[i].cod = -1;

		}

	}

}


void editar (){

	int edita;

	

	printf("Digite o c�digo do produto a ser editado: \n");

	scanf("%i",&edita);

	

	for (i=0; i<tam; i++)

	{

		if (ptr[i].cod == edita)

		{

			printf("Digite o nome do produto:\n");

		    scanf("%s",&ptr[i].nome);

		    printf("Digite o tipo do produto:\n");

		    scanf("%s",&ptr[i].tipo);

		    printf("Digite o pre�o do produto:\n");

		    scanf("%f",&ptr[i].preco);

		    printf("Digite o estoque do produto:\n");

		    scanf("%i",&ptr[i].quant);

		    printf("Digite o c�digo do produto:\n");

		    scanf("%i",&ptr[i].cod);

		}

	}

	

}


void consulta (){

	system("cls");

		printf("\n");

	    printf("Cadastros Realizados:\n");

	for (i=0; i < tam; i++)

	{

		if (ptr[i].cod != -1){

			printf("-------------------------\n");

			printf("Nome do produto: %s\n",ptr[i].nome);

			printf("Tipo do produto: %s\n",ptr[i].tipo);

	        printf("pre�o do produto: %.2f\n",ptr[i].preco);

	        printf("Quantidade do produto: %i\n",ptr[i].quant);

	        printf("C�digo do produto: %i\n",ptr[i].cod);

			printf("-------------------------");

			printf("\n");

			printf("\n");

		}

	}

}


void buscaNome (){

	char busca[50];

	

	printf("Digite o nome: \n");

	scanf("%s",busca);

	

	for (i=0; i < tam; i++)

	{

		if(strcmp(busca, ptr[i].nome) == 0){

			system("cls");

			printf("-------------------------\n");

			printf("Nome do produto: %s\n",ptr[i].nome);

			printf("Tipo do produto: %s\n",ptr[i].tipo);

	        printf("pre�o do produto: %.2f\n",ptr[i].preco);

	        printf("Quantidade do produto: %i\n",ptr[i].quant);

	        printf("C�digo do produto: %i\n",ptr[i].cod);

			printf("-------------------------");

			printf("\n");

			printf("\n");

		}

	}

	

	

}


void loginSenha(){


	char login[6] = "LubySoftware";

	char login1[6] = "";

	char senha[12] = "lubyluby";

	char senha1[12] = "";

	

	printf("Estoque de produto\n\n");

	while(strcmp(login, login1) != 0){

		printf("LOGIN:  ");

	    scanf("%s",login1);

	    

	    if (strcmp(login, login1) != 0){

		    printf("login incorreta\n\n\n");

		}	

	}

	while(strcmp(senha, senha1) != 0){

		printf("SENHA:  ");

	    scanf("%s",senha1);

	    if (strcmp(senha, senha1) != 0){

		    printf("Senha incorreta\n\n\n");

		}	

	}

	system("cls");

}


void menu(){	

    printf("**********MENU***********\n");

	printf("* 1 - Inclus�o          *\n");

	printf("* 2 - Remo��o           *\n");	

	printf("* 3 - Edi��o            *\n");

	printf("* 4 - Consulta          *\n");

	printf("* 5 - Busca por nome    *\n");

	printf("* 6 - Sair              *\n");

	printf("*************************\n");

}
