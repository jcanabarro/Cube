#include <iostream>
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
		bool solved();
		bool operator==(const Rubik &other) const;
		void move_cw(int x, int y, int z, bool clockwise);
		
	private:
		inline void swap_column(Rubik::face &a, Rubik::face &b, std::size_t index);
		inline void rotate_face(Rubik::face &f, bool clockwise);
		
		const Rubik::face sfront, sright, stop;
		const Rubik::face sback, sleft, sbottom;
		Rubik::face front, right, top;
		Rubik::face back, left, bottom;
		std::size_t dim;
};

//--------- Métodos publicos ---------//

template<std::size_t D>
Rubik<D>::Rubik()
{
	back.fill(YELLOW);
	sback.fill(YELLOW);
	right.fill(BLUE);
	sright.fill(BLUE);
	bottom.fill(RED);
	sbottom.fill(RED);
	top.fill(ORANGE);
	stop.fill(ORANGE);
	left.fill(GREEN);
	sleft.fill(GREEN);
	front.fill(WHITE);
	sfront.fill(WHITE);
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
void Rubik<D>::move_cw(int x, int y, int z, bool clockwise)
{
	// indices invalidos
	if(x >= dim || y >= dim || z >= dim)
	{
		throw std::out_of_range();
	}

    // rotaciona uma face dependendo dos indice 
	if(x == 0)
	{
		rotate_face(top, clockwise);
	}
	else if(x == dim - 1)
	{
		rotate_face(bottom, !clockwise);
	}
	else if(y == 0)
	{
		rotate_face(left, clockwise);
	}
	else if(y == dim - 1)
	{
		rotate_face(right, !clockwise);
	}
	else if(z == 0)
	{
		rotate_face(front, clockwise);
	}
	else if(z == dim - 1)
	{
		rotate_face(back, !clockwise);
	}					
	
	// rotaciona uma linha, coluna ou lateral
	if(clockwise)
	{
		if(x != -1)
	 	{
			swap(front[x], right[x]);
			swap(front[x], back[x]);
			swap(front[x], left[x]);
		}
		else if(y != -1)
		{
			swap_column(front, top, y);
			swap_column(front, back, y);
			swap_column(front, bottom, y);
		}
		else if(z != -1)
		{	
			swap_column(right, top, z);
			swap_column(right, left, z);
			swap_column(right, bottom, z);
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
			swap_column(front, bottom, y);
			swap_column(front, back, y);
			swap_column(front, top, y);
		}
		else if(z != -1)
		{
			swap_column(right, bottom, z);
			swap_column(right, left, z);
			swap_column(right, top, z);			
		}		
	}
}

//--------- Métodos privados ---------//

template<std::size_t D>
inline void Rubik<D>::rotate_face(Rubik::face &f, bool clockwise)
{
	if(clockwise)
	{
		for(int i = 0; i < dim / 2; i++)
		{
			for(int j = 0; j < dim - i - 1; j++)
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
inline void Rubik<D>::swap_column(Rubik::face &a, Rubik::face &b, std::size_t index)
{
	for(int i = 0; i < dim; i++)
	{
		swap(a[i][index], b[i][index]);
	}
}

int main()
{	
}
