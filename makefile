# Honor Pledge:
#
#I pledge that I have neither given nor
# received any help on this assignment.
#
#eval "$(ssh-agent -s)"   
#ssh-add ~/.ssh/id_ed25519_github

# aschilling

War.exe: Driver.o card.o standardDeck.o  deck.o nonStandardDeck.o
	g++ Driver.o card.o standardDeck.o  deck.o nonStandardDeck.o -o War.exe 

Driver.o: driver.cpp
	g++ -c driver.cpp -o Driver.o

card.o: card.cpp
	g++ -c card.cpp -o card.o

Card.o: Card.cpp
	g++ -c Card.cpp -o Card.o

nonStandardDeck.o: nonStandardDeck.cpp
	g++ -c nonStandardDeck.cpp -o nonStandardDeck.o

deck.o: deck.cpp
	g++ -c deck.cpp -o deck.o

standardDeck.o: standardDeck.cpp
	g++ -c standardDeck.cpp -o standardDeck.o

clear:
	rm *.o War.exe

run:
	War.exe