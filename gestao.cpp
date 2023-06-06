#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

struct Funcionario {
	char nome[100]; 
	char cargo[50];
	int id;
	int posi_id;
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
void cabecalho(), salvarDados(Funcionario *funcionarios), lerDados(Funcionario *funcionarios);
void listarCargos(Funcionario *funcionarios), listarFuncionarios(Funcionario *funcionarios);
void listarFuncionariosCargo(Funcionario *funcionarios), demissao(Funcionario *funcionarios);
void folhaPagamento(Funcionario *funcionarios), reciboSalario(Funcionario *funcionarios);
void cadastroFuncionario(Funcionario *funcionarios), cabecalhoCadastro();
void opcoes(int op, Funcionario *funcionarios);


int codigo = 0, retorno = -1, numeroLetrasNome, numeroLetrasCargo, contagem = 0;
int i = 0, escolha, voltar = 0, busca1, busca2;
bool valido;
float planoSaude = 600.0;

char listaDeCargos[11][20] = {
    "PRESIDENTE", "CEO", "GERENTE", "ASSISTENTE", "DIRETOR", "TECNICO", "ESTAGIARIO", "SECRETARIA", "COORDENADOR", "ANALISTA", "ASSESSOR"
};

int main(){

	setlocale(LC_ALL, "Portuguese");

	int opcao;
	
	Funcionario *funcionarios = (Funcionario *) malloc(20*sizeof(Funcionario));

	do{
		opcao = menu(funcionarios);
		system("cls");
		
	}while(opcao != 0);

	lerDados(funcionarios);
	free(funcionarios);

	return 0;
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
			contagem++;
			printf("\n---------------------------------------------\n");
			printf("\t    Cadastrar funcionário\n");
			printf("---------------------------------------------\n");	
			if(contagem <= 20){
				cadastroFuncionario(funcionarios);	
			}else{
				printf("\nLimite de cadastro alcançado\n");
			}
			break;
			
		case 2: 
			printf("\n---------------------------------------------\n");
			printf("\t        Listar cargos\n");
			printf("---------------------------------------------\n");
			
			if(contagem != 0){
				listarCargos(funcionarios);
			}else{
				printf("\nNão há cargos cadastrados no momento!\n");
				printf("Cadastre um funcionário para poder listar!\n\n");
			}
			break;
			
		case 3:
			printf("\n---------------------------------------------\n");
			printf("\t      Listar funcionários\n");
			printf("---------------------------------------------\n");
			
			if(contagem != 0){
				listarFuncionarios(funcionarios);
			}else{
				printf("\nNão há funcionários cadastrados no momento!\n");
				printf("Cadastre um funcionário para poder listar!\n\n");
			}
			break;
			
		case 4: 
			printf("\n---------------------------------------------\n");
			printf("\tListar funcionários por cargo\n");
			printf("---------------------------------------------\n");
			
			if(contagem != 0){
				listarFuncionariosCargo(funcionarios);
			}else{
				printf("\nNão existe cargos registrados no momento.");
				printf("\nRealize um cadastro para listar!\n\n");
			}
			break;
			
		case 5: 
			printf("\n---------------------------------------------\n");
			printf("\t    Demissão de funcionário\n");
			printf("---------------------------------------------\n");
			
			if(contagem != 0){	
				demissao(funcionarios);
			}else{
				printf("\nNão há dados cadastrados no momento!\n");
				printf("Para realizar a demissão, realize um cadastro!\n\n");
			}
		
			break;
			
		case 6: 
			printf("\n---------------------------------------------\n");
			printf("\t   Gerar folha de pagamento\n");
			printf("---------------------------------------------\n");
			
			if(contagem != 0){
				folhaPagamento(funcionarios);
			}else{
				printf("\nNão há dados cadastrados no momento!\n");
				printf("Para gerar a folha de pagamento, primeiramente realize um cadastro!\n\n");
			}
			
			break;
			
		case 7: 
			printf("\n---------------------------------------------\n");
			printf("\t    Gerar recibo de salário\n");
			printf("---------------------------------------------\n");
			
			if(contagem != 0){
				reciboSalario(funcionarios);
			}else{
				printf("\nNão há dados cadastrados no momento!\n");
				printf("Para gerar a recibo de salário, primeiramente realize um cadastro!\n\n");
			}
			break;
			
		case 0:
			printf("\n\nEncerrando sistema...\n");
			salvarDados(funcionarios);
			abort();
			break;
			
		default:
			printf("\nOpção inválida! Escolha uma dentre as opções do menu.\n");
			break;
		}	
}

void cadastroFuncionario(Funcionario *funcionarios){

	bool soNumero = false;
	int qtdCpf, cont = 0, totalNome = 0;
	bool soLetra;
	
	soLetra = false;
	do{
		soLetra = false;

		printf("Informe o nome do funcionario: ");
		gets(funcionarios[codigo].nome);
		fflush(stdin);

		numeroLetrasNome = strlen(funcionarios[codigo].nome);
		totalNome = 0;

		for (int i = 0; i < numeroLetrasNome; i++){
			funcionarios[codigo].nome[i] = toupper(funcionarios[codigo].nome[i]);
		}
		
		for (int i = 0; i < numeroLetrasNome; i++){
			if (isalpha(funcionarios[codigo].nome[i]) && isspace(funcionarios[codigo].nome[i])){
				totalNome++;
			}
		
		}
		if(totalNome == numeroLetrasNome){
			soLetra = true;
		}

		if (soLetra == true){
			break;
		}
		else{
			printf("\nFormato de nome inválido! Informe um nome válido e tente novamente.\n");
		}

	} while (1);
	
	fflush(stdin);
	system("cls");
	cabecalho();
	cabecalhoCadastro();

	valido = false;
	
	printf("Cargos disponíveis: \n");
	for(int i = 0; i < 11; i++){
		printf("%s\n", listaDeCargos[i]);
	}
	
	do{
	    printf("\nInforme o cargo do funcionario: ");
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
			printf("\nCargo não existente! Informe um cargo da lista.\n");
		}
		
	}while(1);
			
	system("cls");
	cabecalho();
	cabecalhoCadastro();

	valido = false;
	
	do{
		valido = false;
		soNumero = false;
		printf("Informe o CPF (11 dígitos, sem pontos ou traços): ");
		scanf("%s", &funcionarios[codigo].cpf);
		fflush(stdin);
		
		cont = 0;
		for (int i = 0; i < funcionarios[codigo].cpf[i]; i++){
			if (isdigit(funcionarios[codigo].cpf[i])){
				cont++;
			}
		}

		qtdCpf = strlen(funcionarios[codigo].cpf);
		
		if(cont == 11){
			soNumero = true;
		}
		
		if (qtdCpf == 11){
			valido = true;
		}
	
		if (valido == true && soNumero == true){
			break;
		}else{
			printf("\nFormato de CPF inválido! Informe um CPF válido.\n");
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
	
	funcionarios[codigo].salarioBruto = funcionarios[codigo].diasTrabalhados * funcionarios[codigo].salarioDia;

	if(funcionarios[codigo].salarioBruto <= 1900.0){
		funcionarios[codigo].impostoRenda = 0.0;
	}else if(funcionarios[codigo].salarioBruto <= 2800.0) {
		funcionarios[codigo].impostoRenda = funcionarios[codigo].salarioBruto * 0.075;
	}else if(funcionarios[codigo].salarioBruto <= 3700.0){
		funcionarios[codigo].impostoRenda = funcionarios[codigo].salarioBruto * 0.15;
	}else if(funcionarios[codigo].salarioBruto <= 4600.0){
		funcionarios[codigo].impostoRenda = funcionarios[codigo].salarioBruto * 0.225;
	}else if(funcionarios[codigo].salarioBruto > 4601.0){
		funcionarios[codigo].impostoRenda = funcionarios[codigo].salarioBruto * 0.275;
	}
		
	if(funcionarios[codigo].salarioBruto <= 1900.0){
		funcionarios[codigo].valeTransporte = 0.06;
	}else if(funcionarios[codigo].salarioBruto <= 2800.0){
		funcionarios[codigo].valeTransporte = funcionarios[codigo].salarioBruto * 0.06;
	}else if(funcionarios[codigo].salarioBruto <= 3700.0){
		funcionarios[codigo].valeTransporte = funcionarios[codigo].salarioBruto * 0.06;
	}else if(funcionarios[codigo].salarioBruto <= 4600.0){
		funcionarios[codigo].valeTransporte = funcionarios[codigo].salarioBruto * 0.06;
	}else if(funcionarios[codigo].salarioBruto > 4601.0){
		funcionarios[codigo].valeTransporte = funcionarios[codigo].salarioBruto * 0.06;
	}

	funcionarios[codigo].salarioLiquido = funcionarios[codigo].salarioBruto - funcionarios[codigo].valeTransporte - planoSaude - funcionarios[codigo].impostoRenda;

	printf("\nCadastro concluído!\n\n");
	printf("---------------------------------------------\n");
	printf("Código do funcionário: %d", codigo);
	printf("\n---------------------------------------------\n");

	funcionarios[codigo].id = codigo;
	funcionarios[codigo].posi_id = codigo;
	codigo++;
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
	char cargo[20];
	bool cargoD = false;
	printf("Funcionario com o cargo: ");
	scanf("%s", &cargo);
	
	for(int i = 0; i < strlen(cargo); i++){
		cargo[i] = toupper(cargo[i]);
	}
	
	for(int i = 0; i < codigo; i++){
		if(strcmp(funcionarios[i].cargo, cargo) == 0){
			cargoD = true;
			printf("%d - %s\n",i, funcionarios[i].nome);
		}else{
			printf("\nErro! Não há funcionário cadastrado com esse cargo no momento.\n");
		}
	
	}
}


void demissao(Funcionario *funcionarios){

	printf("\n\nInforme o ID do funcionário para realizar a demissão: ");
	scanf("%d", &funcionarios->id);

	valido = false;

	for (int i = 0; i < codigo; i++){
		if (funcionarios->id == funcionarios[i].posi_id){
			for (int i = funcionarios->id; i < codigo; i++){
				funcionarios[i].id = funcionarios[i + 1].id - 1;
				strcpy(funcionarios[i].nome, funcionarios[i + 1].nome);
				valido = true;
				break;
			}

			codigo--;
			printf("\n\nFuncionário demitido com sucesso.\n");
			contagem--;
		}
	}
	
	if (valido != true){
		printf("\n\nO ID informado não existe! Informe um ID válido.\n");
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

void salvarDados(Funcionario *funcionarios){
	FILE *arq = fopen("dados.txt", "w");

	if(arq == NULL){
		printf("\nNão foi possível receber os dados no arquivo.\n");
		return;
	}

	for (int i = 0; i < codigo; i++)
	{	
		fprintf(arq, "Nome: %s\n", funcionarios[i].nome);
		fprintf(arq, "Cargo: %s\n", funcionarios[i].cargo);
		fprintf(arq, "CPF: %s\n", funcionarios[i].cpf);
		fprintf(arq, "Dias trabalhados: %d\n", funcionarios[i].diasTrabalhados);
		fprintf(arq, "Salário Bruto: %.2f\n", funcionarios[i].salarioBruto);
		fprintf(arq, "Salário Líquido: %.2f\n\n", funcionarios[i].salarioLiquido);
	}
	
	fclose(arq);
}

void lerDados(Funcionario *funcionarios){
	FILE *arq = fopen("dados.txt", "r");

	if(arq == NULL){
		return;
	}

	for (int i = 0; i < codigo; i++)
	{
		fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), arq);
		fgets(funcionarios[i].cargo, sizeof(funcionarios[i].cargo), arq);
		fgets(funcionarios[i].cpf, sizeof(funcionarios[i].cpf), arq);
		fscanf(arq, "%d", &funcionarios[i].diasTrabalhados);
		fscanf(arq, "%f", &funcionarios[i].salarioBruto);
		fscanf(arq, "%f", &funcionarios[i].salarioLiquido);
	}
	
	fclose(arq);
}
