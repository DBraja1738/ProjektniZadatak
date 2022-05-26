#include <stdio.h>
#include <stdlib.h>
#include "header.h"

extern int globalIdCounter;

void upisiRadnika(radnik_t** first)
{
    int i;

radnik_t* noviRadnik=(radnik_t*)calloc(1,sizeof(radnik_t));

if(noviRadnik==NULL){
return;         //provjera za zauzimanje
}
noviRadnik->next=NULL;   //nuliranje veze link liste

    noviRadnik->id=globalIdCounter;
    globalIdCounter++;
    printf("Ime radnika: \n");
	fgets(noviRadnik->ime, 20, stdin);

	i = 0;
	while (noviRadnik->ime[i] != '\n' && i < 20) i++;
	noviRadnik->ime[i] = '\0';

	printf("Prezime radnika: \n");
	fgets(noviRadnik->prezime, 20, stdin);
	i = 0;

	while (noviRadnik->prezime[i] != '\n' && i < 20) i++;
	noviRadnik->prezime[i] = '\0';

    //printf("Radnikova satnica: \n");
   // scanf(" %f",&noviRadnik->satnica);
    //_getch();
        i = 0;

	printf("Kontakt broj radnika: \n");
	fgets(noviRadnik->brojTelefona, 20, stdin);
	i = 0;




if(*first==NULL)
{
    *first=noviRadnik;              //stvori link listu
}
else
    {
        noviRadnik->next=*first;        //ako postoji link lista povezi samo
    *first=noviRadnik;

}


	return ;
}


void ispisRadnika(radnik_t* f)
{
    radnik_t* temp=f;
while(temp != NULL)
    {
    printf("%d,%s,%s,%s\n",temp->id,temp->ime,temp->prezime,temp->brojTelefona);
temp=temp->next;
    }
}


void otkaziRadnika(radnik_t** f, int trazeniID)
{
int i;
radnik_t *temp = *f, *prev;



// ako je head trazeni id
if (temp != NULL && temp->id == trazeniID) {
        *f = temp->next; // zamjeni head
        free(temp); // oslobodi stari head
        return;
    }
//trazi id, listaj po link listi
 while (temp != NULL && temp->id != trazeniID) {
        prev = temp;
        temp = temp->next;
    }

    // ako ne postoji taj ID
    if (temp == NULL)
        return;

    // odspoji link listu
    prev->next = temp->next;
//oslobodi
    free(temp);


return;
}
void urediRadnika(radnik_t** f,int trazeniID)
{
    radnik_t* temp=f, *prev

    // ako je head trazeni id
    if (temp != NULL && temp->id == trazeniID) {
            printf("Zamjeni ime radnika");
            fgets()
            printf("Zamjeni prezime radnika");

            printf("Zamjeni kontakt broj radnika");


    }
}
