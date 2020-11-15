#include "header.h"

/*Funzione che,per 10 volte,incrementa di uno la stazione, ovvero la posizione del treno, 
e tramite scrivi_stazione effettua la modifica poi attende 3 secondi*/
void * Capotreno (void * p){
	struct monitor* m = (struct monitor*) p;
	int i,s;
	s=leggi_stazione(m);
	for(i=0; i<10; i++){
		s=s+1;
		scrivi_stazione(m,s);
		printf("[C: Posizione del treno %d modificata. La nuova posizione è: %d]\n",m->id_treno,s);
		sleep(3);
	}
	pthread_exit(NULL);
}

//Funzione che controlla la posizione di un treno per tre volte
void * Viaggiatori (void * p){
	struct monitor* m = (struct monitor*) p;
	int i;
	int ris;
	for(i=0;i<3;i++){
		sleep(rand()%6+1);
		ris=leggi_stazione(m);
		printf("[V]~Il treno n.ro %d è nella %da stazione\n",m->id_treno,ris);
	}
	pthread_exit(NULL);
}

int main() {
	
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	
	srand(time(NULL));

	struct monitor* m[4];//l'array di monitor per gestire i 4 treni

	pthread_t capo[4];//4 capitreno
	pthread_t viagg[10];//10 viaggiatori	
	
	int i;

	/* TBD: Allocare 4 istanze di monitor, e attivarle con inizializza() */

	//assegno un id ad ogni treno
	m[0]->id_treno=1;
	m[1]->id_treno=2;
	m[2]->id_treno=3;
	m[3]->id_treno=4;

	//creazione dei 4 threads capitreno
	for(i=0;i<4;i++){
		pthread_create(&capo[i],NULL,Capotreno, (void*)  m[i]);
	}

	/* TBD: Avviare 4 thread, facendogli eseguire la funzione Capotreno(),
	 * 	    e passando ad ognuno una istanza di monitor diversa m[i] */


	/* TBD: Avviare 10 thread, facendogli eseguire la funzione Viaggiatori(),
	 *      e passando ad ognuno una istanza di monitor diversa, da scegliere
	 *      a caso con "rand() % 4"
	 */


	/* TBD: Effettuare la join con i thread "Capotreno" */

	/* TBD: Effettuare la join con i thread "Viaggiatori" */

	/* TBD: Disattivazione delle 4 istanze di monitor con rimuovi() */

	/* TBD: Deallocazione delle 4 istanze di monitor con free() */


	return 0;
}	
