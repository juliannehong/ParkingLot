
class ParkingLot
{
public:
  ParkingLot();
  ~ParkingLot();
};


#ifndef ParkingLot_h
#define ParkingLot_h
#include <stdio.h>
#include <array>
#include "Level.h"
#include "Spot.h"


enum VehicleSize {
  Motocycle,
  Compact,
  Bus
};

class ParkingLot {
public:
  ParkingLot();
  const static int NUM_LEVEL = 3;

private:
  std::array<Level*, NUM_LEVEL> _levels;
};

#endif