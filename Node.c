//
// Created by novac on 2020-08-05.
//
#ifndef NODE_C
#define NODE_C
#include "Node.h"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int i =0;

void printList(node_t *head) {
    node_t *current = head;

    printf("\nStudents\n");
    while (current->next != NULL) {
        //if head has data then print that data
        printf("\n%s\t%s", current->student->FirstName, current->student->LastName);
        current = current->next;
        // shift head by one forwad
        // so head =head.next | head.next is type of head
    }
}


void addToStart(node_t **headnode, student_t *student) {

    node_t *head_ = (node_t *) malloc(sizeof(node_t));
    head_->student = (student_t *) malloc(40 * sizeof(char *));
    head_->student->FirstName = (char *) malloc(20 * sizeof(char *));
    head_->student->LastName = (char *) malloc(20 * sizeof(char *));
    char *firstname = malloc(20 * sizeof(char *));
    char *lastname = malloc(20 * sizeof(char *));
    int check;

    check = 1;
    while (check) {

        printf("%s%d%s", "Please enter first name for student ", i+1, ":");
        scanf("%s", firstname);
        if (strlen(firstname) < 21) {
            check = 0;
        } else {
            printf("name to long\n");

        }
    }
    check = 1;
    while (check) {
        printf("%s%d%s", "Please enter Last name for student ", i+1, ":");
        scanf("%s", lastname);
        if (strlen(lastname) < 21) {
            check = 0;
        } else {
            printf("name too long\n");
        }
    }
    //copy the data feilds into my pointer
    strcpy(head_->student->FirstName, firstname);
    strcpy(head_->student->LastName, lastname);

    free(firstname);
    free(lastname);
    //pull ye ol switcheroo!
    head_->next = (*headnode);
    (*headnode) = head_;
    i++;
    if(i==3){
        i=0;
    }
}

void addToEnd(node_t **head, student_t *student) {
    node_t *tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = (node_t *) malloc(sizeof(head));
    tail->student = (student_t *) malloc(40 * sizeof(char *));
    tail->student->FirstName = (char *) malloc(20 * sizeof(char *));
    tail->student->LastName = (char *) malloc(20 * sizeof(char *));
    char *firstname = malloc(20 * sizeof(char *));
    char *lastname = malloc(20 * sizeof(char *));
    int check;
    check = 1;
    while (check) {
        printf("%s%d%s", "Please enter first name for student ", i+1, ":");
        scanf("%s", firstname);
        if (strlen(firstname) < 21) {
            check = 0;
        } else {
            printf("name to long\n");
        }
    }
    check = 1;
    while (check) {
        printf("%s%d%s", "Please enter last name for student ", i+1, ":");
        scanf("%s", lastname);
        if (strlen(lastname) < 21) {
            check = 0;
        } else {
            printf("name too long\n");
        }
    }

    strcpy(tail->student->FirstName, firstname);
    strcpy(tail->student->LastName, lastname);

    free(firstname);
    free(lastname);
    tail->next->next = NULL;

    i++;
    if(i==3){
        i=0;
    }

}

void removeFromStart(node_t **head) {
    node_t *doomed;
    if (head == NULL) {
        printf("List is already empty");
    }
    doomed = (*head);
    (*head) = (*head)->next;
    free(doomed);
}

void removeLast(node_t **head) {
    node_t *current = (*head);

    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void removeByIndex(node_t **head, int position) {

    if ((*head) == NULL)
        return;

    node_t *node = (*head);
    if (position == 0) {
        (*head) = node->next;
        free(node);
        return;
    }
    int j;
    for (j = 0; node != NULL && j < position - 1; j++) {
        node = node->next;
    }
    if (node == NULL || node->next == NULL)
        return;

    node_t *next = node->next->next;
    free(node->next);

    node->next = next;

}

#endif //NODE_C