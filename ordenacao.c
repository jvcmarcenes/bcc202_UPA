#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "ordenacao.h"



UPA *upas_free(UPA *upa, int qtd){
	for(int i = 0; i < qtd; i++) free(upa[i].nome); //Libera as strings
	free(upa); //Libera o vetor das upas
	return upa;
}

void upa_scan(UPA *upa) {
	upa->nome = (char*) malloc(50 * sizeof(char)); //Aloca um vetor de char
	//Lê os dados de cada upa
	scanf("%s %d %d %d %d", upa->nome, &(upa->emergencia), &(upa->urgencia), &(upa->sem_urgencia), &(upa->qtd_medicos));
}

void upas_print(UPA *upa, int qtd){
	for(int i = 0; i < qtd; i++) //Imprime as informaçãoes de cada upa
		printf("%s %d %d %d %d\n", upa[i].nome, upa[i].emergencia, upa[i].urgencia, upa[i].sem_urgencia, upa[i].qtd_medicos);
}

UPA *upas_scan(int *qtd) {
	scanf("%d", qtd); //Lê a quantidade de upas

	UPA *upa = (UPA*) malloc(*qtd * sizeof(UPA)); //Aloca o vetor das upas

	for(int i  = 0; i < *qtd; i++) upa_scan(&upa[i]); //Preenche cada célula da upa

	return upa;
}

void upas_quicksort(UPA *upa, int l, int r){
	int q; //Pivo
	if(l < r){
		q = upas_partition(upa, l, r); //Particiona e mostra o pivo
		upas_quicksort(upa, l, q - 1); //Recursão
		upas_quicksort(upa, q + 1, r); //Recursão
	}
}

int upas_partition(UPA *upa, int l, int r){
	UPA x = upa[r], aux;//Pivo
	int i = l - 1;
	for(int j = l; j < r; j++){ //Varre o vetor procurando alguem menor que x
		if(upas_comp(upa[j], x) >= 0){ //Faz a troca das posições
			aux = upa[++i];
			upa[i] = upa[j];
			upa[j] = aux;
		}
	}
	//Troca o pivo
	aux = upa[++i];
	upa[i] = upa[r];
	upa[r] = aux;

	//Retorna a posição do pivo
	return i;
}

int upas_comp(UPA a, UPA b){
	// -1  se o B tiver prioridade
	// 0  se ambos forem iguais
	// 1  se o A tiver prioridade

	//Compara a quantidade de pessoas na emergencia
	if(a.emergencia < b.emergencia) return -1;
	else if(a.emergencia > b.emergencia) return 1;

	//Compara a quantidade de pessoas na urgencia
	if(a.urgencia < b.urgencia) return -1;
	else if(a.urgencia > b.urgencia) return 1;

	//Compara a quantidade de pessoas na sem urgencia
	if(a.sem_urgencia < b.sem_urgencia) return -1;
	else if(a.sem_urgencia > b.sem_urgencia) return 1;

	//Compara a quantidade de medicos
	if(a.qtd_medicos > b.qtd_medicos) return -1;
	else if(a.qtd_medicos < b.qtd_medicos) return 1;

	//Compara os nomes
	if(strcmp(a.nome, b.nome) > 0 ) return -1;
	else if(strcmp(a.nome, b.nome) < 0 ) return 1;

	return 0;
}
