#ifndef QUEEN_H
#define QUEEN_H

#include "chessPiece.h"

class Queen : public chessPiece {
public:
  Queen(Position position, Color color);

  bool isValidMove(Position newPosition,
      
       const std::vector<std::vector<chessPiece*>>& squares) const override;

  void addMove() override;
};

#endif
