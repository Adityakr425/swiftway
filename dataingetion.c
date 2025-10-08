#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataingetion.h"

static void trim_newline(char *s) {
    size_t l = strlen(s);
    while (l > 0 && (s[l-1] == '\n' || s[l-1] == '\r')) {
        s[l-1] = '\0';
        l--;
    }
}

int collectTrafficData(TrafficData data[]) {
    FILE *fp = fopen("trafficinput.csv", "r");  // updated file name
    if (!fp) {
        printf("\nError: Could not open trafficinput.csv\n");
        return 0;
    }

    char line[256];
    int i = 0;

    // Skip header
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) && i < 100) {
        trim_newline(line);
        char *token = strtok(line, ",");
        if (!token) continue;
        strncpy(data[i].location, token, sizeof(data[i].location) - 1);
        data[i].location[sizeof(data[i].location) - 1] = '\0';

        token = strtok(NULL, ",");
        if (!token) continue;
        data[i].vehicleCount = atoi(token);

        token = strtok(NULL, ",");
        if (!token) continue;
        data[i].avgSpeed = (float)atof(token);

        data[i].id = i + 1;
        strcpy(data[i].congestionLevel, "Not Analyzed");
        i++;
    }

    fclose(fp);
    return i;
}
