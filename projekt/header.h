#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef struct radnik
{
    int id;
    char ime[20],prezime[20],brojTelefona[20];
    float satnica;
    struct radnik* next;
}radnik_t;



void upisiRadnika(radnik_t**);
void ispisRadnika(radnik_t*);
void otkaziRadnika(radnik_t**,int);
void urediRadnika(radnik_t**,int)
#endif // HEADER_H_INCLUDED
