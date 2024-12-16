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
std::vector<std::string>mydeck = mainDeck();
std::vector<std::string>opponentdeck = mainDeck();
std::vector<Opponent>list();
std::vector<Opponent>myOpps = list();
std::vector<std::string> playerHand;
std::vector<std::string>opponentHand;

void clearScreen();
void pause();
std::string pTurn(Player& player, std::vector<std::string>& deck);
void draw(std::vector<std::string>&mydeck, std::vector<std::string>&playerhand, Player& player);
void chooseOpp(std::vector<std::string>&deck, std::vector<Opponent>&myOpps, Opponent& opponent);
void oDraw(std::vector<std::string>&opponentdeck, std::vector<Opponent>& myOpps, Opponent& o, std::vector<std::string>&opponentHand);
int cardValue(const std::string& card);
int calculate(std::vector<std::string>& hand);
int main() {
	Player p1;
	Opponent o;
	pTurn(p1, mydeck);

	for (auto& o : myOpps)
	{
		int game{ 1 };
		while (p1.loss < 4 && o.loss < 4 && p1.win < 4 && o.win < 4)
		{

			pause();
			clearScreen();
			int opponentscore = 0;
			int playerscore = 0;
			playerHand.clear();
			opponentHand.clear();

			draw(mydeck, playerHand, p1);
			chooseOpp(opponentdeck, myOpps, o);
			oDraw(opponentdeck, myOpps, o, opponentHand);
			playerscore = calculate(playerHand);
			
			std::cout << '\n' << '\n' << "Game: " << game++ << " Your current score is : " << playerscore << " pts" << std::endl;
			opponentscore = calculate(opponentHand);
			std::cout << " Your Opponents score is : " << opponentscore << " pts " << std::endl;

			if (playerscore > opponentscore) {
				p1.win++;
				o.loss++;
			}
			if (playerscore < opponentscore) {
				p1.loss++;
				o.win++;
			}

			std::cout << " Current Stats: " << '\n' << '\n' << "Player: " << '\n' << "Wins: " << p1.win << '\n' << "Losses: "
				<< '\n' << p1.loss << '\n' << '\n' << "Opponent:" << '\n' << "Wins : " << o.win << '\n' << "Losses: " << o.loss << std::endl;

		}






	}



	if (o.loss == 4 || p1.win ==4) {
		std::cout << "You have defeated " << o.name << "!" << std::endl;
	}
	if (o.win == 4 || p1.loss ==4) {
		std::cout << " Congratulations! You won " << std::endl;
	}
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
std::vector<Opponent> list()
{
	return{ { "Zaroth the Devourer", 0, 0 },
	{ "Vixira, Mistress of Shadows", 0, 0 },
	{ "Korvax the Eternal", 0, 0 },
	{ "Mordrith, Lord of the Abyss", 0, 0 },
	{ "Nyxxa, Queen of Nightmares", 0,0 },
	{ "Skragoth the Destroyer", 0, 0 } }
	;
}
void clearScreen()
{
	system("cls");
}
void pause()
{
	std::cout << "\nPress Enter to continue: " << std::endl;
	std::cin.ignore();
std::cin.get();
}
std::string pTurn(Player& player, std::vector<std::string>&mydeck) {
	std::cout << " Welcome: " << std::endl;
	std::string name;
	std::cout << " Please enter your name to begin: " << std::endl;
	std::cin >> name;
	player.name = name;
    
	
	
	return player.name;
}

void draw(std::vector<std::string>&mydeck, std::vector<std::string>&playerhand, Player& player)
{
	std::cout << "Press (D)raw to draw 5 cards: " << std::endl;
	char command{ 'x' };
	std::cin >> command;

	if (command == 'd' || command =='D')
	{
		for (int i{ 0 }; i < 5; i++) {
			std::random_device seed1;
			std::default_random_engine e(seed1());
			std::uniform_int_distribution<int> d(0, mydeck.size() - 1);
			int random = d(e);
			std::cout << mydeck.at(random) << '\n';
			playerHand.push_back(mydeck.at(random));
			mydeck.erase(mydeck.begin() +random);
		}
	}
	else {
		std::cout << " Please enter a valid input " << std::endl;
	}
	std::cout << " Thank you, " << player.name;
	
	
}

void chooseOpp(std::vector<std::string>& opponentdeck, std::vector<Opponent>&myOpps, Opponent& opponent)
{
	Opponent o;
	std::cout << " Would you like to (C)ontinue?" << std::endl;
	char cinput;
	std::cin >> cinput;

	if (cinput == 'c' || cinput == 'C')
	{
		std::cout << "Please select an Opponent to Play against: " << std::endl;
		for (int i{ 0 }; i < myOpps.size(); i++) {
			std::cout << i + 1 << " " << myOpps[i].name << '\n';
		}
		int input;
		std::cin >> input;

		switch (input) {
		case 1: std::cout << "You have chosen " << myOpps[0].name << '\n' << std::endl;
		break;
		case 2: std::cout << " You have chosen " << myOpps[1].name << '\n' << std::endl;
			break;
		case 3: std::cout << " You have chosen " << myOpps[2].name << '\n' << std::endl;
			break;
		case 4: std::cout << " You have chosen " << myOpps[3].name << '\n' << std::endl;
		break;
		case 5: std::cout << " You have chosen " << myOpps[4].name << '\n' << std::endl;
			break;
		case 6: std::cout << " You have chosen " << myOpps[5].name << '\n' << std::endl;
			break;
		default : 
			std::cout << "Please enter a valid input: " << std::endl;

		}

		opponent = myOpps[input-1];
	}
	else {
		std::cout << " Please enter correct input: " << std::endl;
	}
	
}

void oDraw(std::vector<std::string>&opponentdeck, std::vector<Opponent>& myOpps, Opponent& o, std::vector<std::string>&opponentHand)
{
	std::cout << "Press (D)raw to let " << o.name << " draw 5 cards: " << std::endl;
	char command{ 'x' };
	std::cin >> command;

	if (command == 'd' || command == 'D')
	{
		for (int i{ 0 }; i < 5; i++) {
			std::random_device seed1;
			std::default_random_engine e(seed1());
			std::uniform_int_distribution<int> d(0, opponentdeck.size() - 1);
			int random = d(e);
			std::cout << opponentdeck.at(random) << '\n';
			opponentHand.push_back(opponentdeck.at(random));
			opponentdeck.erase(opponentdeck.begin() + random);
		}
	}
	else {
		std::cout << " Please enter a valid input " << std::endl;
	}
	
	
}

int cardValue(const std::string& card)
{
	if (card.find("Ace") != std::string::npos) return 14;
	if (card.find("King") != std::string::npos) return 13;
	if (card.find("Queen") != std::string::npos) return 12;
	if (card.find("Jack") != std::string::npos) return 11;
	if (card.find("10") != std::string::npos) return 10;
	if (card.find("9") != std::string::npos) return 9;
	if (card.find("8") != std::string::npos) return 8;
	if (card.find("7") != std::string::npos) return 7;
	if (card.find("6") != std::string::npos) return 6;
	if (card.find("5") != std::string::npos) return 5;
	if (card.find("4") != std::string::npos) return 4;
	if (card.find("3") != std::string::npos) return 3;
	if (card.find("2") != std::string::npos) return 2;

	
}

int calculate(std::vector<std::string>& hand)
{
	int score{ 0 };

	for (const auto cards : hand) {
		score += cardValue(cards);
	}
	return score;
}

