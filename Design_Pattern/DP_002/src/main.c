#include <stdio.h>
#include "Sensor.h"

int main(void) {
    /* Create a new Sensor object */
    Sensor* mySensor = Sensor_Create();
    
    if (mySensor == NULL) {
        printf("Failed to create sensor.\n");
        return -1;
    }
    
    /* Set values using the setter functions */
    Sensor_setFilterFrequency(mySensor, 50);
    Sensor_setUpdateFrequency(mySensor, 100);
    Sensor_setValue(mySensor, 75);
    
    /* Get and print values using the getter functions */
    printf("Sensor Filter Frequency: %d\n", Sensor_getFilterFrequency(mySensor));
    printf("Sensor Update Frequency: %d\n", Sensor_getUpdateFrequency(mySensor));
    printf("Sensor Value: %d\n", Sensor_getValue(mySensor));
    
    /* Destroy the sensor object */
    Sensor_Destroy(mySensor);
    
    return 0;
}
