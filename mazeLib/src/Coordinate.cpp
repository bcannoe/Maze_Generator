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

void Coordinate::setTile(char newTile) {
  tile = newTile;
}

bool Coordinate::visit() {
  visited = true;
  return true;
}
bool Coordinate::isVisited() {
  return visited;
}
