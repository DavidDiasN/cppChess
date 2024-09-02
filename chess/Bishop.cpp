#include <string>
#include "generalTypes.hpp"


class Bishop : PieceStrategy {

    public:
        Bishop::Bishop() {
            team = WHITE;
        }

        Bishop::Bishop(Team chosenTeam) {
            if(chosenTeam < 1) {
                throw InvalidTeamError("Pawn cannot be vacant");
            }
            team = chosenTeam;
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

        bool Bishop::hasSpecialMove() {
            return specialMove;
        }


    private:
        Team team;
        bool specialMove;

};