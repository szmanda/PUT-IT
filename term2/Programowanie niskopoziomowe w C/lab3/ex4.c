 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Computer{
    char name[32];
    char brand[32];
    float price;
} computer;

typedef struct ArrayOfComputers arrayOfComputers;

typedef struct ArrayOfComputers{
    computer *comp;
    arrayOfComputers *next;
} arrayOfComputers;

computer* details(){
    computer* pc = malloc(sizeof(computer));
    char name[32], brand[32];
    float price;

    printf("enter name: ");
    scanf("%s", pc->name);
    fflush(stdin);
    // pc->name = "test";
    printf("enter brand: ");
    scanf("%s", pc->brand);
    fflush(stdin);
    printf("enter price: ");
    scanf("%f", &price);
    pc->price = price;

    return pc;
}

void add(arrayOfComputers *list){
    if (list->comp == NULL){
        //printf("first\n");
        list->comp = details();
        list->next = NULL;
    } else if (list->next == NULL){
        //printf("last\n");
        list->next = (arrayOfComputers *) malloc(sizeof(arrayOfComputers));
        list->next->comp = details();
        list->next->next = NULL;
    } else {
        //printf("next\n");
        add(list->next);
    }
}
void display(arrayOfComputers *list){
    if (list->next == NULL){
        printf(
            "Computer %s, %s - $%f\n\n",
            list->comp->brand,
            list->comp->name,
            list->comp->price
        );
    } else {
        printf(
            "Computer %s, %s - $%f\n",
            list->comp->brand,
            list->comp->name,
            list->comp->price
        );
        display(list->next);
    }
}
void rem(arrayOfComputers *list, char name[32]){
    //printf("remove\n");
    if (list->next == NULL){
        if (strcmp(list->comp->name, name) == 0) {
            list->comp = NULL;
            printf("removed last computer\n");
        }
    } else if (strcmp(list->comp->name, name) == 0) {
        list->comp = list->next->comp;
        list->next = list->next->next;
        printf("removed computer\n");
    } else {
        rem(list->next, name);
    }
}

void search(arrayOfComputers *list, char name[32]){
    if (strcmp(list->comp->name, name) == 0)
    {
        printf(
        "Computer was found: %s, %s - $%f\n",
        list->comp->brand,
        list->comp->name,
        list->comp->price
    );
    }
    if (list->next != NULL)
        search(list->next, name);
}

int main(){
    char c;
    arrayOfComputers list;
    list.comp = NULL;
    list.next = NULL;
    for(;;){
        fflush(stdin);
        scanf("%c",&c);
        if (c=='Q' || c=='q')
            break;
        else if (c=='N' || c=='n')
            add(&list);
        else if (c=='S' || c=='s') {
            char name[32];
            printf("name the pc to search for: ");
            fflush(stdin);
            scanf("%s",name);
            search(&list,name);
        }
        else if (c=='R' || c=='r') {
            char name[32];
            printf("name the pc to remove: ");
            fflush(stdin);
            scanf("%s",name);
            rem(&list,name);
        }
        else if (c=='D' || c=='d')
            display(&list);
    }
    return 0;
}