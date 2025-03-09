/*BUGA Bianca Gabriela - 311CD*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "lists/deque.h"
#include "lists/queue.h"

/**
 * Macro pentru a verifica valoarea de adevar si afisa un mesaj in caz de eroare.
 * @param assertion conditie de evaluat; daca este adevarata, afiseaza eroarea si iese.
 * @param call_description descrierea apelului care a cauzat eroarea.
 */
#define DIE(assertion, call_description)                \
    do {                                                \
        if (assertion) {                                \
            fprintf(stderr, "(%s, %d): ",               \
                    __FILE__, __LINE__);                \
            perror(call_description);                   \
            exit(errno);                                \
        }                                               \
    } while (0)

// UPDATE

/**
 * Structura care reprezinta trenul si contine pointeri catre locomotiva(nodul santinela)
 * si pozitia curenta a mecanicului.
 */
typedef struct train {
    deq_n *engine;    ///< Pointer catre nodul santinela care reprezinta locomotiva.
    deq_n *mechanic;  ///< Pointer catre pozitia curenta a mecanicului.
} train_t;

/**
 * Initializeaza o structura de tip tren.
 * @return Initializeaza structura de tip tren cu locomotiva si mecanic..
 */
train_t init_train();

/**
 * Muta mecanicul cu o pozitie la dreapta.
 * @param train Pointer catre structura de tip tren.
 */
void move_right(train_t *train);

/**
 * Muta mecanicul cu o pozitie la stanga
 * @param train Pointer la structura de tip tren.
 */
void move_left(train_t *train);

/**
 * Scrie sau suprascrie valoarea nodului in care se afla mecanicul.
 * @param train Pointer la tren.
 * @param inscription Caracterul pe care il scriem pe nodul curent.
 */
void write(train_t *train, char inscription);

/**
 * Insereaza un vagon nou in dreapta pozitiei curente a mecanicului si muta mecanicul la acesta.
 * @param train Pointer la tren.
 * @param inscription Caracterul de scris in noul vagon.
 */
void insert_right(train_t *train, char inscription);

/**
 * Introduce un vagon nou la stanga pozitiei curente a mecanicului.
 * Daca mecanicul se afla in primul vagon, va afisa o eroare.
 * @param train Pointer la tren.
 * @param inscription Caracterul de scris in noul vagon
 * @param output File pointer la fisier pentru a scrie output-ul
 */
void insert_left(train_t *train, char inscription, FILE *output);

/**
 * Sterge toate vagoanele, trenul revenind la starea initiala, doar cu locomotiva.
 * @param train Pointer la tren.
 */
void clear_all(train_t *train);

/**
 * Sterge valoarea din vagonul in care se afla mecanicul si elimina vagonul din tren.
 * @param train Pointer la tren.
 */
void clear_cell(train_t *train);

// SEARCH

/**
 * Cauta un sir de caractere incepend de la dreapta pozitiei mecanicului.
 * @param pattern Sirul de caractere pe care il cauta.
 * @param train Pointer la tren.
 * @param output Pointer la fisier pentru a afisa outputul.
 */
void search(char *pattern, train_t *train, FILE *output);

/**
 * Cauta un sir de caractere incepend de la dreapta pozitiei mecanicului.
 * @param pattern Sirul de caractere pe care il cauta
 * @param train Pointer la structura.
 * @param output Pointer la fisier pentru a afisa outputul.
 */
void search_right(char *pattern, train_t *train, FILE *output);

/**
 * Cauta un sir de caractere incepand de la stanga pozitiei mecanicului.
 * @param pattern Sirul de caractere pe care il cauta
 * @param train Pointer la structura.
 * @param output Pointer la fisier pentru a afisa outputul.
 */
void search_left(char *pattern, train_t *train, FILE *output);

// QUERY

/**
 * Afiseaza continutul trenului, marcand pozitia mecanicului.
 * @param train  Pointer la structura.
 * @param output Pointer la fisier pentru a afisa outputul.
 */
void show(train_t *train, FILE *output);

/**
 * Arata valoarea din vagonul in care se afla mecanicul la momentul curent.
 * @param train Pointer la tren.
 * @param output Pointer la fisier pentru a afisa outputul.
 */
void show_current(train_t *train, FILE *output);

// EXECUTE + SWITCH LOGIC

/**
 * Schimba ordinea comenzilor in coada, facand ca ultima comanda sa fie prima executata in continuare.
 * @param commands Coada de comenzi care va fi modificata.
 */
void switchQ(queue_t *commands);

/**
 * Executa urmatoarea comanda din coada.
 * @param commands Coada care contine comenzile
 * @param train Pointer la structura.
 * @param output Pointer la fisier pentru a afisa outputul comenzii.
 */
void execute(queue_t *commands, train_t *train, FILE *output);

/**
 * Ruleaza comanda pe baza intrarii , realizand executia comenzii sau adaugarea in coada.
 * @param command Comanda care trebuie executata.
 * @param commands Coada de comenzi.
 * @param train Pointer la structura.
 * @param output Pointer la fisier pentru a afisa outputul comenzii.
 */
void manage(char *command, queue_t *commands, train_t *train, FILE *output);

/**
 * Proceseaza si executa toate comenzile din coada pentru structura data.
 * Aceasta functie itereaza peste coada de comenzi, executand fiecare comanda pe rand
 * pana cand coada este goala. Se ocupa de logica de executie determinand tipul
 * fiecarei comenzi si apeland functia corespunzatoare care sa efectueze operatiunea 
 * pe structura trenului. De asemenea se ocupa de scrierea outputului in fisierul
 * specificat, cum ar fi rezultatul unei comenzi show sau mesaje de eroare
 * 
 *
 * @param commands Pointer la coada de comenzi care urmeaza sa fie executate. Aceasta coada
 *                 contine toate comenzile adaugate inainte de a apela functia.
 * @param train Pointer la structura pe care vor fi executate comenzile.
 *               Operatiile includ mutarea mecanicului, modificarea vagoanelor sau actualizarea
 *               structurii trenului conform comenzilor
 * @param output Pointer catre fisierul pentru in care va fi scris outputul(e.g., starea curenta a trenului, rezultate pentru search)
 *               Aceste lucru permite functiei sa afiseze direct rezultatele sau sa raporteze mesaje de eroare
 *               de la operatiuni nereusite.
 *              
 */
void run(queue_t *commands, train_t *train, FILE *output);


