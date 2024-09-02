#include "generalTypes.hpp"



class Pawn : PieceStrategy {
    public:
        Pawn::Pawn() {
            team = WHITE;
            direction = -1;
        }

        Pawn::Pawn(Team chosenTeam) {
            if(chosenTeam < 1) {
                throw InvalidTeamError("Pawn cannot be vacant");
            }
            team = chosenTeam;
            if(team == 1) {
                direction = -1;
                return;
            }
            direction = 1;
        }

        bool Pawn::validMovement(const BoardPosition& origin, const BoardPosition& dest) const{
            if (origin.getCol() + direction == dest.getRow() && (origin.getCol() + 1 == dest.getCol() || origin.getCol() - 1 == dest.getCol())) 
                return true;

            if (validForwardMovement(origin, dest))
                return true;

            return false;
        }


    private:
        Team team;
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



