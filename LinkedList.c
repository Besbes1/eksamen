#include<stdio.h>
#include<stdlib.h>

// Define the Node structure
typedef struct Node {
    int data; // Integer data
    struct Node *next; // Pointer to the next node
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }
    newNode->data = data; // Assign data
    newNode->next = NULL; // Initialize next pointer to NULL

    return newNode; // Return the new node
}

// Function to append a node to the end of the list
struct Node* appendNode(struct Node* head, int data) {
    // If the list is empty, create a new node and return it as the head
    if(head == NULL) {
        return createNode(data);
    }
    // Traverse to the end of the list
    struct Node* cursor = head;
    while(cursor->next != NULL) {
        cursor = cursor->next;
    }
    // Add a new node at the end
    cursor->next = createNode(data);

    return head; // Return the head of the list
}

// Function to remove a node with given data from the list
struct Node* removeNode(struct Node* head, int data) {
    struct Node *cursor, *prev;
    cursor = head;
    // Traverse the list
    while(cursor != NULL) {
        // If the node to be removed is found
        if(cursor->data == data) {
            // If the node is the head node
            if(cursor == head) {
                head = head->next; // Change the head
                free(cursor); // Free the old head
                return head;
            } else {
                // Bypass the node
                prev->next = cursor->next;
                free(cursor);
                return head;
            }
        } else {
            // Keep moving if the current node is not the target
            prev = cursor;
            cursor = cursor->next;
        }
    }
    return head; // Return the head of the list
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* cursor = head;
    // Traverse the list
    while(cursor != NULL) {
        printf("%d ", cursor->data); // Print data
        cursor = cursor->next;
    }
    printf("\n");
}

// Function to replace the content of a node given its position
struct Node* replaceNode(struct Node* head, int position, int new_data) {
    // If the list is empty, return NULL
    if(head == NULL) {
        printf("Error: The list is empty.\n");
        return NULL;
    }
    struct Node* cursor = head;
    int pos = 1;
    // Traverse the list until the position is reached or the list ends
    while(cursor != NULL && pos != position) {
        cursor = cursor->next;
        pos++;
    }
    // If the list ended before the position was reached
    if(cursor == NULL) {
        printf("Error: Position out of range.\n");
        return head;
    }
    // Replace the data of the node
    cursor->data = new_data;
    return head;
}

int main() {
    struct Node* head = NULL;

    // Test functions here.
    head = appendNode(head, 1); // Add 1 to the list
    head = appendNode(head, 2); // Add 2 to the list
    head = appendNode(head, 3); // Add 3 to the list
    printList(head); // Print the list

    head = replaceNode(head, 1, 5); // Replace the 2nd node's data with 5
    printList(head); // Print the list again

    head = removeNode(head, 2); // Remove 1 from the list
    printList(head); // Print the list again

    return 0;
}

