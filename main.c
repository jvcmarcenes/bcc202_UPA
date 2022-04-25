
#include "ordenacao.h"

int main() {

	UPA_lista *upa_lista = upa_lista_scan();
	upa_lista_ordena(upa_lista);
	upa_lista_print(upa_lista);
	upa_lista_free(&upa_lista);

	return 0;
}
