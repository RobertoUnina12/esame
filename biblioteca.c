#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome;
	char cognome;
	char matricola;
	int NumeroLibriPrelevati;
struct Studente *next;
}Studente;
/*typedef struct {
	Studente ele[20];
	int num_studente;
}List;*/
struct biblioteca{
	char titolo[100];
	char autore[100];
	int cod_id;
	struct libri *next;
};
/*typedef struct {
	struct libri elementi[20];
	int num_libri;
}Libro;*/
//List inserimento_Studente();
int cerca_Titolo ( struct libri list, char titolo, char autore);
struct libri initList(char titolo, char autore, int code_id;
struct libri inserisciInTesta(struct libri L, char titolo , char autore, int cod_id);
struct libri *Crea_Lista(struct libri *TOP);
int menu();
//libri *leggiFile (FILE *fp, libri *lista);
void scriviLista(struct libri *lista);
void scriviFile(FILE *fp, struct libri *lista);
static struct libri *nuovoNodo(char *titolo, char *autore, int cod_id);
static void freeNodo(struct libri *nodo);
void GestioneErrore();
void freeLista (struct libri *lista);
void stampaLista(struct libri *top);

int main (){
	int scelta;
	FILE *fp;
	struct persona *lista = NULL;
	struct lista *top = NULL;
	int cod_id;
	char titolo;
	char autore;
	struct libri L;
	int presente;
	Libro l;
//lista = nuovoNodo(titolo,autore,cod_id);
//CREA_LISTA (lista)
//lista = inserisciLista(L,autore);
	while ((scelta = menu())){
		switch (scelta) //creo uno switch con 5 case , uno per ogni possibile scelta
		{
			case 1 : //stampa la lista
				fp = fopen ("Libri.txt", "r");
				if (fp==NULL) gestioneErrore();
					lista = leggiFile(fp,lista);
					fclose(fp);
					lista=scriviLista(lista);
					//stampaLista(top);
					break;
			case 2 : //se l'utente preme il tasto dove il libro viene cercato e se è presente lo studente deve inserire matricola
				//cogonome  e nome;
				printf("\n INSERISCI TITOLO LIBRO DA RICHIEDERE : ");
					fflush(stdin);
					gets(titolo);
					fopen("Libri.txt","r");
					lista = leggiFile(fp,lista);
					fclose(fp);
					presente=cerca_Titolo(l.titolo);
					if(titolo !=-1){
						printf("IL LIBRO CERCATO E' PRESENTE NELL'ARCHIVIO ED IL LIBRO E' DISPONIBILE \n");
						inserimento_Studente();
						}else {
							printf ("IL LIBRO CERCATO NON E' PRESENTE NELL'ARCHIVIO QUINDI NON E' DISPONIBILE\n");
						}
						fclose(fp);
						break;
			case 3 : //case costruito per restituire un libro tramite codice 
			break;
			case 4: // esegui richiesta
			break;
			case 5 : //se l'utente vuole uscire dalla biblioteca
			printf("GRAZIE PER AVER SCELTO IL NOSTRO SERVIZIO DI GESTIONE DELLA BIBLIOTECA, TORNA A TROVARCI \n");
			break;
			default : // se l'utente sbaglia ad inserire il numero
			printf ("QUESTO TASTO NON CONSENTE DI EFFETTUARE SCELTE ! RIPROVA \n");
			break;
        }//fine switch
        } //fine do
        return scelta;
        int menu (){
            int scelta ;//questa variabile sara' utilizzata nella switch per decidere che cosa fare 
            printf ("********* \n BENVENUTO NEL PROGRAMMA DI GESTIONE DELLA BIBLIOTECA \n **********\n");
            printf("1.MOSTRA ARCHIVIO\n ");
            printf("2.RICHIEDI LIBRO \n ");
            printf("3.RESTITUISCI LIBRO \n");
            printf("ESEGUI RICHIESTA \n");
            printf("USCIRE\n ");
            printf("INSERISCI SCELTA : ");
            scanf("%d",&scelta); //viene inserito nella variabile var il numero inserito dall'utente e di conseguenza inseito nel ciclo switch
            while (scelta < 0 || scelta > 5) {
                  printf ("QUESTO TASTO NON  CONSENTE DI EFFETTUARE SCELTE ! RIPROVA ! \n ");
                  printf("SCELTA : ");
                  scanf ("%d", &scelta);
                  return scelta;
                  }
                  return scelta;
                  }
                  
                  static struct libri *nuovoNodo(char *titolo, char *autore, int cod_id)
                  {
                         struct libri *nodo;
                         nodo = (struct libri *) malloc(sizeof(struct libri));
                         if (nodo == NULL) return NULL;
                            strcpy (nodo->titolo, titolo);
                            strcpy(nodo->autore, autore);
                            nodo->cod_id = cod_id;
                            nodo->text = NULL;
                            return nodo;
                            }
                            static void freeNodo(struct libri *nodo)
                            {
                                   free((void *)nodo);
                                   }
                                   static struct libri *inserisciLista(struct libri *nodo, struct libri *lista)
                                   {
                                          if (lista == NULL) return nodo;
                                          lista->next = inserisciLista(nodo, lista->next);
                                          return lista;
                                          }
                                          void gestioneErrore()
                                          {
                                               printf("ERRORE\n");
                                               exit(0);
                                               }
                                               void freeLista(struct libri *lista)
                                               {
                                                    if(lista!=NULL)
                                                    {
                                                                   while (lista != NULL)
                                                                   {
                                                                         printf("%s%s%d\n", lista->titolo, lista->autore , lista->cod_id);
                                                                         lista = lista->next;
                                                                         }
                                                                         printf("\n");
                                                                         }
                                                                         libri *leggiFile(FILE *fp, libri *lista)
                                                                         {
                                                                               char titolo[256], autore [256];
                                                                               int cod_id;
                                                                               struct libri *nodo;
                                                                               while(fscanf(fp,"%s%s&d",titolo,autore,&cod_id)==3)
                                                                               {
                                                                                                                                  nodo=nuovoNodo(titolo,autore,cod_id);
                                                                                                                                  if (nodo==NULL)
                                                                                                                                  gestioneErrore();
                                                                                                                                  lista = inserisciLista(nodo,lista);
                                                                                                                                  }
                                                                                                                                  return lista;
                                                                                                                                  }
                                                                                                                                  void scriviFile (FILE *fp, struct libri *lista)
                                                                                                                                  {
                                                                                                                                       while (lista!=NULL)
                                                                                                                                       {
                                                                                                                                             fprint(fp,"%s%s%d\n", lista->titolo, lista->autore, lista->cod_id);
                                                                                                                                             lista = lista->next;
                                                                                                                                             }
                                                                                                                                             }
                                                                                                                                             void stampaLista(struct libri *top)
                                                                                                                                             {
                                                                                                                                                  if (top == NULL){
                                                                                                                                                          printf("\n ------------\n\n");
                                                                                                                                                          }else if (top!=NULL && top->titolo!=0)
                                                                                                                                                          {
                                                                                                                                                                printf("%s%s%d", top->titolo, top->autore, &top->cod_id);
                                                                                                                                                                stampaLista(top->next);
                                                                                                                                                                }
                                                                                                                                                                }
                                                                                                                                                                /*struct libri *CREALISTA(struct libri *top){
                                                                                                                                                                struct libri *tmp=(struct libri *)malloc(sizeof8struct libri));
                                                                                                                                                                tmp->next=TOP;
                                                                                                                                                                strcpy(tmp->titolo, top->titolo);
                                                                                                                                                                strcpy(tmp->autore, top->autore);
                                                                                                                                                                tmp-cod_id=TOP->cod_id;
                                                                                                                                                                return tmp;
                                                                                                                                                                }*/
                                                                                                                                                                int cerca_Titolo(libro list, char titolo)
                                                                                                                                                                {
                                                                                                                                                                    int j;
                                                                                                                                                                    int presenza=-1;
                                                                                                                                                                    for (j=0;j<list.num_lib; j++)
                                                                                                                                                                    {
                                                                                                                                                                        if (strcmp(list.elementi[j].titolo, &titolo)==0)
                                                                                                                                                                        presente = 1;
                                                                                                                                                                        }
                                                                                                                                                                        return presente;
                                                                                                                                                                        }
                                                                                                                                                                        List Inserimento_Studente(){
                                                                                                                                                                             List lista;
                                                                                                                                                                             int i;
                                                                                                                                                                             printf("\n QUANTI LIBRI VUOI PRENDERE IN PRESTITO ? : ");
                                                                                                                                                                             scanf("%d", &lista.num_studente);
                                                                                                                                                                             fflush(stdin);
                                                                                                                                                                             for (i=0; i<lista.num_studente; i++)
                                                                                                                                                                             {
                                                                                                                                                                                 printf("\nINSERISCI NOME : ");
                                                                                                                                                                                 gets(&lista.elementi[i].nome);
                                                                                                                                                                                 printf"\n INSERISCI COGNOME : ");
                                                                                                                                                                                 gets(&lista.elementi[i].cognome);
                                                                                                                                                                                 printf(" \n INSERISCI MATRICOLA : ");
                                                                                                                                                                                 scanf("%s",&lista.elementi[i].matricola);
                                                                                                                                                                                 fflush(stdin);
                                                                                                                                                                                 }
                                                                                                                                                                                 return lista;
                                                                                                                                                                                 } 
                                                                                                                                                                
                                                                                                                                                  
                                                                                                                                                                
                                                                               
                                                                                                                                  
                            
	
