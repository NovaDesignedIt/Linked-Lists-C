
/*
* Title: Assignment 2 - Student Registration System
* w/ Linked List, Ansi-sytle
* Course: CST8234 - C Language
* Term: Summer 2020
*
* Team:
* Student #1: <<< Meech Lamirande lami0039 >>>
* Student #2: <<< Mohit Nargotra narg0001 >>>
* Status:
* Requirement #1: {complete}
* Requirement #2: {complete}
* Requirement #3: {complete}
* Requirement #4: {complete}
* Requirement #5: {complete}
* Requirement #6: {complete}
* Requirement #7: {complete}
* Requirement #8: {complete}
* Requirement #9: {complete}
* Requirement #10: {complete}
* Requirement #11: {complete}
*/
#include "Node.h"

#include <stdio.h>
#include <stdlib.h>
node_t *head;
int main() {

    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    head = NULL;
    //setting the head element
    head = (node_t *) malloc(sizeof(node_t));
    student_t *student = (student_t *) malloc(40 * sizeof(char *));
    if (head == NULL) {
        printf("couldn't not assigne memory");
        exit(1);
    }

    printf("\nFirst you will enter 3 student names that will be added to the start of the list\n");
    int i;
    for (i = 0; i < 3; i++) {
        addToStart(&head, student);
    }

    printList(head);// printlists
    printf("\nnow you will enter 3 names that will be added to the end of the list.\n");
    for (i = 0; i < 3; i++) {
        addToEnd(&head, student);
    }
    printList(head);// printlists
    printf("\nnow you will remove the first 3 in the list \n");
    removeFromStart(&head);
    removeFromStart(&head);
    removeFromStart(&head);

    printList(head);// printlists
    printf("\nnow you will remove the remaining 3 students");
    removeLast(&head);
    removeLast(&head);
    removeLast(&head);

    printf("\nby now your list should be empty!\n");
    printList(head);// printlists
    printf("\n\n ...\n");

    for (i = 0; i < 3; i++) {addToEnd(&head, student);}
    printList(head);// printlists

    printf("\n now you will remove the second element in the list\n\n");
    removeByIndex(&head, 1);

    printList(head);
    //printf("hook");-for debug
    free(head);
    free(student);
    return 0;
}




//********************* [ CODE GRAVEYARD ] *******************************//

//adding the first node
//    node_t * temp = malloc(sizeof(node_t));
//    temp = NULL;
//    temp->next=head->next;
//part2
/*
    i=1;
        //allocated the memory for
    while(i!=4) {
        head->student = (student_t *) malloc(40 * sizeof(char *));
        head->student->FirstName = (char *) malloc(20 * sizeof(char *));
        head->student->LastName = (char *) malloc(20 * sizeof(char *));
        char *firstname = malloc(20 * sizeof(char *));
        char *lastname = malloc(20 * sizeof(char *));
        int check;
        check = 1;
        while (check) {
            printf("Enter student first name %d:", i);
            scanf("%s", firstname);
            if (strlen(firstname) < 21) {
                check = 0;
            } else {
                printf("name to long\n");
            }
        }
        check = 1;
        while (check) {
            printf("Enter student last name %d:", i);
            scanf("%s", lastname);
            if (strlen(lastname) < 21) {
                check = 0;
            } else {
                printf("name too long\n");
            }
        }
        strcpy(head->student->FirstName, firstname);
        strcpy(head->student->LastName, lastname);
        //add to the end of the list
        addToEnd(&head->next,head->student);

        i++;
        free(firstname);
        free(lastname);
    }
    */
//old method main
//   printf("the size of a student %d",sizeof(struct student_t));
//    int i;
//    for(i=0; i<max-1;i++){
//        node[i].next = &node[i+1];
//    }
//    node[max-1].next = NULL;
//    //Set buffers
//    setvbuf(stdout, NULL, _IONBF,0);
//    setvbuf(stderr, NULL, _IONBF,0);
//    //head node is null
//    head =NULL;
//
//    //prompt
//    printf("please enter the first 3 students\n\n");
//
//
//    //allocating space for the structures
//    node_t * ptr_node = malloc(9*sizeof(node_t));
//    //if the pointer returns null the mem
//    if(ptr_node == NULL){
//        printf("cannot allocate memory\n");
//    }else {
//
//        //adding the students to the nodes
//        add_node(ptr_node);
//
//        //printing the students
//        int i = 0;
//        for (i = 0; i < 3; i++) {
//            printf("student full name: %s %s\n", ptr_node[i].student->FirstName, ptr_node[i].student->LastName);
//        }
//
//        //freeing allocated memory
//        for (i = 0; i < 3; i++) {
//            free(ptr_node[i].student);
//        }
//        free(ptr_node);
//    }

//
// hollup

//
//    node_t * NewNo = (node_t*) malloc(sizeof(head));
//    //allocating memory for the student pointer
//    NewNo->student = student;
//    //FirstName = (char *)malloc(sizeof(char*)*21);
//    //NewNo->student->LastName =(char *)malloc(sizeof(char*)*21);
//    NewNo->next=*head;
//    *head=NewNo;



