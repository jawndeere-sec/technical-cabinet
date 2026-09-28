#include <cstdio>

// Example from C++ Crash Course, Types Chapter, p55
struct ClockOfTheLongNow {
    void addYear(){
        year++;
    }
    int year;
};

// Use of default constructor to intilalize the clock class to a valid time integer value for hour and mimute.
/* class Clock {
public:
    Clock() {
        hour = 0;
        minute = 0;
    }

private:
    int hour;
    int minute;
}; */

// Use of parameterized constructor to intilalize the clock class to a valid time integer value for hour and mimute.
class Clock {
public:
    Clock(int startingHour, int startingMinute) {
        hour = startingHour;
        minute = startingMinute;
    }

private:
    int hour;
    int minute;
};

int main() {
    ClockOfTheLongNow clock;
    clock.year = 2010;
    clock.addYear();
    printf("The year is %d\n", clock.year);
    clock.addYear();
    printf("The year is %d\n", clock.year);
    clock.addYear();
    printf("The year is %d\n", clock.year);
    clock.addYear();
    printf("The year is %d\n", clock.year);
    clock.addYear();
    printf("The year is %d\n", clock.year);
    clock.addYear();
    printf("The year is %d\n", clock.year);
}
