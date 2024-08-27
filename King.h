#ifndef KING_H
#define KING_H

#include "chessPiece.h"

class King : public chessPiece {
public:
  King(Position position, Color color);

  bool isValidMove(Position newPosition,
      
     const std::vector<std::vector<chessPiece*>>& squares) const override;

  void addMove() override;
};

#endif
