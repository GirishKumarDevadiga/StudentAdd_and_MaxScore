#include <stdint.h>
#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

typedef struct _student_ Student;

struct _student_{
    char name[20];
    float grade;
    char program[50];
    float marks;
};

typedef struct _node_ Node;

struct _node_
{
    Student data;
    Node *next;
};

typedef struct _slist_ Slist;

struct _slist_ {
    Node *head;
    Node *tail; 
    Student max_score;
    uint32_t length;
};


Slist slist_new();
uint32_t slist_length(const Slist *list);
Slist* slist_addnode_tail(Slist *list, Student val);
Slist* slist_delnode_tail(Slist *list); 
Student slist_max(Slist *list);

#endif //SLIST_H_INCLUDED

