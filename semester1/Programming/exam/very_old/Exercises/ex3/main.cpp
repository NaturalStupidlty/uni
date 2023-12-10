#include <iostream>

struct time{
    int hours;
    int minutes;
    int seconds;
    int subtract25seconds(){
        seconds -= 25;
        if(seconds < 0) {
            seconds += 60;
            minutes -= 1;
            if(minutes < 0) {
                minutes += 60;
                hours -= 1;
                if(hours < 0) {
                    hours += 24;
                }
            }
        }
    }
};

int main() {
    time a = {23, 56, 56};
    a.subtract25seconds();

    std::cout << a.hours << ":" << a.minutes << ":" << a.seconds << std::endl;
    return 0;
}
