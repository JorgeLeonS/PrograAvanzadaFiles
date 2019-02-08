#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
    int age;
    char * name;
    struct node *next;
};
typedef struct node node_t;
/*
Alister Estrada Cueto A01336767
Rosa Maria Miranda Alarcon A01337813
Jorge Leon Salas  A01337252
*/

//Add at the end
void add(int age, char * name, node_t **theList) {
  node_t *newS = (node_t *) malloc(sizeof(node_t));
  newS ->age = age;
  newS ->name = name;
  newS ->next = NULL;

  if(*theList == NULL){
    *theList = newS;
    //printf(" first node ");
  }else{
    node_t * temp = *theList;
    while(temp-> next != NULL){
      temp = temp ->next;
    }
    temp-> next = newS;
     //printf(" next node ");
  }
 
}

//Remove the first item
void pop(node_t **theList){
   if(*theList == NULL){
    printf("No node to remove\n");
  }else{
    node_t *temp = *theList;
    *theList = temp->next;
    free(temp);
  }
}

//Size of the list
int size(node_t * pointerToList){
  node_t * temp = pointerToList;
  int i = 0;
   while(temp != NULL){
    i++;
    temp = temp ->next;
  }
    return i;
}

//Iterating over a list
void print( node_t * pointerToList) {
  node_t * temp = pointerToList;
  printf("[");
   while(temp != NULL){
     printf("%d   %s ;", temp ->age, temp ->name);
      temp = temp ->next;
    }
    printf("]");
}

//Remove Last item of the list
void removeLast( node_t **theList){
   if(*theList == NULL){
    printf("No node to remove\n");
  }else{
    node_t *temp = *theList;
    while(temp->next->next!=NULL){
      temp = temp->next;
    }
    node_t *aux = temp->next;
    temp->next=NULL;
    free(aux);
  }
  
}

//Remove specific item
void removeItem(int position, node_t **theList){
 if(*theList == NULL){
    printf("No node to remove\n");
  }else{
    int i = 0;
    node_t *temp = *theList;

    if(position == 0){
      *theList = temp->next;
      free(temp);
    }else{
      while(i != position-1){
          temp = temp->next;
          i++;
      }

      if(temp->next !=NULL){
        node_t *aux = temp->next;
        temp->next=aux->next;
        free(aux);
      }else{
        printf("No node to remove\n");
      }
    }
    
  }
}

void getItem(int position, node_t **theList){
  //store data on item

  if(*theList == NULL){
    printf("No node to remove\n");
  }else{
    int i = 0;
    node_t *temp = *theList;

    while(i != position){
      temp = temp->next;
      i++;
    }
    
    printf("%d %s \n", temp->age, temp->name);
    
  }
}



//Adding an item to the beginning of the list 
void push(int age, char * name, node_t **theList){
  node_t *newS = (node_t *) malloc(sizeof(node_t));
  newS ->age = age;
  newS ->name = name;
  newS ->next = NULL;

  if(*theList == NULL){
    *theList = newS;
    //printf(" first node ");
  }else{
    node_t * temp = newS;
    temp-> next = *theList;
    *theList= temp;
    
    
     //printf(" next node ");
  }
}

void clear(node_t **theList){
  if(*theList == NULL){
    printf("No node to remove\n");
  }else{
    node_t *temp = *theList;
    node_t *aux = *theList;

    while(temp->next!=NULL){
      aux = temp->next;
      free(temp);
      temp = aux;
    }
    *theList = temp->next;
    free(temp);
  }
}

void loadList(node_t **theList) {

  FILE* stream = fopen("dataC.csv", "r");
    char line[1024];
  while (fgets(line, 1024, stream)){
    //printf("%s \n", line);
    char* name = (char *) malloc(10 *sizeof(char));
    //char * name;
    strcpy(name, strtok(line, ","));
    //name = strtok(line, ",");
    int age = 0;
    //Convert string to int
    age = atoi( strtok(NULL, ""));
   printf(" Record: %s %i \n", name, age);

    add(age, name, theList);
  }

  free(stream);
  
}
void findOldest( node_t * pointerToList){
  printf("Finding Oldest: \n");
  node_t * temp = pointerToList;
  int ptrOld = pointerToList->age;
   while(temp != NULL){
     if(temp->age > ptrOld){
       ptrOld = temp->age;

       
     }
      temp = temp ->next;
    }
    printf("The Oldest is: %d \n", ptrOld);
}

void findYoungest( node_t * pointerToList){
  printf("Finding Youngest: \n");
  node_t * temp = pointerToList;
  int ptrOld = pointerToList->age;
   while(temp != NULL){
     if(temp->age < ptrOld){
       ptrOld = temp->age;

     }
      temp = temp ->next;
    }
    printf("The Youngest is: %d \n", ptrOld);
}

void ageAvg( node_t * pointerToList){
  node_t * temp = pointerToList;
  int ptrOld = pointerToList->age;
  int ctr = 0;
  
   while(temp != NULL){
     ctr++;
     ptrOld += temp->age;
      temp = temp ->next;
    }
    printf("The Avg is: %d \n", ptrOld/ctr);
}

void printLetter(node_t * pointerToList, char letter){
  node_t * temp = pointerToList;
  //char ptrOld[10] = pointerToList->name;
 
   while(temp != NULL){
     if(temp->name[0] == letter){
       printf("The names are: %s \n", temp->name);
     }
     temp = temp ->next;
    }
}
/*
int main(void) {
  node_t * list = NULL;
  
  add(19, "Machu3", &list);
  print(list);
  printf("\n");
  add(20, "Machu", &list);
  add(21, "Machu2", &list);
  add(22, "Machu4", &list);
  add(23, "Machu5", &list);
  print(list);
  push(18, "Machu0", &list);
  printf("\n");
  print(list);
  pop(&list);
  printf("\n");
  print(list);
  removeLast(&list);
  printf("\n");
  print(list);
  removeItem(2, &list);
  printf("\n");
  print(list);
  printf("\n");
  printf("Size of the list: %d", size(list));
  printf("\n");
  getItem(1, &list);
  clear(&list);
  printf("\n");
  printf("Size of the list: %d", size(list));


  return 0;
}
*/
