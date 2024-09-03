#include <string>
#include "generalTypes.hpp"

class BoardPosition {
  	public:
        int BoardPosition::getRow() const {


            return row;
        }

        int BoardPosition::getCol() const {


            return col;
        }

		bool BoardPosition::operator==(const BoardPosition& pos) {
            return (row == pos.row && col == pos.col);
        }
		BoardPosition::BoardPosition(){
            row = 0;
            col = 0;
        }
		BoardPosition::BoardPosition(int in_row, int in_col){
            if(in_row < 8 && in_row >= 0 && in_col < 8 && in_col >= 0) {
                row = in_row;
                col = in_col;
            } else {
                throw BoardBoundsError("Board Position initialized with invalid paramters");
            }
        }
  	private:
    	int row;
    	int col;
};

class PieceStrategy {
  	public:
        virtual bool validMovement(const Board& board, const PieceStrategy& origin, const PieceStrategy& dest) = 0;
		virtual Team getTeam() const = 0;
	
	private:
		Team team;
};