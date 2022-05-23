#include <stdio.h>
#include "header.h"
#include <string.h>
#include <conio.h>


int main (void)
{
    char imeFirme[50];
    printf("Upisi ime firme:");
    scanf("%49s",imeFirme);
    char choice;
	do {
		printf("*****************************\n");
		printf("1 - Upisi radnika\n");
		printf("2 - funkcija 2\n");
		printf("3 - funkcija 3\n");
		printf("0 - zavrsi program\n");
		printf("*****************************\n");

		choice = _getch();
		switch (choice)
		{
		case '1':
        upisiRadnika();
			_getch();
			break;
		case '2':
			//funkcija2();
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
