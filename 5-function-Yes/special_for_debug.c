#include <stdio.h>
#include <math.h>

# define G (6.674*pow(10,-11))
# define M 77.15

int main(){
    double m,R;
    scanf("%lf%lf",&m,&R);
    printf("%.3e",G*M*m/(R*R));
    return 0;
}