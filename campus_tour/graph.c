#include <campus.h>

AdjGraph *adj_graph_init(){
  //initialize
  int pathNum = edgeNum();
  AdjGraph *g = (AdjGraph *)malloc(sizeof(AdjGraph));
  if (g == NULL) {
    printf("Memory allocation failed for graph.\n");
    return NULL;
  }

  g->V = vertexNum();
  g->array = (AdjList *)malloc(sizeof(AdjList) * g->V);
  if (g->array == NULL) {
    printf("Memory allocation failed for adjacency list array.\n");
    free(g);
    return NULL;
  }

  for (int i = 0; i < g->V; i++) {
    g->array[i].adj_v = -1;
    g->array[i].head = NULL;
  }
  //fill the adjacency list
  for(int i = 0; i < pathNum; i++){
    unsigned int j = paths[i].a;
    g->array[j].adj_v = j;
    if(g->array[j].head == NULL){
      g->array[j].head = (AdjListNode *)malloc(sizeof(AdjListNode));
      g->array[j].head->dest = paths[i].b;
      g->array[j].head->weight = paths[i].len;
      g->array[j].head->next = NULL;
    }else{
      AdjListNode *p = g->array[j].head;
      while(p->next != NULL){
        p = p->next;
      }
      p->next = (AdjListNode *)malloc(sizeof(AdjListNode));
      p->next->dest = paths[i].b;
      p->next->weight = paths[i].len;
      p->next->next =NULL;
    }
  }
  //print the adjacency list
  printf("[DEBUG]");
  printf("\nAdjacency Gragh list:\n");
  for(int i = 0; i < g->V; i++){
    AdjListNode *p = g->array[i].head;
    printf("vertex %d: ", i);
    while(p != NULL){
      printf("(%d, %d) ", p->dest, p->weight);
      p = p->next;
    }
    printf("\n");
  }
  return g;
}