#include "PavlovStrategy.h"

PavlovStrategy::PavlovStrategy(const std::string& name) : IStrategy(name)
{
}

Choice PavlovStrategy::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    if (previousDecisions.size() == 0) 
    {
        return Choice::Cooperate;
    }

    if (opponentPreviousDecisions[opponentPreviousDecisions.size() - 1] == Choice::Cooperate)
    {
        return previousDecisions[previousDecisions.size() - 1];
    }

    if (opponentPreviousDecisions[opponentPreviousDecisions.size() - 1] == Choice::Cooperate)
    {
        return Choice::Betray;
    }

    return Choice::Cooperate;
}
