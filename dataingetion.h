#ifndef DATAINGETION_H
#define DATAINGETION_H

typedef struct {
    int id;
    char location[30];
    int vehicleCount;
    float avgSpeed;
    char congestionLevel[20];
} TrafficData;

int collectTrafficData(TrafficData data[]);

#endif
