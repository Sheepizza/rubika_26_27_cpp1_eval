#include "RandomStrategy.h"
#include <ctime>

RandomStrategy::RandomStrategy(const std::string& name) : IStrategy(name)
{
	std::srand(time(NULL));
}

Choice RandomStrategy::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
	bool choice = std::rand() % 2 == 0;

	if (choice)
	{
		return Choice::Betray;
	}
	return Choice::Cooperate;

}
