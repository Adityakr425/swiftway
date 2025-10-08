# SwiftWay: Traffic Flow Analysis System

A simple C-based project for automatic traffic data collection and congestion analysis.

## Files
- `main.c` — Main driver
- `dataingetion.c/.h` — Reads traffic data from CSV
- `processing.c/.h` — Analyzes speed and congestion
- `report.c/.h` — Displays traffic report
- `trafficinput.csv` — Sample input data

## Compile and Run
### Linux / Mac
```bash
gcc main.c dataingetion.c processing.c report.c -o swiftway
./swiftway
