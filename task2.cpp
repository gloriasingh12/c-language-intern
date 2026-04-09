/* =================================================================
PROJECT: Singly Linked List Implementation
DESCRIPTION: Modular program for Insertion, Deletion, and Traversal.
DELIVERABLE: Efficient C code demonstrating dynamic data structures.
=================================================================
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a Node
struct Node {
    int data;
    struct Node* next;
};

// Function to Traverse and Print the Linked List
void display(struct Node* ptr) {
    printf("🔗 Linked List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Function to Insert at the Beginning
struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// Function to Delete a Node by Value
struct Node* deleteByValue(struct Node* head, int value) {
    struct Node *p = head;
    struct Node *q = head->next;
    
    // If head node itself holds the value to be deleted
    if (p->data == value) {
        head = head->next;
        free(p);
        return head;
    }

    // Search for the value to be deleted
    while (q != NULL && q->data != value) {
        p = p->next;
        q = q->next;
    }

    if (q != NULL) {
        p->next = q->next;
        free(q);
        printf("🗑️ Deleted %d from the list.\n", value);
    } else {
        printf("⚠️ Value %d not found in the list.\n", value);
    }
    return head;
}

int main() {
    struct Node* head = NULL;

    printf("🚀 Initializing Linked List Operations...\n\n");

    // 1. Insertion
    head = insertAtFirst(head, 10);
    head = insertAtFirst(head, 20);
    head = insertAtFirst(head, 30);
    head = insertAtFirst(head, 40);
    printf("✅ Nodes Inserted: 40, 30, 20, 10\n");

    // 2. Traversal
    display(head);

    // 3. Deletion
    head = deleteByValue(head, 20);
    
    // 4. Final Traversal
    display(head);

    printf("\n✅ Task 26 Complete: Linked List logic verified.\n");

    return 0;
}
