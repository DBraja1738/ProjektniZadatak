#include <stdio.h>
#include <stdlib.h>
#include "header.h"


radnik_t* upisiRadnika()
{
    int i;

radnik_t* noviRadnik=(radnik_t*)calloc(1,sizeof(radnik_t));

if(noviRadnik==NULL){
return NULL;
}
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




	return noviRadnik;
}
