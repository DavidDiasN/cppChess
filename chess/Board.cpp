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

        bool Board::positionIsUnderAttack() const {
            // at every step of checks you will simply need to 
            // each piece type will be searched for until either a firendly piece is found to be obstructing the attack path
            // or the board goes out of bounds.
            // each type of pieces attack path will need to be investigated which essentially means 
            // we will search for any and all lines of attack

            // bishop line of attack will return true if searching the attack vectors returns a bishop of the enemy side
            // or a queen of the enemy side.
            // same goes for the rook.

            // knight will be easy, you simply need to look for an enemy knight at any valid knight square and if there is a knight
            // you need to check if its team is not equal to your team.

            // checking for kings and pawns should be pretty easy. 
            // whites king can only be threatened by an enemy pawn that is -1 rows and + or -1 colums away from it.
            // vice versa for black

            // either king can only be threatened by antoher king if their position is one hop from another king




            return false;
        }

	private:
		BoardPosition board[8][8];
		BoardPosition inPassingPiece;
};
