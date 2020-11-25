#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXkontakte 200
#define MAXName 25
#define MAXAdress 30
#define MAXHausnummer 3

typedef struct Geburtsdatum {
    int tag;
    int monat;
    int jahr;
} Tgeb;

typedef struct Adresse {
    char strasse[MAXAdress];
    char Hausnummer[MAXHausnummer];
    int PLZ;
    char Ort[MAXAdress];
} Tadresse;

typedef struct Kontakt {
    char vorname[MAXName];
    char nachnahme[MAXName];
    char spitzname[MAXName / 2];
    Tgeb geburtstag;
    Tadresse adresse;
} Tkontakt;

/**
 * Liest alle Daten zu einem Kontakt von der console ein
 * @author: Huber, Constantin und Ismael
 * @return
 * 
 * last change 24.11 von Ismael
 * new:Alle daten können eigelesen werden
 * last change 25.11 von Ismael
 * new: es können x beliebige Kontakte eingelesen werden
 */
Tkontakt Insert();

/**
 * @author Ismael
 * @param str  ein Datum im Format tt.mm.jjjj
 * @return ein gültiges Datum, wenn das Format falsch ist wird 00.00.0000 zurückgegeben
 * 
 */
Tgeb DateConvertFromString(char *str);


int main() {
    Tkontakt Kontake[MAXkontakte];
    short counter = -1;
    do {
        counter++;
        Kontake[counter] = Insert();
    } while (strcmp(Kontake[counter].vorname,"exit"));


    return 0;
}


Tkontakt Insert() {
    Tkontakt person;
    char scanner[MAXName * 2];

    printf("Vor- und Nachname:");
    gets(scanner);
    if (!strcmp(scanner, "exit")) {
        strcpy(person.vorname, strtok(scanner, " "));
        return person;
    }
    strcpy(person.vorname, strtok(scanner, " "));
    strcpy(person.nachnahme, strtok(NULL, " "));

    printf("Spitzname:");
    gets(person.spitzname);

    printf("Gebusrtsdatum (tt.mm.jjjj):");
    gets(scanner);
    person.geburtstag = DateConvertFromString(scanner);

    printf("Straße und Huasnummer");
    gets(scanner);
    strcpy(person.adresse.strasse, strtok(scanner, " "));
    strcpy(person.adresse.Hausnummer, strtok(NULL, " "));

    printf("PLZ:");
    gets(scanner);
    person.adresse.PLZ = atoi(scanner);

    printf("Ort:");
    gets(person.adresse.Ort);
    return person;
}

Tgeb DateConvertFromString(char *str) {
    Tgeb person;
    if (str[2] == '.' && str[5] == '.') {
        person.tag = atoi(strtok(str, "."));
        person.monat = atoi(strtok(NULL, "."));
        person.jahr = atoi(strtok(NULL, "."));
    } else {
        person.tag = 0;
        person.monat = 00;
        person.jahr = 0000;
    }


    return person;
}