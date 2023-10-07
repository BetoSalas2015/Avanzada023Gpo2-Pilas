#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define pausa system("pause")
#define cls system("cls")
#define NL putchar('\n')

struct Nodo 
{
	char info;
	struct Nodo *sig;
};

typedef struct Nodo nodo;


//  Prototipos

nodo *push(nodo *raiz, char dato);
nodo *pop(nodo *raiz, char *dato);
void imprimeLista(nodo *raiz);
int isEmpty(nodo *raiz);
nodo *stackTop(nodo *raiz, char *dato);

///  Primitivas

nodo *push(nodo *raiz, char dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof( nodo ) );
	if(nuevo == NULL)
	{
		printf("No hay memoria. \n");
		exit(1);
	}
	nuevo -> info = dato;
	nuevo -> sig = NULL;

	nuevo ->sig = raiz;
	raiz = nuevo;
	return raiz;
}


nodo *pop(nodo *raiz, char *dato)
{
	nodo *anterior = NULL;
	if(raiz == NULL)
	{
		printf("Lista vacía, no ha nada que eliminar.\n");
		pausa;
		return 0;
	}
	anterior = raiz;
	raiz = raiz ->sig;				// raiz = anterior -> sig
	*dato = anterior ->info;
	free(anterior);
	return raiz;
}
	

void imprimeLista(nodo *raiz)
{
	nodo *recorre = raiz;
	while( recorre != NULL)
	{
		printf("%c, ", recorre ->info);
		recorre = recorre ->sig; 
	}
	putchar('\n');
}

int isEmpty(nodo *raiz)
{
	if(raiz == NULL)
		return 1;		// Verdadero
	else
		return 0;		// Falso
}

nodo *stackTop(nodo *raiz, char *dato)
{
	if(raiz == NULL)
	{
		printf("Lista vacía, no ha nada que eliminar.\n");
		pausa;
		return 0;
	}
	*dato = raiz ->info;
	return raiz;
}
