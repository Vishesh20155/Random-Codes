#include <stdio.h>
#include <time.h>

int main()
{
    time_t t;
    struct tm *tmp;

    time(&t);

    /* add a week to today */
    // t += 7 * 24 * 60 * 60;

    tmp = localtime(&t);
    // printf("%02d/%02d/%02d\n", tmp->tm_mon+1, tmp->tm_mday,
    //     tmp->tm_year % 100);
    printf("%s", asctime(tmp));
    return 0;
}