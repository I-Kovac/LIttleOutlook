#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXkontakte 200
#define MAXName 25
#define MAXAdress 30
#define MAXHausnummer 3
#define MAXPlz 3

typedef struct Geburtsdatum {
    int tag;
    int monat;
    int jahr;     // hier unbedingt mit int arbeiten sonst wird vergleichen schwierig
} Tgeb;

typedef struct Adresse {
    char strasse[MAXAdress];
    char Hausnummer[MAXHausnummer];
    char PLZ[MAXPlz];
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
 * new:Name Vorname Spitzname und Geburtsdatum wird richtig eingelesesn
 * last change 25.11 von Huber
 * ZACK ZARAP
 */
Tkontakt Insert();

/**
 * @author Ismael
 * @param str  ein Datum im Format tt.mm.jjjj
 * @return ein gültiges Datum, wenn das Format falsch ist wird 00.00.0000 zurückgegeben
 * 
 */
Tgeb DateConvertFromString(char *str);

/**
 * lol
 * @param str Ein langer String, bestehend aus Straße, hausnummer, PLZ, Ort
 * @return Adresse einer Person aufgeteilt in Straße Hausnummer PLZ Ort
 */
Tadresse AdressConvertFromString(char *str);

int main() {
    Tkontakt Kontake[MAXkontakte];
    printf("");

    Insert();

    return 0;
}


Tkontakt Insert() {
    Tkontakt person;
    char scanner[MAXName * 2];
    char speicher[MAXName];

    printf("Vor- und Nachname:");
    gets(scanner);
    strcpy(person.vorname, strtok(scanner, " "));
    strcpy(person.nachnahme, &scanner[strlen(person.vorname) + 1]);

    printf("Spitzname:");
    gets(person.spitzname);

    printf("Gebusrtsdatum (tt.mm.jjjj):");
    gets(scanner);
    person.geburtstag = DateConvertFromString(scanner);

    printf("Adresse");
    gets(scanner);

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