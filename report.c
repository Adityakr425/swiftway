#include <stdio.h>
#include "report.h"

void displayReport(TrafficData data[], int n) {
    printf("\nID  Location     Vehicles   Speed   Congestion\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-3d %-12s %-10d %-7.2f %s\n",
               data[i].id, data[i].location, data[i].vehicleCount,
               data[i].avgSpeed, data[i].congestion);
    }
}
