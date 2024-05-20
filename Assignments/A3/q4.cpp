#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

const int OBJECTS = 5; // Assuming some number of objects

class Drone {
protected:
    float latitude, longitude, altitude, speed;

public:
    Drone(float latitude, float longitude, float altitude, float speed) : latitude(latitude), longitude(longitude), altitude(altitude), speed(speed) {}

    void adjustAltitude(float altitude) {
        this->altitude = altitude;
    }

    void setSpeed(float speed) {
        this->speed = speed;
    }

    float getSpeed() const {
        return speed;
    }

    float distance(float dx, float dy, float dz) {
        return sqrt(dx * dx + dy * dy + dz * dz);
    }
};

class Flyable {
public:
    virtual void takeoff() = 0;

    virtual void land() = 0;

    virtual void navigateTo(float latitude, float longitude, float altitude) = 0;
};

class Scannable {
public:
    virtual void scanArea(float radius) = 0;
};

class ReconDrone : public Drone, public Flyable, public Scannable {
private:
    float max_flight_time;
    int camera_resolution;

public:
    ReconDrone(float latitude, float longitude, float altitude, float speed, float max_time, int cam_res)
            : Drone(latitude, longitude, altitude, speed), max_flight_time(max_time), camera_resolution(cam_res) {}

    void takeoff() override {
        cout << "Taking Off!" << endl;
    }

    void land() override {
        cout << "Landing!" << endl;
    }

    void navigateTo(float dest_latitude, float dest_longitude, float dest_altitude) override {
        float dx = (dest_latitude - latitude) * cos((latitude + dest_latitude) / 2);
        float dy = dest_longitude - longitude;
        float dz = dest_altitude - altitude;
        float distance = this->distance(dx, dy, dz);
        float time = distance / getSpeed();

        cout << "Anticipated arrival time: " << time << " hours" << endl;
    }

    void scanArea(float radius) override {
        cout << "Performing scan within a radius of " << radius << "m." << endl;
        int detected_objects = 0;
        for (int i = 0; i < OBJECTS; ++i) {
            // Assume some random values for objects
            float object_latitude = static_cast<float>(rand() % 20);
            float object_longitude = static_cast<float>(rand() % 20);
            float object_altitude = static_cast<float>(rand() % 20);

            float dx = object_latitude - latitude;
            float dy = object_longitude - longitude;
            float dz = object_altitude - altitude;

            if (distance(dx, dy, dz) <= radius) {
                cout << "Object detected: (" << object_latitude << ", " << object_longitude << ", " << object_altitude << ")" << endl;
                detected_objects++;
            }
        }
        cout << "Detected " << detected_objects << " objects." << endl;
    }
};

int main() {
    cout << "Name: Hafsa Rashid" << endl << "Student ID: 23K-0064" << endl;
    cout<<"\n";
    ReconDrone r(0, 0, 100, 50, 10, 720); 
    r.takeoff();
    r.navigateTo(2, 3, 489);
    r.scanArea(280);
    r.land();

    return 0;
}
