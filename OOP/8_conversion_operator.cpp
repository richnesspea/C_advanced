#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Conversion operator to int (total seconds)
    explicit operator int() const { //Convert from type Time to int
        return hours * 3600 + minutes * 60 + seconds;
    }
};

int main() {
    Time t(1, 30, 15);  // 1 hour, 30 minutes, 15 seconds
    int totalSeconds = static_cast<int>(t);  // Implicit conversion using operator int()
    
    cout << "Total seconds: " << totalSeconds << endl;  // Output: 5415
    return 0;
}
