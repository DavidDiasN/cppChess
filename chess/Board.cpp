#include "generalTypes.hpp"

class Board {
	public:
		PieceStrategy Board::getPiece(BoardPosition pos) const	{

        }
		void Board::movePiece(BoardPosition origin, BoardPosition dest) {
            if(origin == dest || this->getPiece(origin).getTeam() == this->getPiece(dest).getTeam()) 
                return;
            
            if(!this->getPiece(origin).validMovement(origin, dest))
                return;


            // the end of this void functino should invoke other functions that will update the board and call 
            // some method that will allow the viewing object to update its view and display any text needed.
            // may need to call this function with some output stream object.

        }

		BoardPosition Board::getInPassingPiece() const {
            return inPassingPiece;
        }

	private:
		BoardPosition board[8][8];
		BoardPosition inPassingPiece;
};
