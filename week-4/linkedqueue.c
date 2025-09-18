#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

// Function declarations
void create_queue(struct queue *);
struct queue *insert(struct queue *, int);
struct queue *delete_element(struct queue *);
int peek(struct queue *);
struct queue *display(struct queue *);

int main() {
    int val, option;
    struct queue *q;

    // Allocate memory for the queue
    q = (struct queue *)malloc(sizeof(struct queue));
    create_queue(q);

    do {
        printf("\n****** MAIN MENU ******");
        printf("\n1. INSERT");
        printf("\n2. DELETE");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the number to insert in the queue: ");
                scanf("%d", &val);
                q = insert(q, val);
                break;
            case 2:
                q = delete_element(q);
                break;
            case 3:
                val = peek(q);
                if (val != -1)
                    printf("The value at the front of the queue is: %d\n", val);
                break;
            case 4:
                q = display(q);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != 5);

    return 0;
}

void create_queue(struct queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

struct queue *insert(struct queue *q, int val) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return q;
    }

    ptr->data = val;
    ptr->next = NULL;

    if (q->rear == NULL) {
        // Queue is empty
        q->front = q->rear = ptr;
    } else {
        q->rear->next = ptr;
        q->rear = ptr;
    }

    return q;
}

struct queue *delete_element(struct queue *q) {
    struct node *ptr;

    if (q->front == NULL) {
        printf("UNDERFLOW: Queue is empty\n");
        return q;
    }

    ptr = q->front;
    printf("The value being deleted is: %d\n", ptr->data);
    q->front = q->front->next;

    if (q->front == NULL) {
        // Queue has become empty
        q->rear = NULL;
    }

    free(ptr);
    return q;
}

int peek(struct queue *q) {
    if (q->front == NULL) {
        printf("QUEUE IS EMPTY\n");
        return -1;
    }
    return q->front->data;
}

struct queue *display(struct queue *q) {
    struct node *ptr = q->front;
    if (ptr == NULL) {
        printf("QUEUE IS EMPTY\n");
        return q;
    }

    printf("Queue: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return q;
}


