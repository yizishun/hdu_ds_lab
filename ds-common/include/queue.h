
typedef struct queue{
    char *name;
    int size;
    int *queue;
    int head;
    int tail;
}Queue;

Queue *init_queue(int size, char *name);
void enqueue(Queue *q, int val);
int dequeue(Queue *q);