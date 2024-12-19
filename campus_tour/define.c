#include <campus.h>

Location locations[] = {
        {0, "Gate", "Main gate in HDU"},          // Gate -> 0
        {1, "Library", "Library in HDU"},         // Library -> 1
        {2, "Sports", "Sports in HDU"},           // Sports -> 2
        {3, "Science", "Science in HDU"},         // Science -> 3
        {4, "Auditorium", "Auditorium in HDU"},   // Auditorium -> 4
        {5, "Canteen", "Canteen in HDU"},         // Canteen -> 5
        {6, "Cafeteria", "Cafeteria in HDU"},     // Cafeteria -> 6
        {7, "Dormitory", "Dormitory in HDU"},     // Dormitory -> 7
        {8, "Sports2", "Sports2 in HDU"},         // Sports2 -> 8
        {9, "Science2", "Science2 in HDU"},       // Science2 -> 9
    };

    // 修改后的路径数组，从0开始
Path paths[] = {
        {0, 1, 200},  // Gate -> Library
        {0, 2, 150},  // Gate -> Sports
        {1, 3, 300},  // Library -> Science
        {1, 4, 400},  // Library -> Auditorium
        {2, 5, 250},  // Sports -> Canteen
        {2, 6, 350},  // Sports -> Cafeteria
        {3, 7, 200},  // Science -> Dormitory
        {4, 8, 500},  // Auditorium -> Sports2
        {5, 9, 300},  // Canteen -> Science2
        {6, 7, 150},  // Cafeteria -> Dormitory
        {7, 8, 400},  // Dormitory -> Sports2
        {8, 9, 250},  // Sports2 -> Science2
    };

int edgeNum()
{
  return sizeof(paths)/sizeof(paths[0]);
}

int vertexNum()
{
  return sizeof(locations)/sizeof(locations[0]);
}
