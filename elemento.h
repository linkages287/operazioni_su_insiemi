/*file elemento.h
*/


/*dichiarazione dei prototipi di funzione*/
/*e progettazione struttura*/


typedef struct set_element 
  
  {  
	int value;
	struct set_element *next;
  }     insieme;




insieme* aggiungi_elemento ( insieme*, int );

insieme* crea_insieme (insieme*);

insieme* cerca_elemento (insieme*, int );

int cerca_elemento_bool (insieme*, int);

void stampa_insieme (insieme*);

insieme* elimina_elemento (insieme*,int);

insieme* unione_insiemi (insieme*, insieme*);

insieme* intersezione_insieme (insieme* , insieme*);

insieme* differenza_insieme ( insieme* , insieme* );

insieme *trova_minimo (insieme *);

insieme *trova_massimo (insieme *);
	
insieme *ordina_insieme (insieme *);

insieme *copia_insieme_append (insieme *);


