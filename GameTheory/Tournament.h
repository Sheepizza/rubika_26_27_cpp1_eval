#pragma once

#include "Ranking.h"
#include "IStrategy.h"

#include <vector>

class Tournament
{
public:
	Tournament();

	void PopulateStrategy();

	void Simulate();

	std::vector<Ranking> GenerateFinalRankingByPoint() const;
	std::vector<Ranking> GenerateFinalRankingByWinDrawLoss() const;

private:
	std::vector<IStrategy*> Strategies;
	std::vector<Ranking> Rankings;
};