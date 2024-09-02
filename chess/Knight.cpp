#include <string>
#include "generalTypes.hpp"


class Knight : PieceStrategy {

    public:
        Knight::Knight() {
            team = WHITE;
        }

        Knight::Knight(Team chosenTeam) {
            if(chosenTeam < 1) {
                throw InvalidTeamError("Pawn cannot be vacant");
            }
            team = chosenTeam;
        }

        bool Knight::validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[]) {
            int rowDisplacement = dest.getRow() - origin.getRow();
            int colDisplacement = dest.getCol() - origin.getCol();

            if(abs(rowDisplacement) == 1 && abs(colDisplacement) == 2 || abs(rowDisplacement) == 2 && abs(colDisplacement) == 1) {
                vec[0] = rowDisplacement;
                vec[1] = colDisplacement;
                return true;
            }

            return false;
        }

        bool Knight::hasSpecialMove() {
            return specialMove;
        }

    private:
        Team team;
        bool specialMove;

};