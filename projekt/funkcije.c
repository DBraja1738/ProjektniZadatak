#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void upisiRadnika(radnik_t** first)
{
    int i;

radnik_t* noviRadnik=(radnik_t*)calloc(1,sizeof(radnik_t));

if(noviRadnik==NULL){
return;
}
noviRadnik->next=NULL;

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
	printf("Kontakt broj radnika: \n");
	fgets(noviRadnik->brojTelefona, 20, stdin);
	i = 0;

if(*first==NULL)
{
    *first=noviRadnik;
}
else
    {
        noviRadnik->next=*first;
    *first=noviRadnik;

}


	return ;
}


void ispisRadnika(radnik_t* f)
{
    radnik_t* temp=f;
while(temp != NULL)
    {
    printf("%s,%s,%s\n",temp->ime,temp->prezime,temp->brojTelefona);
temp=temp->next;
    }
}
