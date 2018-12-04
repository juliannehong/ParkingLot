#pragma once

#include <stdio.h>
#include "ParkingLot.h"
#include "Spot.h"

class Level {
public:
  Level(int floor);
  const static int NUM_LARGE_SPOT = 25;
  const static int NUM_COMPACT_SPOT = 50;
  const static int NUM_SMALL_SPOT = 30;
  const static int NUM_TOTAL_SPOTS = NUM_LARGE_SPOT + NUM_COMPACT_SPOT + NUM_SMALL_SPOT;
  Spot* getAvailableSpot(Vehicle* v) const;
  bool isFull() { return _full; }

private:
  ParkingLot* _parkingLot;
  const int numOfSpotsLeft(const VehicleSize& s) const;
  bool updateAvailableSpotIndex(const VehicleSize& s);
  const int getFirstAvailableSpotIndex(const VehicleSize& s);
  

  int _levelNumber;

  struct _spots {
    std::array<Spot*, NUM_LARGE_SPOT> _largeSpots;
    std::array<Spot*, NUM_COMPACT_SPOT> _compactSpots;
    std::array<Spot*, NUM_SMALL_SPOT> _smallSpots;
  }* _spotsInLevel;
  
  int _numLargeSpotLeft;
  int _numCompactSpotLeft;
  int _numSmallSpotLeft;
  int _firstAvailableLargeSpotIndex;
  int _firstAvailableCompactSpotIndex;
  int _firstAvailableSmallSpotIndex;

  bool _full;
};

static_assert(sizeof(Level) == 40, "Level is not properly sized!");