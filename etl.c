
#include <stdio.h>
#include <string.h>
#include "etl.h"

void cleanTrafficData(TrafficData data[], int *n) {
    int j = 0;
    for (int i = 0; i < *n; i++) {
        // Skip rows with invalid or missing data
        if (data[i].vehicleCount <= 0 || data[i].avgSpeed <= 0) {
            printf("Skipping invalid record: %s\n", data[i].location);
            continue;
        }

        // Fix overly high speeds (> 200 km/h)
        if (data[i].avgSpeed > 200) {
            printf("Correcting abnormal speed in %s from %.2f to 80.0\n",
                   data[i].location, data[i].avgSpeed);
            data[i].avgSpeed = 80.0;
        }

        // Keep valid record
        data[j++] = data[i];
    }

    *n = j;
    printf("ETL cleaning complete. %d valid records retained.\n", *n);
}
