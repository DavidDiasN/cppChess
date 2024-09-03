#ifndef generalTypes
#define generalTypes
#include <string>

enum Team {
	VACANT,
  	WHITE,
  	BLACK
};

class BoardPosition {
  	public:
    	int getRow() const;
    	int getCol() const;
		bool operator==(const BoardPosition& pos);
		BoardPosition();
		BoardPosition(int row, int col);
  	private:
    	int row;
    	int col;
};

class Board {
	public:
		PieceStrategy getPiece(BoardPosition pos) const;	
		void movePiece(BoardPosition origin, BoardPosition dest);
		BoardPosition getInPassingPiece() const;

	private:
		BoardPosition board[8][8];
		BoardPosition inPassingPiece;
};

class PieceStrategy {
  	public:
        virtual bool validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) const = 0;
		virtual bool boardContextMovement(const Board& board, const BoardPosition& origin, const BoardPosition& dest, const int vec[2]) const = 0;
		virtual Team getTeam() const = 0;
	
	private:
		Team team;
		bool specialMove;
};

class BoardBoundsError {
	public:
		BoardBoundsError::BoardBoundsError() {
			message = "Unnamed BoardBoundsError";
		}

		BoardBoundsError::BoardBoundsError(std::string errorMessage) {
			message = errorMessage;
		}

	private:
		std::string message;

};

class InvalidTeamError {
	public:
		InvalidTeamError::InvalidTeamError() {
			message = "Unnamed Invalid Team Error";
		}

		InvalidTeamError::InvalidTeamError(std::string errorMessage) {
			message = errorMessage;
		}

	private:
		std::string message;

};

#endif
