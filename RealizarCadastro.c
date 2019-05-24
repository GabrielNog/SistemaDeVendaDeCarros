#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
// DEFININDO ENTRADAS.
struct CadastroCliente{
    //ENTRADAS PARA O CLIENTE.
    char nome[30];
    int idade;
    char genero[10];
    // ENTRADAS PARA O VEICULO.
    char marca[30];
    int ano;
    float preco;


};
struct CadastroCliente c;


// FUNÇÃO PARA REALIZAR CADASTRO DO CLIENTE E DO VEICULO.
void RealizarCadatro(){

   FILE *database;

    database = fopen("Cadastro.txt","a");
    if(database == NULL){
            printf("Arquvio não encontrado\n");
            exit(1);
    }else{
        printf("Database conectada!!!\n");
    }
    int id = 1;
    int a;
    int num;
    do{
        printf("Digite (1) para realizar o cadastro pessoal ou (2) para cadastro do veiculo:\n")/
        scanf("%d",&num);
        switch(num){

            case 1:
                printf("Digite o seu nome completo:");
                fflush(stdin);
                gets(c.nome);

                printf("Digite a sua idade:");
                fflush(stdin);
                scanf("%d",&c.idade);

                printf("Digite o seu genero:");
                fflush(stdin);
                gets(c.genero);
                fprintf(database,"%d;%s;%d;%s\n",id,c.nome,c.idade,c.genero);
                break;

            case 2:
                printf("Digite a marca do veiculo:");
                fflush(stdin);
                gets(c.marca);

                printf("Digite o ano do veiculo:");
                fflush(stdin);
                scanf("%d",&c.ano);

                printf("Digite o preco de venda:");
                fflush(stdin);
                scanf("%f",&c.preco);
                fprintf(database,"%d;%s;%d;%.2f\n",id,c.marca,c.ano,c.preco);

                break;

            default:
                printf("Escolha o numero certo.\n");
        }

        printf("deseja continuar (1)-SIM E (0)-NAO: ");
        scanf("%d",&a);
        id ++;
    }while(a!=0);
    fclose(database);
}

int main(){

    RealizarCadatro();


return 0;
}
