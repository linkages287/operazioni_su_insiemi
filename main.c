/*
 *  main.c
 *  PER UTILIZZO DELLA LIBRERIA
 *  elemento.h
 * 
 *
 */

#include <stdio.h>
#include "elemento.h"
#define cls "\033[2J" 

/*definisco la funzione di stampa menu*/
int crea_menu();

int main (void)

{

/*definizione variabili locali*/
int scelta=0;
int valore=0; 

/*insiemi basici A e B di lavoro*/
insieme *set_a=NULL;
insieme *set_b=NULL;

/*insiemi risultato*/
insieme *unione=NULL;
insieme *intersezione=NULL;
insieme *differenza_ab=NULL;
insieme *differenza_ba=NULL;

/*esecuzione programma in base 
alla scelta effettuata */

do
{
     scelta = crea_menu();
     switch (scelta)

      {
	case 1:
	printf ("\n--- CREAZIONE INSIEME A ---\n\n");
	set_a = crea_insieme(set_a);
	break;
	
	case 2:
	printf ("\n--- CREAZIONE INSIEME B ---\n\n");
	set_b = crea_insieme(set_b);
	break;
	
	case 3:
	printf ("\n---------STAMPA ELEMENTI PER ELIMINAZIONE--------\n");
        printf ("\nElementi dell'insieme A: \n");
	stampa_insieme(set_a);
	
	if (set_a==NULL) 
	printf ("L'INSIEME E' VUOTO, NON CE' NULLA DA ELIMINARE");
         
	else {
	printf ("\nInserisci VALORE da eliminare: ");
	scanf ("%d",&valore);
	set_a = elimina_elemento (set_a,valore);
	getchar();
	printf("\nVerifico l'insieme modificato...\n");
	stampa_insieme(set_a);  
	}	
	break;

	case 4:
	printf ("\n---------STAMPA ELEMENTI PER ELIMINAZIONE--------\n");
	printf ("\nElementi dell'insieme A: \n");
	stampa_insieme(set_b);
        
	if (set_b==NULL)
	printf ("\nL'INSIEME E' VUOTO NON CE' NULLA DA ELIMINARE");

	else {
	printf ("\nInserisci VALORE da eliminare: ");
	scanf ("%d",&valore);
	set_b=elimina_elemento(set_b,valore);
	getchar();
	printf("\nVerifico l'insieme modificato...\n");
	stampa_insieme(set_b);
	}
	break;

	case 5:
	printf ("\n   INSIEME A\n");
	stampa_insieme (set_a);
	printf ("\n   INSIEME B\n");
        stampa_insieme (set_b);
	break;

	case 6:
    	printf ("\n UNIONE INSIEMI A e B\n");
    	unione = unione_insiemi (set_a,set_b);
    	stampa_insieme (unione);
    	break;

	case 7:
	printf ("\n INTERSEZIONE INSIEMI A e B\n");
	intersezione = intersezione_insieme (set_a,set_b);
	stampa_insieme (intersezione);
	break;

	case 8:
	printf ("\n DIFFERENZA INSIEMI A - B\n");
	differenza_ab= differenza_insieme ( set_a, set_b);
	stampa_insieme (differenza_ab);		  
	break;

	case 9:
	printf ("\n DIFFERENZA INSIEMI B - A\n");
	differenza_ba= differenza_insieme ( set_b, set_a);
	stampa_insieme (differenza_ba);		  
	break;	  
			  
	case 0:
	printf ("\n      .....Uscita programma.....\n\n\n");
	break;
			  
	case 63: /*corrisponde al tasto o*/
	printf("\nORDINAMENTO INSIEMI A e B\n");
	set_a=ordina_insieme(set_a);  
	set_b=ordina_insieme(set_b);  
	printf ("\n   INSIEME A E' STATO ORDINATO\n");
	stampa_insieme(set_a);
	printf ("\n   INSIEME B E' STATO ORDINATO\n");
	stampa_insieme(set_b);
	break;

	 }
} while (scelta!=0);
	
	return (0);
	
};

/*implementazione funzioni nel main program */
int crea_menu ()

{   
   
   int scelta;

   printf (cls); 
   printf ("\n\n\n");
   printf ("	|********************** MENU *******************|\n");
   printf ("	|						|\n");
   printf ("	|    	        OPZIONI DISPONIBILI  	        |\n");
   printf ("	|                                               |\n");
   printf ("	| 1) Crea insieme / aggiungi elementi insieme A	|\n");
   printf ("	| 2) Crea insieme / aggiungi elementi insieme B	|\n");
   printf ("	| 3) Elimina  elementi insieme A		|\n");
   printf ("	| 4) Elimina  elementi insieme B		|\n");
   printf ("	| 5) Stampa a schermo  gli insiemi disponibili  |\n");
   printf ("	| 6) Unione insiemi A e B			|\n");
   printf ("	| 7) Intersezione insiemi A e B			|\n");
   printf ("	| 8) Differenza insiemi A-B			|\n");
   printf ("	| 9) Differenza insiemi B-A			|\n");
   printf ("	| o) Ordina insiemi A e B			|\n");
   printf ("	| 0) Uscita Programma				|\n");
   printf ("	|                                               |\n");
   printf ("	|                                               |\n");
   printf ("	|***********************************************|\n");


  do 
  {

  printf ("\n	-- SCELTA OPZIONE-->     ");
		  scelta=getchar()-48;/*il risultato viene sciftato per poter far corrispondere
					al codice ascii del tasto 1 il numero 1*/
		  while(getchar()!='\n');/*svuota lo stdio*/  
  }
   		while (((scelta<0) && (scelta>9)) && (scelta!=63));
	
	        return scelta; 
  
};
  






