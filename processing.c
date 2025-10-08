#include <stdio.h>
#include <string.h>
#include "processing.h"

void analyzeTraffic(TrafficData data[], int n) {
    for (int i = 0; i < n; i++) {
        if (data[i].avgSpeed < 30.0f)
            strcpy(data[i].congestionLevel, "High");
        else if (data[i].avgSpeed < 50.0f)
            strcpy(data[i].congestionLevel, "Moderate");
        else
            strcpy(data[i].congestionLevel, "Low");
    }
}
