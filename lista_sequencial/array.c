#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int empty(int current); // Verificar se a lista está vazia
int full(int current,int max); // Verificar se a lista está cheia
void list_size(int current);
int get_pos(int pos, int* lista, int current);
int change(int pos, int* lista, int current);
int insert(int pos, int* lista, int current, int max);
int remove_num(int pos, int* lista, int current, int max);

int main(){
    int lista[10] = {1,3,5,7,10};
    int max = 10;
    int current = 5;
    int user_input, is_full, is_empty, opc, pos, pass;

    do{
        is_empty = empty(current);
        is_full = full(current, max);

        printf("\n O que você deseja fazer na lista?\n");
        printf("(1) Obter tamanho da lista\n");
        printf("(2) Obter elemento de uma determinada posição\n");
        printf("(3) Modificar elemento de determinada posição\n");
        printf("(4) Inserir elemento em determinada posição\n");
        printf("(5) Retirar elemento de determinada posição\n");
        scanf("%d", &opc);

        if(is_full == 1 && opc == 4){
            printf("\n\nLISTA CHEIA, VOCÊ NÃO PODE ADICIONAR!!!!\n");
        }

        else if(is_empty == 1 && opc != 1){
            printf("\n\nLISTA VAZIA!!!\n");
        }

        else if(opc == 1){
            list_size(current);
        }
        else if(opc == 2){
            printf("Digite a posição: ");
            scanf("%d", &pos);
            pass = get_pos(pos, lista, current);
            if(pass == -1)
                printf("Posição inválida!\n");
        }
        else if(opc == 3){
            printf("Digite a posição: ");
            scanf("%d", &pos);
            pass = change(pos, lista, current);
            if(pass == -1)
                printf("Posição inválida!\n");
        }
        else if(opc == 4){
            printf("Digite a posição: ");
            scanf("%d", &pos);
            pass = insert(pos, lista, current, max);
            if(pass == -1)
                printf("Posição inválida!\n");
            else
                current++;
        }
        else if(opc == 5){
            printf("Digite a posição: ");
            scanf("%d", &pos);
            pass = remove_num(pos, lista, current, max);
            if(pass == -1)
                printf("Posição inválida!\n");
            else
                current--;
        }
        else
            printf("OPÇÃO INVÁLIDA\n");
        printf("\nSe deseja continuar digite um número diferente de -1: ");
        scanf("%d", &user_input);
    }while(user_input != -1);

    printf("Lista Final: \n");
    for(int i = 0; i <= current-1; i++){
        printf("%d, ", lista[i]);
    }

    return 0;
}

int empty(int current){
    if(current == 0)
        return 1;
    else return 0;
}

int full(int current,int max){
    if(current == max)
        return 1;
    else return 0;
}

void list_size(int current){
    printf("O tamanho current da lista é: %d\n", current);
}

int get_pos(int pos, int* lista, int current){
    if(pos > current || pos <= 0)
        return -1;
    
    printf("\nO número nessa posição é: %d\n", lista[pos-1]);
    return 0;
}

int change(int pos, int* lista, int current)
{
    if(pos > current || pos <= 0)
        return -1;
    
    int num;
    printf("Digite qual número você quer colocar: ");
    scanf("%d", &num);
    printf("\n");

    lista[pos-1] = num;
    return 0;
}

int insert(int pos, int* lista, int current, int max)
{
    if(full(current, max) == 1||pos > (current + 1) || pos <= 0)
        return -1;
    
    int num;
    printf("Digite qual número você quer colocar: ");
    scanf("%d", &num);

    for(int i = current; i >= pos; i--){
        lista[i] = lista[i-1];
    }

    lista[pos-1] = num;

    return 0;
}

int remove_num(int pos, int* lista, int current, int max)
{
    if(full(current, max) == 1||pos > (current + 1) || pos <= 0)
        return -1;
    
    for(int i = pos - 1; i <= current - 1; i++){
        lista[i] = lista[i+1];
    }

    return 0;
}