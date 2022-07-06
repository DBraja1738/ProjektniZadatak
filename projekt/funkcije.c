
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

extern int globalIdCounter;

radnik_t* readFile(void)
{

    int nID,i;
    FILE* fp=fopen("id.txt","r");
    if(fp==NULL){
        printf("program je prvi put pokrenut\n");
        return NULL;
    }

    fscanf(fp,"%d",&nID);
    fclose(fp);
    if(nID==0)
        {
        return NULL;
        }
    globalIdCounter=nID;

    radnik_t* first=NULL;
    fp=fopen("radnici.txt","r");
    if(fp==NULL)
    {
    printf("file open fail\n");
    return NULL;
    }
radnik_t* noviRadnik;
char tempIme[20],tempPrez[20],tempBroj[20];
int tempID;
float tempSat;

for(i=0;i<nID;i++){

strcpy(tempIme,"");
strcpy(tempPrez,"");
strcpy(tempBroj,"");

fscanf(fp,"%d\t%s\t%s\t%f\t%s\n",&tempID,tempIme,tempPrez,&tempSat,tempBroj);

radnik_t* noviRadnik=(radnik_t*)calloc(1,sizeof(radnik_t));

if(noviRadnik==NULL){
        printf("neuspjesno zauzimanje prostora");
        return NULL;
}
noviRadnik->next=NULL;

strcpy(noviRadnik->ime,tempIme);
strcpy(noviRadnik->prezime,tempPrez);
strcpy(noviRadnik->brojTelefona,tempBroj);
noviRadnik->id=tempID;
noviRadnik->satnica=tempSat;

if(first==NULL)
{
    first=noviRadnik;              //stvori link listu
}
else
    {
        noviRadnik->next=first;        //ako postoji link lista povezi samo
    first=noviRadnik;

}


}




return first;
}




void upisiRadnika(radnik_t** first)
{
    int i;

radnik_t* noviRadnik=(radnik_t*)calloc(1,sizeof(radnik_t));

if(noviRadnik==NULL){
        printf("neuspjesno zauzimanje prostora");
        return;         //provjera za zauzimanje
}
noviRadnik->next=NULL;   //nuliranje taila link liste

    noviRadnik->id=globalIdCounter;
    globalIdCounter++;

    printf("Ime radnika: \n");
	fgets(noviRadnik->ime, 20, stdin);
    i = 0;
	while (noviRadnik->ime[i] != '\n' && i < 19) i++; // nuliranje viska
	noviRadnik->ime[i] = '\0';

	printf("Prezime radnika: \n");
	fgets(noviRadnik->prezime, 20, stdin);
	i = 0;
	while (noviRadnik->prezime[i] != '\n' && i < 19) i++;
	noviRadnik->prezime[i] = '\0';
    i=0;

	printf("Kontakt broj radnika: \n");
	fgets(noviRadnik->brojTelefona, 20, stdin);
    noviRadnik->brojTelefona[strlen(noviRadnik->brojTelefona)-1]='\0';

    printf("Radnikova satnica: \n");
    scanf("%f",&noviRadnik->satnica);
    getchar();
//treba kad se pojavi radnik da se zapise u datoteku i na pocetku da se iscita iz datoteke
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
    printf("id\time\tprezime\t satnica\tbroj telefona\n");
while(temp != NULL)
    {
    printf("%d\t%s\t%s\t%f\t%s\n",temp->id,temp->ime,temp->prezime,temp->satnica,temp->brojTelefona);
temp=temp->next;
    }
}


void otkaziRadnika(radnik_t** f, int trazeniID)
{
//int i;
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

    // ako ne postoji radnik
    if (temp == NULL)
        return;

    // prespoji link listu
    prev->next = temp->next;
//oslobodi
    free(temp);


return;
}
void urediRadnika(radnik_t** f,int trazeniID)
{
    radnik_t* temp=*f;
    int i;


     while (temp != NULL && temp->id != trazeniID)
        {
        temp=temp->next;
        }



            printf("promjeni ime\n");
            fgets(temp->ime,20,stdin);
            temp->ime[strlen(temp->ime) - 1] = '\0';
            printf("promjeni prezime\n");
            fgets(temp->prezime,20,stdin);
            temp->prezime[strlen(temp->prezime) - 1] = '\0';
            printf("promjeni kontakt broj\n");
            fgets(temp->brojTelefona,20,stdin);
            temp->ime[strlen(temp->brojTelefona) - 1] = '\0';
            printf("promjeni satnicu\n");
            scanf("%f",&temp->satnica);
            getchar();
            return;
}

void bubbleSort(radnik_t *f)
{
int swapped, i;
    radnik_t *ptr1;
    radnik_t *lptr = NULL;


    if (f == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = f;

        while (ptr1->next != lptr)
        {
            if (ptr1->satnica > ptr1->next->satnica)
            {
                zamjeni(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);



    //radi petlju dok se ne dodje do kraja
    return;
}


void zamjeni(radnik_t *a, radnik_t *b)
{
    radnik_t* temp = a;
    char tempIme[20],tempPrezime[20],tempBroj[20];
    float tempSatnica;
    int tempID;

    strcpy(tempIme,a->ime);
    strcpy(tempPrezime,a->prezime);
    strcpy(tempBroj,a->brojTelefona);
    tempSatnica=a->satnica;
    tempID=a->id;

    strcpy(a->ime,b->ime);
    strcpy(a->prezime,b->prezime);
    strcpy(a->brojTelefona,b->brojTelefona);
    a->satnica=b->satnica;
    a->id=b->id;

    strcpy(b->ime,tempIme);
    strcpy(b->prezime,tempPrezime);
    strcpy(b->brojTelefona,tempBroj);
    b->satnica=tempSatnica;
    b->id=tempID;



    return;
}

void upisiUFile(radnik_t* f,char imeFirme[])
{
    radnik_t* temp=f;
    FILE* fp=fopen("radnici.txt","w");
    if(fp==NULL)
    {
        printf("neuspjesno otvoren file");
        return;
    }
    fprintf(fp,"\t\t\t%s",imeFirme);
    fprintf(fp,"id\time\tprezime\t satnica\tbroj telefona\n");
    while(temp!=NULL){

    fprintf(fp,"%d\t%s\t%s\t%f\t%s\n",temp->id,temp->ime,temp->prezime,temp->satnica,temp->brojTelefona);
    temp=temp->next;
    }
    fclose(fp);

}

void oslobodiMemoriju(radnik_t** f)
{
 radnik_t* temp=*f;
 while(temp->next!=NULL){
 *f = temp->next;
 free(temp);
 temp=*f;
 }
*f=NULL;
}

void pamtiID(radnik_t *f)
{
    radnik_t* temp=f;
    int i=0;
    while(temp!=NULL)
        {
        i++;
        temp=temp->next;
        }

FILE* fp=fopen("id.txt","w");

fprintf(fp,"%d",i);

fclose(fp);

}
void updateFile(radnik_t* f)
{
FILE* fp=NULL;


radnik_t* temp= f;
fp=fopen("radnici.txt","w");

    while(temp!=NULL){
fprintf(fp,"%d\t%s\t%s\t%f\t%s\n",temp->id,temp->ime,temp->prezime,temp->satnica,temp->brojTelefona);
    temp=temp->next;
    }

fclose(fp);
return;
}


/*void deserialise(radnik_t** f)
{
FILE* fp=fopen("radnici.txt",'r');
if(fp==NULL)
    {
    printf("file open fail\n");
    return;
    }

radnik_t* temp;

while(fscanf(fp,"%d\t%s\t%s\t%f\t%s\n",temp->id,&temp->ime,&temp->prezime,temp->satnica,&temp->brojTelefona)>0){
insert_end(f,*temp);
}
fclose(fp);
return;
}


void insert_end(radnik_t** root, radnik_t value) {
    radnik_t* new_node = malloc(sizeof(radnik_t));
    if (new_node == NULL) {
        exit(1);
    }
    new_node->next = NULL;
    new_node->satnica = value.satnica;

    if (*root == NULL) {
        *root = new_node;
        return;
    }

    radnik_t* curr = *root;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}
*/
