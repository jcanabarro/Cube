#include "shuffle.cpp"
#include <queue>
#include <set>

template<std::size_t D>
bool _limited_dfs(Rubik<D> cube, std::set<Rubik<D>> &visited, int deep, int max_deep, int &n_states, int max_states)
{
	n_states++;
	
	if(deep > max_deep) return false;
	if(cube.solved()) return true;
	if(n_states > max_states) {
		std::cout << "LIMITED_DFS=MEMORY_FAIL ";
		return false;
	}
	
	visited.insert(Rubik<D>(cube));
	
	Shuffle<D> move;
	bool possible = false;
	
	for(std::size_t i = 0; i < 6 * D && !possible; i++)
	{
		Rubik<D> v(cube);
		
		v.move(move.get_mx()[i], move.get_my()[i], move.get_mz()[i], move.get_mcw()[i]);
		
		if(visited.find(v) == visited.end())
		{
			possible = std::max(possible, _limited_dfs<D>(v, visited, deep + 1, max_deep, n_states, max_states));
		}
	}
	
	return possible;
}

template<std::size_t D>
bool limited_dfs(Rubik<D> cube, int max_deep, int max_states)
{
	std::set<Rubik<D>> visited;
	int n_states = 0;
	bool ans = _limited_dfs<D>(cube, visited, 0, max_deep, n_states, max_states);
	
	std::cout << "DFS_LIMITED_N_STATES=" << n_states << " FOUND_SOLUTION=" << ans << std::endl;
	
	return ans;
}

template<std::size_t D>
bool bfs(Rubik<D> cube, int max_states)
{
	if(cube.solved())
		return true;
	
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
		
		state++;		
		
		if(state > max_states) 
		{
			std::cout << "BFS_N_STATES=" << state << " NOT_FOUND_SOLUTION=MEMORY" << std::endl;
			return false;
		}
		
		for(std::size_t i = 0; i < 6 * D; i++)
		{
			Rubik<D> v(u);
			
			v.move(move.get_mx()[i], move.get_my()[i], move.get_mz()[i], move.get_mcw()[i]);
			
			if(v.solved())  {
				std::cout << "BFS_N_STATES=" << state << std::endl;
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
