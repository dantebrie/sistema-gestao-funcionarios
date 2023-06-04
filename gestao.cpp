#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

struct Funcionario {
	char nome[100]; 
	char cargo[50];
	int diasTrabalhados;
	float salarioDia;
	char cpf[14];
	float salarioBruto; 
	float salarioLiquido;
	float valeTransporte;
	float impostoRenda;
	struct Funcionario *prox;
};

typedef struct Funcionario funcionarios;

int menu(Funcionario *funcionarios);
void cabecalho();
void listarCargos(Funcionario *funcionarios), listarFuncionarios(Funcionario *funcionarios);
void listarFuncionariosCargo(Funcionario *funcionarios), demissao(Funcionario *funcionarios);
void folhaPagamento(Funcionario *funcionarios), reciboSalario(Funcionario *funcionarios);
void cadastroFuncionario(Funcionario *funcionarios), cabecalhoCadastro();
void opcoes(int op, Funcionario *funcionarios), valoresSalario(Funcionario *funcionarios);


int codigo = 0, retorno = -1, numeroLetrasNome, numeroLetrasCargo;

int i = 0, escolha, voltar = 0, busca1, busca2;
bool valido;
float planoSaude = 600.0;

char listaDeCargos[15][20] = {
    "PRESIDENTE", "CEO", "GERENTE", "ASSISTENTE", "DIRETOR", "TECNICO", "ESTAGIARIO", "SECRETARIA", "COODERNADOR", "ANALISTA", "ASSESSOR"
};

int main(){

	setlocale(LC_ALL, "Portuguese");
	
	int opcao;
	
	Funcionario *funcionarios = (Funcionario *) malloc(sizeof(Funcionario));
		
	do{
		opcao = menu(funcionarios);
		system("cls");
		
	}while(opcao != 0);
}
	
void cabecalho(){
	printf("*****************************************************************************************************************\n");
	printf("\t\t\t\t\tSISTEMA DE GESTÃO DE FUNCIONÁRIOS\n");
	printf("*****************************************************************************************************************\n");
}

int menu(Funcionario *funcionarios){
	
	int opcao;
	
	cabecalho();
	
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
	scanf("%d", &opcao);
	fflush(stdin);
	
	system("cls");
	
	opcoes(opcao, funcionarios);
	
	system("pause");
	
	printf("\n---------------------------------------------\n");

	
	return opcao;
}

void opcoes(int op, Funcionario *funcionarios){
	
	cabecalho();
	
	switch(op){
		case 1:
			printf("\n---------------------------------------------\n");
			printf("\t    Cadastrar funcionário\n");
			printf("---------------------------------------------\n");		
			cadastroFuncionario(funcionarios);
			break;
			
		case 2: 
			printf("\n---------------------------------------------\n");
			printf("\t        Listar cargos\n");
			printf("---------------------------------------------\n");
			listarCargos(funcionarios);
			break;
			
		case 3:
			printf("\n---------------------------------------------\n");
			printf("\t      Listar funcionários\n");
			printf("---------------------------------------------\n");
			listarFuncionarios(funcionarios);
			break;
			
		case 4: 
			printf("\n---------------------------------------------\n");
			printf("\tListar funcionários por cargo\n");
			printf("---------------------------------------------\n");
			listarFuncionariosCargo(funcionarios);
			break;
			
		case 5: 
			printf("\n---------------------------------------------\n");
			printf("\t    Demissão de funcionário\n");
			printf("---------------------------------------------\n");
			demissao(funcionarios);
			break;
			
		case 6: 
			printf("\n---------------------------------------------\n");
			printf("\t   Gerar folha de pagamento\n");
			printf("---------------------------------------------\n");
			folhaPagamento(funcionarios);
			break;
			
		case 7: 
			printf("\n---------------------------------------------\n");
			printf("\t    Gerar recibo de salário\n");
			printf("---------------------------------------------\n");
			reciboSalario(funcionarios);
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

void cadastroFuncionario(Funcionario *funcionarios){
	valido = false;
	
	do
	{
		printf("Informe o nome do funcionario: ");
		gets(funcionarios[codigo].nome);
		fflush(stdin);
		numeroLetrasNome = strlen(funcionarios[codigo].nome);
		for (int i = 0; i < funcionarios->nome[i]; i++)
		{
			if (isalpha(funcionarios->nome[i]))
			{
				valido = true;
			}
			
		}

		if (valido == true)
		{
			break;
		}
		else
		{
			printf("O que foi digitado não é um nome! Tente novamente.\n");
		}

	} while (1);
	
	fflush(stdin);
	system("cls");
	cabecalho();
	cabecalhoCadastro();

	valido = false;

	do{
	    printf("Informe o cargo do funcionario: ");
	    gets(funcionarios[codigo].cargo);
	    fflush(stdin); 
	
		numeroLetrasCargo = strlen(funcionarios[codigo].cargo);        
	
		for(int contador = 0; contador < numeroLetrasCargo; contador++){
			funcionarios[codigo].cargo[contador] = toupper(funcionarios[codigo].cargo[contador]);
		}
	
		for(int contador = 0; contador < 11; contador++){
			if(strcmp(funcionarios[codigo].cargo, listaDeCargos[contador]) == 0){
				valido = true;
			}
		}
		
		if(valido == true){
			break;
		}else{
			printf("Cargo não existente! Informe um cargo da lista.\n\n");
		}
		
	}while(1);
			
	system("cls");
	cabecalho();
	cabecalhoCadastro();

	valido = false;
	bool soNumero = false;
	int qtdCpf;
	do
	{
		printf("Informe o CPF (11 dígitos, sem pontos ou traços): ");
		scanf("%s", &funcionarios[codigo].cpf);
		fflush(stdin);
		
		
		for (int i = 0; i < funcionarios->cpf[i]; i++)
		{
			if (isdigit(funcionarios->cpf[i]))
			{
				soNumero = true;
			}
		}

		qtdCpf = strlen(funcionarios[codigo].cpf);
		if (soNumero == true)
		{
			if (qtdCpf == 11)
			{
				valido = true;
			}
		}
	
		if (valido == true)
		{
			break;
		}
		else
		{
			printf("Formato de CPF inválido! Digite novamente.\n\n");
		}
		
	} while (1);
	
	system("cls");
	cabecalho();
	cabecalhoCadastro();

	retorno = -1;
	
	printf("Informe o número de dias trabalhados: ");
	retorno = scanf("%d", &funcionarios[codigo].diasTrabalhados);
	fflush(stdin);
	
	while(retorno == 0){
		if(retorno == 0){
			printf("\nDigite apenas números!");
			printf("\nInforme o número de dias trabalhados: ");
			retorno = scanf("%d", &funcionarios[codigo].diasTrabalhados);
			fflush(stdin);	
		}
	}
	
	system("cls");
	cabecalho();
	cabecalhoCadastro();
	
	retorno = -1;
    printf("Informe o salário por dia: ");
    retorno = scanf("%f", &funcionarios[codigo].salarioDia);
	fflush(stdin);
	while(retorno == 0){
		if(retorno == 0){
			printf("\nDigite apenas números!\n");
			printf("\nInforme o salário por dia: ");
    		retorno = scanf("%f", &funcionarios[codigo].salarioDia);
			fflush(stdin);
		}
	}
	
	printf("\nCadastro concluído!\n");
	
	valoresSalario(funcionarios);

	codigo++;
}

void valoresSalario(Funcionario *funcionarios){

	funcionarios[codigo].salarioBruto = funcionarios[codigo].diasTrabalhados * funcionarios[codigo].salarioDia;

	if (funcionarios[codigo].salarioBruto <= 1900.0) {
			funcionarios[codigo].impostoRenda = 0.0;
		} else if (funcionarios[codigo].salarioBruto <= 2800.0) {
			funcionarios[codigo].impostoRenda = funcionarios[codigo].salarioBruto * 0.075;
		} else if (funcionarios[codigo].salarioBruto <= 3700.0) {
			funcionarios[codigo].impostoRenda = funcionarios[codigo].salarioBruto * 0.15;
		} else if (funcionarios[codigo].salarioBruto <= 4600.0) {
			funcionarios[codigo].impostoRenda = funcionarios[codigo].salarioBruto * 0.225;
		} else if (funcionarios[codigo].salarioBruto > 4601.0) {
			funcionarios[codigo].impostoRenda = funcionarios[codigo].salarioBruto * 0.275;
		}
		
	if (funcionarios[codigo].salarioBruto <= 1900.0) {
		funcionarios[codigo].valeTransporte = 0.06;
	} else if (funcionarios[codigo].salarioBruto <= 2800.0) {
		funcionarios[codigo].valeTransporte = funcionarios[codigo].salarioBruto * 0.06;
	} else if (funcionarios[codigo].salarioBruto <= 3700.0) {
		funcionarios[codigo].valeTransporte = funcionarios[codigo].salarioBruto * 0.06;
	} else if (funcionarios[codigo].salarioBruto <= 4600.0) {
		funcionarios[codigo].valeTransporte = funcionarios[codigo].salarioBruto * 0.06;
	} else if (funcionarios[codigo].salarioBruto > 4601.0) {
		funcionarios[codigo].valeTransporte = funcionarios[codigo].salarioBruto * 0.06;
	}

	funcionarios[codigo].salarioLiquido = funcionarios[codigo].salarioBruto - funcionarios[codigo].valeTransporte - planoSaude - funcionarios[codigo].impostoRenda;
}
void listarCargos(Funcionario *funcionarios){
	
	for(int i = 0; i < codigo; i++){
		printf("%d - %s\n", i, funcionarios[i].cargo);
	}	
}

void listarFuncionarios(Funcionario *funcionarios){
	
	for(int i = 0; i < codigo; i++){
		printf("%d - %s\n", i, funcionarios[i].nome);
	}
}

void listarFuncionariosCargo(Funcionario *funcionarios){ 

	bool cargosIguais = false;
	
	for(int i = 0; i < codigo; i++){
		if(strcmp(funcionarios[i].cargo, funcionarios[i + 1].cargo) == 0){
			cargosIguais = true;
		}
	}	
	if(cargosIguais == true){
		printf("Tem cargos iguais na lista!");
	}
}

void demissao(Funcionario *funcionarios){
	char demitido[100];
	bool certo = false;
	
	printf("Testando demissão");
	
	printf("\nDigite o nome do funcionário que pretende realizar a demissão: ");
	gets(demitido);
	fflush(stdin);
	
	for(int i = 0; i < codigo; i++){
		if(strcmp(demitido, funcionarios[i].nome) == 0){
			certo = true;
		}
	}
	
	if(certo == true){
		printf("Tem funcionário com esse nome aqui!");
	}else{
		printf("Não tem funcionário com esse nome aqui");
	}
}

void folhaPagamento(Funcionario *funcionarios){
	
	printf("Digite o código do funcionário: ");
	scanf("%d", &busca1);
	fflush(stdin);
	
	printf("\nFolha de Pagamento\n");
    printf("Nome: %s\n", funcionarios[busca1].nome);
    printf("Cargo: %s\n", funcionarios[busca1].cargo);
    printf("CPF: %s\n", funcionarios[busca1].cpf);
    printf("Dias Trabalhados: %d\n", funcionarios[busca1].diasTrabalhados);
    printf("Salário por Dia: %.2f\n", funcionarios[busca1].salarioDia);
    printf("Salário Bruto: %.2f\n", funcionarios[busca1].salarioBruto);
    printf("Descontos:\n");
    printf(" - Vale Transporte: %.2f\n", funcionarios[busca1].valeTransporte);
    printf(" - Plano de Saúde: %.2f\n", planoSaude);
    printf(" - Imposto de Renda: %.2f\n", funcionarios[busca1].impostoRenda);
    printf("Salário Líquido: %.2f\n", funcionarios[busca1].salarioLiquido);
    printf("---------------------------------------------\n");
}

void reciboSalario(Funcionario *funcionarios){
		
	printf("Digite o código do funcionário: ");
	scanf("%d", &busca2);
	fflush(stdin);
	printf(".............................................\n");
    printf("Nome: %s\n", funcionarios[busca2].nome);
    printf("Cargo: %s\n", funcionarios[busca2].cargo);
    printf("CPF: %s\n", funcionarios[busca2].cpf);
    printf("Salário Bruto: %.2f\n", funcionarios[busca2].salarioBruto);
    printf(".............................................\n");
    printf("Descontos:\n");
	printf(".............................................\n");
    printf(" - Vale Transporte: %.2f\n", funcionarios[busca2].valeTransporte);
    printf(" - Plano de Saúde: %.2f\n", planoSaude);
    printf(" - Imposto de Renda: %.2f\n", funcionarios[busca2].impostoRenda);
    printf(".............................................\n");
    printf("Salário Líquido: %.2f\n", funcionarios[busca2].salarioLiquido);
    printf("---------------------------------------------\n");
}
void cabecalhoCadastro(){
	printf("\n---------------------------------------------\n");
	printf("\t    Cadastrar funcionário\n");
	printf("---------------------------------------------\n");		
}
