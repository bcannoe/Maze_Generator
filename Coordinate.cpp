#include "Coordinate.h"

Coordinate::Coordinate(int x, int y, char tile) {
  this->x = x;
  this->y = y;
  this->tile = tile;
}

int Coordinate::getX() {
  return x;
}

int Coordinate::getY() {
  return y;
}

char Coordinate::getTile() {
  return tile;
}

bool Coordinate::isVisited() {
  return visited;
}
