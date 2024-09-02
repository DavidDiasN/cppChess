#include <string>
#include "generalTypes.hpp"


class Rook : PieceStrategy {

    public:
        Rook::Rook() {
            team = WHITE;
            hasMoved = false;
        }

        Rook::Rook(Team chosenTeam) {
            if(chosenTeam < 1) {
                throw InvalidTeamError("Pawn cannot be vacant");
            }
            team = chosenTeam;
            hasMoved = false;
        }

        bool Rook::validMovement(const BoardPosition& origin, const BoardPosition& dest) {
            if((origin.getRow() == dest.getRow()) != (origin.getCol() == dest.getCol())){
                return true;
            }
            return false;
        }

        bool Rook::getHasMoved() const {
            return hasMoved;
        }

        void Rook::completedFirstMove() {
            hasMoved = true;
        }

    private:
        Team team;
        bool hasMoved;

};