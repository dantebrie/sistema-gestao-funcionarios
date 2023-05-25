#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int code = 0;

struct Funcionario{
	char nome[100]; 
	char cargo[50];
};

void menu();
void cadastro(Funcionario *funcionarios);

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	menu();
	
}

void menu(){
	printf("********************************************\n");
	printf("          CADASTRO DE FUNCIONÁRIOS          \n");
	printf("********************************************\n");
	printf("1 - Cadastrar funcionário\n");
	printf("2 - Listar cargos\n");
	printf("3 - Listar funcionários\n");
	printf("4 - Listar funcionários por cargo\n");
	printf("5 - Realizar demissão de um funcionário\n");
	printf("6 - Gerar folha de pagamento\n");
	printf("7 - Gerar recibo de salário\n");
	printf("0 - Sair");
}


void cadastro(Funcionario *funcionarios){

	printf("Nome do funcionário: ");
	gets(funcionarios[code].nome);
	fflush(stdin);
	
	printf("Cargo: ");
	gets(funcionarios[code].cargo);
}
