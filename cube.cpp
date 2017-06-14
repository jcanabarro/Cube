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


---------------------------------------------------------------
      R              R'                L               L'
                                                 
front  back     front  back      front  back     front  back
5 5 5  0 0 0    5 5 5  0 0 0     5 5 5  0 0 0    5 5 5  0 0 0
5 5 5  0 0 0    5 5 5  0 0 0     5 5 5  0 0 0    5 5 5  0 0 0
5 5 5  0 0 0    5 5 5  0 0 0     5 5 5  0 0 0    5 5 5  0 0 0
                                                 
left   right    left   right     left   right    left   right
4 4 4  A B C    4 4 4  A B C     A B C  1 1 1    A B C  1 1 1
4 4 4  H 1 D    4 4 4  H 1 D     H 4 D  1 1 1    H 4 D  1 1 1
4 4 4  G F E    4 4 4  G F E     G F E  1 1 1    G F E  1 1 1
                                                 
top    bottom   top    bottom    top    bottom   top    bottom
3 3 3  2 2 2    3 3 3  2 2 2     3 3 3  2 2 2    3 3 3  2 2 2
3 3 3  2 2 2    3 3 3  2 2 2     3 3 3  2 2 2    3 3 3  2 2 2
3 3 3  2 2 2    3 3 3  2 2 2     3 3 3  2 2 2    3 3 3  2 2 2
                                                 
                              to
                                                 
front  back     front  back      front  back     front  back
5 5 2  0 0 3    5 5 3  0 0 2     3 5 5  2 0 0    2 5 5  3 0 0
5 5 2  0 0 3    5 5 3  0 0 2     3 5 5  2 0 0    2 5 5  3 0 0
5 5 2  0 0 3    5 5 3  0 0 2     3 5 5  2 0 0    2 5 5  3 0 0
                                                 
left   right    left   right     left   right    left   right
4 4 4  G H A    4 4 4  C D E     C D E  1 1 1    G H A  1 1 1
4 4 4  F 1 B    4 4 4  B 1 F     B 4 F  1 1 1    F 4 B  1 1 1
4 4 4  E D C    4 4 4  A H G     A H G  1 1 1    E D C  1 1 1
                                                 
top    bottom   top    bottom    top    bottom   top    bottom
3 3 5  2 2 0    3 3 0  2 2 5     0 3 3  5 2 2    5 3 3  0 2 2
3 3 5  2 2 0    3 3 0  2 2 5     0 3 3  5 2 2    5 3 3  0 2 2
3 3 5  2 2 0    3 3 0  2 2 5     0 3 3  5 2 2    5 3 3  0 2 2
---------------------------------------------------------------

-------------------------------
U                 U'
                  
front  back       front  back
5 5 5  0 0 0      5 5 5  0 0 0
5 5 5  0 0 0      5 5 5  0 0 0
5 5 5  0 0 0      5 5 5  0 0 0
                  
left   right      left   right
4 4 4  1 1 1      4 4 4  1 1 1
4 4 4  1 1 1      4 4 4  1 1 1
4 4 4  1 1 1      4 4 4  1 1 1
                  
top    bottom     top    bottom
A B C  2 2 2      A B C  2 2 2
H 3 D  2 2 2      H 3 D  2 2 2
G F E  2 2 2      G F E  2 2 2
                  
->                ->
                  
front  back       front  back
1 1 1  4 4 4      4 4 4  1 1 1
5 5 5  0 0 0      5 5 5  0 0 0
5 5 5  0 0 0      5 5 5  0 0 0
                  
left   right      left   right
5 5 5  0 0 0      0 0 0  5 5 5
4 4 4  1 1 1      4 4 4  1 1 1
4 4 4  1 1 1      4 4 4  1 1 1
                  
top    bottom     top    bottom
G H A  2 2 2      C D E  2 2 2
F 3 B  2 2 2      B 3 F  2 2 2
E D C  2 2 2      A H G  2 2 2
-------------------------------

-------------------------------
F                 F'
                  
front  back       front  back
A B C  0 0 0      A B C  0 0 0
H 5 D  0 0 0      H 5 D  0 0 0
G F E  0 0 0      G F E  0 0 0
                  
left   right      left   right
4 4 4  1 1 1      4 4 4  1 1 1
4 4 4  1 1 1      4 4 4  1 1 1
4 4 4  1 1 1      4 4 4  1 1 1
                  
top    bottom     top    bottom
3 3 3  2 2 2      3 3 3  2 2 2
3 3 3  2 2 2      3 3 3  2 2 2
3 3 3  2 2 2      3 3 3  2 2 2
                  
->                ->
                  
front  back       front  back
G H A  0 0 0      C D E  0 0 0
F 5 B  0 0 0      B 5 F  0 0 0
E D C  0 0 0      A H G  0 0 0
                  
left   right      left   right
4 4 1  3 1 1      4 4 3  2 1 1
4 4 1  3 1 1      4 4 3  2 1 1
4 4 1  3 1 1      4 4 3  2 1 1
                  
top    bottom     top    bottom
3 3 3  1 1 1      3 3 3  4 4 4
3 3 3  2 2 2      3 3 3  2 2 2
4 4 4  2 2 2      1 1 1  2 2 2
-------------------------------

------------------------------
Mh               Mh'
                 
front  back      front  back
5 5 5  0 0 0     5 5 5  0 0 0
A B C  G H I     A B C  G H I
5 5 5  0 0 0     5 5 5  0 0 0
                 
left   right     left   right
4 4 4  1 1 1     4 4 4  1 1 1
L K J  D E F     L K J  D E F
4 4 4  1 1 1     4 4 4  1 1 1
                 
top    bottom    top    bottom
3 3 3  2 2 2     3 3 3  2 2 2
3 3 3  2 2 2     3 3 3  2 2 2
3 3 3  2 2 2     3 3 3  2 2 2
                 
->               ->
                 
front  back      front  back
5 5 5  0 0 0     5 5 5  0 0 0
J K L  D E F     L K J  D E F
5 5 5  0 0 0     5 5 5  0 0 0
                 
left   right     left   right
4 4 4  1 1 1     4 4 4  1 1 1
I H G  A B C     C B A  G H FI
4 4 4  1 1 1     4 4 4  1 1 1
                 
top    bottom    top    bottom
3 3 3  2 2 2     3 3 3  2 2 2
3 3 3  2 2 2     3 3 3  2 2 2
3 3 3  2 2 2     3 3 3  2 2 2
------------------------------
