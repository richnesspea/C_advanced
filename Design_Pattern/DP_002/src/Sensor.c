#include "Sensor.h"
#include <stdlib.h>

/* Initialize function (can be customized for initial values) */
void Sensor_Init(Sensor* const me) {
    me->filterFrequency = 0;
    me->updateFrequency = 0;
    me->value = 0;
}

/* Cleanup function */
void Sensor_Cleanup(Sensor* const me) {
    (void)me; // Báo cho trình biên dịch rằng tham số này cố ý không được sử dụng
}

/* Getter for filterFrequency */
int Sensor_getFilterFrequency(const Sensor* const me) {
    return me->filterFrequency;
}

/* Setter for filterFrequency */
void Sensor_setFilterFrequency(Sensor* const me, int p_filterFrequency) {
    me->filterFrequency = p_filterFrequency;
}

/* Getter for updateFrequency */
int Sensor_getUpdateFrequency(const Sensor* const me) {
    return me->updateFrequency;
}

/* Setter for updateFrequency */
void Sensor_setUpdateFrequency(Sensor* const me, int p_updateFrequency) {
    me->updateFrequency = p_updateFrequency;
}

/* Getter for value */
int Sensor_getValue(const Sensor* const me) {
    return me->value;
}

/* Setter for value */
void Sensor_setValue(Sensor* const me, int p_value) {
    me->value = p_value;
}

/* Create a new Sensor object */
Sensor* Sensor_Create(void) {
    Sensor* me = (Sensor*) malloc(sizeof(Sensor));
    if (me != NULL) {
        Sensor_Init(me);
    }
    return me;
}

/* Destroy a Sensor object */
void Sensor_Destroy(Sensor* const me) {
    if (me != NULL) {
        Sensor_Cleanup(me);
        free(me);
    }
}
