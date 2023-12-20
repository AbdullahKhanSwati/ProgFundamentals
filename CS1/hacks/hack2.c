#include <stdio.h>
#include <math.h>

#define EARTH_RADIUS 6371.0 // Earth radius in kilometers

int main() {
    double lat1, lon1, lat2, lon2;
    
    // Get user input for location coordinates
    printf("Enter latitude and longitude for the Origin (in degrees, separated by space): ");
    scanf("%lf %lf", &lat1, &lon1);
    
    printf("Enter latitude and longitude for the Destination (in degrees, separated by space): ");
    scanf("%lf %lf", &lat2, &lon2);
    
    // Convert latitude and longitude from degrees to radians
    double lat1Rad = lat1 * 3.14/ 180.0;
    double lon1Rad = lon1 * 3.14 / 180.0;
    double lat2Rad = lat2 * 3.14 / 180.0;
    double lon2Rad = lon2 * 3.14 / 180.0;
    
    // Calculate distance using the Spherical Law of Cosines formula
    double dLat = lat2Rad - lat1Rad;
    double dLon = lon2Rad - lon1Rad;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1Rad) * cos(lat2Rad) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;
    
    // Print the result
    printf("\nLocation Distance\n");
    printf("========================\n");
    printf("Origin:      (%lf, %lf)\n", lat1, lon1);
    printf("Destination: (%lf, %lf)\n", lat2, lon2);
    printf("Air distance is %.6lf kms\n", distance);
    
    return 0;
}