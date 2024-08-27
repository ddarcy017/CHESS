#ifndef ROOK_H
#define ROOK_H

#include "chessPiece.h"

class Rook : public chessPiece {
public:
  Rook(Position position, Color color);

  bool isValidMove(Position newPosition,
      
    const std::vector<std::vector<chessPiece*>>& squares) const override;

  void addMove() override;  // Ensure this declaration is present
};

#endif
