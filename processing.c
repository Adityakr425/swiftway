#include <string.h>
#include "processing.h"

void analyzeTraffic(TrafficData data[], int n) {
    for (int i = 0; i < n; i++) {
        if (data[i].avgSpeed < 30)
            strcpy(data[i].congestion, "High");
        else if (data[i].avgSpeed < 50)
            strcpy(data[i].congestion, "Moderate");
        else
            strcpy(data[i].congestion, "Low");
    }
}
