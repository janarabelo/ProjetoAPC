#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

//Síntese
//Objetivo: Gerenciar associados de um clube esportivo
//Entrada: Cadastro de associados
//Saída: Gerenciar as informações dos associados inseridas pelo usuário


 typedef struct Dependente
 {
    char nome[20];
    int idade;
}Dependente;


typedef struct Associado
 {
    int id;
    char nome[20];
    int idade;
    int qtdDep;
    Dependente dep[3];
    bool natacao;
    bool futsal;
    bool tenis;
} Associado;


void imprime_menu ();
void cadastrar_associado (int *quantAss, Associado pessoa[200]); // case 1
void cadastrar_dependente (Associado pessoa[200], int quantAss); // case 2
void listar_associados (Associado pessoa[200], int quantAss); // case 3
void  listar_modalidade (Associado pessoa[200], int quantAss); // case 4
void pesquisar_associado (Associado pessoa[200], int quantAss); // case 5
void relatorio_associado (Associado pessoa[200], int quantAss); // case 6
int total_dependente (Associado pessoa[200], int quantAss);
double total_mensalidades (Associado pessoa[200], int quantAss);
double maior_mensalidade (Associado pessoa[200], int quantAss);


int main ()
{
    int menu, quantAss = 0;
    char voltaMenu;

    Dependente dep[3];
    Associado pessoa[200];


        // Laço para repetir o menu e para usuario escolher a opção desejada
        do
           {
                imprime_menu ();
               scanf ("%d", &menu);
               system("cls || clear ");
               getchar();

               switch (menu)
                {
                case 1:
                    cadastrar_associado (&quantAss, pessoa);
                    break;
                case 2:
                    cadastrar_dependente (pessoa, quantAss);
                    printf ("Digite uma tecla para volta ao menu.\n");
                    scanf ("%c", &voltaMenu);
                    getchar();
                    system("cls || clear ");
                    break;
                case 3:
              //      if (quantAss == 0)
                  ///      printf ("Nao ha ")
                    listar_associados (pessoa, quantAss);
                    printf ("Digite uma tecla para volta ao menu.\n");
                    scanf ("%c", &voltaMenu);
                    getchar();
                    system("cls || clear ");
                    break;
                case 4:
                    listar_modalidade (pessoa, quantAss);
                    printf ("Digite uma tecla para volta ao menu.\n");
                    scanf ("%c", &voltaMenu);
                    getchar();
                    system("cls || clear ");
                    break;
                case 5:
                    pesquisar_associado (pessoa, quantAss);
                    printf ("Digite uma tecla para volta ao menu.\n");
                    scanf ("%c", &voltaMenu);
                    getchar();
                    system("cls || clear ");
                    break;
                case 6:
                    relatorio_associado (pessoa, quantAss);
                    printf ("Digite uma tecla para volta ao menu.\n");
                    scanf ("%c", &voltaMenu);
                    getchar();
                    system("cls || clear ");
                    break;
                case 7:
                    printf ("tchau, usuario!\n");
                    break;
                default:
                    printf ("Numero incorreto!!\7\n");
                }
            }
        while (menu != 7);

}

// Imprimir o menu
void imprime_menu ()
{
        printf ("         Sistema de Gerencia de Clube Esportivo\n\n");
        printf("1. Cadastrar associado\n");
        printf ("2. Cadastrar dependente\n");
        printf ("3. Listar associados\n");
        printf("4. Listar associados por modalidade\n");
        printf ("5. Pesquisar associados\n");
        printf("6. Gerar relatorio de associados\n");
        printf ("7. Finalizar Programa\n");

}


// Função para o usuário cadastrar os associados
void cadastrar_associado (int *quantAss, Associado pessoa[*quantAss])
{
    int i, mesmoID, nat, fut, ten;


        printf ("Insira o identificador.\n");
        do
        {
            scanf ("%d", &pessoa[ *quantAss].id);
            for (i = 0 ; i < *quantAss ; i ++)
            {
                if (pessoa[i].id == pessoa[ *quantAss].id)
                {
                    printf ("Nao pode haver dois associados com o mesmo identificador!\n\7 ");
                    mesmoID = pessoa[ *quantAss].id;
                }
            }
        }
        while(mesmoID == pessoa[ *quantAss].id);
        getchar();
        printf ("Insira o nome.\n");
        scanf ("%[^\n]s", pessoa[ *quantAss].nome);
        // Laço para caso o usuário ultrapasse o limite de caracter
        while (strlen(pessoa[*quantAss].nome) > 20)
        {
            printf ("Voce escedeu o numero de caracteres permitidos!\n\7");
            scanf ("%[^\n]s", pessoa[ *quantAss].nome);
        }
        printf ("Insira a idade.\n");
        scanf("%d", &pessoa[ *quantAss].idade);
        // Laço para caso o usuário digite uma idade negativa
        while (pessoa[ *quantAss].idade < 0 )
        {
            printf ("Digite apenas idade positiva!!\n\7");
            scanf("%d", &pessoa[ *quantAss].idade);
        }
        system("cls || clear ");


        printf ("O associado faz aula de alguma dessas modalidades?\n");
        printf ("\"Sim = 1\"\n\"Nao = 0\"\n\n");
        printf ("Faz natacao?\n");
        scanf ("%d", &nat);
        // Laço para permitir que o usuário digite apenas os numeros "0" ou "1"
        while (nat != 0 && nat != 1 )
        {
            printf ("Digite apenas \"1\" ou \"0\"!!\n\7");
            scanf ("%d", &nat);
        }
        if (nat == 1 )
            pessoa[ *quantAss].natacao = true;
        else
            pessoa[ *quantAss].natacao = false;
        printf ("Faz futsal?\n");
        scanf ("%d", &fut);
        while (fut != 0 && fut != 1 )
        {
           printf ("Digite apenas \"1\" ou \"0\"!!\n\7");
            scanf ("%d", &fut);
        }
        if (fut == 1)
            pessoa[ *quantAss].futsal = true;
        else
            pessoa[ *quantAss].futsal = false;
        printf ("Faz tenis?\n");
        scanf ("%d", &ten);
        while (ten != 0 && ten != 1)
        {
            printf ("Digite apenas \"1\" ou \"0\"!!\n\7");
            scanf ("%d", &ten);
        }
        if (ten == 1)
            pessoa[ *quantAss].tenis = true;
        else
            pessoa[ *quantAss].tenis = false;

        ( *quantAss)++;
        system("cls || clear ");


}


void cadastrar_dependente (Associado pessoa[200], int quantAss)
{
    int i, continua, procuraID, erro = 0;


        printf ("Infome o identificador do associado.\n");
        scanf ("%d", &procuraID);
        system("cls || clear ");

        // Laço para procurar o identificdor
        for (i = 0; i < quantAss ; i++)
        {
            if (procuraID == pessoa[i].id)
            {
                procuraID = i;
                erro = 1;
            }

        }

        // Laço para cadastrar os dependentes
        do
        {
            // Caso o identificador nao seja encontrado
            if (erro == 0)
            {
                printf ("Identificador nao encontrado!\n\7");
                break;
            }


            //  Caso o usuário tente cadastra mais de três dependestes
             if(pessoa[procuraID].qtdDep == 3)
            {
                printf ("O numero maximo de dependentes foi alcancado.\n\n\7");
                break;
            }

            getchar();
            printf ("Insira o nome.\n");
            scanf ("%[^\n]s", pessoa[procuraID].dep[pessoa[procuraID].qtdDep].nome);
            getchar();

            while (strlen(pessoa[procuraID].dep[pessoa[procuraID].qtdDep].nome) > 20)
            {
                printf ("Voce escedeu o numero de caracteres permitidos!\n\7");
                scanf ("%[^\n]s", pessoa[procuraID].dep[pessoa[procuraID].qtdDep].nome);
            }
            printf ("Insira a idade.\n");
            scanf("%d", &pessoa[procuraID].dep[pessoa[procuraID].qtdDep].idade);
            while (pessoa[procuraID].dep[pessoa[procuraID].qtdDep].idade < 0 )
            {
                printf ("Digite apenas idade positiva!!\n\7");
                scanf("%d", &pessoa[procuraID].dep[pessoa[procuraID].qtdDep].idade);
            }
            system("cls || clear ");

            printf ("Deseja continuar cadastrando dependente para esse associado?\n\"Sim = 1\"\n\"nao = 0\".\n");
            scanf ("%d", &continua);
            // Laço para permitir que o usuário digite apenas os numeros "0" ou "1"
            while (continua != 0 && continua != 1 )
            {
                printf ("Digite apenas \"1\" ou \"0\"!!\n\7");
                scanf ("%d", &continua);
            }
            pessoa[procuraID].qtdDep ++;
            system("cls || clear ");

        }
        while (continua == 1);

        for (i = 0 ; i < pessoa[procuraID].qtdDep ; i ++)
        {
            printf ("%s - %d\n\n", pessoa[procuraID].dep[i].nome, pessoa[procuraID].dep[i].idade);
        }



}


// Funçao para listar todos os associados e suas informações
void listar_associados (Associado pessoa[200], int quantAss)
{
    int i;

        for (i = 0 ; i < quantAss ; i ++)
        {
            printf ("%d - %s - %d - %d - ", pessoa[i].id, pessoa[i].nome, pessoa[i].idade, pessoa[i].qtdDep);
            if (pessoa[i].natacao)
            {
                printf ("Faz natacao - ");
            }
            else
                printf ("Nao faz natacao - ");

             if (pessoa[i].futsal)
              {
                    printf ("Faz futsal - ");
              }
            else
                printf ("Nao faz futsal - ");

             if (pessoa[i].tenis)
              {
                    printf ("Faz tenis\n");
              }
            else
                printf ("Nao faz tenis\n\n");
       }

}


// Função para listar os associados divididos por modaidade
void  listar_modalidade (Associado pessoa[200], int quantAss)
{
    int menu, i;
    char voltaMenu;

        // Laço para repetir o menu e para usuario escolher a modalidade desejada
        do
        {
            printf ("           Selecione a modalidade desejada.\n");
            printf ("1 - Natacao\n");
            printf ("2 - Futsal\n");
            printf ("3 - Tenis\n");
            printf ("4 - Sair\n");
            scanf ("%d", &menu);
            system("cls || clear ");

            switch (menu)
            {
            case 1:
                printf ("\n");
                 for (i = 0 ; i < quantAss ; i++)
                {
                    if (pessoa[i].natacao == true)
                        printf ("%d - %s\n", pessoa[i].id, pessoa[i].nome);
                }
                printf ("Digite uma tecla para volta ao menu de modalidade.\n");
                scanf ("%c", &voltaMenu);
                getchar();
                system("cls || clear ");
              break;
            case 2:
                printf ("\n");
                  for (i = 0 ; i < quantAss ; i++)
                  {
                        if (pessoa[i].futsal == true)
                            printf ("%d - %s\n", pessoa[i].id, pessoa[i].nome);
                  }
                printf ("Digite uma tecla para volta ao menu de modalidade.\n");
                scanf ("%c", &voltaMenu);
                getchar();
                system("cls || clear ");
                break;
            case 3:
                printf ("\n");
                 for (i = 0 ; i < quantAss ; i++)
                 {
                     if (pessoa[i].tenis == true)
                        printf ("%d - %s\n", pessoa[i].id, pessoa[i].nome);
                 }
                printf ("Digite uma tecla para volta ao menu de modalidade.\n");
                scanf ("%c", &voltaMenu);
                getchar();
                system("cls || clear ");
                break;
            case 4:
                break;
            default:
                printf ("Numero incorreto!!\7\n");
                break;
            }
        }
        while (menu != 4);

}





// Função para o usuário buscar por um associado especifico
void pesquisar_associado (Associado pessoa[200], int quantAss)
{
    char pesquisa[20];
    int i, erro = 0, aulas;
    double mensal;


        printf ("Insira o nome do associado que deseja pesquisar.\n");
        scanf ("%[^\n]s", pesquisa);


        // Laço para caso o usuário procure um associado não cadastrado
        for (i = 0 ; i < quantAss ; i ++)
        {
            if (strcmp(pesquisa, pessoa[i].nome) == 0)
                erro = 1;
        }

        if (erro == 0)
            printf ("Associado nao encontrado!\n\7");


        // Laço para mostrar informações do associado procurado
        for (i = 0 ; i < quantAss ; i ++)
        {

            if (strcmp(pesquisa, pessoa[i].nome) == 0)
            {
                 aulas = 0;

                if (pessoa[i].natacao)
                    aulas = aulas + 1;

                if (pessoa[i].futsal)
                    aulas = aulas + 1;

                if (pessoa[i].tenis)
                    aulas = aulas + 1;


                 mensal = 0;

                mensal = mensal + 100;

                mensal = mensal + (pessoa[i].qtdDep * 50);

                if (pessoa[i].natacao)
                    mensal = mensal + 30;

                if (pessoa[i].futsal)
                    mensal = mensal + 30;

                if (pessoa[i].tenis)
                    mensal = mensal + 30;





                printf ("%d - %s - %d - %d - ", pessoa[i].id, pessoa[i].nome, pessoa[i].idade, pessoa[i].qtdDep);
                printf ("%d - ",  aulas);
                printf ("R$%.2lf\n", mensal);
            }

        }


}



// Função para gerar relatorio dos associados
void relatorio_associado (Associado pessoa[200], int quantAss)
{
    int i, aulas, aulas2, maisAulas = 0, quantNat = 0, quantFut = 0, quantTen = 0, totalDep = 0;
    double valorMedio = 0;

        printf ("Numero total de associados cadastrados: %d\n", quantAss);


        printf ("Numero total de dependentes cadastrados: %d\n", total_dependente (pessoa, quantAss));

        // lLaço para mostrar o numero de associados que faz aula de cada modalidade
        for (i = 0 ; i < quantAss ; i ++)
        {
            if (pessoa[i].natacao)
                quantNat = quantNat + 1;

            if (pessoa[i].futsal)
                quantFut = quantFut + 1;

              if (pessoa[i].tenis)
                quantTen = quantTen + 1;

        }
        printf ("Numero de associados que fazem aula de Natacaoo: %d\n", quantNat);
        printf ("Numero de associados que fazem aula de Futsal: %d\n", quantFut);
        printf ("Numero de associados que fazem aula de Tenis: %d \n", quantTen);


        printf ("Valor total de todas as mensalidades dos associados: R$%.2lf\n", total_mensalidades (pessoa, quantAss));


        // Media das mensalidades
        valorMedio = total_mensalidades (pessoa, quantAss) / quantAss;
        printf ("Valor medio das mensalidades dos associados: %.2lf\n", valorMedio);


        printf ("Valor de mensalidade mais alto pago por um associado: R$%.2lf\n", maior_mensalidade (pessoa, quantAss));










        // Laço para a maior quantidade de aulas feitas
        for (i = 0 ; i < quantAss ; i ++)
        {
            aulas = 0;
            if (pessoa[i].natacao)
                aulas = aulas + 1;

            if (pessoa[i].futsal)
                aulas = aulas + 1;

            if (pessoa[i].tenis)
                aulas = aulas + 1;

            if (aulas > maisAulas)
                maisAulas = aulas;
        }
        // Laço para mostrar os associados que fazem mais aulas
        for (i = 0 ; i < quantAss ; i ++)
        {
            aulas = 0;
            if (pessoa[i].natacao)
                aulas = aulas + 1;

            if (pessoa[i].futsal)
                aulas = aulas + 1;

            if (pessoa[i].tenis)
                aulas = aulas + 1;


            if (aulas == maisAulas)
            {
                printf ("Nome do(s) associado(s) que fazem mais aulas:\n");
                printf ("%s\n", pessoa[i].nome);
            }

        }


}


// Função para o total de dependentes
int total_dependente (Associado pessoa[200], int quantAss)
{
    int i, totalDep = 0;

        for (i = 0 ; i < quantAss ; i ++)
        {
            totalDep = totalDep + pessoa[i].qtdDep;
        }

        return totalDep;
}

// Função para o total de todas as mensalidades pagas pelos associados
double total_mensalidades (Associado pessoa[200], int quantAss)
{
    int i;
    double totalMensal = 0;

        for (i = 0 ; i < quantAss ; i ++)
        {
            totalMensal = totalMensal + 100;

            totalMensal = totalMensal + (pessoa[i].qtdDep * 50);

            if (pessoa[i].natacao)
                totalMensal = totalMensal + 30;

            if (pessoa[i].futsal)
                totalMensal = totalMensal + 30;

            if (pessoa[i].tenis)
                totalMensal = totalMensal + 30;

    }

    return totalMensal;

}


// Função para o associado que paga a maior mensalidade
double maior_mensalidade (Associado pessoa[200], int quantAss)
{
    int i, mensal, maiorMensal = 0;

        for (i = 0 ; i < quantAss ; i ++)
        {
            mensal = 0;
            mensal = mensal + 100;
            mensal = mensal + (pessoa[i].qtdDep * 50);
            if (pessoa[i].natacao)
                mensal = mensal + 30;
            if (pessoa[i].futsal)
                mensal = mensal + 30;
            if (pessoa[i].tenis)
                mensal = mensal + 30;

            if (mensal > maiorMensal)
                maiorMensal = mensal;
        }

       return maiorMensal;
}











