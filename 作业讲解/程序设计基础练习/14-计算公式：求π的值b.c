#include <stdio.h>

int main() {

    double eps;
    scanf("%lf", &eps);
    double pi = 0;

    int i = 1;
    // tem 1 表示分子, tem2 表示分母
    double tem1 = 1, tem2 = 1;

    while(2 * tem1 / tem2 >= eps) {
        pi += 2 * tem1 / tem2;
        tem1 *= i;
        tem2 *= 2 * i + 1;
        i++;
    }
    pi += 2 * tem1 / tem2;

    printf("%d %.7lf", i, pi);

    return 0;
}
