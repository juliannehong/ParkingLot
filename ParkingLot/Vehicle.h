#ifndef Vehicle_h
#define Vehicle_h

#include "ParkingLot.h"

class Vehicle {
public:
  
  Vehicle(VehicleSize s);
  const VehicleSize getSize() { return _size; }
  const int getVehicleId() { return _vehicleId; }
private:
  void parkSpot(Spot* s);
  Spot* queryAvailableParkingSpot();
  bool canFit(Spot* s);
  void leaveSpot(Spot* s);

private:
  VehicleSize _size;
  Spot* _parkedSpot;
  Level* _currentLevel;
  int _vehicleId;
};

class Motocycle : public Vehicle {
public:
  Motocycle();

};

class Car : public Vehicle {
public:
  Car();

};

class Bus : public Vehicle {
public:
  Bus();

};
#endif