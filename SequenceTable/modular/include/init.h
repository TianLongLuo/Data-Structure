#ifndef INIT_H
#define INIT_H

#define Size 5

typedef struct Table
{
    int* head;
    int length;
    int size;
}table;

extern table initTable();
extern void displayTable(table t);

#endif