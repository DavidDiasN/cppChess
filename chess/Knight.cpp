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

        bool Knight::validMovement(const BoardPosition& origin, const BoardPosition& dest) {
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
            
            if(rowDisplacement == 1 && colDisplacement == 2 || rowDisplacement == 2 && colDisplacement == 1)
                return true;

            return false;
        }


    private:
        Team team;

};