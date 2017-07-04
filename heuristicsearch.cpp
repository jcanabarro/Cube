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


template<std::size_t D>
int _layer(std::array<std::array<char,D>,D> f, int color, int layer_solve)
{
	int cost = 0;
	
	for(std::size_t i = 0; i < D; i++)
	{
		for(std::size_t j = 0; j < D; j++)
		{
			if(f[layer_solve-1][j] != color)
			{
				cost++;
			}
		}
	}
	
	return cost;
}

/*
layer to be solved 
where layer = 0 
		-> solve bottom + first layer from right/left/front/back
where layer = 1
		-> solve the second layer from right/left/front/back
where layer = 2
		-> solve the third layer from right/left/front/back
where layer = 3
		->solve the top
*/

template<std::size_t D> 
int layer(Rubik<D> cube, int layer_solve[], int ind)
{
	if(layer_solve[ind] == 0)
		return _heuristic<D>(cube.bottom, RED);
    else if()
	else if(layer_solve[ind] == 1 || layer_solve[ind] == 2)
		return _layer<D>(cube.front, WHITE, layer_solve[ind])
	     	 + _layer<D>(cube.back, YELLOW, layer_solve[ind])
	         + _layer<D>(cube.right, BLUE, layer_solve[ind])
	         + _layer<D>(cube.left, GREEN, layer_solve[ind]);
}


template<std::size_t D>
bool needThinkBetter(Rubik<D> cube)
{
	if(cube.solved()) return true;
	
	Shuffle<D> move;
    std::priority_queue<std::pair<int,Rubik<D>>, std::vector<std::pair<int,Rubik<D>>>, std::greater<std::pair<int,Rubik<D>>>> next;
    std::set<Rubik<D>> visited;

    next.push({0, Rubik<D>(cube)});
	visited.insert(Rubik<D>(cube));
	
	int state = 0;
	int layer_solve[4] = { 0,1,3,2 };
	int ind = 0;

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
				next.push({1 + u.first + layer<D>(v, layer_solve, ind), Rubik<D>(v)});
				visited.insert(Rubik<D>(v));
				ind++;
				if(ind == 4)
					ind = 0;
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
