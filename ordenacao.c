
#include<stdio.h>
#include<stdlib.h>
#include "ordenacao.h"



UPA *upas_free(UPA *upa, int qtd){
	for(int i = 0; i < qtd; i++) free(upa[i].nome); //Libera as strings
	free(upa); //Libera o vetor das upas
	return upa;
}

void upa_scan(UPA *upa) {
	upa->nome = (char*) malloc(50 * sizeof(char)); //Aloca um vetor de char
	//Lé os dados de cada upa
	scanf("%s %d %d %d %d", upa->nome, &(upa->emergencia), &(upa->urgencia), &(upa->sem_urgencia), &(upa->qtd_medicos));
}

void upas_print(UPA *upa, int qtd){
	for(int i = 0; i < qtd; i++) //Imprime as informaçãoes de cada upa
		printf("%s %d %d %d %d\n", upa[i].nome, upa[i].emergencia, upa[i].urgencia, upa[i].sem_urgencia, upa[i].qtd_medicos);
}

UPA *upas_scan(int *qtd) {
	scanf("%d", qtd); //Lé a quntidade de upas

	UPA *upa = (UPA*) malloc(*qtd * sizeof(UPA)); //Aloca o vetor das upas

	for(int i  = 0; i < *qtd; i++) upa_scan(&upa[i]); //Preenche cada celula da upa

	return upa;
}

void upas_quicksort(UPA *upa, int l, int r){
	int q;
	if(l < r){
		q = upas_partition(upa, l, r);
		upas_quicksort(upa, l, q - 1);
		upas_quicksort(upa, q + 1, r);
	}
}

int upas_partition(UPA *upa, int l, int r){
	//TODO fazer essa porra aqui
}