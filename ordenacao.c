
#include<stdio.h>
#include<stdlib.h>
#include "ordenacao.h"

struct upa {
	char *nome;
	int emergencia;
	int urgencia;
	int sem_urgencia;
	int qtd_medicos;
};

UPA *upa_new(char *nome, int emergencia, int urgencia, int sem_urgencia, int qtd_medicos) {
	UPA *upa = malloc(sizeof(UPA));
	*upa = (UPA) { nome, emergencia, urgencia, sem_urgencia, qtd_medicos };
	return upa;
}

void upa_free(UPA **upa) {
	free((*upa)->nome);
	free(*upa);
	*upa = NULL;
}

UPA *upa_scan() {
	char *nome = malloc(50 * sizeof(char));
	int emergencia, urgencia, sem_urgencia, qtd_medicos;
	scanf("%s %d %d %d %d", nome, &emergencia, &urgencia, &sem_urgencia, &qtd_medicos);
	return upa_new(nome, emergencia, urgencia, sem_urgencia, qtd_medicos);
}

void upa_print(UPA *upa) {
	printf("%s %d %d %d %d\n", upa->nome, upa->emergencia, upa->urgencia, upa->sem_urgencia, upa->qtd_medicos);
}

struct upa_lista {
	UPA **ptr;
	int qtd;
};

UPA_lista *upa_lista_new(int qtd) {
	UPA_lista *upa_lista = malloc(sizeof(UPA_lista));
	upa_lista->ptr = malloc(qtd * sizeof(UPA *));
	upa_lista->qtd = qtd;
	return upa_lista;
}

void upa_lista_free(UPA_lista **upa_lista) {
	for (int i = 0; i < (*upa_lista)->qtd; i++) upa_free((*upa_lista)->ptr + i);
	free(*upa_lista);
	*upa_lista = NULL;
}

UPA_lista *upa_lista_scan() {
	int qtd;
	scanf("%d", &qtd);
	UPA **upas = malloc(qtd * sizeof(UPA *));
	for (int i = 0; i < qtd; i++) upas[i] = upa_scan();
	UPA_lista *upa_lista = malloc(sizeof(UPA_lista));
	*upa_lista = (UPA_lista) { upas, qtd };
	return upa_lista;
}

void upa_lista_print(UPA_lista *upa_lista) {
	for (int i = 0; i < upa_lista->qtd; i++) upa_print(upa_lista->ptr[i]);
}

void upa_lista_ordena(UPA_lista *upa_lista) {

}
