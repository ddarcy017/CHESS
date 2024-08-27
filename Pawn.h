#ifndef PAWN_H
#define PAWN_H

#include "chessPiece.h"

class Pawn : public chessPiece {
public:
  Pawn(Position position, Color color);

  bool isValidMove(Position newPosition,
      
       const std::vector<std::vector<chessPiece*>>& squares) const override;

  void addMove() override;
};

#endif
