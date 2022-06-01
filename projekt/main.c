#include <stdio.h>
#include "header.h"
#include <string.h>
#include <conio.h>

int globalIdCounter=0;

int main (void)
{
    srand((unsigned)time(NULL));
    radnik_t* first=NULL;

  //  char imeFirme[50]={'\0'};
  //  printf("Upisi ime firme:");
    // fgets(imeFirme,50,stdin);
    char choice;
	do {
		printf("*****************************\n");
		printf("1 - Upisi radnika\n");
		printf("2 - Ispis radnika\n");
		printf("3 - Otkazi radnika\n");
		printf("4 - Uredi radnika\n");
		printf("5 - Sortiraj radnike po satnici\n");
		printf("6 - Upisi radnike u datoteku\n");
		printf("0 - zavrsi program\n");

		printf("*****************************\n");
        int trazeniID;
		choice = _getch();
		switch (choice)
		{
		case '1':
        upisiRadnika(&first);
			_getch();
			break;
		case '2':
			ispisRadnika(first);
			_getch();
			break;
		case '3':

		    printf("Otkazi radnika koji ima ID:");
		    scanf("%d",&trazeniID);
		    _getch();
            otkaziRadnika(&first,trazeniID);

			break;
		case '4':
            printf("Uredi radnika koji ima ID:");
		    scanf("%d",&trazeniID);
            _getch();
            urediRadnika(&first,trazeniID);

			break;
			case '5':
            bubbleSort(first);
            _getch();
			break;
		default:
			printf("pogresan odabir!\n");
			_getch();
			break;
		}
	} while (choice != '0');
	printf("kraj programa");
	_getch();

return 0;
}
