#include "BetrayStrategy.h"

BetrayStrategy::BetrayStrategy(const std::string& name) : IStrategy(name)
{
}

Choice BetrayStrategy::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    return Choice::Betray;
}
