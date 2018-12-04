#include <iostream>
#include "Spot.h"

Spot::Spot(int levelNumber, int spotNumber, int rowNumber, VehicleSize vehicleSize) :
  _levelNumber(levelNumber), _spotNumber(spotNumber), _rowNumber(rowNumber), _vehicleSize(vehicleSize), _vehicle(nullptr) {}

bool Spot::parkVehicle(Vehicle* v) {
  if (v->getSize > _vehicleSize) {
    std::cout << "vehicle_" << v->getVehicleId() << " can't fit in this spot" << std::endl;
    return false;
  }
  if (_vehicle != nullptr) {
    std::cout << "this spot is already taken" << std::endl;
    return false;
  }
  _vehicle = v;
  return true;
}

bool Spot::freeVehicle(const Vehicle* v) {
  if (_vehicle != nullptr) {
    std::cout << "this spot is already taken" << std::endl;
    return false;
  }
  else {
    _vehicle = nullptr;
    return true;
  }
}