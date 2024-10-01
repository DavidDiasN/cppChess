#include <string>
#include "generalTypes.hpp"


class Bishop : public Piece {

    public:
        Bishop::Bishop() : Piece("Bishop") {}

        Bishop::Bishop(Team chosenTeam) {
            if(chosenTeam < 1) {
                throw InvalidTeamError("Bishop cannot be vacant");
            }
            team = chosenTeam;
            specialMove = false;
            name = "Bishop";
        }

        bool Bishop::validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) {
            int rowDisplacement = dest.getRow() - origin.getRow();
            int colDisplacement = dest.getCol() - origin.getCol();

            if (rowDisplacement/colDisplacement == 1 || rowDisplacement/colDisplacement == -1){
                vec[0] = rowDisplacement;
                vec[1] = colDisplacement;
                return true;
            }
            
            return false;
        }


		bool Bishop::boardContextMovement(const Board& board, const BoardPosition& origin, const BoardPosition& dest, const int vec[2]) const {
            int vectorTransformation[2] = {1, 1};
            int counter = 1;
            if (vec[0] < vectorTransformation[0]) 
                vectorTransformation[0] = -1;
            
            if (vec[1] < vectorTransformation[1]) 
                vectorTransformation[1] = -1;

            while(counter < abs(vec[0])) {
                if (board.getPiece(BoardPosition(origin.getRow() + vectorTransformation[0] * counter, origin.getCol() + vectorTransformation[1] * counter))->getTeam() != VACANT)
                    return false;
                counter++;
            }

            return true;
        }


};