
#ifndef ORDENACAO_H
#define ORDENACAO_H

//TAD da upa
typedef struct upa{
	char *nome;
	int emergencia;
	int urgencia;
	int sem_urgencia;
	int qtd_medicos;
}UPA;

UPA *upas_scan(int *qtd); //Aloca um vetor de upas e lé os dados de cada upa
void upa_scan(UPA *upa); //Lé os dados de cada upa
UPA *upas_free(UPA *upa, int qtd);//Libera o vetor das upas
void upas_print(UPA *upa, int qtd); //Imprime as upas
void upas_quicksort(UPA *upa, int l, int r); //Ordena as upas
int upas_partition(UPA *upa, int l, int r); //Particiona as upas
int upas_comp(UPA a, UPA b); //Compara duas upas

#endif
