
#include <string>
#include "generalTypes.hpp"


class King : public Piece {

    public:
        King(){};

        King(Team chosenTeam) {};

        bool validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) {};

		bool boardContextMovement(const Board& board, const BoardPosition& origin, const BoardPosition& dest, const int vec[2]) const {};

        bool getHasMoved() const {}

        void completedFirstMove() {};

    private:
        bool hasMoved;
};

class Queen : public Piece {

    public:
        Queen(){};

        Queen(Team chosenTeam) {};

        bool validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) const{};

        bool BishopMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) const {};

		bool boardContextMovement(const Board& board, const BoardPosition& origin, const BoardPosition& dest, const int vec[2]) const {};

        bool RookMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) const {};
};

class Bishop : public Piece {

    public:
        Bishop() {};

        Bishop(Team chosenTeam) {};

        bool validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) {};


		bool boardContextMovement(const Board& board, const BoardPosition& origin, const BoardPosition& dest, const int vec[2]) const {};
};


class Knight : public Piece {

    public:
        Knight() {};

        Knight(Team chosenTeam) {};

        bool validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) {};


		bool boardContextMovement(const Board& board, const BoardPosition& origin, const BoardPosition& dest, const int vec[2]) const {};

        bool hasSpecialMove() {};
};


class Rook : public Piece {

    public:
        Rook() {};

        Rook(Team chosenTeam) {};

        bool validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) {};

		bool boardContextMovement(const Board& board, const BoardPosition& origin, const BoardPosition& dest, const int vec[2]) const {};

        bool getHasMoved() const {};

        void completedFirstMove() {};

        bool hasSpecialMove() {}; 

    private:
        bool hasMoved;
};


class Pawn : public Piece {
    public:
        Pawn() {};

        Pawn(Team chosenTeam) {};

        bool validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) const{};

		bool boardContextMovement(const Board& board, const BoardPosition& origin, const BoardPosition& dest, const int vec[2]) const {};


        bool hasSpecialMove() {};


    private:
        int direction;

        int validPawnAttack(BoardPosition origin, BoardPosition dest) {};

        bool validForwardMovement(BoardPosition origin, BoardPosition dest) const{};

        bool validInPassingMove(Board board, BoardPosition origin, BoardPosition dest, int attackDirection) {};
    
};


class Vacant : public Piece {
    public:
        Vacant() {};

        Team getTeam() {};

        bool validMovement(const BoardPosition& origin, const BoardPosition& dest, int vec[2]) const {};

        bool hasSpecialMove() {};
};


