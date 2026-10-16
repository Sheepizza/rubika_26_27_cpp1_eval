#pragma once
#include "IStrategy.h"

class BetrayStrategy : public IStrategy
{
public:
	BetrayStrategy(const std::string& name);

	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

