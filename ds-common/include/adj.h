#ifndef ADJ_H
#define ADJ_H

typedef struct AdjListNode {
  int dest;
  int weight;
  struct AdjListNode *next;
} AdjListNode;

typedef struct {
  int adj_v;
  AdjListNode *head;
} AdjList;

typedef struct {
  int V;
  AdjList *array;
} AdjGraph;

#endif