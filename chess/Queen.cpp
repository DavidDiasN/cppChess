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

        bool Queen::validMovement(const BoardPosition& origin, const BoardPosition& dest) const{
            return (RookMovement(origin, dest) || BishopMovement(origin, dest));
        }

        bool Queen::BishopMovement(const BoardPosition& origin, const BoardPosition& dest) const {
            if(origin.getRow() == dest.getRow() || origin.getCol() == dest.getCol()) 
                return false;

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

            if(rowDisplacement == colDisplacement)
                return true;
            
            return false;
        }

        bool Queen::RookMovement(const BoardPosition& origin, const BoardPosition& dest) const {
            if((origin.getRow() == dest.getRow()) != (origin.getCol() == dest.getCol())) 
                return true;

            return false;
        }


    private:
        Team team;

};