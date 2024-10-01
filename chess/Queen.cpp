#include <string>
#include "generalTypes.hpp"

class Queen : public Piece {

    public:
        Queen::Queen() : Piece("Queen") {}

        Queen::Queen(Team chosenTeam) {
            if(chosenTeam < 1) {
                throw InvalidTeamError("Queen cannot be vacant");
            }
            team = chosenTeam;
            specialMove = false;
            name = "Queen";
        }

        bool Queen::validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) const{
            return (RookMovement(origin, dest, vec) || BishopMovement(origin, dest, vec));
        }

        bool Queen::BishopMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) const {
            int rowDisplacement = dest.getRow() - origin.getRow();
            int colDisplacement = dest.getCol() - origin.getCol();

            if (abs(rowDisplacement/colDisplacement) == 1){
                vec[0] = rowDisplacement;
                vec[1] = colDisplacement;
                return true;
            }
            
            return false;
        }

		bool Queen::boardContextMovement(const Board& board, const BoardPosition& origin, const BoardPosition& dest, const int vec[2]) const {
            if (vec[0] == 0 || vec[1] == 0) {
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
            } else {
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
        }

        bool Queen::RookMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) const {
            int rowDisplacement = dest.getRow() - origin.getRow();
            int colDisplacement = dest.getCol() - origin.getCol();

            if (rowDisplacement == 0 || colDisplacement == 0){
                vec[0] = rowDisplacement;
                vec[1] = colDisplacement;
                return true;
            }
            
            return false;
        }
};