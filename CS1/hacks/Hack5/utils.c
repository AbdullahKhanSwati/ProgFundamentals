// utils.c

#include "utils.h"
#include <math.h>

double degreesToRadians(double degree) {
    return degree * 3.14 / 180.0;
}

double getAirDistance(double originLatitude, double originLongitude, double destinationLatitude, double destinationLongitude) {
    double earthRadius = 6371.0; // in kilometers

    // Convert degrees to radians
    originLatitude = degreesToRadians(originLatitude);
    originLongitude = degreesToRadians(originLongitude);
    destinationLatitude = degreesToRadians(destinationLatitude);
    destinationLongitude = degreesToRadians(destinationLongitude);

    // Calculate the spherical law of cosines
    double distance = acos(sin(originLatitude) * sin(destinationLatitude) +
                            cos(originLatitude) * cos(destinationLatitude) * cos(destinationLongitude - originLongitude)) * earthRadius;

    return distance;
}

double lorentzTimeDilation(double t, double percentC) {
    double c = 299792458.0; // speed of light in meters per second

    // Calculate time dilation using Lorentz equation
    double dilation = t / sqrt(1 - pow((percentC / 100.0), 2));

    return dilation;
}
