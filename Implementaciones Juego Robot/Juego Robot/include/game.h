#ifndef GAME_H
#define GAME_H


class game
{
    public:
        game(int Moves);
        virtual ~game();

        int setRemainingMoves(int Moves);
        int getRemainingMoves();

        void reduceMoves();


    protected:

    private:
        int remainingMoves;
};

#endif // GAME_H
