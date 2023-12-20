// utilsTester.c

#include <stdio.h>
#include "utils.h"

int main() {
    // Test degreesToRadians
    double radians = degreesToRadians(180.0);
    printf("Test degreesToRadians: Expected: 3.14159, Actual: %lf\n", radians);

    // Test getAirDistance
    double airDistance = getAirDistance(37.7749, -122.4194, 34.0522, -118.2437);
    printf("Test getAirDistance: Expected: ~616.7 km, Actual: %lf km\n", airDistance);

    // Test lorentzTimeDilation
    double dilatedTime = lorentzTimeDilation(1.0, 25.0);
    printf("Test lorentzTimeDilation: Expected: ~1.032796, Actual: %lf\n", dilatedTime);

    return 0;
}
