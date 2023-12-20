#include <stdio.h>
#include <time.h>

int main() {
    int birthDay, birthMonth, birthYear;
    printf("Enter your birth day (1-31): ");
    scanf("%d", &birthDay);

    printf("Enter your birth month (1-12): ");
    scanf("%d", &birthMonth);

    printf("Enter your birth year: ");
    scanf("%d", &birthYear);

    time_t now = time(NULL); // Get current time
    struct tm *currentTime = localtime(&now); // Convert current time to structure

    int currentYear = currentTime->tm_year + 1900;
    int currentMonth = currentTime->tm_mon + 1;
    int currentDay = currentTime->tm_mday;

    // Calculate age
    int age = currentYear - birthYear;
    if (birthMonth > currentMonth || (birthMonth == currentMonth && birthDay > currentDay)) {
        age--; // Hasn't had birthday this year yet
    }

    printf("You are %d years old.\n", age);
    return 0;
}
