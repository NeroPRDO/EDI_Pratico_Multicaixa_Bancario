#ifndef FILA_H
#define FILA_H

#include "clientes.h"

#define TAM_MAX_FILA 100  // Tamanho máximo da fila circular

typedef struct {
    Cliente clientes[TAM_MAX_FILA];
    int inicio;
    int fim;
    int quantidade;
} Fila;

// Inicializa uma fila vazia
void inicializar_fila(Fila *fila);

// Verifica se a fila está cheia
int fila_cheia(Fila *fila);

// Verifica se a fila está vazia
int fila_vazia(Fila *fila);

// Insere um cliente na fila
int enfileirar(Fila *fila, Cliente cliente);

// Remove um cliente da fila
int desenfileirar(Fila *fila, Cliente *cliente);

// Exibe todos os clientes da fila
void exibir_fila(Fila *fila, const char *tipo);

#endif
