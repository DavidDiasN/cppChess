#include "generalTypes.hpp"

class Board {
	public:
		PieceStrategy Board::getPiece(BoardPosition pos) const	{

        }
		void Board::movePiece(BoardPosition origin, BoardPosition dest) {
            if(origin == dest || this->getPiece(origin).getTeam() == this->getPiece(dest).getTeam()) 
                return;

            int vec[2] = {0, 0};

            // the is it possible for the piece section
            
            if (!this->getPiece(origin).validMovement(origin, dest, vec))
                return;

            // check if the path a piece takes is greateer than 1 in vec[0] and vec[1]
            if (!this->getPiece(origin).boardContextMovement(*this, origin, dest, vec))
                return;




            // end of is it possible for the piece section


            // now I have a vector that I can use to iterate through a pieces movement path.
            // with the vector I will check every piece of the board on the pieces path until I 
            // hit the final movement where I will need to check if that space is a vacant piece
            // or an enemy piece. If it is an enemy piece that will involve invoking a eatPiece() function
            // still need to code the check checker

            // REMEMBER TO CREATE THE STATE ENUM FOR CFP(CLEAR FOR PLAY), CHECK, and CHECKMATE.


            // a user can move during a state of CFP and CHECK.

            // if clear for play after a move the enemy king and the players king will be checked for a check state
            // if in check the move must resolve check to CFP. the board will also be evaluated for discovered check.

            // if a castle move is made special rules about moving through check must be made.
            // during in passing special checks must also be made.


            // the end of this void functino should invoke other functions that will update the board and call 
            // some method that will allow the viewing object to update its view and display any text needed.
            // may need to call this function with some output stream object.


            //ANY PIECE WITH A HAS MOVED FIELD MUST BE UPDATED AT THE END OF EVERY SUCCESSFUL TURN. NO EXCEPCTIONS
            //THE IN PASSING PIECE ALSO MUST BE UPDATED AT THE END OF ANY TURN THAT STARS WITH A NONE VACANT
            // IN PASSING PIECE

        }

		BoardPosition Board::getInPassingPiece() const {
            return inPassingPiece;
        }

	private:
		BoardPosition board[8][8];
		BoardPosition inPassingPiece;
};
