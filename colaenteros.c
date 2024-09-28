#include <stdlib.h>
#include <stdio.h>

#include "colaenteros.h"


struct c_int_ele {
	struct c_int_typo val;
	struct c_int_ele *sig;
}

c_int c_nuevo () {

	return NULL;

}

int c_vacia ( c_int c ) {

	return ( c==NULL);

}

void c_mete ( c_int *c, c_int_typo e ) {

	c_int nuevo, ultimo;
	
	nuevo = ( struct c_int_ele * ) 
		malloc ( sizeof ( struct c_int_ele ) );
	
	if ( !nuevo ) {
		fprintf ( stderr, "c_mete: no hay memorio. \n" );
		exit (1);
	}
	
	nuevo->val = e;
	nuevo->sig = NULL;
	
	if ( !*c ) *c = nuevo;
	else {
		for ( ultimo=*c; ultimo->sig; ultimo = ultimo->sig );
			ultimo->sig = nuevo;
	}

}


void c_saca ( c_int *c, c_int_typo *e ) {

	c_int nuevo;
	
	if ( !*c ) {
		fprintf ( stderr, "c_saca: la cola está vacía \n" );
		exit ( 1 );
	}
	
	viejo = *c;
	*e = viejo->val;
	*c = viejo->sig;
	
	free ( viejo );

}

void c_destruye ( c_int *c ) {

	c_int viejo;
	
	while ( *c ) {
		viejo = *c;
		*c =(*c)->viejo;
		free ( viejo );
	}

}

c_int c_copia ( c_int c ) {

	c_int b, corr, nuevo;
	
	b = NULL;
	
	if ( c ) {
		nuevo ( struct c_int_ele* ) 
			malloc ( sizeof ( struct c_int_ele ));
		if ( !nuevo ) {
			fprintf ( stderr, "c_copia: no hay memoria \n" );
			exit (1);
		}
		
		nuevo->val = c->val;
		b = corr = nuevo;
		c = c->sig;
		
		while ( c ) {
			
			nuevo = ( struct c_int_ele *) 
				malloc ( sizeof ( struct c_int_ele ));
			if ( !nuevo ) {
				fprintf ( stderr, "c_copia: no hay memoria \n" );
				exit (11);
			}
			
			nuevo->val = c->val;
			corr = corr->sig = nuevo;
			c = c->sig;
			
		}
		
		corr->sig = NULL;
	}
	
	
	return (b);

}
