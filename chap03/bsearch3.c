#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[5];
    int height;
    int weight;
} Person;

//---comparing function of Person struct(sort name by ascending)---//
int npcmp(const Person *x, const Person *y)
{
    return strcmp(x->name, y->name);
}

int main(void)
{
    Person x[] = {
        { "Choi", 165, 51},
        { "Ham", 181, 73},
        { "Hong", 172, 84},
        { "Kim", 179, 79},
        { "Lee", 176, 52},
        { "Park", 172, 63}
    };
    int nx = sizeof(x) / sizeof(x[0]);
    int retry;
    puts("search by name");
    do {
        Person temp, *p;
        printf("name: ");
        scanf("%s", temp.name);
        p = bsearch(&temp, x, nx, sizeof(Person), 
            (int(*)(const void *, const void *)) npcmp);
        if(p == NULL)
            puts("Failed to search");
        else {
            puts("Searching success!! Find the element below.");
            printf("x[%d] : %s %dcm %dkg\n",
                (int)(p - x), p -> name, p -> height, p -> weight);
        }
        printf("Again search?(1) yes/(0) no: ");
        scanf("%d", &retry);
    } while(retry == 1);

    return 0;
}