#include <stdio.h>
void go_north_west(int * lat, int * lon)
{
    *lat = *lat + 50;
    *lon = *lon - 50;
}

int main()
{
    int lat = 0;
    int lon = 100;
    printf("Latitude %d | Longitude %d\n", lat, lon);
    go_north_west(&lat, &lon);
    printf("Latitude %d | Longitude %d\n", lat, lon);
    return 0;
}