#include <iostream>

#define YELLOW 0
#define BLUE   1
#define RED    2
#define ORANGE 3
#define GREEN  4 
#define WHITE  5

class Rubik 
{
public:
	Rubik() 
	{
		
	}
private:	
	int front[3][3], left[3][3], right[3][3]
	int back[3][3], top[3][3], bottom[3][3];
}

/*
Movimentos:
R L U D F B Mh Mv         -> Horarios
R' L' U' D' F' B' Mh' Mv' -> Anti-Horario
Total=16 movimentos
*/

-------------
R

front  back
5 5 5  0 0 0
5 5 5  0 0 0
5 5 5  0 0 0

left   right
4 4 4  A B C
4 4 4  H 1 D
4 4 4  G F E

top    bottom
3 3 3  2 2 2
3 3 3  2 2 2
3 3 3  2 2 2

->

front  back
5 5 2  0 0 3
5 5 2  0 0 3
5 5 2  0 0 3

left   right
4 4 4  G H A
4 4 4  F 1 B
4 4 4  E D C

top    bottom
3 3 5  2 2 0
3 3 5  2 2 0
3 3 5  2 2 0
-------------

-------------
R'

front  back
5 5 5  0 0 0
5 5 5  0 0 0
5 5 5  0 0 0

left   right
4 4 4  A B C
4 4 4  H 1 D
4 4 4  G F E

top    bottom
3 3 3  2 2 2
3 3 3  2 2 2
3 3 3  2 2 2

->

front  back
5 5 3  0 0 2
5 5 3  0 0 2
5 5 3  0 0 2

left   right
4 4 4  C D E
4 4 4  B 1 F
4 4 4  A H G

top    bottom
3 3 0  2 2 5
3 3 0  2 2 5
3 3 0  2 2 5
-------------

-------------
L

front  back
5 5 5  0 0 0
5 5 5  0 0 0
5 5 5  0 0 0

left   right
A B C  1 1 1
H 4 D  1 1 1
G F E  1 1 1

top    bottom
3 3 3  2 2 2
3 3 3  2 2 2
3 3 3  2 2 2

->

front  back
3 5 5  2 0 0
3 5 5  2 0 0
3 5 5  2 0 0

left   right
C D E  1 1 1
B 4 F  1 1 1
A H G  1 1 1

top    bottom
0 3 3  5 2 2
0 3 3  5 2 2
0 3 3  5 2 2
-------------

-------------
L'

front  back
5 5 5  0 0 0
5 5 5  0 0 0
5 5 5  0 0 0

left   right
A B C  1 1 1
H 4 D  1 1 1
G F E  1 1 1

top    bottom
3 3 3  2 2 2
3 3 3  2 2 2
3 3 3  2 2 2

->

front  back
2 5 5  3 0 0
2 5 5  3 0 0
2 5 5  3 0 0

left   right
G H A  1 1 1
F 4 B  1 1 1
E D C  1 1 1

top    bottom
5 3 3  0 2 2
5 3 3  0 2 2
5 3 3  0 2 2
-------------
/*
front  back
5 5 5  0 0 0
5 5 5  0 0 0
5 5 5  0 0 0

left   right
4 4 4  1 1 1
4 4 4  1 1 1
4 4 4  1 1 1

top    bottom
3 3 3  2 2 2
3 3 3  2 2 2
3 3 3  2 2 2
*/
