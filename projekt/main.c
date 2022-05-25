#include <stdio.h>
#include "header.h"
#include <string.h>
#include <conio.h>


int main (void)
{
    radnik_t* first=NULL;

    char imeFirme[50];
   // printf("Upisi ime firme:");
   // fgets();
    char choice;
	do {
		printf("*****************************\n");
		printf("1 - Upisi radnika\n");
		printf("2 - Ispis radnika\n");
		printf("3 - funkcija 3\n");
		printf("0 - zavrsi program\n");
		printf("*****************************\n");

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
           // funkcija3();
			_getch();
			break;
		case '0':


			break;
		default:
			printf("pogresan odabir!");
			_getch();
			break;
		}
	} while (choice != '3');
	printf("kraj programa");
	_getch();

return 0;
}
