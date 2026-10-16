#include "ResentfulStrategy.h"

ResentfulStrategy::ResentfulStrategy(const std::string& name) : IStrategy(name)
{
}

Choice ResentfulStrategy::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    if (opponentPreviousDecisions.size() != 0)
    {
        if (opponentPreviousDecisions[opponentPreviousDecisions.size() - 1] == Choice::Betray || previousDecisions[previousDecisions.size() - 1] == Choice::Betray)
        {
            return Choice::Betray;
        }
    }

    return Choice::Cooperate;
}
