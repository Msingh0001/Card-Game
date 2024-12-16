#include <iostream>
#include <random>
#include <vector>	
#include <string>

struct Player {
	std::string name;
	int loss{ 0 };
	int win{ 0 };

};
struct Opponent {
	std::string name;
	int loss{ 0 };
	int win{ 0 };

};


std::vector<std::string>mainDeck();
std::vector<std::string>deck = mainDeck();


std::string pTurn(Player& player);
void draw(std::vector<std::string>deck);
int main() {
	Player p1;
	pTurn(p1);
	draw(deck);


	







}
std::vector<std::string> mainDeck()
{
	return {
		"Ace of Spades", "Ace of Hearts", "Ace of Hearts", "Ace of Clubs", "Ace of Clubs", "Ace of Diamonds", "Ace of Diamonds",
			"2 of Spades", "2 of Spades", "2 of Hearts", "2 of Hearts", "2 of Clubs", "2 of Clubs", "2 of Diamonds", "2 of Diamonds",
			"3 of Spades", "3 of Spades", "3 of Hearts", "3 of Hearts", "3 of Clubs", "3 of Clubs", "3 of Diamonds", "3 of Diamonds",
			"4 of Spades", "4 of Spades", "4 of Hearts", "4 of Hearts", "4 of Clubs", "4 of Clubs", "4 of Diamonds", "4 of Diamonds",
			"5 of Spades", "5 of Spades", "5 of Hearts", "5 of Hearts", "5 of Clubs", "5 of Clubs", "5 of Diamonds", "5 of Diamonds",
			"6 of Spades", "6 of Spades", "6 of Hearts", "6 of Hearts", "6 of Clubs", "6 of Clubs", "6 of Diamonds", "6 of Diamonds",
			"7 of Spades", "7 of Spades", "7 of Hearts", "7 of Hearts", "7 of Clubs", "7 of Clubs", "7 of Diamonds", "7 of Diamonds",
			"8 of Spades", "8 of Spades", "8 of Hearts", "8 of Hearts", "8 of Clubs", "8 of Clubs", "8 of Diamonds", "8 of Diamonds",
			"9 of Spades", "9 of Spades", "9 of Hearts", "9 of Hearts", "9 of Clubs", "9 of Clubs", "9 of Diamonds", "9 of Diamonds",
			"10 of Spades", "10 of Spades", "10 of Hearts", "10 of Hearts", "10 of Clubs", "10 of Clubs", "10 of Diamonds", "10 of Diamonds",
			"Jack of Spades", "Jack of Spades", "Jack of Hearts", "Jack of Hearts", "Jack of Clubs", "Jack of Clubs", "Jack of Diamonds", "Jack of Diamonds",
			"Queen of Spades", "Queen of Spades", "Queen of Hearts", "Queen of Hearts", "Queen of Clubs", "Queen of Clubs", "Queen of Diamonds", "Queen of Diamonds",
			"King of Spades", "King of Spades", "King of Hearts", "King of Hearts", "King of Clubs", "King of Clubs", "King of Diamonds", "King of Diamonds"
	};


	
}
std::string pTurn(Player& player) {
	std::cout << " Welcome: " << std::endl;
	std::string name;
	std::cout << " Please enter your name to begin: " << std::endl;
	std::cin >> name;
	player.name = name;
    
	std::cout << " Thank you, " << name << '\n' << "Scoreboard: " << '\n'
		<< "Wins: " << player.win << '\n' << "Losses: " << player.loss << std::endl;

	return player.name;
}

void draw(std::vector<std::string>deck)
{
	std::cout << "Press (D)raw to draw 5 cards: " << std::endl;
	char command{ 'x' };
	std::cin >> command;

	if (command == 'd' || command =='D')
	{
		for (int i{ 0 }; i < 5; i++) {
			std::random_device seed1;
			std::default_random_engine e(seed1());
			std::uniform_int_distribution<int> d(0, deck.size() - 1);
			int random = d(e);
			std::cout << deck.at(random) << '\n';
		}
	}
	else {
		std::cout << " Please enter a valid input " << std::endl;
	}
}
