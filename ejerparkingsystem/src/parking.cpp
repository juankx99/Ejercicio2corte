#include <iostream>
using namespace std;

class ParkingSystem {
private:
    int spaces[4]; 

public:
    ParkingSystem(int big, int medium, int small) {
        spaces[1] = big;
        spaces[2] = medium;
        spaces[3] = small;
    }

    bool addCar(int carType) {
        if (spaces[carType] > 0) {
            spaces[carType]--;
            return true;
        }
        return false;
    }
};

// Example usage:
 int main() {
    ParkingSystem parkingSystem(1, 1, 0);
    cout << parkingSystem.addCar(1) << endl; // True (1)
    cout << parkingSystem.addCar(2) << endl; // True (1)
    cout << parkingSystem.addCar(3) << endl; // False (0)
    cout << parkingSystem.addCar(1) << endl; // False (0)
    return 0;
 }