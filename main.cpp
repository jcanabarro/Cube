#include "blindsearch.cpp"
#include "heuristicsearch.cpp"
#include <iostream>
#include <unistd.h>
#include <iomanip>

#define MAX_MEM 1073741824 // 1 GiB

template<std::size_t D>
void execute_bfs(Rubik<D> cube, int max_state)
{
	clock_t t0 = clock();
	bfs<D>(cube, max_state);
	std::cout << std::fixed << std::setprecision(3) << "BFS_TIME=" << (double(clock()) - t0) / CLOCKS_PER_SEC << std::endl;
}

template<std::size_t D>
void execute_dfs(Rubik<D> cube, int moves, int max_state)
{
	clock_t t0 = clock();
	limited_dfs<D>(cube, moves, max_state);
	std::cout << std::fixed << std::setprecision(3) << "DFS_TIME=" << (double(clock()) - t0) / CLOCKS_PER_SEC << std::endl;
}

template<std::size_t D>
void execute_astar(Rubik<D> cube, int max_state)
{
	clock_t t0 = clock();
	astar<D>(cube, max_state);
	std::cout << std::fixed << std::setprecision(3) << "ASTAR_TIME=" << (double(clock()) - t0) / CLOCKS_PER_SEC << std::endl;
}

template<std::size_t D>
void execute_lastar(Rubik<D> cube, int max_state)
{
	clock_t t0 = clock();
	lastar<D>(cube, max_state);
	std::cout << std::fixed << std::setprecision(3) << "LASTAR_TIME=" << (double(clock()) - t0) / CLOCKS_PER_SEC << std::endl;
}

int main()
{		
	for(int moves = 2; moves <= 10; moves++)
	{
		std::cout << "\n\n\n______________N_MOVES=" << moves << std::endl; 
		
		Shuffle<2> shuffle;
		
		for(int test_n = 0; test_n < 3; test_n++)
		{
			sleep(0.100); // mudar a seed randomica
			Rubik<2> cube = shuffle.random(moves);
			
			std::cout << "_______________\n";
			std::cout << "TEST_N=" << test_n << std::endl;
			std::cout << "_______________" << std::endl;
	
			int n_max_of_states = MAX_MEM / sizeof cube;	
			execute_bfs<2>(cube, n_max_of_states);
			execute_dfs<2>(cube, moves + 1, n_max_of_states);
			execute_astar<2>(cube, n_max_of_states);
			execute_lastar<2>(cube, n_max_of_states);
		}
	}
}

// bool limited_dfs(Rubik<D> cube, std::set<Rubik<D>> &visited, int deep, int max_deep, int &n_states)
