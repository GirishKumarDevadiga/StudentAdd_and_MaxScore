#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../Headers/slist.h"

void test_add_delete_student() {
    Slist s1 = slist_new();
    Slist *list = &s1;
    Student st = {"", 0, "", 0};
    
    assert(slist_length(list) == 0);

    strcpy(st.name, "Girish");
    st.grade = 8.5;
    strcpy(st.program, "BDA");
    st.marks = 80;    
    list = slist_addnode_tail(list, st);
    assert(slist_length(list) == 1);
    assert(slist_max(list).marks == 80); 

    strcpy(st.name, "Kumar");
    st.grade = 7.5;
    strcpy(st.program, "BDA");
    st.marks = 90;    
    list = slist_addnode_tail(list, st);
    assert(slist_length(list) == 2);
    assert(slist_max(list).marks == 90);

 
    strcpy(st.name, "Giri");
    st.grade = 6.5;
    strcpy(st.program, "BDA");
    st.marks = 70;
    list = slist_addnode_tail(list, st);
    assert(slist_length(list) == 3);
    assert(slist_max(list).marks == 90);

    assert(strcmp(slist_max(list).name, "Kumar") == 0);
    assert(strcmp(slist_max(list).program, "BDA") == 0);  
    
    list = slist_delnode_tail(list);
    assert(slist_length(list) == 2);
    assert(slist_max(list).marks == 90);

    list = slist_delnode_tail(list);
    assert(slist_length(list) == 1);
    assert(slist_max(list).marks == 80);


    
  
}

int main() {
   test_add_delete_student();

   return 0;

}
