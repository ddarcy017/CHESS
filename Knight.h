#ifndef KNIGHT_H
#define KNIGHT_H

#include "chessPiece.h"

class Knight : public chessPiece {
public:
  Knight(Position position, Color color);

  bool isValidMove(Position newPosition,
      
       const std::vector<std::vector<chessPiece*>>& squares) const override;

  void addMove() override;
};

#endif
