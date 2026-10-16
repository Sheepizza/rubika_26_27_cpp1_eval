#pragma once
#include "IStrategy.h"

class ResentfulStrategy : public IStrategy
{
public:
	ResentfulStrategy(const std::string& name);

	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

