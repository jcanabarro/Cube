#include "shuffle.cpp"
#include <queue>
#include <set>

int states = 0;

template<std::size_t D>
bool limited_dfs(Rubik<D> cube, std::set<Rubik<D>> &visited, int deep, int max_deep)
{
	if(deep > max_deep) return false;
	if(cube.solved()) return true;
	
	states++;
	visited.insert(Rubik<D>(cube));
	
	Shuffle<D> move;
	bool possible = false;
	
	for(std::size_t i = 0; i < 6 * D && !possible; i++)
	{
		Rubik<D> v(cube);
		
		v.move(move.get_mx()[i], move.get_my()[i], move.get_mz()[i], move.get_mcw()[i]);
		
		if(visited.find(v) == visited.end())
		{
			possible = std::max(possible, limited_dfs(v, visited, deep + 1, max_deep));
		}
	}
	
	return possible;
}

template<std::size_t D>
bool bfs(Rubik<D> cube)
{
	Shuffle<D> move;
	std::queue<Rubik<D>> next;
	std::set<Rubik<D>> visited;
		
	next.push(Rubik<D>(cube));
	visited.insert(Rubik<D>(cube));
	
	int state = 0;
	
	while(!next.empty())
	{
		Rubik<D> u = next.front();
		next.pop();
		
		if(u.solved())
		{
			std::cout << state << std::endl;
			return true;
		}
		
		state++;		
		
		for(std::size_t i = 0; i < 6 * D; i++)
		{
			Rubik<D> v(u);
			
			v.move(move.get_mx()[i], move.get_my()[i], move.get_mz()[i], move.get_mcw()[i]);
			
			if(v.solved())  {
				std::cout << state << std::endl;
				return true;
			}
			
			if(visited.find(v) == visited.end())
			{
				next.push(Rubik<D>(v));
				visited.insert(Rubik<D>(v));
			}
		}
	}
	
	return false;
}

int main()
{
	Shuffle<3> shuffle;
	
	Rubik<3> cube = shuffle.random(4);
	
	//~ bfs<3>(cube);
	std::set<Rubik<3>> visited;
	std::cout << limited_dfs<3>(cube, visited, 0, 5) << std::endl;
	std::cout << states << std::endl;
	
	//~ for(int i = 0; i < 12; i++)
	//~ {
		//~ std::cout << "i=" << i << std::endl;
		//~ Rubik<2> cube;
		//~ std::cout << shuffle.get_mx()[i] << ' ' << shuffle.get_my()[i] << ' ' << shuffle.get_mz()[i] << ' ' << shuffle.get_mcw()[i] << std::endl;
		//~ cube.move(shuffle.get_mx()[i], shuffle.get_my()[i], shuffle.get_mz()[i], shuffle.get_mcw()[i]);
		//~ cube.move(shuffle.get_mx()[i], shuffle.get_my()[i], shuffle.get_mz()[i], !shuffle.get_mcw()[i]);
	
		//~ bfs<2>(cube);	
	//~ }
}

//~ 0, -1, -1, 0
//~ 0, -1, -1, 1
//~ 1, -1, -1, 1
//~ -1, 0, -1, 1
// -1, -1, 0, 0 ACHAMO O BUGs
// -1, -1, 2, 0 ACHAMO O BUG2
