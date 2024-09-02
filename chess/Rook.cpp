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

        bool Rook::validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) {
            int rowDisplacement = dest.getRow() - origin.getRow();
            int colDisplacement = dest.getCol() - origin.getCol();

            if (rowDisplacement == 0 || colDisplacement == 0) {
                vec[0] = rowDisplacement;
                vec[1] = colDisplacement;
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

        bool Rook::hasSpecialMove() {
            return specialMove;
        } 


    private:
        Team team;
        bool hasMoved;
        bool specialMove;

};