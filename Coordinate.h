class Coordinate {
public:
  Coordinate(int x, int y, char tile);
  int getX();
  int getY();
  char getTile();
  void setTile(char);
  bool visit();
  bool isVisited();
private:
  int x;                              // x-axis position
  int y;                              // y-axis position
  char tile;                          // is it a space, a wall, or the goal?
  bool visited = false;               // Has this cell been visited before?
};
