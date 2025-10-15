#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataingetion.h"

int collectTrafficData(TrafficData data[]) {
    FILE *f = fopen("trafficinput.csv", "r");
    if (!f) {
        printf("Error opening trafficinput.csv\n");
        return 0;
    }

    char line[100];
    int i = 0;
    fgets(line, sizeof(line), f); // skip header

    while (fgets(line, sizeof(line), f)) {
        sscanf(line, "%[^,],%d,%f", data[i].location,
               &data[i].vehicleCount, &data[i].avgSpeed);
        data[i].id = i + 1;
        strcpy(data[i].congestion, "Not Checked");
        i++;
    }

    fclose(f);
    printf("Data extraction complete. %d records loaded.\n", i);
    return i;
}
