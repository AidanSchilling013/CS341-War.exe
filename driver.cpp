// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// aschilling
//valgrind --log-file=valgrind.txt War.exe      use for memory leak test
#include "standardDeck.h"
#include "nonStandardDeck.h"

void distributeDeck(deck &deckDist, deck &deckP1, deck &deckP2, bool dealP1)
{
    deckDist.initializeDeck();
    deckDist.shuffle();

    for (int i = deckDist.getNumCards(); i > 0; i--)
    {
        if (dealP1 == true)
        {
            deckP1.addCard(deckDist.dealCard());
            dealP1 = !dealP1;
        }
        else
        {
            deckP2.addCard(deckDist.dealCard());
            dealP1 = !dealP1;
        }
        }
}

void gameOfWar(deck &deckP1, deck &deckP2, deck &deckBG, Card &lastCard, std::string &lastCardFace, Card &currentCard, std::string &currentCardFace, bool &dealP1)
{
    while ((deckP1.getNumCards() != 0) && (deckP2.getNumCards() != 0))
        {
            if (deckBG.isEmpty())
            {
                if (dealP1 == true)
                {
                    lastCard = deckP1.dealCard();
                    deckBG.addCard(lastCard);
                }
                else{
                    lastCard = deckP2.dealCard();
                    deckBG.addCard(lastCard);
                }
                dealP1 = !dealP1;
            }
            if (dealP1 == true)
            {   
                currentCard = deckP1.dealCard();
                deckBG.addCard(currentCard);
                
                if (currentCard.getFace() == lastCard.getFace())
                {
                    while (!deckBG.isEmpty())
                    {
                        deckP1.addCard(deckBG.dealCard());
                    }
                    deckP1.shuffle();
                    
                }
                else
                {
                    lastCard = currentCard;
                    dealP1 = !dealP1;
                }
            }
            else
            {
                currentCard = deckP2.dealCard();
                deckBG.addCard(currentCard);
                
                if (currentCard.getFace() == lastCard.getFace())
                {
                    while (!deckBG.isEmpty())
                    {
                        deckP2.addCard(deckBG.dealCard());
                    }
                    deckP2.shuffle();
                    
                }
                else
                {
                    lastCard = currentCard;
                    dealP1 = !dealP1;
                }
            }
        }
}

int main()
{
    srand(time(nullptr));

    bool dealP1 = true;
    int winsP1 = 0;
    int winsP2 = 0;
    double scoreP1 = 0.0;
    double scoreP2 = 0.0;
    int nwinsP1 = 0;
    int nwinsP2 = 0;
    double nscoreP1 = 0.0;
    double nscoreP2 = 0.0;

    for (int i = 0; i < 50; i++)
    {
        StandardDeck deckDist; //deck distributed to players 1 and 2
        StandardDeck deckP1; //player 1
        StandardDeck deckP2; //player 2
        StandardDeck deckBG; //battleground for cards you can win
        distributeDeck(deckDist, deckP1, deckP2, dealP1);

        Card lastCard;
        std::string lastCardFace;
        Card currentCard;
        std::string currentCardFace;

        dealP1 = true;
        gameOfWar(deckP1, deckP2, deckBG, lastCard, lastCardFace, currentCard, currentCardFace, dealP1);


        scoreP1 += deckP1.getNumCards();
        scoreP2 += deckP2.getNumCards();

        if (deckP1.isEmpty())
        {
            winsP2++;
        }
        else
        {
            winsP1++;
        }
    }
        
    std::cout << "wins P1: " << winsP1 << " wins P2 " << winsP2 << std::endl;
    std::cout << "player1 average score " << scoreP1/50 << "    player 2 average score " << scoreP2/50 << std::endl;

        
    for (int i = 0; i < 50; i++)
    {
        //moved inside the loop to reset the deck each game
        nonStandardDeck ndeckDist; //deck distributed to players 1 and 2
        nonStandardDeck ndeckP1; //player 1
        nonStandardDeck ndeckP2; //player 2
        nonStandardDeck ndeckBG; //battleground for cards you can win

        distributeDeck(ndeckDist, ndeckP1, ndeckP2, dealP1);

        Card nlastCard;
        std::string nlastCardFace;
        Card ncurrentCard;
        std::string ncurrentCardFace;

        dealP1 = true;
        gameOfWar(ndeckP1, ndeckP2, ndeckBG, nlastCard, nlastCardFace, ncurrentCard, ncurrentCardFace, dealP1);


        nscoreP1 += ndeckP1.getNumCards();
        nscoreP2 += ndeckP2.getNumCards();

        if (ndeckP1.isEmpty())
        {
            nwinsP2++;
        }
        else
        {
            nwinsP1++;
        }
    }
        
        std::cout << "wins P1: " << nwinsP1 << " wins P2 " << nwinsP2 << std::endl;
        std::cout << "player1 average score " << nscoreP1/50 << "    player 2 average score " << nscoreP2/50 << std::endl;
        
            return 0;
    }
    