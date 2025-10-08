#include <stdio.h>
#include "report.h"

void displayReport(TrafficData data[], int n) {
    printf("\n================ TRAFFIC REPORT ================\n");
    printf("%-5s %-12s %-15s %-10s %-15s\n",
           "ID", "Location", "Vehicle Count", "Speed", "Congestion");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-5d %-12s %-15d %-10.2f %-15s\n",
               data[i].id, data[i].location, data[i].vehicleCount,
               data[i].avgSpeed, data[i].congestionLevel);
    }

    FILE *f = fopen("traffic_data.txt", "w");
    if (f) {
        for (int i = 0; i < n; i++) {
            fprintf(f, "%d,%s,%d,%.2f,%s\n", data[i].id, data[i].location,
                    data[i].vehicleCount, data[i].avgSpeed, data[i].congestionLevel);
        }
        fclose(f);
        printf("\nData saved to traffic_data.txt successfully!\n");
    } else {
        printf("\nError saving data!\n");
    }
}
