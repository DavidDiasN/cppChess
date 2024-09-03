#include <string>
#include "generalTypes.hpp"


class King : PieceStrategy {

    public:
        King::King() {
            team = WHITE;
            hasMoved = false;
        }

        King::King(Team chosenTeam) {
            if (chosenTeam < 1) {
                throw InvalidTeamError("Pawn cannot be vacant");
            }
            team = chosenTeam;
            hasMoved = false;
        }

        bool King::validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) {
            int rowDisplacement = dest.getRow() - origin.getRow();
            int colDisplacement = dest.getCol() - origin.getCol();

            if (abs(rowDisplacement) <= 1 && abs(colDisplacement) <= 1) {
                vec[0] = rowDisplacement;
                vec[1] = colDisplacement;
                return true;
            }

            if (!hasMoved && abs(dest.getCol() - origin.getCol()) == 2) {
                vec[0] = 0;
                vec[1] = colDisplacement;
            }

            return false;
        }

		bool King::boardContextMovement(const Board& board, const BoardPosition& origin, const BoardPosition& dest, const int vec[2]) const {
            // need to check for castle move. Should check if the knights have moved.
            // wait can I complete the castle and notify the calling function that the castle is valid?
            // will i need to carve out a special case?


        }

        bool King::getHasMoved() const {
            return hasMoved;
        }

        void King::completedFirstMove() {
            hasMoved = true;
        }

        bool King::hasSpecialMove() {
            return specialMove;
        }


    private:
        Team team;
        bool hasMoved;
        bool specialMove;


};