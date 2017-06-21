#include "shuffle.cpp"
#include <queue>
#include <set>

template<std::size_t D>
void bfs(Rubik<D> cube)
{
	Shuffle<D> move;
	std::queue<Rubik<D>> next;
	int visited[D][D][D][D][D][D][D][D][D][D][D][D];
		
	next.push(cube);
	visited.insert(cube);
	
	while(!next.empty())
	{
		Rubik<D> u = next.front();
		next.pop();
		
		for(std::size_t i = 0; i < 6 * D; i++)
		{
			Rubik<D> v(u);
			
			v.move(move.get_mx()[i], move.get_my()[i], move.get_mz()[i], move.get_mcw()[i]);
			
			if(visited.find(v) == visited.end())
			{
				next.push(v);
				visited.insert(v);
			}
		}
	}
}

int main()
{
	Shuffle<2> shuffle;
	
	bfs(shuffle.random(18));
}
