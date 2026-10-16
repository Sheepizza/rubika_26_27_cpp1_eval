#include <vector>
#include <assert.h>

/*
 * To analyze satellite images, a geospatial company studies maps of remote ocean regions.
 * Each map is represented as a grid where land and water are identified.
 *
 * Your task is to determine how many separate islands are present on a given map.
 * The map is represented as a 2D grid of characters :
 *    - '1' represents land
 *    - '0' represents water
 *
 * An island is defined as a group of connected land cells.
 * Cells are considered connected if they are adjacent horizontally or vertically(not diagonally).
 * The grid is surrounded by water.
 * 
 * Implement the function count_islands which returns the total number of islands present in the map.
 */

#include <iostream>

struct Vector2
{
    Vector2(int i, int j) { x = i; y = j; }
    int x = 0;
    int y = 0;
};

std::vector<Vector2> knownGroundCell;
int islands = 0;

void CheckNeighbors(std::vector<std::vector<char>>& grid, Vector2 pos) 
{
    int X = pos.x;
    int Y = pos.y;

    if (X + 1 < grid.size())
    {
        if (Y < grid[X + 1].size())
        {
            if (grid[X + 1][Y] == '1')
            {
                knownGroundCell.push_back(Vector2(X + 1, Y));
            }
        }
    }

    if (X - 1 >= 0)
    {
        if (Y < grid[X - 1].size())
        {
            if (grid[X - 1][Y] == '1')
            {
                knownGroundCell.push_back(Vector2(X - 1, Y));
            }
        }
    }

    if (Y + 1 < grid[X].size())
    {
        if (grid[X][Y + 1] == '1')
        {
            knownGroundCell.push_back(Vector2(X, Y + 1));
        }
    }

    if (Y - 1 >= 0)
    {
        if (grid[X][Y - 1] == '1')
        {
            knownGroundCell.push_back(Vector2(X, Y - 1));
        }
    }

    for (size_t i = 0; i < knownGroundCell.size(); i++)
    {
        if (knownGroundCell[i].x == X && knownGroundCell[i].y == Y)
        {
            return;
        }
    }

    islands += 1;
}

int count_islands(std::vector<std::vector<char>>& grid)
{
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                CheckNeighbors(grid, Vector2(i, j));
            }
        }
    }

	return islands;
}

int main()
{
    {
        std::vector<std::vector<char>> grid = {
            {'1','0','0','0'},
            {'1','1','0','0'},
            {'0','0','0','0','1'},
            {'0','0','0','1'}
        };
        assert(count_islands(grid) == 3);
    }

    return 0;
}