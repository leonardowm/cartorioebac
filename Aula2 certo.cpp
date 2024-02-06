#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioeteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Bibioteca de aloca��es de texto por regi�o
#include <string.h> // Biblioteca respons�vel pelas string

int registro() // Fun��o para cadastrar usu�rios
{
	// inicio cria��o variaveis
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40]; // Vari�vel para registrar CPF
	char nome[40]; // Vari�vel para registrar nome
	char sobrenome[40]; // Vari�vel para registrar sobrenome
	char cargo[40]; // Vari�vel para registrar cargo
	// fim cria��o variaveis
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf); // Armazena no string
	
	strcpy(arquivo, cpf); // Atribui string do CPF para o arquivo
	
	FILE *file; // Cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // Cria o arquivo no banco de dados (w=novo)
	fprintf(file,cpf); // Salvo o valor da vari�vel no bando de dados
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // (a=atualiza��o)
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); 
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); 
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo); 
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja deletar:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!. \n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //	Definindo vari�veis
	int laco=1; //	Definindo vari�veis
	
	for(laco=1;laco=1;) //Repeti��o
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");	
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); // Fim do menu
	
		scanf ("%d", &opcao); //Armazenamento da escolha do usu�rio (armazena na vari�vel)
	
		system("cls"); // limpa tela
		
		// In�cio da sele��o
		switch(opcao) // Decis�o 
		{
			case 1:
			registro();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			
	// Fim da sele��o
	
}
	// printf("Esse Software � de livre uso dos alunos\n");
}
}
