#ifndef CAMPUS_H
#define CAMPUS_H

#include <common.h>
#include <utils.h>
#include <adj.h>

typedef struct {
  int no;
  char *name;
  char *description;
} Location;

typedef struct {
  int a;
  int b;
  int len;
} Path;

extern Location locations[];
int vertexNum();
extern Path paths[];
int edgeNum();

AdjGraph *adj_graph_init();
Path *dijkstra(int start, int end, AdjGraph *graph, int *pathlen, int *pathsz);

#endif
