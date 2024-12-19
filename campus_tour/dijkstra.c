#include <campus.h>
#define INF 9999

typedef struct {
  int value;
  int parent;
  int parent_value;
  int frozen;
} Node;

int extract_min(AdjGraph *graph, Node *d);
Path *dijkstra(int start, int end, AdjGraph *graph, int *pathlen, int *pathsz)
{
  Path *sp;
  Node *d = malloc(sizeof(Node) * graph->V);
  //init d
  d[start].value = 0;
  d[start].parent = -1;
  d[start].frozen = 0;
  for(int i = 0; i < graph->V; i++){
    if(i != start){
      d[i].value = INF;
      d[i].parent = -1;
      d[i].frozen = 0;
    }
  }
  //start!
  int ing;
  while((ing = extract_min(graph, d)) != -1){
    AdjListNode *p = graph->array[ing].head;
    while(p){
      int v = p->dest;
      int w = p->weight;
      if(d[v].frozen == 0 && d[v].value > d[ing].value + w){
        d[v].value = d[ing].value + w;
        d[v].parent = ing;
        d[v].parent_value = w;
      }
      p = p->next;
    }
    d[ing].frozen = 1;
  }
  if(d[end].parent == -1){
    #ifdef DEBUG
    printf("[DEBUG]:No such Path\n");
    #endif
    return NULL;
  }
  sp = malloc(sizeof(Path));
  int n = 1;
  #ifdef DEBUG
  printf("[DEBUG]:Path\n");
  #endif
  for(int i = end; i != start; i = d[i].parent){
    sp[n - 1].a = d[i].parent;
    sp[n - 1].b = i;
    sp[n - 1].len = d[i].parent_value;
    n++;
    sp = realloc(sp, sizeof(Path) * n);
    #ifdef DEBUG
    printf("[DEBUG]:%d\n", i);
    #endif
  }
  #ifdef DEBUG
  printf("[DEBUG]:distence = %d\n", d[end].value);
  printf("[DEBUG]:Path end\n");
  #endif
  *pathlen = d[end].value;
  *pathsz = n - 1;
  return sp;
}

int extract_min(AdjGraph *graph, Node *d)
{
  int min = INF;
  int min_index = -1;
  for(int i = 0; i < graph->V; i++){
    if(d[i].frozen == 0 && d[i].value < min){
      min = d[i].value;
      min_index = i;
    }
  }
  #ifdef DEBUG
  printf("[DEBUG]:find min %d, index %d\n", min, min_index);
  #endif
  return min_index;
}