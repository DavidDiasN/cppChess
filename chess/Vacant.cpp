#include "generalTypes.hpp"


class Vacant : PieceStrategy {
    public:
        Team Vacant::getTeam() {
            return team;
        }

        bool Vacant::validMovement(const PieceStrategy& origin, const PieceStrategy& dest, int vec[2]) const {
            return false;
        }


        bool Vacant::hasSpecialMove() {
            return false;
        } 

    private: 
        Team team = VACANT;
        bool specialMove = false;
};