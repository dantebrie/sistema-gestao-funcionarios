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
	int idade;
	char cpf[12];
	float salarioBruto, salarioLiquido;
	float valeTransporte, impostoRenda;
	
	struct Funcionario *prox;
};

typedef struct Funcionario funcionarios;

int menu(Funcionario *funcionarios);
void cabecalho();
void listarCargos(Funcionario *funcionarios), listarFuncionarios(Funcionario *funcionarios);
void listarFuncionariosCargo(Funcionario *funcionarios), demissao(Funcionario *funcionarios);
void folhaPagamento(Funcionario *funcionarios), reciboSalario(Funcionario *funcionarios);
void cadastroFuncionario(Funcionario *funcionarios);
void contas(Funcionario *funcionarios);
void opcoes(int op, Funcionario *funcionarios);

int codigo = 0, retorno = -1, numeroLetrasNome, numeroLetrasCargo;
char Funcionariocpf[10];
int i = 0, escolha, voltar = 0;
bool caracter;
char cpf[12];
float valeTransporte, impostoRenda;
float salarioBruto, salarioLiquido;
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
			printf("Só é possível digitar numeros de 0 a 7!");
			printf("Tente novamente!");
			break;
		}	
}

void cadastroFuncionario(Funcionario *funcionarios){
	 
     
/*	printf("Nome do funcionário: ");
	fgets(funcionarios[codigo].nome, 100, stdin);
	
	fflush(stdin);*/
	
	do {
	    caracter = false;
	
	    printf("Informe o nome do funcionario: ");
	    fflush(stdout); // Limpa o buffer de saída antes de ler a entrada
	    fgets(funcionarios[codigo].nome, 100, stdin);
		
		numeroLetrasNome = strlen(funcionarios[codigo].nome);

	    // Verifica cada caractere do nome
	    for (int i = 0; i < numeroLetrasNome - 1; i++) {
	        if (!isalpha(funcionarios[codigo].nome[i]) && funcionarios[codigo].nome[i] != ' ') {
	            caracter = true;
	            break;
	        } 
	    }
	    if (caracter) {
	            printf("\nO nome deve conter apenas letras. Tente novamente.\n\n");
	        }
	    } while (caracter);
	    
	    
	/*printf("Cargo do funcionário: ");
	fgets(funcionarios[codigo].cargo, 50, stdin);
	
	fflush(stdin);*/
	
	do {
        caracter = false;

        printf("Informe o cargo do funcionario: ");
        fflush(stdout); // Limpa o buffer de saída antes de ler a entrada
        fgets(funcionarios[codigo].cargo, 50, stdin);
        
		printf("\nNúmero letras: %d\n", numeroLetrasCargo);
		for(int contador = 0; contador < numeroLetrasCargo; contador++){
			funcionarios[codigo].cargo[contador] = toupper(funcionarios[codigo].cargo[contador]);
		}
		
        // Verifica cada caractere do nome
        for (int i = 0; i < numeroLetrasCargo - 1; i++) {
            if (!isalpha(funcionarios[codigo].cargo[i] ) && funcionarios[codigo].cargo[i]  != ' ') {
                caracter = true;
                break;
            } 
        }
	    if (caracter) {
	            printf("\nO cargo deve conter apenas letras. Tente novamente.\n\n");
	        }
	    } while (caracter);
	
	/*printf("Salário do funcionário: ");
	retorno = scanf("%f", &funcionarios[codigo].salario);
	fflush(stdin);
	
	if(retorno == 0){
		printf("\nERRO! Digite o salário novamente! Lembre-se salário é constituído de números!");
		printf("\n\nSalário do funcionário:: ");
		retorno = scanf("%d", &funcionarios[codigo].salario);
		fflush(stdin);
	}*/
	
	retorno = -1;
	
	printf("Idade: ");
	retorno = scanf("%d", &funcionarios[codigo].idade);
	fflush(stdin);
	
	if(retorno == 0){
		printf("\nERRO! Digite a idade novamente! Lembre-se idade são apenas números!");
		printf("\n\nIdade: ");
		retorno = scanf("%d", &funcionarios[codigo].idade);
		fflush(stdin);
	}
	
	/*retorno = -1;
	
	printf("CPF: ");
	retorno = scanf("%d", &funcionarios[codigo].cpf);
	fflush(stdin);
	
	if(retorno == 0){
		printf("\nERRO! Digite o CPF novamente! Lembre-se CPF são apenas números!");
		printf("\n\nCPF: ");
		retorno = scanf("%d", &funcionarios[codigo].cpf);
		fflush(stdin);
	}*/
	while (1) {
	        printf("Informe o CPF (11 dígitos, sem pontos ou traços): ");
	        fflush(stdout);
	        if (scanf("%11s", &funcionarios[codigo].cpf) != 1) {
	            printf("Entrada inválida! Digite apenas números.\n\n");
	            while (getchar() != '\n'); // Limpa o buffer do teclado
	            break; // Reinicia o loop
	        }
	
	        int count = 0;
	    
	        for (int i = 0; funcionarios[codigo].cpf[i] != '\0'; i++) {
	            if (!isdigit(funcionarios[codigo].cpf[i])) {
	                printf("Entrada inválida! Digite apenas números.\n\n");
	                count = -1; // Sinaliza que a entrada é inválida
	                break; // Sai do loop for
	            }
	            count++;
	        }
			
			
	        if (count == 11) {
	        	
                 break;// Sai do loop while
	        } else {
	           printf("CPF inválido! Digite exatamente 11 dígitos.\n");
        	}
		}
		
	printf("Informe o numero de dias trabalhados: ");
	scanf("%d", &funcionarios[codigo].diasTrabalhados, 100, stdin);

    printf("Informe o salario por dia: ");
    scanf("%f", &funcionarios[codigo].salarioDia, 100, stdin);

	codigo++;
	
	printf("\nCadastro concluído!\n");
}

/*void cadastroCargo(Funcionario *funcionarios){ //A parte do contador se torna um problema se separar assim
	
	printf("Cargo do funcionário: ");
	fgets(funcionarios[codigo].cargo, 50, stdin);
	fflush(stdin);
	
}
*/

void listarCargos(Funcionario *funcionarios){
	
	for(int i = 0; i < codigo; i++){
		printf("%d - %s\n", i + 1, funcionarios[i].cargo);
	}	
}

void listarFuncionarios(Funcionario *funcionarios){
	
	for(int i = 0; i < codigo; i++){
		printf("%d - %s\n", i + 1, funcionarios[i].nome);
	}
}

void listarFuncionariosCargo(Funcionario *funcionarios){ //Tem que consertar isso aqui
	
/*	for(int i = 0; i < codigo; i++){
		printf("%d - %s\n", i + 1, funcionarios[i].nome);
	}
	printf("\n");*/
	
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
	fgets(demitido, 100, stdin);
	
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

void contas(Funcionario *funcionarios){ 

	    salarioBruto = funcionarios->diasTrabalhados * funcionarios->salarioDia;
	    if (funcionarios[codigo].salarioBruto <= 1900.0) {
	        funcionarios[codigo].impostoRenda = 0.0;
	    } else if (funcionarios[codigo].salarioBruto <= 2800.0) {
	        funcionarios[codigo].impostoRenda = salarioBruto * 0.075;
	    } else if (funcionarios[codigo].salarioBruto <= 3700.0) {
	        funcionarios[codigo].impostoRenda = salarioBruto * 0.15;
		} else if (funcionarios[codigo].salarioBruto <= 4600.0) {
	        funcionarios[codigo].impostoRenda = salarioBruto * 0.225;
	    } else if (funcionarios[codigo].salarioBruto > 4601.0) {
	        funcionarios[codigo].impostoRenda = salarioBruto * 0.275;
	    }
	    
	    if (funcionarios[codigo].salarioBruto <= 1900.0) {
	        funcionarios[codigo].valeTransporte = 0.06;
	    } else if (funcionarios[codigo].salarioBruto <= 2800.0) {
	        funcionarios[codigo].valeTransporte = salarioBruto * 0.06;
	    } else if (funcionarios[codigo].salarioBruto <= 3700.0) {
	        funcionarios[codigo].valeTransporte = salarioBruto * 0.06;
		} else if (funcionarios[codigo].salarioBruto <= 4600.0) {
	        funcionarios[codigo].valeTransporte = salarioBruto * 0.06;
	    } else if (funcionarios[codigo].salarioBruto > 4601.0) {
	        funcionarios[codigo].valeTransporte = salarioBruto * 0.06;
	    }
	
	    // Calculo do salário líquido com descontos
	    salarioLiquido = salarioBruto - valeTransporte - planoSaude - impostoRenda;
}
void folhaPagamento(Funcionario *funcionarios){
    contas(funcionarios);
	
    printf("\nFolha de Pagamento\n");
    printf("Nome: %s\n", funcionarios->nome);
    printf("Cargo: %s\n", funcionarios->cargo);
    printf("Idade: %d\n", funcionarios->idade);
    printf("CPF: %s\n", funcionarios->cpf);
    printf("Dias Trabalhados: %d\n", funcionarios->diasTrabalhados);
    printf("Salário por Dia: %.2f\n", funcionarios->salarioDia);
    printf("Salário Bruto: %.2f\n", salarioBruto);
    printf("Descontos:\n");
    printf(" - Vale Transporte: %.2f\n", valeTransporte);
    printf(" - Plano de Saúde: %.2f\n", planoSaude);
    printf(" - Imposto de Renda: %.2f\n", impostoRenda);
    printf("Salário Líquido: %.2f\n", salarioLiquido);
}

void reciboSalario(Funcionario *funcionarios){
	    contas(funcionarios);
	    printf("\nRecibo de SalÃ¡rio\n");
	    printf("Nome: %s", funcionarios->nome);
	    printf("Cargo: %s\n", funcionarios->cargo);
	    printf("Idade: %d\n", funcionarios->idade);
	    printf("CPF: %s\n", funcionarios->cpf);
	    printf("Salário Bruto: %.2f\n", salarioBruto);
	    printf("Descontos:\n");
	    printf(" - Vale Transporte: %.2f\n", valeTransporte);
	    printf(" - Plano de Saúde: %.2f\n", planoSaude);
	    printf(" - Imposto de Renda: %.2f\n", impostoRenda);
	    printf("Salário Líquido: %.2f\n\n", salarioLiquido);
}
