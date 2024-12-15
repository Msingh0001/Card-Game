#include <iostream>
#include <random>
#include <vector>	
#include <string>

struct Player {
	std::string name;
	int loss;
	int win;

};
struct Opponent {
	std::string name;
	int loss;
	int win;

};
void pTurn();

int main() {
	pTurn();








}
void pTurn() {
	std::cout << " Welcome: " << std::endl;
	Player p1;
	std::string name;
	std::cout << " Please enter your name to begin: " << std::endl;
	std::cin >> name;
	p1.name = name;

	std::cout << "Thank you, " << name << std::endl;

}