
#include "ordenacao.h"

int main() {
	UPA *upa;
	int qtd;
	upa = upas_scan(&qtd);
	upas_quicksort(upa, 0, qtd - 1);
	upas_print(upa, qtd);
	upas_free(&upa, qtd);

	return 0;
}
