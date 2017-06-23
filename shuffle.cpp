#include "cube.cpp"
#include <vector>
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

void print(std::vector<int> a)
{
	for(auto A : a)
	{
		std::cout << A << ' ';
	}
	
	std::cout << std::endl;
}

template<std::size_t D>
Shuffle<D>::Shuffle()
{
	int total_n_moves = 6 * D;
	int n_axis_moves = 2 * D;
	int max_idx_n = D;
	
	move_x = std::vector<int>(total_n_moves); // ERADO
	move_y = std::vector<int>(total_n_moves); // RRADO
	move_z = std::vector<int>(total_n_moves); // ADO
	move_cw = std::vector<int>(total_n_moves); // NOP
	
	for(int i = 0; i < total_n_moves; i++)
	{
		move_x[i] = i < n_axis_moves ? i % max_idx_n : -1;
		move_y[i] = i < n_axis_moves * 2 && i >= n_axis_moves ? i % max_idx_n : -1;
		move_z[i] = i >= n_axis_moves * 2 ? i % max_idx_n : -1;
		//~ move_cw[i] = i % 2; // i % 2 // i % D <- BUG
		move_cw[i] = (i % (D * 2)) >= D; // i % 2 // i % D <- BUG
	}
	
	//~ 0 0 1 1 0 0 1 1 0 0 1 1
	//~ 0 0 0 1 1 1 0 0 0 1 1 1
	
	//~ print(move_x);
	//~ print(move_y);
	//~ print(move_z);
	//~ print(move_cw);
	//~ std::cout << "---------\n";
}

template<std::size_t D>
Rubik<D> Shuffle<D>::random(int n_moves)
{
	Rubik<D> cube;	
	int total_n_moves = 6 * D;
	
	srand(time(NULL));
	
	for(int i = 0; i < n_moves; i++)
	{
		int index = rand() % total_n_moves;
		
		cube.move(move_x[index], move_y[index], move_z[index], move_cw[index]);
	}
	
	return cube;
}

//~ int main()
//~ {		
	//~ Shuffle<10> shuffler;
	//~ Rubik<10> cube = shuffler.random(10000);
	//~ cube.print();
//~ }
