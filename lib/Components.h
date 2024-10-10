#ifndef _COMPONENTS_H_
#define _COMPONENTS_H_

int option = 1;
typedef struct {
    double r;
    double g;
    double b;
} Color;
typedef struct {
    char* name;
    double min_y;
    double max_y;
} Opt;
typedef struct {
    char* title;
    Opt* opts;
} Menu;
#endif