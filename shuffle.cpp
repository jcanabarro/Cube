#include "cube.cpp"
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

template<std::size_t D>
class Shuffle
{
public:
	Shuffle();
	Rubik<D> random(int n_moves);
	std::vector<int> get_mx();
	std::vector<int> get_my();
	std::vector<int> get_mz();
	std::vector<int> get_mcw();
private:
	std::vector<int> move_x, move_y, move_z, move_cw;
};

template<std::size_t D>
std::vector<int> Shuffle<D>::get_mx()
{
	return move_x;
}

template<std::size_t D>
std::vector<int> Shuffle<D>::get_my()
{
	return move_y;
}

template<std::size_t D>
std::vector<int> Shuffle<D>::get_mz()
{
	return move_z;
}

template<std::size_t D>
std::vector<int> Shuffle<D>::get_mcw()
{
	return move_cw;
}

template<std::size_t D>
Shuffle<D>::Shuffle()
{
	int total_n_moves = 6 * D;
	int n_axis_moves = 2 * D;
	int max_idx_n = D;
	
	move_x = std::vector<int>(total_n_moves);
	move_y = std::vector<int>(total_n_moves);
	move_z = std::vector<int>(total_n_moves);
	move_cw = std::vector<int>(total_n_moves);
	
	for(int i = 0; i < total_n_moves; i++)
	{
		move_x[i] = i < n_axis_moves ? i % max_idx_n : -1;
		move_y[i] = i < n_axis_moves * 2 && i >= n_axis_moves ? i % max_idx_n : -1;
		move_z[i] = i >= n_axis_moves * 2 ? i % max_idx_n : -1;
		move_cw[i] = (i % (D * 2)) >= D;
	}
}

template<std::size_t D>
Rubik<D> Shuffle<D>::random(int n_moves)
{
	Rubik<D> cube;	
	std::set<Rubik<D>> visited;
	int total_n_moves = 6 * D;
	
	srand(time(NULL));
	visited.insert(cube);
	
	for(int i = 0; i < n_moves; i++)
	{
		int index = rand() % total_n_moves;
		
		Rubik<D> tmp(cube);
		
		tmp.move(move_x[index], move_y[index], move_z[index], move_cw[index]);
		
		if(visited.find(tmp) != visited.end())
		{
			i--;
			continue;
		}
		
		cube = tmp;
	}
	
	return cube;
}
