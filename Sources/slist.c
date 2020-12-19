#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../Headers/slist.h"

Slist slist_new() {
    Slist s1 = {NULL, NULL, {"", 0, "", 0} ,0};
    return s1;
}

uint32_t slist_length(const Slist *list){
    assert(list != NULL);
    return list->length;
}

//helper function which is not visible outside
static Node* _get_new_node_(Slist *list, Student val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;

    return newnode;
}


Slist*   slist_addnode_tail(Slist *list, Student val){
    assert(list != NULL);
    Node *new_node = _get_new_node_(list, val);


    if(list->tail != NULL) {
        list->tail->next = new_node;
        list->tail = new_node;
   
    }
    else{
        list->head = list->tail = new_node;

        
    }

    ++list->length;

      if(list->max_score.marks != 0) {

         if(val.marks > list->max_score.marks){
               list->max_score = val;
           }
         
      }  else {
           list->max_score = val;
       }
     
    assert(( list->length == 1 && list->head == list->tail) || 
           (list->length > 1 && list->head != list->tail ));

    return list;

}


Slist* slist_delnode_tail(Slist *list) {
    assert (list !=NULL);
    Node *last, *cur;
    //Student temp = {"", 0, "", 0};    

    if (list->tail !=NULL) {
        last = list->tail;
        if (list->head == list->tail){
            list->head = list->tail = NULL;
        }
        else {
            for(cur = list->head; cur->next !=last; cur = cur->next);
            list->tail = cur;
            cur->next = NULL;
        }
        --list->length;
        free(last);
    }
    
   // In case of deletion from the list
   //for(Node *cur1 = list->head; cur1 != NULL ; cur1 = cur1->next){ 
      // if (cur1->data.marks > temp.marks){
       //    temp = cur1->data;
     //   }
    //}
    //list->max_score = temp;


    return list;
}

Student slist_max(Slist *list) {
   assert (list !=NULL);
   
   return list->max_score;
}


