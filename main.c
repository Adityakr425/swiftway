#include <stdio.h>
#include "dataingetion.h"
#include "etl.h"
#include "processing.h"
#include "report.h"

int main() {
    TrafficData data[100];
    int n;

    printf("\n--- SWIFTWAY TRAFFIC SYSTEM ---\n");

    // Extract
    n = collectTrafficData(data);
    if (n == 0) {
        printf("No data found. Exiting.\n");
        return 1;
    }

    // Transform (clean)
    cleanTrafficData(data, &n);

    // Load + Analyze + Report
    analyzeTraffic(data, n);
    displayReport(data, n);

    printf("\nProcess finished successfully.\n");
    return 0;
}
