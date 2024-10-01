#include "generalTypes.hpp"

class Vacant : public Piece {
    public:
        Vacant() : Piece("Vacant", VACANT, false) {}

        Team Vacant::getTeam() { return team; }

        bool Vacant::validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) const { return false; }

        bool Vacant::hasSpecialMove() { return false; } 

};