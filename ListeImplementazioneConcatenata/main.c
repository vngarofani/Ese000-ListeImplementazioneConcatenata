/* 
 * File:   main.c
 * Author: f.trotta
 *
 * Created on 28 dicembre 2014, 14.50
 */

#include <stdio.h>
#include <stdlib.h>

#include ".\linkedList.h"

#define ERRORMESSAGE_MAXLEN 100

void assertSize(int code, LLElement * first, int expectedSize);
void assertKey(int code, LLElement * first, int position, int expectedKey);
void assertPosition(int code, LLElement * first, int key, int startPosition, int expectedPosition);
void printAndExit(int code, char message[]);

/*
 * 
 */
int main(int argc, char** argv) {
    
    LLElement * list=NULL;
    int i;
    
    assertSize(10, list, 0);
    
    // Operazioni 20
    list = LLInsertAtBeginning(list, 100);
    list = LLInsertAtBeginning(list, 200);
    list = LLInsertAtBeginning(list, 300);
    
    assertSize(20, list, 3);
    assertKey(21, list, 0, 300);
    assertKey(22, list, 0, 300);
    assertKey(23, list, 1, 200);
    assertKey(24, list, 2, 100);
    assertKey(25, list, 0, 300);
    
    // Operazioni 30
    list = LLRemoveFirst(list);
    
    assertSize(30, list, 2);
    assertKey(31, list, 0, 200);
    assertKey(32, list, 1, 100);
    
    // Operazioni 40
    list = LLRemoveLast(list);
        
    assertSize(40, list, 1);
    assertKey(41, list, 0, 200);
    
    // Operazioni 50
    for(i=0; i<5; i++) {
        list = LLInsertAtEnd(list, i*1000);
    }
    
    assertSize(50, list, 6);
    assertKey(51, list, 0, 200);
    for(i=0; i<5; i++) {
        assertKey(52, list, 1+i, i*1000);
    }
    
    // Operazioni 60
    list = LLRemoveAtPosition(list, 1);
    
    assertSize(60, list, 5);
    assertKey(61, list, 0, 200);
    for(i=1; i<5; i++) {
        assertKey(62, list, i, i*1000);
    }
    
    // Operazioni 70
    list = LLInsertAtPosition(list, 3, 10000);
    
    assertSize(70, list, 6);
    assertKey(71, list, 3, 10000);
    
    // Operazioni 80
    list = LLInsertAtEnd(list, 10000);
    assertSize(80, list, 7);
    assertKey(81, list, 3, 10000);
    assertKey(82, list, 6, 10000);
    assertPosition(83, list, 10000, 0, 3);
    assertPosition(84, list, 10000, 4, 6);
    
    // Operazioni 90
    list = LLEmptyList(list);   // always free the memory when the list is not
                                // needed anymore
    assertSize(90, list, 0);

    return (EXIT_SUCCESS);
}

void assertSize(int code, LLElement * first, int expectedSize) {
    int currentSize = LLSize(first);
    char message[ERRORMESSAGE_MAXLEN];
    if(currentSize != expectedSize) {
        sprintf(message, "Dimensione attesa: %d - Dimensione corrente: %d\n", expectedSize, currentSize);
        printAndExit(code, message);
    }
    return;
}


void assertKey(int code, LLElement * first, int position, int expectedKey) {
    int currentKey;    
    char message[ERRORMESSAGE_MAXLEN];
    currentKey = LLGetKey(first, position);
    if(expectedKey != currentKey) {
        sprintf(message, "Posizione %d. Valore atteso: %d - Valore corrente: %d\n", position, expectedKey, currentKey);
        printAndExit(code, message);
    }
}

void assertPosition(int code, LLElement * first, int key, int startPosition, int expectedPosition) {
    int currentPosition;    
    char message[ERRORMESSAGE_MAXLEN];
    currentPosition = LLFindKey(first, key, startPosition);
    if(expectedPosition != currentPosition) {
        sprintf(message, "Ricerca valore %d da posizione %d. Posizione attesa: %d - Posizione corrente: %d\n", 
                key, 
                startPosition, 
                expectedPosition, 
                currentPosition);
        printAndExit(code, message);
    }
}


void printAndExit(int code, char message[]) {
    fprintf(stderr, "Asserzione %d fallita. %s", code, message);
    exit(code);
}

