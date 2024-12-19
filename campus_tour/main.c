#include <campus.h>
/*
设计并实现一个校园导游程序，为来访的客人提供各种信息查询服务，具体包括：
（1）设计校园平面图，其中所含景点不少于10个。以图中顶点表示校内各景点，存放景点名称、代号、简介等信息：以边表示路径，存放路径长度等相关信息；
（2）为来访客人提供图中任意景点相关信息的查询；
（3）为来访客人提供途中任意景点的问路查询，即查询任意两个景点之间的一条最短的简单路径
*/
void information()
{
  printf("Please enter the name of the location you want to query:\n");
  printf(">");
  int num;
  scanf("%d", &num);
  printf("The information of %d is: name = %s\n", num, locations[num].name);
  printf("Description:\n %s\n", locations[num].description);
}
int main()
{
  int choice;
  AdjGraph *g = adj_graph_init();
  printf("GRAPH: \n");
  int vnum = vertexNum();
  for (int i = 0; i < vnum; i++)
  {
    printf("no:%d %s (%s)\n", locations[i].no,locations[i].name, locations[i].description); 
  }
  while (1){
  printf("\nThis is a campus tour system.\n");
  printf("Please select a function:\n");
  printf("1. Query information of a location\n");
  printf("2. Query the shortest path between two locations\n");
  printf("3. Exit\n");
  printf(">");
  scanf("%d", &choice);
  switch (choice)
  {
    case 1:
      information();
      break;
    case 2:
      printf("Please enter the number of the two locations you want to query:\n");
      printf(">");
      int a, b;
      scanf("%d %d", &a, &b);
      int pathlen = 0;
      int pathsz = 0;
      Path *sp = dijkstra(a, b, g, &pathlen, &pathsz);
      if(sp == NULL){
        printf("No path found\n");
        break;
      }
      printf("The shortest path between %s and %s is:\n", locations[a].name, locations[b].name);
      for (int i = pathsz - 1; i >= 0; i--)
      {
        printf("%s -> %s distence = %d\n", locations[sp[i].a].name, locations[sp[i].b].name, sp[i].len);
      }
      printf("The total length of the path is %d\n", pathlen);
      break;
    case 3:
      exit(0);
    default:
      printf("Invalid choice\n");
  }
  }
}