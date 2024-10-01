#include <string>
#include "generalTypes.hpp"


class Knight : public Piece {

    public:
        Knight::Knight() : Piece("Knight") {}

        Knight::Knight(Team chosenTeam) {
            if(chosenTeam < 1) {
                throw InvalidTeamError("Knight cannot be vacant");
            }
            team = chosenTeam;
            specialMove = false;
            name = "Knight";
        }

        bool Knight::validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) {
            int rowDisplacement = dest.getRow() - origin.getRow();
            int colDisplacement = dest.getCol() - origin.getCol();

            if(abs(rowDisplacement) == 1 && abs(colDisplacement) == 2 || abs(rowDisplacement) == 2 && abs(colDisplacement) == 1) {
                vec[0] = rowDisplacement;
                vec[1] = colDisplacement;
                return true;
            }

            return false;
        }


		bool Knight::boardContextMovement(const Board& board, const BoardPosition& origin, const BoardPosition& dest, const int vec[2]) const {
            return true;
        }

        bool Knight::hasSpecialMove() {
            return specialMove;
        }
};