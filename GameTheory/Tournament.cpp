#include "Tournament.h"
#include "CooperateStrategy.h"
#include "BetrayStrategy.h"
#include "TitForTatStrategy.h"
#include "ResentfulStrategy.h"
#include "PavlovStrategy.h"
#include "RandomStrategy.h"
#include <algorithm>

Tournament::Tournament()
{
}

void Tournament::PopulateStrategy()
{
	Strategies.push_back(new CooperateStrategy("Cooperate"));
	Rankings.push_back(Ranking("Cooperate"));

	Strategies.push_back(new BetrayStrategy("Betray"));
	Rankings.push_back(Ranking("Betray"));

	Strategies.push_back(new TitForTatStrategy("TitForTat"));
	Rankings.push_back(Ranking("TitForTat"));

	Strategies.push_back(new ResentfulStrategy("Resentful"));
	Rankings.push_back(Ranking("Resentful"));

	Strategies.push_back(new PavlovStrategy("Pavlov"));
	Rankings.push_back(Ranking("Pavlov"));

	Strategies.push_back(new RandomStrategy("Random"));
	Rankings.push_back(Ranking("Random"));
}

void Tournament::Simulate()
{
	for (size_t i = 0; i < Strategies.size(); i++)
	{
		for (size_t j = 0; j < Strategies.size(); j++)
		{
			std::vector<Choice> strategy1Decisions;
			std::vector<Choice> strategy2Decisions;

			for (size_t round = 0; round < 50; round++)
			{
				Choice strategy1Choice = Strategies[i]->Decide(strategy1Decisions, strategy2Decisions);
				Choice strategy2Choice = Strategies[j]->Decide(strategy1Decisions, strategy2Decisions);

				strategy1Decisions.push_back(strategy1Choice);
				strategy2Decisions.push_back(strategy2Choice);

				if (strategy1Choice == Choice::Cooperate && strategy2Choice == Choice::Cooperate)
				{
					Rankings[i].TotalPoint += 3;

					Rankings[j].TotalPoint += 3;
				}
				else if (strategy1Choice == Choice::Betray && strategy2Choice == Choice::Betray)
				{
					Rankings[i].TotalPoint += 1;

					Rankings[j].TotalPoint += 1;
				}
				else if (strategy1Choice == Choice::Cooperate && strategy2Choice == Choice::Betray)
				{
					Rankings[j].TotalPoint += 5;
				}
				else
				{
					Rankings[i].TotalPoint += 5;
				}
			}

			if (Rankings[i].TotalPoint == Rankings[j].TotalPoint)
			{
				Rankings[i].Draw += 1;
				Rankings[j].Draw += 1;
			}
			else if (Rankings[i].TotalPoint > Rankings[j].TotalPoint)
			{
				Rankings[i].Win += 1;
				Rankings[j].Lose += 1;
			}
			else
			{
				Rankings[i].Lose += 1;
				Rankings[j].Win += 1;
			}
		}
	}
}

std::vector<Ranking> Tournament::GenerateFinalRankingByPoint() const
{
	std::vector<Ranking> r = Rankings;

	std::sort(r.begin(), r.end(), [](Ranking& r1, Ranking& r2)
		{
			if (r1.TotalPoint != r2.TotalPoint) 
			{
				return r1.TotalPoint > r2.TotalPoint;
			}

			if (r1.Win != r2.Win)
			{
				return r1.Win > r2.Win;
			}

			if (r1.Draw != r2.Draw)
			{
				return r1.Draw > r2.Draw;
			}

			if (r1.Lose != r2.Lose)
			{
				return r1.Lose > r2.Lose;
			}

			return true;
		});

	return r;
}

std::vector<Ranking> Tournament::GenerateFinalRankingByWinDrawLoss() const
{
	std::vector<Ranking> r = Rankings;

	std::sort(r.begin(), r.end(), [](Ranking& r1, Ranking& r2)
		{
			if (r1.Win != r2.Win)
			{
				return r1.Win > r2.Win;
			}

			if (r1.Draw != r2.Draw)
			{
				return r1.Draw > r2.Draw;
			}

			if (r1.Lose != r2.Lose)
			{
				return r1.Lose > r2.Lose;
			}

			return true;
		});

	return r;
}
