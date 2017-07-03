#include "blindsearch.cpp"
#include <functional>
#include <queue>
#include <utility>
#include <set>
#include <chrono>

template<std::size_t D>
int _heuristic(std::array<std::array<char,D>,D> f, int color)
{
	int cost = 0;
	
	for(std::size_t i = 0; i < D; i++)
	{
		for(std::size_t j = 0; j < D; j++)
		{
			if(f[i][j] != color)
			{
				cost++;
			}
		}
	}
	
	return cost;
}

template<std::size_t D>
int heuristic(Rubik<D> cube)
{
	return _heuristic<D>(cube.front, WHITE)
	     + _heuristic<D>(cube.back, YELLOW)
	     + _heuristic<D>(cube.right, BLUE)
	     + _heuristic<D>(cube.left, GREEN)
	     + _heuristic<D>(cube.bottom, RED)
	     + _heuristic<D>(cube.top, ORANGE);
}

template<std::size_t D>
bool astar(Rubik<D> cube)
{
	srand(time(NULL));
	
	if(cube.solved()) return true;
	
	Shuffle<D> move;
	std::priority_queue<std::pair<int,Rubik<D>>, std::vector<std::pair<int,Rubik<D>>>, std::greater<std::pair<int,Rubik<D>>>> next;
	std::set<Rubik<D>> visited;
	
	next.push({0, Rubik<D>(cube)});
	visited.insert(Rubik<D>(cube));
	
	int state = 0;
	
	while(!next.empty())
	{
		std::pair<int,Rubik<D>> u = next.top();
		next.pop();
				
		state++;		
		
		for(std::size_t i = 0; i < 6 * D; i++)
		{
			Rubik<D> v(u.second);
			
			v.move(move.get_mx()[i], move.get_my()[i], move.get_mz()[i], move.get_mcw()[i]);
			
			if(v.solved())  {
				std::cout << state << std::endl;
				return true;
			}
			
			if(visited.find(v) == visited.end())
			{
				next.push({1 + u.first + heuristic<D>(v), Rubik<D>(v)});
				visited.insert(Rubik<D>(v));
			}
		}
	}
	
	return false;
}

int main()
{	
	Shuffle<2> shuffle;
	Rubik<2> cube = shuffle.random(20); // 3x3 Com quinze ainda não dá com 15
	astar<2>(cube);
}
