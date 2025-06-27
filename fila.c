#include <stdio.h>
#include "fila.h"

// Autor: Maria Fernanda Zandona Casagrande GRR20241727
// Descrição: Inicializa a fila
void inicializar_fila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}

int fila_cheia(Fila *fila) {
    return fila->quantidade == TAM_MAX_FILA;
}

int fila_vazia(Fila *fila) {
    return fila->quantidade == 0;
}

// Autor: Maria Fernanda Zandona Casagrande GRR20241727
// Descrição: Insere um cliente no final da fila circular
int enfileirar(Fila *fila, Cliente cliente) {
    if (fila_cheia(fila)) return 0;
    fila->clientes[fila->fim] = cliente;
    fila->fim = (fila->fim + 1) % TAM_MAX_FILA;
    fila->quantidade++;
    return 1;
}

// Autor: Maria Fernanda Zandona Casagrande GRR20241727
    // Descrição: Remove um cliente do início da fila circular
int desenfileirar(Fila *fila, Cliente *cliente) {
    if (fila_vazia(fila)) return 0;
    *cliente = fila->clientes[fila->inicio];
    fila->inicio = (fila->inicio + 1) % TAM_MAX_FILA;
    fila->quantidade--;
    return 1;
}

void exibir_fila(Fila *fila, const char *tipo) {
    printf("Fila %s (%d clientes):\n", tipo, fila->quantidade);
    int i = fila->inicio;
    for (int count = 0; count < fila->quantidade; count++) {
        Cliente c = fila->clientes[i];
        printf("  - %s | N: %d | Procedimentos: %d\n", c.nome, c.numero, c.procedimentos);
        i = (i + 1) % TAM_MAX_FILA;
    }
}