#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//reference https://www.youtube.com/watch?v=YjxKYxpf51E&t=104

typedef struct Node
{
    int value;
    struct None *next;
} Node;

typedef struct 
{
    Node *head;
    Node *tail;
    int size;
} Queue;

Queue *create_queue();
int size(Queue *queue);
bool is_empty(Queue *queue);
int peek (Queue *queue, bool *status);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue, bool *status);
void destroy_queue(Queue *queue);

int main()
{
    return 0;
}

Queue *create_queue()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}
int size(Queue *queue)
{
    return queue -> size;
}
bool is_empty(Queue *queue)
{
    return (queue->size == 0);
}
int peek (Queue *queue, bool *status)
{
    if (is_empty(queue))
    {
        *status = false;
    }
    *status = true;
    return queue->head->value;
}
void enqueue(Queue *queue, int value)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    //TBC
}
int dequeue(Queue *queue, bool *status)
void destroy_queue(Queue *queue)
