#include "Vehicle.h"
#include <iostream>
Vehicle::Vehicle(VehicleSize s) : _size(s), _parkedSpot(nullptr) {}

void Vehicle::parkSpot(Spot* s) {
  if (s->parkVehicle(this)) 
    _parkedSpot = s;
}

bool Vehicle::canFit(Spot* s) {
  return _size <= s->getSpotSize();
}

Spot* Vehicle::queryAvailableParkingSpot() {

  Spot* availableSpot;
  try {
    if (_currentLevel != nullptr)
      availableSpot = _currentLevel->getAvailableSpot(this);
    if (availableSpot == nullptr)
      throw -1;
  }
  catch (int x) {
    std::cout << "no spot available" << std::endl;
  }
  return availableSpot;
}

void Vehicle::leaveSpot(Spot* s) {
  if (s->freeVehicle(this))
    _parkedSpot = nullptr;
}

Motocycle::Motocycle() : Vehicle(VehicleSize::Motocycle) {}
Car::Car() : Vehicle(VehicleSize::Compact) {}
Bus::Bus() : Vehicle(VehicleSize::Bus) {}
