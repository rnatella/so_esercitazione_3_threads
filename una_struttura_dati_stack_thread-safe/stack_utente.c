#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "stack.h"

void *Inserisci(void * s)
{

	int i;
	Elem v;


	for(i=0; i<4; i++) {

		v = rand() % 11;

		/* TBD: Effettuare un inserimento con StackPush() */

		int size = /* TBD: Chiamare il metodo StackSize() */
		printf("Dimensione: %d\n", size);

		sleep(1);
	}

	pthread_exit(NULL);
}


void *Preleva(void * s)
{

	int i;
	Elem v1, v2;


	for(i=0; i<10; i++) {

		/* TBD: Prelevare con StackPop() in v1 */

		/* TBD: Prelevare con StackPop() in v2 */

		printf("Somma: %d\n", v1+v2);

		int size = /* TBD: Chiamare il metodo StackSize() */
		printf("Dimensione: %d\n", size);

		sleep(3);
	}

	pthread_exit(NULL);

}


int main(int argc, char *argv[])
{

	int rc;
	int i;

	srand(time(NULL));


	Stack * stack = /* TBD: Allocare un oggetto stack */

	/* TBD: Inizializzare lo stack con StackInit(),
	 *      indicando "4" come dimensione massima */


	for(i=0; i<5; i++) {

		/* TBD: Creare 5 thread tramite pthread_create(), facendogli
		 *      eseguire la funzione Inserisci(), e passandogli
		 *      l'oggetto stack come parametro puntatore */

	}


	/* TBD: Creare un thread, facendogli eseguire la funzione Preleva(),
	 *      e passandogli l'oggetto stack come parametro puntatore */



	for(i=0; i<5; i++) {

		/* TBD: Effettuare la join con i thread figli
		 *      che hanno eseguito Inserisci() */
	}


	/* TBD: Effettuare la join con il thread figlio
	 *      che ha eseguito Preleva() */


	/* TBD: Disattivare l'oggetto stack con StackRemove(),
	 *      e deallocarlo dalla memoria */
}

