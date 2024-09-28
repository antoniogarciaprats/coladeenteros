#ifndef C1CP_tip_TYPO
#define C1CP_tip_TYPO

struct c_int_typo {
	int x;
}

typedef struct c_int_ele *c_int;

c_int c_nuevo ();
int c_vacia ( c_int c );
void c_mete ( c_int *c, c_int_typo e );
void c_saca ( c_int *c, c_int_typo *e );
void c_destruye ( c_int *c );
c_int c_copia ( c_int c );

#endif
