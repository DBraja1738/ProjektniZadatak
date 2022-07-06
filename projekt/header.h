#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef struct radnik
{
    int id;
    char ime[20],prezime[20],brojTelefona[20];
    float satnica;
    struct radnik* next;
}radnik_t;


radnik_t* readFile();
void upisiRadnika(radnik_t**);
void ispisRadnika(radnik_t*);
void otkaziRadnika(radnik_t**,int);
void urediRadnika(radnik_t**,int);
void bubbleSort(radnik_t*);
void zamjeni(radnik_t*,radnik_t*);
void upisiUFile(radnik_t*,char[]);
void pamtiID(radnik_t*);
void oslobodiMemoriju(radnik_t**);
void deserialise(radnik_t**);
void updateFile(radnik_t*);
void insert_end(radnik_t**, radnik_t);

#endif // HEADER_H_INCLUDED
