#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef struct radnik
{
char ime[20],prezime[20],brojTelefona[20];
float placa;
struct radnik* next;
}radnik_t;

void upisiRadnika(radnik_t**);
void ispisRadnika(radnik_t*);
#endif // HEADER_H_INCLUDED
