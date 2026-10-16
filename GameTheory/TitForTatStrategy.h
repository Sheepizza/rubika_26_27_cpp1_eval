#pragma once
#include "IStrategy.h"

class TitForTatStrategy : public IStrategy
{
public:
	TitForTatStrategy(const std::string& name);

	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

