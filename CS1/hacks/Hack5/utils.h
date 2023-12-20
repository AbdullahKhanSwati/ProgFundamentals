// utils.h

#ifndef UTILS_H
#define UTILS_H

double degreesToRadians(double degree);
double getAirDistance(double originLatitude, double originLongitude, double destinationLatitude, double destinationLongitude);
double lorentzTimeDilation(double t, double percentC);

#endif  // UTILS_H