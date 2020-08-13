/*
 * Node.h
 */

#ifndef NODE_H_
#define NODE_H_

// TODO: add typedef for a Student struct
// TODO: add typedef for a Node struct
typedef struct Student{
    char *FirstName;
    char *LastName;
}student_t;

typedef struct Node{
    student_t * student;
    struct Node *next;
}node_t;



/*
 Adds a new node to the end of the list
 */
void addToEnd(node_t **head, student_t *student);

/*
 Adds a new node to the beginning of the list
 */
void addToStart(node_t **head, student_t *student);

/*
 Prints all student names in the following format: lastName, firstName
 */
void printList(node_t *head);

/*
 Removes a node by index
 */
void removeByIndex(node_t **head, int n);

/*
 Removes the last node in the list
 */
void removeLast(node_t **head);

/*
 Remove the first node in the list
 */
void removeFromStart(node_t **head);

#endif /* NODE_H_ */
