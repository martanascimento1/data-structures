#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 256


typedef struct no {
    unsigned char c;
    int frequencia;
    struct no *esq, *dir, *prox;
} No;


typedef struct lista {
    No *inicio;
    No *fim;
    int tam;
} Lista;

//PARTE 1 - Inicialização da tabela de frequência
void inicializa_tabela_com_zero (unsigned int tab[]) {
    for (int i = 0; i < MAX; i++) {
        tab[i] = 0;
    }
}

void preenche_tab_freq (unsigned char texto[], unsigned int tab[]) {
    int i = 0;
    while (texto[i] != '\0') {
        tab[texto[i]]++;
        i++;
    }
}

void imprime_tab_freq (unsigned int tab[]) {
    for (int i = 0; i < MAX; i++) {
        if (tab[i] != 0) {
            printf("%d = %u = %c\n", i, tab [i], i);
    } }
}

//PARTE 2 - Criação da lista encadeada ordenada
void criar_lista (Lista *lista) {
    lista->inicio = NULL;
    lista->tam = 0;
}
void inserir(Lista *lista, No *novo) {
    No *aux;
    if (lista->inicio == NULL) {
        lista->inicio = novo;
    }
     else if (novo->frequencia < lista->inicio->frequencia) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
    }
    else {
        aux = lista->inicio;
        while (aux->prox != NULL && aux->prox->frequencia <= novo->frequencia) {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }

    lista->tam++;
}

void preencher_lista (unsigned int tab[], Lista *lista) {
    No *novo;
    for (int i = 0; i < MAX; i++) {
        if (tab[i] > 0) {
            novo = (No *) malloc(sizeof(No));
            if (novo) {
            novo->c = i;
            novo->frequencia = tab[i];
            novo->esq = NULL;
            novo->dir = NULL;
            novo->prox = NULL;
            inserir(lista, novo);
            }
            else {
                printf("Erro de alocação\n");
                break;
            }
        }
    }
}

void imprimir_lista (Lista *lista) {
    No *aux;
    aux = lista->inicio;
    while (aux != NULL) {
        printf("\tCaracter: %c  \tFrequência = %d\n", aux->c, aux->frequencia);
        aux = aux->prox;
    }
}

//PARTE 3 - Criação da árvore de Huffman

No* remover_inicio(Lista *lista) {
    No *aux = NULL;
    if (lista->inicio) {
        aux = lista->inicio;
        lista->inicio = aux->prox;
        aux->prox = NULL;
        lista->tam--;
    }
    
    return aux;
}

No* criar_arvore(Lista *lista) {
    No *novo, *p, *seg;
    while (lista->tam > 1) {
        p = remover_inicio(lista);
        seg = remover_inicio(lista);
        novo = malloc(sizeof(No));
        if (novo) {
            novo->c = '*';
            novo->frequencia = p->frequencia + seg->frequencia;
            novo->esq = p;
            novo->dir = seg;
            novo->prox = NULL;
            inserir(lista, novo);
        }
        else {
            printf("Erro de alocação\n");
            break;
        }
    }
    return lista->inicio;
}

void imprimir_arvore(No *raiz, int tam) {
    if (raiz->esq == NULL && raiz->dir == NULL) {
        printf("\tFolha: %c\t Altura = %d\n", raiz->c);
    }
    else {
        imprimir_arvore(raiz->esq, tam+1);
        imprimir_arvore(raiz->dir, tam+1);
    }
}

//Montar o dicinário de Huffman

int altura_arvore(No *raiz) {
    int alt_esq, alt_dir;
    if (raiz == NULL) {
        return -1;
    }
    else {
         alt_esq = altura_arvore(raiz->esq) +1;
         alt_dir = altura_arvore(raiz->dir) +1;
        if (alt_esq > alt_dir) {
            return alt_esq;
        }
        else {
            return alt_dir;
        }
    }
}

char** aloca_dicionario(int altura) {
    char **dicionario;
    dicionario = (char**)malloc(sizeof(char *) * MAX);
    for (int i = 0; i < MAX; i++) {
        dicionario[i] =(char*)calloc(altura, sizeof(char));
        
    } return dicionario;
}

void gerar_dicionario(char **dicionario, No *raiz, char *codigo, int tam) {
    char esquerda[tam], direita[tam];
    if (raiz->esq == NULL && raiz->dir == NULL) {
        strcpy(dicionario[raiz->c],codigo);
    }
    else {
       strcpy(esquerda, codigo);
       strcpy(direita, codigo);
       strcat(esquerda, "0");
       strcat(direita, "1");
        gerar_dicionario(dicionario,raiz->esq, esquerda, tam);
        gerar_dicionario(dicionario, raiz->dir, direita, tam);

} }

void imprimir_dicionario(char **dicionario) {
    for (int i = 0; i < MAX; i++) {
        if(strlen(dicionario[i]) > 0) {
            printf("\tdicionario\n");
            printf("\t 3%d = %s\n", i, dicionario[i]); }
    }
}

//PARTE 5 - Codificação do texto
int calcula_tamanho_string(char **dicionario,unsigned char *texto) {
    int i=0, tam =0;
    while (texto[i] != '\0') {
        tam = tam + strlen(dicionario[texto[i]]);
        i++;
    }
    return tam+1;
}
char* codificar( char **dicionario, unsigned char *texto) {
    int i=0 ;
    char *codigo;
    int tam = calcula_tamanho_string(dicionario, texto);
    codigo = (char*)calloc(tam, sizeof(char));
    while (texto[i] != '\0')
    {
        dicionario[texto[i]];
        strcat(codigo, dicionario[texto[i]]);
            i++;
    }

    return codigo;
}

//PARTE 6 - Decodificação do texto
char* decodificar( unsigned char texto[] , No*raiz) {
    int i = 0;
    No *aux = raiz;
    char *decodificado;
    char temp [2];
    decodificado = (char*)calloc(strlen(texto), sizeof(char));
    while (texto[i] != '\0') {
        if (texto[i] == '0') {
            aux = aux->esq;
        }
        else {
            aux = aux->dir;
        }
        if (aux->esq == NULL && aux->dir == NULL) {
            temp[0] = aux->c;
            temp[1] = '\0';
            strcat(decodificado, temp);
            aux = raiz;
        }
        i++;
    }
    return decodificado;
}

// Parte 7: Compactação e descompactação de arquivos
void compactar (unsigned char str[]) {
    FILE *arq;
    arq = fopen("compactado.wg", "wb");
    int i = 0, j=7;
    unsigned char mascara, byte = 0; //00000000
    if (arq) {
        while (str[i] != '\0')

        {
        mascara = 1;
        if (str[i] == '1') {
            mascara = mascara << j;
            byte = byte | mascara;
        }
        j--;
        if (j < 0) { //tem um byte formado
            fwrite(&byte, sizeof(unsigned char), 1, arq);
            j = 7;
            byte = 0;
        }
        i++;
    }
    if (j != 7) {
        fwrite(&byte, sizeof(unsigned char), 1, arq);
    }
    fclose(arq);
    }
    
    else {
        printf("\nErro ao abrir/criar o arquivo \n");
    }
} 

//Descompactar
unsigned int eh_bit_um (unsigned char byte, int posicao) {
    unsigned char mascara = (1 << posicao);
    return byte & mascara;
}
void descompactar(No *raiz) {
    FILE *arq;
    arq = fopen("compactado.wg", "rb");
    No *aux = raiz;
    unsigned char byte, mascara;
    int i ;
    if (arq) {
        while (fread(&byte, sizeof(unsigned char), 1, arq) > 0) {
            for (i = 7; i>= 0; i--) {
                if (eh_bit_um(byte, i)) {
                    aux = aux->dir;
                }
                else {
                   aux = aux->esq;
                }
                if (aux->esq == NULL && aux->dir == NULL) {
                    printf("%c", aux->c);
                    aux = raiz;
                }
            }
            
        }
        fclose(arq);
    }
    else {
        printf("\nErro ao abrir o arquivo\n");
    }
}

int descobrir_tamanho (char *nome_arquivo) {
    FILE *arq;
    int tam =0;
    arq = fopen("teste.txt", "r");
    if (arq) {
        while (fgetc(arq) != -1) {
            tam++;
            fclose(arq);
        }
    }
    else {
        printf("\nErro ao abrir o arquivo em descobrir_tamanho\n");
        
    }
    return tam;

}

void ler_texto (unsigned char *texto) {
    FILE *arq;
    arq = fopen("teste.txt", "r");
    char letra;
    int i = 0;
    if (arq) {
        
           while (!feof (arq))
           {
           letra = fgetc(arq);
           if (letra != -1) {
               texto[i] = letra;
               i++;
           }
           else {
               texto[i] = '\0';
           }
           
            fclose(arq);
        } }
    else {
        printf("\nErro ao abrir o arquivo em ler_texto\n");
        
    }
   
}
int main () {
    //unsigned char texto[] ="Vamos aprender a programação"
    unsigned char *texto;
    unsigned int tab_freq[MAX];
    Lista lista;
    No *arvore;
    int altura;
    int tam;
    char **dicionario;
    char *codificado, *decodificado;
    setlocale(LC_ALL, "Portuguese");

    tam = descobrir_tamanho(texto);
    printf("Tamanho do arquivo: %d\n", tam);
    texto = calloc(tam+2, sizeof(unsigned char));
    ler_texto(texto);
    printf("\n\tTexto: %s\n", texto);
    
    //PARTE 1 - Inicialização da tabela de frequência
    inicializa_tabela_com_zero(tab_freq);
    preenche_tab_freq(texto, tab_freq);
    imprime_tab_freq(tab_freq);

    //PARTE 2 - Criação da lista encadeada ordenada
    criar_lista(&lista);
    preencher_lista(tab_freq, &lista);
    imprimir_lista(&lista);

    //PARTE 3 - Criação da árvore de Huffman
    arvore = criar_arvore(&lista);
    imprimir_arvore(arvore, 0);

    //PARTE 4 - Montar o dicionário de Huffman
    altura = altura_arvore(arvore)+1;
    dicionario = aloca_dicionario(altura);
    gerar_dicionario(dicionario, arvore, "", altura);
    imprimir_dicionario(dicionario);

    //PARTE 5 - Codificação do texto
    codificado = codificar(dicionario, texto);
    printf("\n\tTexto codificado: %s\n ", codificado);

    //PARTE 6 - Decodificação do texto
    decodificado = decodificar(codificado, arvore);
    printf("\n\tTexto decodificado: %s\n", decodificado);

    //PARTE 7 - Compactação e descompactação de arquivos
    compactar(codificado);
    // PARTE 8 - descompactar
    printf("\n\tTexto descompactado: ");
    descompactar(arvore);
    printf("\n\n");

    free(texto);
    free(codificado);
    free(decodificado);

  return 0;
}