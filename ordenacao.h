
#ifndef ORDENACAO_H
#define ORDENACAO_H

typedef struct upa UPA;
typedef struct upa_lista UPA_lista;

UPA_lista *upa_lista_scan();
void upa_lista_free(UPA_lista **upa_lista);
void upa_lista_print(UPA_lista *upa_lista);
void upa_lista_ordena(UPA_lista *upa_lista);

#endif
