#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   
    if (argc != 5) {
        printf("ERROR: Invalid number of command line arguments.\n");
        printf("Usage: %s <total GB> <current day> <total GB used> <total days in the month>\n", argv[0]);
        return 1;
    }

    
    double totalGB = atof(argv[1]);
    int currentDay = atoi(argv[2]);
    double totalGBUsed = atof(argv[3]);
    int totalDays = atoi(argv[4]);

    
    if (totalGB <= 0 || currentDay <= 0 || currentDay > totalDays || totalGBUsed < 0 || totalDays <= 0) {
        printf("ERROR: Invalid input values.\n");
        return 1;
    }

    
    double averageDailyUse = totalGBUsed / currentDay;
    double remainingDays = totalDays - currentDay;
    double remainingGB = totalGB - totalGBUsed;
    double maxDailyUseToStayWithinPlan = remainingGB / remainingDays;

   
    printf("%d days used, %d days remaining\n", currentDay, remainingDays);
    printf("Average daily use: %.3lf GB/day\n", averageDailyUse);

    if (averageDailyUse > maxDailyUseToStayWithinPlan) {
        printf("You are EXCEEDING your average daily use (%.3lf GB/day).\n", maxDailyUseToStayWithinPlan);
        printf("Continuing this high usage, you'll exceed your data plan by %.3lf GB.\n", 
               (averageDailyUse - maxDailyUseToStayWithinPlan) * remainingDays);
        printf("To stay below your data plan, use no more than %.3lf GB/day.\n", maxDailyUseToStayWithinPlan);
    } else if (averageDailyUse == maxDailyUseToStayWithinPlan) {
        printf("You are at your average daily use (%.3lf GB/day).\n", averageDailyUse);
        printf("You can use up to %.3lf GB/day and stay below your data plan limit.\n", 
               averageDailyUse + 1.0 / remainingDays);  
    } else {
        printf("You are below your average daily use (%.3lf GB/day).\n", averageDailyUse);
        printf("You can use up to %.3lf GB/day and stay below your data plan limit.\n", 
               averageDailyUse + 1.0 / remainingDays);  
    }

    return 0;
}
