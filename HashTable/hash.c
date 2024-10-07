#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct No{
    int item;
    struct No *next;
}No;

typedef struct elemento{
    No *lista;
}Lista;

typedef struct Hash{
    Lista *table[257];
}Hash;

No *Insert(int item, No *next){
    No *novo_no = malloc(sizeof(No));
    novo_no->item = item;
    novo_no->next = next;

    return novo_no;
}

Hash *HashTable(int size){
    Hash *new_table = malloc(sizeof(Hash));
    for(int i = 0; i < size; i++){
        new_table->table[i] = malloc(sizeof(Lista));
        new_table->table[i]->lista = NULL;
    }
    return new_table;
}

int hash(int id, int table_size){
    return id % table_size;
}

void put(Hash *hash_table, int key, int size){
    int h = hash(key, size);
    No *new_node = Insert(key, NULL);
    if(hash_table->table[h]->lista == NULL){
        hash_table->table[h]->lista = new_node;
    }
    else{
        No *aux = hash_table->table[h]->lista;
        if(aux != NULL){
            while(aux->next != NULL){
                aux = aux->next;
            }
            aux->next = new_node;
        }
    }
}

void print(Hash *ht, int size){
    for(int i = 0; i < size; i++){
        printf("%d -> ", i);
        No *aux = ht->table[i]->lista;
        while(aux != NULL){
            printf("%d -> ", aux->item);
            aux = aux->next;
        }
        printf("\\");
        printf("\n");
    }
}

void main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int size, lidos;
        scanf("%d %d", &size, &lidos);
        Hash *map;
        map = HashTable(size);
        for(int j = 0; j < lidos; j++){
            int lido;
            scanf("%d", &lido);
            put(map, lido, size);
        }
        print(map, size);
        for(int x = 0; x < size; x++){
            free(map->table[x]->lista);
            free(map->table[x]);
        }
        free(map);
        if(i < n - 1){
            printf("\n");
        }
    }
}