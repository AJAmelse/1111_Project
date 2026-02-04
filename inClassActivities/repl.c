#include <stdio.h>


int main(){
    int capacity = 0;
    printf("What is your capacity?: ");
    scanf(" %d", &capacity);
    char firstNames[capacity][32];
    char lastNames[capacity][32];
    int attendees = 0;

    while(attendees < capacity){
        printf("Name to register: ");
        scanf(" %s", firstNames[attendees]);
        scanf(" %s", lastNames[attendees]);
        attendees++;
        printf("Add more people? y/n: ");
        char cont = 'y';
        scanf(" %c", &cont);
        if(cont != 'y'){
            break;
        }
    }

    printf("\nattendees: \n");
    for(int i = 0; i < attendees; i++){
        printf(" %s", firstNames[i]);
        printf(" %s\n", lastNames[i]);
    }

    return 0;
}
