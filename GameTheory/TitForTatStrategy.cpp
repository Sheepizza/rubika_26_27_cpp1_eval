#include "TitForTatStrategy.h"

TitForTatStrategy::TitForTatStrategy(const std::string& name) : IStrategy(name)
{
}

Choice TitForTatStrategy::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    if (opponentPreviousDecisions.size() == 0)
    {
        return Choice::Cooperate;
    }

    return opponentPreviousDecisions[opponentPreviousDecisions.size() - 1];
}
