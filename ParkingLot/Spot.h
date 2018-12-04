#ifndef Spot_h
#define Spot_h
#include <stdio.h>
#include "ParkingLot.h"
#include "Vehicle.h"
class Spot {
public:
  Spot(int levelNumber, int spotNumber, VehicleSize vehicleSize);
  bool isAvailable() { return _vehicle == nullptr; }
  VehicleSize getSpotSize() { return _vehicleSize; }
  bool parkVehicle(Vehicle* v);
  bool freeVehicle(const Vehicle* v);

private:
  int _levelNumber;
  int _spotNumber;
  int _rowNumber;
  Vehicle* _vehicle;
  VehicleSize _vehicleSize;
};
#endif
