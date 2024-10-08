#ifndef SENSOR_H
#define SENSOR_H

/*## class Sensor */

typedef struct sensor {
    int filterFrequency;
    int updateFrequency;
    int value;
}Sensor;

/* Function declarations */
int Sensor_getFilterFrequency(const Sensor* const me);
void Sensor_setFilterFrequency(Sensor* const me, int p_filterFrequency);

int Sensor_getUpdateFrequency(const Sensor* const me);
void Sensor_setUpdateFrequency(Sensor* const me, int p_updateFrequency);

int Sensor_getValue(const Sensor* const me);
void Sensor_setValue(Sensor* const me, int p_value);

Sensor* Sensor_Create(void);
void Sensor_Destroy(Sensor* const me);

#endif /* SENSOR_H */