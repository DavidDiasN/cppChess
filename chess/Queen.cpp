#include <string>
#include "generalTypes.hpp"


class Queen : PieceStrategy {

    public:
        Queen::Queen() {
            team = WHITE;
        }

        Queen::Queen(Team chosenTeam) {
            if(chosenTeam < 1) {
                throw InvalidTeamError("Pawn cannot be vacant");
            }
            team = chosenTeam;
        }

        bool Queen::validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) const{
            return (RookMovement(origin, dest, vec) || BishopMovement(origin, dest, vec));
        }

        bool Queen::BishopMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) const {
            int rowDisplacement = dest.getRow() - origin.getRow();
            int colDisplacement = dest.getCol() - origin.getCol();

            if (rowDisplacement/colDisplacement == 1 || rowDisplacement/colDisplacement == -1){
                vec[0] = rowDisplacement;
                vec[1] = colDisplacement;
                return true;
            }
            
            return false;
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

        bool Queen::hasSpecialMove() {
            return specialMove;
        } 


    private:
        Team team;
        bool specialMove;

};