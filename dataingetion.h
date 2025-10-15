#ifndef DATAINGETION_H
#define DATAINGETION_H

typedef struct {
    int id;
    char location[30];
    int vehicleCount;
    float avgSpeed;
    char congestion[15];
} TrafficData;

int collectTrafficData(TrafficData data[]);

#endif
