#include "generalTypes.hpp"
#include <array>
#include <string>

class Board {
	public:
        const std::array<std::array<int, 2>, 4> knightTransformations = {{{2, 0}, {-2, 0}, {0, 2}, {0, -2}}};
        const std::array<std::array<int, 2>, 4> rookTransformations = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
        const std::array<std::array<int, 2>, 4> bishopTransformations = {{{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}};

		Piece* Board::getPiece(BoardPosition pos) const {
            return board[pos.getRow()][pos.getCol()];
        }

		void Board::movePiece(BoardPosition origin, BoardPosition dest) {
            if(origin == dest || getPiece(origin)->getTeam() == getPiece(dest)->getTeam()) 
                return;

            int vec[2] = {0, 0};

            // the is it possible for the piece section
            
            if (!getPiece(origin)->validMovement(origin, dest, vec))
                return;

            // check if the path a piece takes is greateer than 1 in vec[0] and vec[1]
            if (!getPiece(origin)->boardContextMovement(*this, origin, dest, vec))
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

        bool Board::positionIsUnderAttack(BoardPosition pos, Piece& originPiece) const {

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


            // for loop that runs until it reaches board[0] or board[7] in row or column
            // if the loop finds an enemy piece of type Queen, rook, or bishop it will terminate.

            // for knight loop it should simply check valid positions that result from the knight transform.

            // pawns can only be in one of two positions to be a threat.

            // kings can be anywhere around so a simple check on all the squares around pos is needed.




            for (int i = 0; )




            return false;
        }


        Board() {
            Piece*** board = new Piece**[8];
            for (int i = 0; i <= 7; i++) {
                board[i] = new Piece*[8];
            }
        }

	private:
		std::array<std::array<Piece*,8>, 8> board;
		BoardPosition inPassingPiece;

        inline bool checkPieceType(Piece* piece, std::string&& typeName) const {
            return piece->getName() == typeName;
        }

        inline bool inBounds(int num) const {
            return (num > 7 || num < 0);
        }

        bool Board::pawnThreat(BoardPosition pos, Team enemyTeam, int direction) const {
            int rowDisp = pos.getRow() + direction;
            int colPlus1 = pos.getCol()+1;
            int colMinus1 = colPlus1-2;

            if(!inBounds(rowDisp) || !inBounds(colPlus1) || !inBounds(colMinus1))
                return false;

            Piece* threatPiece1 = getPiece(BoardPosition(rowDisp, colPlus1));
            Piece* threatPiece2 = getPiece(BoardPosition(rowDisp, colMinus1));

            bool threat1 = (threatPiece1->getTeam() == enemyTeam && checkPieceType(threatPiece1, "Pawn"));
            bool threat2 = (threatPiece2->getTeam() == enemyTeam && checkPieceType(threatPiece2, "Pawn"));

            return threat1 || threat2;
        }

        bool Board::KnightThreat(BoardPosition pos, Team enemyTeam) const {
            for(std::array<int, 2> x: knightTransformations) {
                if(x[0] == 0) {
                    
                    int colDisp = pos.getCol() + x[1];
                    if (!inBounds(colDisp))
                        return false;
                    int rowPlus1 = pos.getRow() + 1;
                    if (!inBounds(rowPlus1))
                        return false;
                    int rowMinus1 = rowPlus1 - 2;
                    if (!inBounds(rowMinus1))
                        return false;

                    Piece* threatPiece1 = getPiece(BoardPosition(rowPlus1, colDisp));
                    Piece* threatPiece2 = getPiece(BoardPosition(rowMinus1, colDisp));

                    bool threat1 = (threatPiece1->getTeam() == enemyTeam && checkPieceType(threatPiece1, "Knight"));
                    bool threat2 = (threatPiece2->getTeam() == enemyTeam && checkPieceType(threatPiece2, "Knight"));
                    if (threat1 || threat2) {
                        return true;
                    }
                    
                } else {
                    int rowDisp = pos.getRow() + x[0];
                    if (!inBounds(rowDisp))
                        return false;
                    int colPlus1 = pos.getCol() + 1;
                    if (!inBounds(colPlus1))
                        return false;
                    int colMinus1 = colPlus1 - 2;
                    if (!inBounds(colMinus1))
                        return false;
                    
                    Piece* threatPiece1 = getPiece(BoardPosition(rowDisp, colPlus1));
                    Piece* threatPiece2 = getPiece(BoardPosition(rowDisp, colMinus1));

                    bool threat1 = (threatPiece1->getTeam() == enemyTeam && checkPieceType(threatPiece1, "Knight"));
                    bool threat2 = (threatPiece2->getTeam() == enemyTeam && checkPieceType(threatPiece2, "Knight"));
                    if (threat1 || threat2) {
                        return true;
                    }
                }
            }
            return false;
        }


        bool Board::rookThreat(BoardPosition pos, Team enemyTeam) const {
            
            for(std::array<int, 2> x: rookTransformations) {
                int multi = 1;

                int rowDisp = pos.getRow() + x[0] * multi;
                int colDisp = pos.getCol() + x[1] * multi;

                while(inBounds(colDisp && rowDisp)) {
                    rowDisp = pos.getRow() + x[0] * multi;
                    colDisp = pos.getCol() + x[1] * multi;
                    Piece* threatPiece = getPiece(BoardPosition(rowDisp, colDisp));
                    if(threatPiece->getTeam() == enemyTeam ) {
                        if(multi == 1 && checkPieceType(threatPiece, "King"))
                            return true;
                        else if (checkPieceType(threatPiece, "Rook") || checkPieceType(threatPiece, "Queen"))
                            return true; 
                        else 
                            break;
                    } else if (threatPiece->getTeam() == VACANT) {
                        multi++;
                        continue;
                    } else 
                        break;
                }
            }

            return false;
        }

        bool Board::bishopThreat(BoardPosition pos, Team enemyTeam) const {
            
            for(std::array<int, 2> x: bishopTransformations) {
                int multi = 1;

                int rowDisp = pos.getRow() + x[0] * multi;
                int colDisp = pos.getCol() + x[1] * multi;

                while(inBounds(colDisp && rowDisp)) {
                    rowDisp = pos.getRow() + x[0] * multi;
                    colDisp = pos.getCol() + x[1] * multi;
                    Piece* threatPiece = getPiece(BoardPosition(rowDisp, colDisp));
                    if(threatPiece->getTeam() == enemyTeam ) {
                        if(multi == 1 && checkPieceType(threatPiece, "King"))
                            return true;
                        else if (checkPieceType(threatPiece, "Bishop") || checkPieceType(threatPiece, "Queen"))
                            return true; 
                        else 
                            break;
                    } else if (threatPiece->getTeam() == VACANT) {
                        multi++;
                        continue;
                    } else 
                        break;
                }
            }

            return false;
        }


};
