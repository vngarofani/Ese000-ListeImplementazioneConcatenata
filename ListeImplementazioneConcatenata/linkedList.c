#include <stdlib.h>
#include ".\linkedList.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtBeginning(LLElement * first, int key) {
    LLElement*new;
    new=(LLElement *)malloc(sizeof(LLElement));
    if(new != NULL) {
        new->next=first;
        new->key=key;
        first=new;
    }
     // TODO To be implemented
    return NULL;
}

/*
 * Inserts the new key at the end of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtEnd(LLElement * first, int key) {
    LLElement * new;
    LLElement ** temp;
    new = (LLElement *)malloc(sizeof(LLElement));
    if(new != NULL) {
        temp = &first;
        while(*temp != NULL)
            temp = &((*temp)->next);
        new->next = NULL;
        new->key = key;
        *temp = new;
    // TODO To be implemented
    return NULL;
}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtPosition(LLElement * first, int key, int position) {
    LLElement * new;
    LLElement ** temp;
    int i;
    new = (LLElement *)malloc(sizeof(LLElement));
    if(new != NULL) {
        temp = &first;
        for(i=0; i<position; i++)
            temp = &((*temp)->next);
        new->next = *temp;
        new->key = key;
        *temp = new;
}
    // TODO To be implemented
    return NULL;
}

/*
 * Returns the size of the list.
 */
int LLSize(LLElement * first) {
    // TODO To be implemented
    return 0;
}   

/*
 * Returns the key at the specified position.
 */ 
int LLGetKey(LLElement * first, int position) {
    // TODO To be implemented
    return 0;
}

/*
 * Returns the position of the first element, starting from startPosition, that
 * has the specified key.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement * first, int key, int startPosition) {
    // TODO To be implemented
    return -1;
}

/*
 * Remove the first element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveFirst(LLElement * first) {
    // TODO To be implemented
    return NULL;
}

/*
 * Remove the last element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveLast(LLElement * first) {
    // TODO To be implemented
    return NULL;
}

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveAtPosition(LLElement * first, int position) {
    // TODO To be implemented
    return NULL;
}

/* Empties the list */
LLElement * LLEmptyList(LLElement *first) {
    // TODO To be implemented
    return NULL;
}