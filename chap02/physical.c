#include <stdio.h>
#define VMAX 21

//physical data type
typedef struct {
    char name[20];
    int height;
    double vision;
} PhysCheck;

// get an average of height
double ave_height(const PhysCheck dat[], int n)
{
    int i;
    double sum = 0;
    for (i = 0; i < n; i++)
        sum = dat[i].height;
    return sum / n;
}

// get a distribution of vision
void dist_vision(const PhysCheck dat[], int n, int dist[n])
{
    int i;
    for(i = 0; i < VMAX; i++)
    {
        dist[i] = 0;
    }
    for(i = 0; i < n; i++) {
        if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX/10.0)
            dist[(int)(dat[i].vision * 10)]++;
    }
}

int main(void)
{
    int i;
    PhysCheck x[] = {
        { "Park", 162, 0.3 },
        { "Ham" , 173, 0.7 },
        { "Choi", 175, 2.0 },
        { "Hong", 171, 1.5 },
        { "Lee" , 168, 0.4 },
        { "Kim" , 174, 1.2 },
        { "Beck", 169, 0.8 },
    };
    int nx = sizeof(x) / sizeof(x[0]);
    int vdist[VMAX];
    puts("----- physical examination -----");
    puts("name            height    vision");
    puts("--------------------------------");
    for(i = 0; i < nx; i++)
        printf("%-16.4s%4d%10.1f\n", x[i].name, x[i].height, x[i].vision);
    printf("\n average height: %5.1f cm\n", ave_height(x, nx));
    dist_vision(x, nx, vdist);
    printf("\n distribution of vision\n");
    for(i = 0; i < VMAX; i++){
        printf("%3.1f ~ : ", i/10.0);
        for(int j = 0; j < vdist[i]; j++)
            printf("*");
        puts("");
    }
    return 0;

}