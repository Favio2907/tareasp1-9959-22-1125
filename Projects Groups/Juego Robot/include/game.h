#ifndef GAME_H
#define GAME_H


class game
{
    public:
        game(int Moves, int Moves2, int Moves3);
        virtual ~game();

        int setRemainingMoves(int Moves);
        int getRemainingMoves();
        int setRemainingMoves2(int Moves2);
        int getRemainingMoves2();
        int setRemainingMoves3(int Moves3);
        int getRemainingMoves3();

        void reduceMoves();
        void reduceMoves2();
        void reduceMoves3();


    protected:

    private:
        int remainingMoves;
        int remainingMoves2;
        int remainingMoves3;
};

#endif // GAME_H
