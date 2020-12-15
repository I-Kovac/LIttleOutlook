#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXkontakte 200
#define MAXName 25
#define MAXAdress 30
#define MAXHausnummer 3
#define TRUE 1
#define FALSE 0
#define MEN_NEW_CONTACT 1
#define MEN_MORE_NEW_CONTACTS 2
#define MEN_DEL_CONTACT 3
#define MEN_EDIT_CONTACT 4
#define MEN_SHOW_CONTACT 5
#define MEN_SHOW_ALL_CONTACTS 6
#define MEN_SEARCH_COTACT 7
#define MEN_NEXT_BIRTHDAY 8
#define MEN_ALL_MONTH_BIRTHDAYS 9

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
    char nachname[MAXName];
    char spitzname[MAXName / 2];
    Tgeb geburtstag;
    Tadresse adresse;
    char email[MAXAdress];
    char telefon[MAXAdress];
} Tkontakt;

/**
 * Menü in dem man die Funktion die man ausführen will auswählen kann.
 * @return... Auswahl der Funktion
 */
int Menu();

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
 * @author Constantin
 * @param Der zu löschende Kontakt
 */
void del(Tkontakt *pkontakt);

/**
 * @author Ismael
 * @param str  ein Datum im Format tt.mm.jjjj
 * @return ein gültiges Datum, wenn das Format falsch ist wird 00.00.0000 zurückgegeben
 *
 */
Tgeb DateConvertFromString(char *str);

int main() {
    Tkontakt kontakte[MAXkontakte];
    int auswahl;
    int ende = FALSE;
    int counterinsert = 0;
    int hobn = FALSE;
    int counter=0;

    do {
        auswahl = Menu();
        if (auswahl == 0) {
            ende = TRUE;
        } else if (auswahl == MEN_NEW_CONTACT) {
           kontakte[counterinsert] = Insert();
            counterinsert++;
        } else if (auswahl == MEN_MORE_NEW_CONTACTS) {
            printf("Sie können nun so viele Kontakte wie Sie wollen einlesen. Um die Eingabe zu stoppen bitte \"exit\"\n"
                   "als Vornamen eingeben!\n");
            do{
                kontakte[counterinsert] = Insert();
                counterinsert++;
            }while(strcmp(kontakte[counterinsert-1].vorname, "exit") != 0);
            counterinsert--;
        } else if (auswahl == MEN_DEL_CONTACT) {
            printf("Welchen Kontakt möchten Sie löschen");
            scanf(" %s", kontakte->vorname);
            scanf(" %s", kontakte->nachname);
            while (hobn == FALSE) {
                if ((strcmp(kontakte[counter].vorname, kontakte->vorname) == FALSE) &&
                    (strcmp(kontakte[counter].nachname, kontakte->nachname) == FALSE)) {
                    hobn = TRUE;
                } else {
                    counter++;
                }
                del(&kontakte[counter]);
            }

        } else if (auswahl == MEN_EDIT_CONTACT) {

        } else if (auswahl == MEN_SHOW_CONTACT) {

        } else if (auswahl == MEN_SHOW_ALL_CONTACTS) {

        } else if (auswahl == MEN_SEARCH_COTACT) {

        } else if (auswahl == MEN_NEXT_BIRTHDAY) {

        } else if (auswahl == MEN_ALL_MONTH_BIRTHDAYS) {

        }
    } while (ende != TRUE);

    return 0;
}

int Menu() {
    int auswahl;

    do {
        printf("Willkommen zu LittleOutlook!\n"
               "Wählen Sie aus:\n"
               "[0]Beenden\n"
               "[%d]Kontakt erstellen\n"
               "[%d]Mehrere Kontakte erstellen\n"
               "[%d]Kontakt löschen\n"
               "[%d]Kontakt bearbeiten\n"
               "[%d]Kontakt anzeigen\n"
               "[%d]Alle Kontakte anzeigen\n"
               "[%d]Kontakt suchen\n"
               "[%d]Den nächsten Geburtstag ausgeben\n"
               "[%d]Alle Geburtstage in einem Monat ausgeben\n", MEN_NEW_CONTACT, MEN_MORE_NEW_CONTACTS, MEN_DEL_CONTACT,
               MEN_EDIT_CONTACT, MEN_SHOW_CONTACT, MEN_SHOW_ALL_CONTACTS, MEN_SEARCH_COTACT, MEN_NEXT_BIRTHDAY, MEN_ALL_MONTH_BIRTHDAYS);

        printf("\nAuswahl: ");
        scanf("%d", &auswahl);

    } while (auswahl < 0 || auswahl > 9);

    return auswahl;
}

Tkontakt Insert() {
    Tkontakt person;
    char scanner[MAXName * 2];
    printf("Vorname: ");
    scanf(" %s", person.vorname);
    if (!strcmp(person.vorname, "exit")) {
        return person;
    }
    printf("Nachname: ");
    scanf(" %s", person.nachname);
    printf("Spitzname: ");
    scanf(" %s", person.spitzname);
    printf("Gebusrtsdatum (tt.mm.jjjj): ");
    scanf(" %s", scanner);
    person.geburtstag = DateConvertFromString(scanner);
    printf("Straße: ");
    scanf(" %s", person.adresse.strasse);
    printf("Hausnummer: ");
    scanf(" %s", person.adresse.Hausnummer);
    printf("PLZ:");
    scanf("%d", &person.adresse.PLZ);

    printf("Ort: ");
    scanf(" %s", person.adresse.Ort);

    printf("E-Mail: ");
    scanf(" %s", person.email);

    printf("Telefon: ");
    scanf(" %s", person.telefon);
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

void del(Tkontakt *pkontakt) {
    strcpy(pkontakt->vorname, "0");
    strcpy(pkontakt->nachname, "0");
    strcpy(pkontakt->spitzname, "0");
    pkontakt->geburtstag.tag=0;
    pkontakt->geburtstag.monat=0;
    pkontakt->geburtstag.jahr=0;
    strcpy(pkontakt->adresse.strasse, "0");
    strcpy(pkontakt->adresse.Hausnummer, "0");
    pkontakt->adresse.PLZ=0;
    strcpy(pkontakt->adresse.Ort, "0");
    strcpy(pkontakt->email, "0");
    strcpy(pkontakt->telefon, "0");
}