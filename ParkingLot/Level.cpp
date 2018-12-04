#include "Level.h"
#include "Spot.h"
#include <iostream>

Level::Level(int floor) :
  _levelNumber(floor), _numLargeSpotLeft(NUM_LARGE_SPOT), _numCompactSpotLeft(NUM_COMPACT_SPOT), _numSmallSpotLeft(NUM_SMALL_SPOT),
  _firstAvailableLargeSpotIndex(0), _firstAvailableCompactSpotIndex(0), _firstAvailableSmallSpotIndex(0) {
  
  for (int i = 0; i < NUM_LARGE_SPOT; ++i)
    _largeSpots[i] = new Spot(floor, i, Bus);
  for (int i = 0; i < NUM_COMPACT_SPOT; ++i)
    _compactSpots[i] = new Spot(floor, i, Compact);
  for (int i = 0; i < NUM_SMALL_SPOT; ++i) {
    _compactSpots[i] = new Spot(floor, i, Motocycle);
  }
}

bool Level::updateAvailableSpotIndex(const VehicleSize& s) {

  if (s == Bus) {
    for (int i = 0; i < NUM_LARGE_SPOT; ++i) {
      if (_largeSpots[i]->isAvailable()) {
        _firstAvailableLargeSpotIndex = i;
        return true;
      }
    }
  }
  else if (s == Compact) {
    for (int i = 0; i < NUM_COMPACT_SPOT; ++i) {
      if (_compactSpots[i]->isAvailable()) {
        _firstAvailableCompactSpotIndex = i;
        return true;
      }
    }
  }
  else {
    for (int i = 0; i < NUM_SMALL_SPOT; ++i) {
      if (_smallSpots[i]->isAvailable())
        _firstAvailableSmallSpotIndex = i;
      return true;
    }
  }
  return false;
}

const int Level::getFirstAvailableSpotIndex(const VehicleSize& s) {
  int re;
  switch (s) {
  case Bus:
    re = _firstAvailableLargeSpotIndex;
    break;
  case Compact:
    re = _firstAvailableCompactSpotIndex;
    break;
  case Motocycle:
    re = _firstAvailableSmallSpotIndex;
    break;
  default:
    break;
  }
  return re;
}

const int Level::numOfSpotsLeft(const VehicleSize& s) const {
  int re;
  switch (s) {
  case Bus:
    re = _numLargeSpotLeft;
    break;
  case Compact:
    re = _numCompactSpotLeft;
    break;
  case Motocycle:
    re = _numSmallSpotLeft;
    break;
  default:
    break;
  }
  return re;
}

Spot* Level::getAvailableSpot(Vehicle* v) const {
  const VehicleSize& s = v->getSize();
  if (numOfSpotsLeft(s) > 0)
    
}