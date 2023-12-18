#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int registro() //Fun��o para cadastrar usu�rios no sistema
{
	//in�cio da cria��o de var�veis/strings
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o seu CPF para cadastro: ");
	  scanf("%s", cpf); //o scanf com "%s" � para armazenar os caracteres do cpf na String. String � uma sequ�ncia de caract(letra, s�mbolo) utilizada
	//p/ armazenar o texto
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings	
	
	FILE *file; //o fun��o FILE manda acessar o "file" e eu vou atribuir algum valor ao file na pr�xima linha, no caso o valor vai ser o do arquivo que � igual oa cpf
	file = fopen(arquivo, "w");
	fprintf (file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //esse "a" � pra atuolizar o arquivo, ja o "w" � pra escrever algo novo 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //esse "a" � pra atuolizar o arquivo, ja o "w" � pra escrever algo novo 
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
	file = fopen(cpf, "r"); //esse "r" � o comando de ordem para ler o arquivo e consultar
	
	if (file == NULL)
	{
		printf ("N�o foi poss�vel abrir o arquivo, sem registros! \n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL);
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system ("pause");
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF o qual voc� quer apagar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE* file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Esse arquivo n�o existe \n\n");
		system("pause");
	}
	
		
	
	}

int saida()
{
	exit(0);
}


int main()
{
	int opcao=0; //repare que s� tem um = nessa linha, isso quer dizer que eu estou atribuindo um valor a essa vari�vel que � diferente de == quando eu comparo
	int laco=1;
	
	for(laco=1;laco==1;)
	{
		system("cls");
		
		
	
    setlocale(LC_ALL, "Portuguese"); //Definindo linguageum
    
	printf("### Cart�rio do Raphael### \n\n"); //In�cio do menu
	printf( "Escolha a op��o que deseja no menu \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes \n");
	printf("\t4 - Encerrar o programa\n\n");
	printf("Op��o: "); //fim do menu
	
	
	//scanf tem como fun��o escanear o que o usu�rio coloca
	scanf("%d" , &opcao);//Armazenando a escolha do usu�rio
	
	system ("cls"); //tem como fun��o limpar a tela
	
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
	
	default: printf("Essa op��o n�o existe, tente novamente!\n");
	system("pause");
	break;
}
	
	
}
}
