#pragma once
#include "IStrategy.h"

class CooperateStrategy : public IStrategy
{
public:
	CooperateStrategy(const std::string& name);

	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;

};

