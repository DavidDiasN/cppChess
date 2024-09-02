#include "generalTypes.hpp"


class Vacant : PieceStrategy {
    public:
        Team Vacant::getTeam() {
            return team;
        }

        bool Vacant::validMovement(const PieceStrategy& origin, const PieceStrategy& dest) const {
            return false;
        }

    private: 
        Team team = VACANT;
};