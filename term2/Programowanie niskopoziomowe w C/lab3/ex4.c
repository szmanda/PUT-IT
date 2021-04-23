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
        printf("first\n");
        list->comp = details();
        list->next = NULL;
    } else if (list->next == NULL){
        printf("last\n");
        list->next = (arrayOfComputers *) malloc(sizeof(arrayOfComputers));
        list->next->comp = details();
        list->next->next = NULL;
    } else {
        printf("next\n");
        add(list->next);
    }
}
void display(arrayOfComputers *list){
    if (list->next == NULL){
        printf(
            "Computer %s, %s - %f $",
            list->comp->brand,
            list->comp->name,
            list->comp->price
        );
    } else {
        printf("next\n");
        add(list->next);
    }
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
        else if (c=='S' || c=='s')
            break;
        else if (c=='R' || c=='q')
            break;
        else if (c=='D' || c=='d')
            display(&list);
    }
    return 0;
}