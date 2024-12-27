#include <iostream>
using namespace std;

class Driver;  // Forward declaration of Driver class

class Car {
private:
    enum { Off, On };  // Mode: Off (non-automatic drive), On (automatic drive)
    enum { Minvel = 0, Maxvel = 200 };  // Velocity range from 0 to 200
    int mode;  // Mode of the car (Off or On)
    int velocity;  // Current velocity

public:
    friend class Driver;  // Declare Driver as a friend class

    // Constructor with default mode as On and velocity as 50
    Car(int m = On, int v = 50) : mode(m), velocity(v) { }

    // Increase the velocity by v
    bool velup(int v) {
        if (velocity + v <= Maxvel) {
            velocity += v;
            return true;
        }
        return false;  // Exceed the maximum velocity
    }

    // Decrease the velocity by v
    bool veldown(int v) {
        if (velocity - v >= Minvel) {
            velocity -= v;
            return true;
        }
        return false;  // Exceed the minimum velocity
    }

    // Check if the car mode is On
    bool ison() const {
        return mode == On;
    }

    // Get the current velocity of the car
    int getvel() const {
        return velocity;
    }

    // Display the mode and velocity of the car
    void showinfo() const {
        cout << "Mode: " << (mode == On ? "Automatic" : "Manual") << ", Velocity: " << velocity << endl;
    }

    // Set the mode of the car (On or Off)
    void setmode() {
        mode = (mode == On) ? Off : On;  // Toggle between On and Off
    }
};

class Driver {
public:
    // Increase the velocity of the car by v
    bool velup(Car& car, int v) {
        return car.velup(v);
    }

    // Decrease the velocity of the car by v
    bool veldown(Car& car, int v) {
        return car.veldown(v);
    }

    // Change the mode of the car: If it's On, set it to Off; otherwise, set it to On
    void setmode(Car& car) {
        car.setmode();  // Use Car's public method to toggle mode
    }

    // Check if the car mode is On
    bool ison(Car& car) const {
        return car.ison();
    }
};

int main() {
    // Create a car object with default mode and velocity
    Car car;
    Driver driver;

    // Display initial car info
    cout << "Initial Car Info: ";
    car.showinfo();

    // Driver increases the velocity by 30
    driver.velup(car, 30);
    cout << "After increasing velocity by 30: ";
    car.showinfo();

    // Driver decreases the velocity by 20
    driver.veldown(car, 20);
    cout << "After decreasing velocity by 20: ";
    car.showinfo();

    // Change the mode of the car
    driver.setmode(car);
    cout << "After changing mode: ";
    car.showinfo();

    // Check if the car is in automatic mode
    if (driver.ison(car)) {
        cout << "The car is in automatic mode." << endl;
    } else {
        cout << "The car is in manual mode." << endl;
    }

    // Driver increases the velocity beyond the max limit
    if (!driver.velup(car, 250)) {
        cout << "Cannot increase velocity beyond the max limit!" << endl;
    }

    // Driver decreases the velocity below the min limit
    if (!driver.veldown(car, 200)) {
        cout << "Cannot decrease velocity below the min limit!" << endl;
    }

    return 0;
}
