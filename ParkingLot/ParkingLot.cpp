#include "ParkingLot.h"


ParkingLot::ParkingLot() {
  for (int i = 1; i <= NUM_LEVEL; ++i) {
    _levels[i] = new Level(i);
  }
}