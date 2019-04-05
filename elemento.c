
/* implementazione libreria elemento.c
/  permette di operare su insiemi di liste
/  svolgendo operzioni basiche di creazione
/  stampa, eliminazione, ricerca, intersezione
/  unione, e differenza sugli insiemi*/




#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "elemento.h"



/*========================================================================*/
/* FUNZIONE BASICA DI INSERIMENTO ELEMENTO IN UNA LISTA CON MALLOC        */
/* L'INSERIMENTO DEI DATI E' NON E'  ORDINATO SECONDO IL VALORE           */ 
/* QUINDI L'ULTIMO ELEMENTO INSERITO VIENE ACCODATO IN TESTA ALLA LISTA   */
/*========================================================================*/


insieme *aggiungi_elemento ( insieme *ultimo, int n)

  {
	insieme *nuovo = NULL;
	  
	/*definisce lo spazio di memoria dell'elemento 
	creato assegnandolo al puntatore*/

	nuovo = (insieme *)malloc (sizeof(insieme));
        	
	/* se malloc restituisce NULL la funzione non e' riuscita ad effettuare 
	l'allocazione per il nuovo elemento*/
        
        if (nuovo == NULL) 
	{
		
	printf ("Errore nell'allocazione dell'oggetto nella memoria HEAP");
	return nuovo;
		
	}
	
	nuovo->value = n;
	nuovo->next = ultimo; 
	return nuovo; 
  }	


/*==========================================================*/
/*FUNZIONE PER AGGIUNGERE GLI ELEMENTI ALL'INSIEME          */
/*         >CON CONTROLLO DEI DATI INSERITI<                */
/*==========================================================*/
	
    
insieme *crea_insieme (insieme *nodo)

  {       
	/*dichiarazione variabili locali*/	
		int a=0,val=0;
		int trovato=0;
		double tester=0;
			

        for (;;) /*scelgo un ciclo infinito per l'inserimento dati nel mio insieme*/
	{
	
	 printf	("\nInserisci un nuovo elemento nell'insieme ('t' per terminare): ");
	
	/*di seguito il controllo sul tipo di input inserito
	in particolare viene controllato che venga in effetti inserito un numero
	e che tale numero sia intero*/

	while (scanf ("%lf",&tester)!=1)
        		{ 	
			    
		/*se incontra il valore t termina l'inserimento*/	
		/*getchar e' cmq inserito in un ciclo while per 
        	svuotare lo stdio nel caso venisse introdotto per errore piu'
  		di un carattere, l'inserimento termina quando uno dei caratteri
		 inseriti e' il tasto t */                    			
				
			do 
			{
			val=getchar(); 
			if (val=='t') trovato=1;
			}
			while (val!='\n');	    
			if (trovato==1)
			return nodo;
		
			printf("\nATTENZIONE: DATA TYPE ERRATO!\n");
			printf("INSERISCI UN NUMERO <INTERO> OPPURE 't' PER TERMINARE: ");
		
			}

		/*effettuazione controlli di tipo, unicita' elemento e dimensione tramite if annidiati*/
	 	

		if (tester>=INT_MIN && tester<=INT_MAX)	
		{ 
		
		if ((tester/(int)tester)!=1 && (tester!=0)) /*includo nel controllo il caso limite 0*/
			    	 
				{
				printf("ATTENZIONE VALORE INSERITO NON DI TIPO INTERO\n");
				printf ("ELEMENTO NON INSERITO\n");
				}	else  	
					{ 
					if (cerca_elemento_bool(nodo,a=(int)tester)==1)
					{
					printf ("ATTENZIONE L'ELEMENTO E' GIA' PRESENTE NELL'INSIEME\n");
					printf("ELEMENTO -DUPLICATO- NON INSERITO\n");
					}
					else
					nodo = aggiungi_elemento (nodo,a);
					};
		}
		else   { 
			printf ("ATTENZIONE VALORE INSERITO FUORI DIMENSIONE MASSIMA\n");
			printf ("DIMENSIONI ACCETTABILI TRA %d e %d\n",INT_MIN,INT_MAX);
			printf("ELEMENTO NON INSERITO\n");
		 	};
 
	}; 
	}
        
/*=========================================================*/
/*FUNZIONE DI RICERCA IL DATO ALL INTERNO DELLA LISTA      */
/*E  RESTITUISCE IL PUNTATORE DELL'ELEMENTO TROVATO        */
/*OPPURE NULL                                              */
/*=========================================================*/
		

insieme *cerca_elemento (insieme *nodo,int n)
	
	{ 
		/*definizione variabili locali*/
		insieme *punta=NULL;	
	
		for(punta=nodo; punta!=NULL ;punta=punta->next)
			
		{
			if (punta->value==n)
				return punta;
		}
				
		printf("ELEMENTO CONTROLLATO NON APPARTENENTE ALL'INSIEME\n");
		return NULL;
	
	}
	
/*=========================================================*/
/*FUNZIONE DI RICERCA DATO ALL INTERNO DELLA LISTA         */
/*LA FUNZIONE RESTITUISCE IL VALORE BOOLEANO DEL RISULTATO */
/* DELLA RICERCA (simile alla precedente)                  */
/*=========================================================*/
	
	

  int cerca_elemento_bool (insieme *nodo,int n)
	
	{ 	/*definizione variabili locali*/
	        insieme *punta=NULL;

		for(punta=nodo; punta!=NULL ;punta=punta->next)			
		{
			if (punta->value==n)
			return 1;
		}
		return 0;			
		}   
	
/*=================================================*/
/*          FUNZIONE DI STAMPA INSIEME             */
/*=================================================*/

  void  stampa_insieme (insieme *nodo)
       
   {        
	/*dichiarazione variabili locali*/
	insieme *puntatore=NULL;
	int contatore=0;
		
	for (puntatore=nodo; puntatore!=NULL ;puntatore=puntatore->next)
	{
	contatore++;	
	printf ("Trovato elemento N. %d, contiene il valore: %d \n",contatore,puntatore->value);
	}	  
	if (contatore==0) printf ("    -INSIEME VUOTO-\n");       
	printf(">>  -------------INVIO per continuare--------------  <<\n");
        while (getchar()!='\n');
		
   }

/*=================================================*/
/* FUNZIONE DI ELIMINAZIONE ELEMENTO DALL'INSIEME  */
/*=================================================*/

insieme *elimina_elemento ( insieme *nodo, int n)
	{
		
		insieme *primo=nodo;/* salva la pos del primo elemento*/
		insieme *precedente=nodo;
		insieme *seguente=NULL;
		int counter =0;
	        		        

 /*verifica che l'elemento da eliminare sia presente*/
	 if (cerca_elemento_bool(nodo,n)==1)
	{
     
            while(nodo!=NULL)
    
            {     
                
		
		/*esegue se non e' il primo elemento*/
		if (nodo->value==n && counter==1)                
			{  	    		
			seguente=nodo->next;
			free((insieme *)nodo);
			nodo=precedente;
			nodo->next=seguente;
			nodo=primo;
			return nodo;         
			}      
                
		/*esegue se e' il primo elemento della lista*/
		/*in tal caso sposta il puntatore sull'elemento seguente*/
		else if (nodo->value==n && counter==0)
			{ 
			nodo=nodo->next;
			free((insieme *)primo);
			return nodo;
			}
                        
			precedente=nodo;/*punta l'elemento precedente*/
			nodo=nodo->next;/*passa all'elemento seguente per la successiva analisi*/
			counter=1;/*indentifica il primo elemente della lista*/
    
	     } 	
	  }	
            printf("Valore in ricerca NON trovato, eliminazione non effettuata\n");
	    nodo=primo;
            return nodo;
	     	
	}


/*====================================================*/
/*		FUNZIONE DI UNIONE INSIEMI            */			
/*====================================================*/
  
 insieme *unione_insiemi ( insieme *a , insieme *b )

	{   
	/*dichiarazione variabili locali*/
        insieme *a_a;
        insieme *b_b;
        insieme *unione=NULL;
        
        for (a_a=a;a_a!=NULL;a_a=a_a->next)
        {   
            unione = aggiungi_elemento (unione,a_a->value);
        }
        
	/*gli elementi del secondo insieme vengono aggiunti solo
	se non sono gia' presenti nell'insieme unione*/
		
        for (b_b=b;b_b!=NULL;b_b=b_b->next)
        {  
	if  (cerca_elemento_bool(unione,b_b->value)==0)
        unione = aggiungi_elemento (unione,b_b->value);
        }
        return unione;
    }
      

/*====================================================*/
/*		FUNZIONE DI INTERSEZIONE INSIEMI      */			
/*====================================================*/
	

  insieme *intersezione_insieme ( insieme *a , insieme *b )

	{   /*dichiarzione variabili locali*/
		insieme *a_a;
		insieme *b_b=b;
		insieme *intersezione=NULL;
		
		
		for (a_a=a;a_a!=NULL;a_a=a_a->next)
		{    	
		if (cerca_elemento_bool(b_b,a_a->value)==1)
		intersezione = aggiungi_elemento(intersezione,a_a->value);
		}

		return intersezione;
	}
				
          

/*====================================================*/
/*		FUNZIONE DI  DIFFERENZA INSIEMI       */			
/*====================================================*/

 insieme *differenza_insieme ( insieme *a , insieme *b )
	
	{		
		/*dichiarazione variabili locali*/
		insieme *a_a;
		insieme *b_b=b;
		insieme *differenza=NULL;
		
		for (a_a=a;a_a!=NULL;a_a=a_a->next)
		{    	
		if (cerca_elemento_bool(b_b,a_a->value)==0)
		differenza = aggiungi_elemento(differenza,a_a->value);
		}
		
		return differenza;
	}


/*====================================================*/
/*		FUNZIONE DI  TROVA MIN         	      */			
/*		restituisce la posizione del minimo   */
/*====================================================*/


  insieme *trova_minimo (insieme *a)

	{      
		insieme *a_a=a;
		insieme *minimo=a_a;
		
		int min;
		min=a_a->value;
		
		while (a_a!=NULL)
		{	
			
		    if (a_a->value<min)
			{
			minimo=a_a;
			min=a_a->value;
			}
			a_a=a_a->next;
		}
		
		return minimo;
	}



/*====================================================*/
/*		FUNZIONE DI  TROVA MASSIMO	      */			
/*	restituisce la posizione del valore massimo   */
/*====================================================*/


insieme *trova_massimo (insieme *a)

{      
	insieme *a_a=a;
	insieme *massimo=a_a;
	
	int max;
	max=a_a->value;
	
	while (a_a!=NULL)
	{	
		
		if (a_a->value>max)
		{
		massimo=a_a;
		max=a_a->value;
		}
		a_a=a_a->next;
	}
	return massimo;
}



/*====================================================*/
/*		FUNZIONE DI ORDINAMENTO LISTA	      */			
/*		restituisce una lista ordinata        */
/*          !!la vecchia lista viene distrutta!!      */
/*====================================================*/	

insieme *ordina_insieme (insieme *a)


{  	 /*dichiarazione variabili locali*/
	insieme *a_a=a;
	insieme *p;
	insieme *ordina=NULL;

	while (a_a!=NULL)
	{	
	p=trova_minimo(a_a);/* trova il minino della lista */       
	ordina=aggiungi_elemento(ordina,p->value);/*lo aggiunge alla nuova lista*/
	a_a=elimina_elemento(a_a,p->value);/*cancella l'elemento dalla vecchia lista*/
	}
	return ordina;
}
	
/*====================================================*/
/*	FUNZIONE DI COPIA LISTA		     	      */			
/*	COPIA UNA LISTA SU UNA SECONDA LISTA          */
/*  accodando gli elementi se la seconda lista non    */
/*  e' vuota		   			      */
/*====================================================*/	
	
	
insieme *copia_insieme_append (insieme *a)

{	/*dichiarazione variabili locali*/
	insieme *a_a=a;
  	insieme *copia=NULL;
	
	for (a_a=a;a_a!=NULL;a_a=a_a->next)
	{
	copia=aggiungi_elemento(copia,a_a->value);
	}
	return copia;
}

	
	
	
	
	



			

			

