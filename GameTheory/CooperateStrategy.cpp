#include "CooperateStrategy.h"

CooperateStrategy::CooperateStrategy(const std::string& name) : IStrategy(name)
{
}

Choice CooperateStrategy::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    return Choice::Cooperate;
}
