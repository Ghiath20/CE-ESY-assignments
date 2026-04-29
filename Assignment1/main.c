#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20

typedef struct {
    char buffer[MAX_SIZE];
    int head;
    int tail;
    int itemCount;
} RingBuffer;

void initialize(RingBuffer *rb) {
    rb->head = 0;
    rb->tail = 0;
    rb->itemCount = 0;
}

int isBufferEmpty(const RingBuffer *rb) {
    return rb->itemCount == 0;
}

int isBufferFull(const RingBuffer *rb) {
    return rb->itemCount == MAX_SIZE;
}

void insert(RingBuffer *rb, char element) {
    if (isBufferFull(rb)) {
        printf("Overflow\n");
        return;
    }
    rb->buffer[rb->tail] = element;
    rb->tail = (rb->tail + 1) % MAX_SIZE;
    rb->itemCount++;
}

char removeElement(RingBuffer *rb) {
    if (isBufferEmpty(rb)) {
        printf("Underflow\n");
        return '\0';
    }
    char element = rb->buffer[rb->head];
    rb->head = (rb->head + 1) % MAX_SIZE;
    rb->itemCount--;
    return element;
}

int main() {

    RingBuffer rb;
    initialize(&rb);

    char userName[50];
    printf("Enter your name: ");
    scanf("%49s", userName);
    strcat(userName, "CE-ESY");

    for (int i = 0; i < (int)strlen(userName); i++) {
        insert(&rb, userName[i]);
    }

    while (!isBufferEmpty(&rb)) {
        char extractedChar = removeElement(&rb);
        printf("%c", extractedChar);
    }
 
    return 0;
}
