#include <string>
#include "generalTypes.hpp"

class Rook : public Piece {

    public:
        Rook::Rook() : Piece("Rook", WHITE, true), hasMoved{false} {}

        Rook::Rook(Team chosenTeam) {
            if(chosenTeam < 1) {
                throw InvalidTeamError("Rook cannot be vacant");
            }
            team = chosenTeam;
            hasMoved = false;
            specialMove = false;
            name = "Rook";
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


		bool Rook::boardContextMovement(const Board& board, const BoardPosition& origin, const BoardPosition& dest, const int vec[2]) const {
            int vectorTransformation[2] = {1, 1};
            int counter = 1;

            if(vec[0] + vec[1] < 0) {
                vectorTransformation[0] = -1;
                vectorTransformation[1] = -1;
            }
            
            if (vec[0] == 0)
                vectorTransformation[0] = 0;
            else 
                vectorTransformation[1] = 0;

            while(counter < abs(vec[0] + vec[1])) {
                if (board.getPiece(BoardPosition(origin.getRow() + vectorTransformation[0] * counter, origin.getCol() + vectorTransformation[1] * counter))->getTeam() != VACANT)
                    return false;
                counter++;
            }

            return true;
        }

        bool Rook::getHasMoved() const { return hasMoved; }

        void Rook::completedFirstMove() { hasMoved = true; }

        bool Rook::hasSpecialMove() { return specialMove; } 

    private:
        bool hasMoved;
};