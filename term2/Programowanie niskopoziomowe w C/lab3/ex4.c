#include <stdio.h>
#include <stdlib.h>

struct Computer{
    char *name[32];
    char *brand[32];
    float *price;
};

struct ArrayOfComputers{
    struct Computer *comp;
    struct ArrayOfComputers *next;
};

void add(struct ArrayOfComputers *list){
    struct ArrayOfComputers * last = list;
    while (last->next != NULL) last = last->next;
    last->next = (struct ArrayOfComputers *) malloc(sizeof(struct ArrayOfComputers));
    last->next->comp = (struct Computer *) malloc(sizeof(struct Computer));
    *last->next->comp->brand = "SpaceX";
    
    *last->next->comp->name = "starship";
    *last->next->comp->price = 2.99f;
    last->next->next = NULL;

}
void display(struct ArrayOfComputers *list){
    struct ArrayOfComputers * last = list;
    while (last->comp != NULL) {printf("name: %s", *last->comp->name); last = last->next;}
}
int main(){
    char c;
    struct ArrayOfComputers list;
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
        else if (c=='D' || c=='q')
            display(&list);
    }
    return 0;
}