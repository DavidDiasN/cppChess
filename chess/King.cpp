#include <string>
#include "generalTypes.hpp"


class King : PieceStrategy {

    public:
        King::King() {
            team = WHITE;
            hasMoved = false;
        }

        King::King(Team chosenTeam) {
            if(chosenTeam < 1) {
                throw InvalidTeamError("Pawn cannot be vacant");
            }
            team = chosenTeam;
            hasMoved = false;
        }

        bool King::validMovement(const BoardPosition& origin, const BoardPosition& dest) {
            int rowDisplacement = 0;
            int colDisplacement = 0;

            if(origin.getRow() > dest.getRow()) 
                rowDisplacement = origin.getRow() - dest.getRow();
            else
                rowDisplacement = dest.getRow() - origin.getRow();
            
            if(origin.getCol() > dest.getCol()) 
                rowDisplacement = origin.getCol() - dest.getCol();
            else
                colDisplacement = dest.getCol() - origin.getCol();

            if(rowDisplacement <= 1 && colDisplacement <= 1)
                return true;
            if(basicCastleCheck(origin, dest))
                return true;
            return false;
        }


        bool basicCastleCheck(const BoardPosition& origin, const BoardPosition& dest) {
            if(hasMoved)
                return false;
            if(dest.getCol() == origin.getCol() + 2)
                return true;
            
            return false;
        }

        bool King::getHasMoved() const {
            return hasMoved;
        }

        void King::completedFirstMove() {
            hasMoved = true;
        }

    private:
        Team team;
        bool hasMoved;

};