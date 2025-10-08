#include <stdio.h>
#include <stdlib.h>
#include "dataingetion.h"
#include "processing.h"
#include "report.h"

int main() {
    TrafficData data[100];
    int n = 0;

    printf("\n===== SMART STREAM: TRAFFIC FLOW SYSTEM =====\n");

    // Automatically collect data at startup
    printf("\nCollecting live traffic data (from CSV)...\n");
    n = collectTrafficData(data);
    if (n == 0) {
        printf("\nError: Unable to collect traffic data. Exiting program.\n");
        return 1;
    }

    printf("Traffic data collected successfully! (%d records)\n", n);

    // Automatically analyze
    printf("\nAnalyzing and predicting congestion levels...\n");
    analyzeTraffic(data, n);
    printf("Traffic analysis completed.\n");

    // Automatically display + save report
    printf("\nGenerating traffic report...\n");
    displayReport(data, n);

    printf("\nSystem execution complete.\n");
    return 0;
}
