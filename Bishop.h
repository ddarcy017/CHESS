#ifndef BISHOP_H
#define BISHOP_H

#include "chessPiece.h"

class Bishop : public chessPiece {
public:
  Bishop(Position position, Color color);

  bool isValidMove(Position newPosition,
      
    const std::vector<std::vector<chessPiece*>>& squares) const override;

  void addMove() override;
};

#endif
