#include "generalTypes.hpp"
#include <string>



class Pawn : public Piece {
    public:
        Pawn::Pawn() : Piece("Pawn", WHITE, true), direction{-1} {}

        Pawn::Pawn(Team chosenTeam) {
            if (chosenTeam == 2) 
                direction = 1;
            else if(team == 1)
                direction = -1;
            else
                throw InvalidTeamError("Pawn cannot be vacant");

            team = chosenTeam;
            specialMove = true;
            name = "Pawn";
        }

        bool Pawn::validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) const{
            // no movement in col means this is not an attack move.
            if (origin.getCol() == dest.getCol()) {
                if (origin.getRow() + direction == dest.getRow()) {
                    vec[0] = direction;
                    vec[1] = 0;
                    return true;
                } else if (origin.getRow() + direction * 2 == dest.getRow() && origin.getRow() == 1 || origin.getRow() == 6) {
                    vec[0] = direction * 2;
                    vec[1] = 0;
                    return true;
                } else {
                    return false;
                }
            }

            int rowDisplacement = dest.getRow() - origin.getRow();
            int colDisplacement = dest.getCol() - origin.getCol();

            if (rowDisplacement = direction && abs(colDisplacement) == 1) {
                vec[0] = direction;
                vec[1] = colDisplacement;
                return true;
            } 

            return false;
        }

		bool Pawn::boardContextMovement(const Board& board, const BoardPosition& origin, const BoardPosition& dest, const int vec[2]) const {
            if (vec[1] == 0) {
                if (board.getPiece(BoardPosition(origin.getRow() + direction, origin.getCol()))->getTeam() == VACANT) {
                    if (vec[0] == direction) 
                        return true;
                    else if (board.getPiece(BoardPosition(origin.getRow() + direction * 2, origin.getCol()))->getTeam() == VACANT)
                        return true;
                    else
                        return false;
                }
            }

            Team destinationTeam = board.getPiece(BoardPosition(origin.getRow() + vec[0], origin.getCol() + vec[1]))->getTeam(); 
            if (destinationTeam != team && destinationTeam != VACANT) 
                return true;

            if (BoardPosition(origin.getRow(), origin.getCol() + vec[1]) == board.getInPassingPiece()) 
                return true;

            return false;
        }


        bool Pawn::hasSpecialMove() {
            return specialMove;
        }


    private:
        int direction;

        int validPawnAttack(BoardPosition origin, BoardPosition dest) {

        if ((dest.getRow() == origin.getRow() + direction) && dest.getCol() == origin.getCol() + 1) 
            return 1;

        if ((dest.getRow() == origin.getRow() + direction) && dest.getCol() == origin.getCol() - 1)
            return -1;

        return 0;
        }

        bool validForwardMovement(BoardPosition origin, BoardPosition dest) const{
            if (dest.getCol() != origin.getCol()) 
                return false;

            if (dest.getRow() == origin.getRow() + direction)
                return true;

            if (team == BLACK && origin.getRow() == 1 || origin.getRow() == 6 && team == WHITE) {
                if (dest.getRow() == origin.getRow() + direction || dest.getRow() == origin.getRow() + 2 * direction)
                    return true;
            }

            return false;
        }

        bool validInPassingMove(Board board, BoardPosition origin, BoardPosition dest, int attackDirection) {
            bool validDestination = (board.getInPassingPiece() == BoardPosition(dest.getRow() - attackDirection, dest.getCol()));
            bool validOrigin = (board.getInPassingPiece().getRow() == origin.getRow() && board.getInPassingPiece().getCol() == origin.getCol() + attackDirection);
            return (validDestination && validOrigin);
        }
    
};



