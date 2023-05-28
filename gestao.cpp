#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	char name[100]; 
	char position[50];
	float salary;
}Funcionario;

int menu(Funcionario funcionarios);
void header(), listarCargos(), listarFuncionarios(), listarFuncionariosCargo(), demissao(), folhaPagamento(), reciboSalario();
void cadastro(Funcionario funcionarios);
void options(int op, Funcionario func);

int code = 0;

int main(){

	setlocale(LC_ALL, "Portuguese");
	
	int option;
	
	Funcionario funcionarios;
	
	option = menu(funcionarios);
	
}

void header(){
	printf("*****************************************************************************************************************\n");
	printf("\t\t\t\t\tSISTEMA DE GESTÃO DE FUNCIONÁRIOS\n");
	printf("*****************************************************************************************************************\n");
}

int menu(Funcionario funcionarios){
	
	int option;
	
	header();
	printf("1 - Cadastrar funcionário\n");
	printf("2 - Listar cargos\n");
	printf("3 - Listar funcionários\n");
	printf("4 - Listar funcionários por cargo\n");
	printf("5 - Realizar demissão de um funcionário\n");
	printf("6 - Gerar folha de pagamento\n");
	printf("7 - Gerar recibo de salário\n");
	printf("0 - Sair\n");
	printf("---------------------------------------------\n");
	printf("Digite o número da opção desejada: ");
	scanf("%d", &option);
	fflush(stdin);
	
	options(option, funcionarios);
	
	printf("\n---------------------------------------------\n");
}

void options(int op, Funcionario func){
	header();
	switch(op){
		case 1:
			printf("\n---------------------------------------------\n");
			printf("\t    Cadastrar funcionário\n");
			printf("---------------------------------------------\n");		
			cadastro(func);
			break;
			
		case 2: 
			printf("\n---------------------------------------------\n");
			printf("\t        Listar cargos\n");
			printf("---------------------------------------------\n");
			//listarCargos();
			break;
			
		case 3:
			printf("\n---------------------------------------------\n");
			printf("\t      Listar funcionários\n");
			printf("---------------------------------------------\n");
			//listarFuncionarios();
			break;
			
		case 4: 
			printf("\n---------------------------------------------\n");
			printf("\tListar funcionários por cargo\n");
			printf("---------------------------------------------\n");
			//listarFuncionariosCargo();
			break;
			
		case 5: 
			printf("\n---------------------------------------------\n");
			printf("\t    Demissão de funcionário\n");
			printf("---------------------------------------------\n");
			//demissao();
			break;
			
		case 6: 
			printf("\n---------------------------------------------\n");
			printf("\t   Gerar folha de pagamento\n");
			printf("---------------------------------------------\n");
			//folhaPagamento();
			break;
			
		case 7: 
			printf("\n---------------------------------------------\n");
			printf("\t    Gerar recibo de salário\n");
			printf("---------------------------------------------\n");
			//reciboSalario();
			break;
			
		case 0:
			printf("\n\nEncerrando sistema...");
			abort();
			break;
			
		default:
			printf("\nERRO! Número incorreto!\n");
			printf("Só é possível digitar numéros de 0 a 7!");
			printf("Tente novamente!");
			break;
		}	
}

void cadastro(Funcionario func){

	printf("Nome do funcionário: ");
	fgets(func.name, 100, stdin);
	fflush(stdin);
	
	printf("Cargo: ");
	fgets(func.position, 50, stdin);
	fflush(stdin);
	
	printf("Salário: ");
	scanf("%f", &func.salary);
	fflush(stdin);
}

void listarCargos(){
	printf("Testando lista");
}

void listarFuncionarios(){
	printf("Testando lista fun.");
}

void listarFuncionariosCargo(){
	printf("Testando lista fun. cargos");
}

void demissao(){
	printf("Testando demissão");
}

void folhaPagamento(){
	printf("Testando folha de pagamento");	
}

void reciboSalario(){
	printf("Testando recibo pagamento");
}


