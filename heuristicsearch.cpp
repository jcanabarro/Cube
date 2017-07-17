#include "blindsearch.cpp"
#include <functional>
#include <queue>
#include <utility>
#include <set>
#include <chrono>

typedef std::pair<int,int> ii;

#define COST first.first
#define LAYER first.second

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
				std::cout << "A*=" << state << std::endl;
				//~ v.print();
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
int _layer(std::array<std::array<char,D>,D> f, int color, int layer)
{
	int cost = 0;
	
	for(std::size_t i = 0; i <= (std::size_t)layer; i++)
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
int layer(Rubik<D> cube, int layer_)
{	
	int auxfront = _layer<D>(cube.front, WHITE, layer_) ;
	int auxback = _layer<D>(cube.back, YELLOW, layer_) ;
	int auxrig =  _layer<D>(cube.right, BLUE, layer_); 
	int auxleft = _layer<D>(cube.left, GREEN, layer_); 
	int auxbot =  _layer<D>(cube.bottom, RED, D - 1);
	int auxtop = _layer<D>(cube.top, ORANGE, layer_) + (layer_ == D - 1) ? _layer<D>(cube.top, ORANGE, layer_) : 0;
	int aux = auxfront + auxback + auxrig + auxleft + auxbot + auxtop;
	
	return aux;
}

template<std::size_t D>
bool lastar(Rubik<D> cube)
{
	if(cube.solved()) return true;
	
	Shuffle<D> move;
    std::priority_queue<std::pair<ii,Rubik<D>>, std::vector<std::pair<ii,Rubik<D>>>, std::greater<std::pair<ii,Rubik<D>>>> next;
    std::set<Rubik<D>> visited;

    next.push({{0, 0}, Rubik<D>(cube)});
	visited.insert(Rubik<D>(cube));
	
	int layer_ = 0;
	int state = 0;

	while(!next.empty())
	{
		std::pair<ii,Rubik<D>> u = next.top();
		next.pop();
				
		if(u.LAYER < layer_) continue;		
				
		state++;		
		
		for(std::size_t i = 0; i < 6 * D; i++)
		{
			Rubik<D> v(u.second);
			
			v.move(move.get_mx()[i], move.get_my()[i], move.get_mz()[i], move.get_mcw()[i]);
			
			if(visited.find(v) == visited.end())
			{
				int hcost = layer<D>(v, layer_);
				
				if(hcost == 0)
				{
					if(layer_ < u.LAYER + 1)
						std::cout << "STATE=" << state << " LAYER=" << u.LAYER+1 << std::endl; 
						
					layer_ = std::max(layer_, u.LAYER + 1);
				}
				
				next.push({{1 + u.COST + hcost, layer_}, Rubik<D>(v)});
				visited.insert(Rubik<D>(v));
			}
			
			if(v.solved())  {
				std::cout << "LA*=" << state << std::endl;
				//~ v.print();
				return true;
			}
		}
	}
	
	return false;
}

int main()
{	
	Shuffle<2> shuffle;
	Rubik<2> cube = shuffle.random(12); // 3x3 Com quinze ainda não dá com 15
	lastar<2>(cube);
	astar<2>(cube);
}
