#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pelas strings

int registro() //Função para cadastrar usuários no sistema
{
	//início da criação de varáveis/strings
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o seu CPF para cadastro: ");
	  scanf("%s", cpf); //o scanf com "%s" é para armazenar os caracteres do cpf na String. String é uma sequência de caract(letra, símbolo) utilizada
	//p/ armazenar o texto
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings	
	
	FILE *file; //o função FILE manda acessar o "file" e eu vou atribuir algum valor ao file na próxima linha, no caso o valor vai ser o do arquivo que é igual oa cpf
	file = fopen(arquivo, "w");
	fprintf (file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //esse "a" é pra atuolizar o arquivo, ja o "w" é pra escrever algo novo 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //esse "a" é pra atuolizar o arquivo, ja o "w" é pra escrever algo novo 
	fprintf(file, ",");
	fclose(file);
	
	
	
	
	printf ("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	printf ("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
	
	
	
		}
		
	

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //esse "r" é o comando de ordem para ler o arquivo e consultar
	
	if (file == NULL)
	{
		printf ("Não foi possível abrir o arquivo, sem registros! \n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL);
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system ("pause");
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF o qual você quer apagar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE* file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Esse arquivo não existe \n\n");
		system("pause");
	}
	
		
	
	}

int saida()
{
	exit(0);
}


int main()
{
	int opcao=0; //repare que só tem um = nessa linha, isso quer dizer que eu estou atribuindo um valor a essa variável que é diferente de == quando eu comparo
	int laco=1;
	
	for(laco=1;laco==1;)
	{
		system("cls");
		
		
	
    setlocale(LC_ALL, "Portuguese"); //Definindo linguageum
    
	printf("### Cartório do Raphael### \n\n"); //Início do menu
	printf( "Escolha a opção que deseja no menu \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes \n");
	printf("\t4 - Encerrar o programa\n\n");
	printf("Opção: "); //fim do menu
	
	
	//scanf tem como função escanear o que o usuário coloca
	scanf("%d" , &opcao);//Armazenando a escolha do usuário
	
	system ("cls"); //tem como função limpar a tela
	
	switch(opcao)
	{
	 case 1: 
    registro();
		break;
	
		case 2:	
	consulta();
	break;
	
	case 3: 
	deletar();
	break;
	
	case 4:
		saida();
		break;
	
	default: printf("Essa opção não existe, tente novamente!\n");
	system("pause");
	break;
}
	
	
}
}
