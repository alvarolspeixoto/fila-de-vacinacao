#include <stdio.h>
#include <stdlib.h>  //usado system
#include <ctype.h>   //usado toupper
#include <string.h>  //usado strcmp e strlen

typedef struct Paciente{
    char Nome[20];
    char CPF[11];
    int Prioridade;
} TpPaciente;

char Nome[20];
char CPF[11];
int Prioridade;

TpPaciente PacienteAtual;

 // Controle dos n�veis de prioridade;
int p1 = 101;
int p2 = 201;
int p3 = 301;
int p4 = 401;
int p5 = 501;

TpPaciente Pacientes[50];
int TamanhoHeap = 0;

int pegarIndexPai(int index){
    return index/2;
}

int pegarIndexFilhoEsquerdo(int index){
    return index*2;
}

int pegarIndexFilhoDireito(int index){
    return index*2+1;
}

void subirHeap(int index){
    if(index <= 1) return;
    int parentIndex = pegarIndexPai(index);
    if(Pacientes[index].Prioridade < Pacientes[parentIndex].Prioridade){
        TpPaciente temp = Pacientes[index];
        Pacientes[index] = Pacientes[parentIndex];
        Pacientes[parentIndex] = temp;

        subirHeap(parentIndex);
    }
}

void descerHeap(int index){
    if(index*2 > TamanhoHeap) return;
    int esquerda = pegarIndexFilhoEsquerdo(index);
    int direita = pegarIndexFilhoDireito(index);

    int menor = index;
    if(esquerda <= TamanhoHeap && Pacientes[esquerda].Prioridade < Pacientes[menor].Prioridade){
        menor = esquerda;
    }
    if(direita <= TamanhoHeap && Pacientes[direita].Prioridade < Pacientes[menor].Prioridade){
        menor = direita;
    }
    if(menor == index) return;

    TpPaciente temp = Pacientes[index];
    Pacientes[index] = Pacientes[menor];
    Pacientes[menor] = temp;

    descerHeap(menor);
    
}

void push(TpPaciente Paciente){
    TamanhoHeap++;
    Pacientes[TamanhoHeap] = Paciente;
    subirHeap(TamanhoHeap);
}

void pop(){
    if(TamanhoHeap == 0) return;
    Pacientes[1] = Pacientes[TamanhoHeap];
    TamanhoHeap--;
    descerHeap(1);
}

int ChecaCPF(char CPF[]){ // Verifica se um dado CPF já se encontra na fila
    int Achou = 0;
    int i = 1;
    do{
        if(strcmp(Pacientes[i].CPF, CPF) == 0){
            Achou = 1;
            
        }
        i++;
    } while(i <= TamanhoHeap && Achou == 0);
    return Achou;
}

void Inserir(){ // Inserção
    char R = 'S';
    char R2 = 'S';
    int Repetido = 0;
    int Opcao, i;
    
    system("cls");
    printf("\n=============== Fila de espera ==============\n\n");
    while(R != 'N'){
        i = 0;
        printf("Digite o nome: ");
        scanf("%s", &Nome);
        printf("\nDigite o CPF: ");
        scanf("%s", &CPF);
        if(TamanhoHeap > 0){
            do{   
                i++;
                if(strcmp(CPF, Pacientes[i].CPF) == 0){
                    Repetido = 1;
                    system("cls");
                    printf("\nCPF ja cadastrado no sistema!\n");
                    printf("%i\n", TamanhoHeap);
                    printf("%i", i);
                    printf("\nDeseja escolher outro CPF? S/N: ");
                    scanf(" %c", &R2);
                    R2 = toupper(R2);
                    if(R2 == 'N'){
                        Repetido = 0;
                        break;
                    }
                    printf("\nDigite o CPF: ");
                    scanf("%s", &CPF);
                    i = 0;
                }
            } while (i <= TamanhoHeap);
            if(R2 == 'N'){
                break;
            }
        }
        printf("\nEscolha o primeiro grupo abaixo do qual o paciente faz parte:\n");
        printf("1 - Profissionais da saude e portadores de deficiencias mentais\n");
        printf("2 - Pessoas com comorbidades, gravidas e puerperas\n");
        printf("3 - Pessoas como idade acima de 60 anos, professores e motoristas\n");
        printf("4 - Criancas de 0 a 5 anos\n");
        printf("5 - Pessoas com idade entre 6 e 60 anos\n\n");
        printf("Opcao escolhida: ");
        scanf("%i", &Opcao);
        switch (Opcao){
    case 1:
            Prioridade = p1;
            p1++;
            break;
        case 2:
            Prioridade = p2;
            p2++;
            break;
        case 3:
            Prioridade = p3;
            p3++;
            break;
        case 4:
            Prioridade = p4;
            p4++;
            break;
        case 5:
            Prioridade = p5;
            p5++;
            break;
        }
    strcpy(PacienteAtual.Nome, Nome);
    strcpy(PacienteAtual.CPF, CPF);
    PacienteAtual.Prioridade = Prioridade;
    push(PacienteAtual);
    system("cls");
    printf("Paciente inserido na fila com sucesso!\n");
    printf("Deseja inserir um novo paciente? S/N: ");
    scanf(" %c", &R);
    R = toupper(R);
    system("cls");
    }
}

void AplicarVacina(){ // Representa a exclusão no heap (remoção do primeiro item da fila)
    system("cls");
    printf("\n============== Aplicacao de vacina ===============\n\n");
    if(TamanhoHeap == 0){
        printf("Nao ha pacientes na fila.\n");
    } else {
        printf("Vacina aplicada com sucesso!\n");
        printf("===== Paciente vacinado =====\n");
        printf("Nome: %s\n", Pacientes[1].Nome);
        printf("CPF: %s\n", Pacientes[1].CPF);
        printf("Prioridade: %i\n", Pacientes[1].Prioridade);
        pop();
    }
    system("pause");
}

int Consultar(){  // Consulta individual por CPF
    int Achou = 0;
    int i = 1;
    char CPF[11];
    system("cls");
    printf("\n============= Pesquisa de pacientes ===============\n\n");
    if(TamanhoHeap == 0){
        printf("Nao ha pacientes na fila.\n");
    } else{
        printf("Digite o CPF do paciente desejado: ");
        scanf("%s", &CPF);
        do{
            if(strcmp(Pacientes[i].CPF, CPF) == 0){
                Achou = 1;
                printf("Nome: %s |", Pacientes[i].Nome);
                printf(" Prioridade: %i |", Pacientes[i].Prioridade);
                printf(" CPF: %s \n", Pacientes[i].CPF);
            }
            i++;
        } while(i <= TamanhoHeap && Achou == 0);
        if(Achou == 0){
            printf("Paciente nao encontrado!\n");
        }
    }
    system("pause");
    return i;    
}

void ConsultarTodos(){ // Consulta total
    system("cls");
    printf("============== Pacientes na fila ===============\n\n");
    if(TamanhoHeap == 0){
        printf("Nao ha pacientes na fila.");
    } else{
        int i;
        for (i = 1; i <= TamanhoHeap; i++){
            printf("Nome: %s |", Pacientes[i].Nome);
            printf(" Prioridade: %i |", Pacientes[i].Prioridade);
            printf(" CPF: %s \n", Pacientes[i].CPF);
        }
    }
    printf("\n");
    system("pause");
}

void AlterarDados(){ // Alteração
    system("cls");
    int Controle;
    int Opcao, i;
    char NovoCPF[11];
    char NovoNome[20];
    printf("\n============== Alteracao dos dados ================\n\n");
    if(TamanhoHeap == 0) {
        printf("Nao ha pacientes para alterar dados.\n");
    } else {
        i = Consultar() - 1;
        system("cls");
        printf("Qual dado deseja alterar? \n");
        printf("1 - Nome\n");
        printf("2 - CPF\n");
        printf("Opcao escolhida: ");
        scanf("%i", &Opcao);
        switch (Opcao){
            case 1:
                printf("\nDigite o novo nome: ");
                scanf("%s", &NovoNome);
                break;
            case 2:
                printf("\nDigite o novo CPF: ");
                scanf("%s", &NovoCPF);
                Controle = ChecaCPF(NovoCPF);
                break;
            default:
                break;
        }
        if(Controle == 1){
            system("cls");
            printf("\nAlteracao cancelada.\n");
            printf("O CPF escolhido ja se encontra cadastrado.\n");
            printf("Volte ao menu e verifique a lista de espera.\n");
        } else if(Opcao == 1){
            system("cls");
            strcpy(Pacientes[i].Nome, NovoNome);
            printf("\nAlteracao realizada com sucesso!\n");
        } else if(Opcao == 2){
            system("cls");
            strcpy(Pacientes[i].CPF, NovoCPF);
            printf("\nAlteracao realizada com sucesso!\n");
        }
    }
    system("pause");
}

int main(){

    int Opcao;

    do{
        system("cls");
        printf("\n========== Posto de Vacinacao ==========\n");
        printf("Seja bem-vindo ao sistema de vacinacao!\n");
        printf("Os pacientes serao vacinados de acordo com a fila de prioridade!\n\n");
        printf("\nDigite o numero da acao que deseja realizar:\n\n");
        printf("1 - Inserir paciente na fila de espera pela vacina \n");
        printf("2 - Aplicar vacina \n");
        printf("3 - Consultar paciente da fila \n");
        printf("4 - Realizar consulta total dos pacientes na fila \n");
        printf("5 - Alterar dados de algum paciente \n");
        printf("6 - Sair \n\n");
        printf("Opcao escolhida: ");
        scanf("%i", &Opcao);
        switch (Opcao){
        case 1: 
            Inserir(); 
            break;
        case 2: 
            AplicarVacina();
            break;
        case 3:
            Consultar(); 
            break;
        case 4:
            ConsultarTodos();
            break;
        case 5:
            AlterarDados(); 
            break;
        }
        
    } while(Opcao != 6);
    return 0;
}
