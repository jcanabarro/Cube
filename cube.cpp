#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <array>

#define YELLOW 0
#define BLUE   1
#define RED    2
#define ORANGE 3
#define GREEN  4 
#define WHITE  5

template<std::size_t D> 
class Rubik
{
	typedef std::array<std::array<int,D>,D> face;
	
	public:
		Rubik();
		Rubik(int dump);
		bool solved();
		bool operator==(const Rubik &other) const;
		void move(int x, int y, int z, bool clockwise);
		void print(Rubik::face f);
		void print();
	private:
		inline void swap_column(Rubik::face &a, Rubik::face &b, std::size_t index, bool mirror);
		inline void rotate_face(Rubik::face &f, bool clockwise);
		
		Rubik::face sfront, sright, stop;
		Rubik::face sback, sleft, sbottom;
		Rubik::face front, right, top;
		Rubik::face back, left, bottom;
		std::size_t dim;
};

// -- Métodos para debug -- //
template<std::size_t D>
Rubik<D>::Rubik(int dump)
{
	for(int i = 0; i < (int)D; i++)
		for(int j = 0; j < (int)D; j++)
			front[i][j] = 'A' + (D * i + j);
			
	for(int i = 0; i < (int)D; i++)
		for(int j = 0; j < (int)D; j++)
			right[i][j] = 'A' + 9 + (D * i + j);
			
	for(int i = 0; i < (int)D; i++)
		for(int j = 0; j < (int)D; j++)
			back[i][j] = 'A' + 18 + (D * i + j);
			
	for(int i = 0; i < (int)D; i++)
		for(int j = 0; j < (int)D; j++)
			left[i][j] = 'a' + (D * i + j);
			
	for(int i = 0; i < (int)D; i++)
		for(int j = 0; j < (int)D; j++)
			top[i][j] = 'a' + 9 + (D * i + j);			

	for(int i = 0; i < (int)D; i++)
		for(int j = 0; j < (int)D; j++)
			bottom[i][j] = 'a' + 18 + (D * i + j);
	dim = D;
}

template<std::size_t D>
void Rubik<D>::print(Rubik::face f)
{
	for(int i = 0; i < (int)f.size(); i++)
	{
		for(int j = 0; j < (int)f[i].size(); j++)
		{
			std::cout << char(f[i][j]) << ' ';
		}
		
		std::cout << '\n';
	}
}

template<std::size_t D>
void Rubik<D>::print()
{
	std::cout << "left:\n";
	print(left);
	std::cout << "front:\n";
	print(front);
	std::cout << "right:\n";
	print(right);
	std::cout << "back:\n";
	print(back);
	std::cout << "top:\n";
	print(top);
	std::cout << "bottom:\n";
	print(bottom);
}

//--------- Métodos publicos ---------//

template<std::size_t D>
Rubik<D>::Rubik()
{
	for(std::size_t i = 0; i < D; i++)
	{
		back[i].fill(YELLOW);
		sback[i].fill(YELLOW);
		right[i].fill(BLUE);
		sright[i].fill(BLUE);
		bottom[i].fill(RED);
		sbottom[i].fill(RED);
		top[i].fill(ORANGE);
		stop[i].fill(ORANGE);
		left[i].fill(GREEN);
		sleft[i].fill(GREEN);
		front[i].fill(WHITE);
		sfront[i].fill(WHITE);
	}
	dim = D;
}

template<std::size_t D>
bool Rubik<D>::solved()
{
	return front == sfront && back   == sback 
	    && right == sright && left   == sleft 
	    && top   == stop   && bottom == sbottom;
}

template<std::size_t D>
bool Rubik<D>::operator==(const Rubik &other) const
{
	return front == other.front && back   == other.back 
	    && right == other.right && left   == other.left
	    && top   == other.top   && bottom == other.bottom;
}

/**
 *	x: Se diferente de -1, então implica em uma rotação em uma linha.
 *     Seu valor indica qual linha será rotacionada. 
 * 	y: Se diferente de -1, então implica em uma rotação em uma coluna.
 *     Seu valor indica qual coluna será rotacionada.
 *  z: Se diferente de -1, então implica em uma rotação em uma lateral.
 *     Seu valor indica qual lateral será rotacionada.
 *  clockwise: indica se a rotação será no sentido horário caso verda-
 *             deiro, anti-horário caso contrário.
 * 	Obs: 1. Todos os movimentos usam como referência a face 'front';
 *       2. Não pode ter dois valores diferentes de -1.
 */
template<std::size_t D>
void Rubik<D>::move(int x, int y, int z, bool clockwise)
{
	// indices invalidos
	if(x >= (int)dim || y >= (int)dim || z >= (int)dim)
	{
		throw std::out_of_range("");
	}

    // rotaciona uma face dependendo dos indice 
	if(x == 0)
	{
		rotate_face(top, clockwise);
	}
	else if(x == (int)dim - 1)
	{
		rotate_face(bottom, !clockwise);
	}
	else if(y == 0)
	{
		rotate_face(left, clockwise);
	}
	else if(y == (int)dim - 1)
	{
		rotate_face(right, !clockwise);
	}
	else if(z == 0)
	{
		rotate_face(front, clockwise);
	}
	else if(z == (int)dim - 1)
	{
		rotate_face(back, !clockwise);
	}					
	
	// rotaciona uma linha, coluna ou lateral
	if(!clockwise)
	{
		if(x != -1)
	 	{
			swap(front[x], right[x]);
			swap(front[x], back[x]);
			swap(front[x], left[x]);
		}
		else if(y != -1)
		{
			swap_column(front, top, y, false);
			swap_column(front, back, y, true);
			swap_column(front, bottom, y, false);
		}
		else if(z != -1)
		{	
			swap_column(right, top, z, false);
			swap_column(right, left, z, true);
			swap_column(right, bottom, z, false);
		}
	}
	else
	{
		if(x != -1)
		{
			swap(front[x], left[x]);
			swap(front[x], back[x]);
			swap(front[x], right[x]);
		}
		else if(y != -1)
		{
			swap_column(front, bottom, y, false);
			swap_column(front, back, y, true);
			swap_column(front, top, y, false);
		}
		else if(z != -1)
		{
			swap_column(right, bottom, z, false);
			swap_column(right, left, z, true);
			swap_column(right, top, z, false);			
		}		
	}
}

//--------- Métodos privados ---------//

template<std::size_t D>
inline void Rubik<D>::rotate_face(Rubik::face &f, bool clockwise)
{
	if(clockwise)
	{
		for(int i = 0; i < (int)dim / 2; i++)
		{
			for(int j = 0; j < (int)dim - i - 1; j++)
			{
				int tmp = f[i][j];
				
				f[i][j] = f[dim - j - 1][i];
				f[dim - j - 1][i] = f[dim - i - 1][dim - j - 1];
				f[dim - i - 1][dim - j - 1] = f[j][dim - i - 1];
				f[j][dim - i - 1] = tmp;
			}
		}
	}
	else
	{
		for(std::size_t i = 0; i < dim / 2; i++)
		{
			for(std::size_t j = 0; j < dim - i - 1; j++)
			{
				int tmp = f[i][j];
				
				f[i][j] = f[j][dim - i - 1];
				f[j][dim- i - 1] = f[dim - i - 1][dim - j - 1];
				f[dim - i - 1][dim - j - 1] = f[dim - j - 1][i];
				f[dim - j - 1][i] = tmp;
			}
		}	
	}
}

template<std::size_t D>
inline void Rubik<D>::swap_column(Rubik::face &a, Rubik::face &b, std::size_t index, bool mirror)
{
	if(mirror)
	{
		// Confirmar isso
		for(int i = 0; i < (int)dim; i++)
		{
			int tmp = a[i][index];
			a[i][index] = b[dim-i-1][dim-index-1];
			b[dim-i-1][dim-index-1] = tmp; 
		}	
	}
	else
	{
		for(int i = 0; i < (int)dim; i++)
		{
			int tmp = a[i][index];
			a[i][index] = b[i][index];
			b[i][index] = tmp;
		}
	}
}

int main()
{	
	int move_x[] = {0, 1, 2, 0, 1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	int move_y[] = {-1, -1, -1, -1, -1, -1, 0, 1, 2, 0, 1, 2, -1, -1, -1, -1, -1, -1};
	int move_z[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 0, 1, 2};
	int move_c[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0}; 
	
	int itest = 6;
	
	for(int i = itest; i <= itest; i++)
	{
		Rubik<3> rubik(12938);
		
		rubik.move(move_x[i], move_y[i], move_z[i], move_c[i]);
		rubik.print();	
	}
}

//~ Moviments
//~ 0 -1 -1 true  - OK
//~ 1 -1 -1 true  - OK
//~ 2 -1 -1 true  - OK
//~ 0 -1 -1 false - OK
//~ 1 -1 -1 false - OK
//~ 2 -1 -1 false - OK
//~ -1 0 -1 true
//~ -1 1 -1 true
//~ -1 2 -1 true
//~ -1 0 -1 false
//~ -1 1 -1 false
//~ -1 2 -1 false
//~ -1 -1 0 true
//~ -1 -1 1 true
//~ -1 -1 2 true
//~ -1 -1 0 false
//~ -1 -1 1 false
//~ -1 -1 2 false
