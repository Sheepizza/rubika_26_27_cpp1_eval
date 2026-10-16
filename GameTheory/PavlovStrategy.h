#pragma once
#include "IStrategy.h"

class PavlovStrategy : public IStrategy
{
public:
	PavlovStrategy(const std::string& name);

	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

