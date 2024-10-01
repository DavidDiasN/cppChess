#include <string>
#include "generalTypes.hpp"

class BoardPosition {
  	public:
        int BoardPosition::getRow() const { return row; }
        int BoardPosition::getCol() const { return col; }

		bool BoardPosition::operator==(const BoardPosition& pos) {
            return (row == pos.row && col == pos.col);
        }

		BoardPosition::BoardPosition(): row{0}, col{0} { }

		BoardPosition::BoardPosition(int in_row, int in_col) {
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

class Piece {
  	public:
        Piece(): team{WHITE}, specialMove{false} {}
        Piece(std::string name) : name{name}, team{WHITE}, specialMove{false} {}
        Piece(Team team, bool specialMove) : team{team}, specialMove{specialMove} {}
        virtual bool validMovement(const Board& board, const Piece& origin, const Piece& dest) = 0;
		Team Piece::getTeam() const { return team; } const 
		std::string Piece::getName(){return name; } const
        bool Piece::hasSpecialMove() const { return specialMove; }

	protected:
        std::string name;
		Team team;
        bool specialMove;
};
