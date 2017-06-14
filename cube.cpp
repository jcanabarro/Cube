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
<<<<<<< HEAD
/*
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

-------------
D

front  back
5 5 5  0 0 0
5 5 5  0 0 0
5 5 5  0 0 0

left   right
4 4 4  1 1 1
4 4 4  1 1 1
4 4 4  1 1 1

top    bottom
3 3 3  A B C
3 3 3  H 2 D
3 3 3  G F E

->

front  back
5 5 5  0 0 0
5 5 5  0 0 0
4 4 4  1 1 1

left   right
4 4 4  1 1 1
4 4 4  1 1 1
0 0 0  5 5 5

top    bottom
3 3 3  G H A
3 3 3  F 2 B
3 3 3  E D C
-------------

-------------
D'

front  back
5 5 5  0 0 0
5 5 5  0 0 0
5 5 5  0 0 0

left   right
4 4 4  1 1 1
4 4 4  1 1 1
4 4 4  1 1 1

top    bottom
3 3 3  A B C
3 3 3  H 2 D
3 3 3  G F E

->

front  back
5 5 5  0 0 0
5 5 5  0 0 0
1 1 1  4 4 4

left   right
4 4 4  1 1 1
4 4 4  1 1 1
5 5 5  0 0 0

top    bottom
3 3 3  C D E  
3 3 3  B 2 F
3 3 3  A H G
-------------

-------------
B

front  back
5 5 5  0 0 0
5 5 5  0 0 0
5 5 5  0 0 0

left   right
4 4 4  1 1 1
4 4 4  1 1 1
4 4 4  1 1 1

top    bottom
3 3 3  A B C
3 3 3  H 2 D
3 3 3  G F E

->

front  back
5 5 5  C D E
5 5 5  B 0 F
5 5 5  A H G

left   right
4 4 4  1 1 1
4 4 4  1 1 1
3 3 3  2 2 2

top    bottom
3 3 3  2 2 2  
3 3 3  2 2 2
1 1 1  4 4 4
-------------
B'

front  back
5 5 5  0 0 0
5 5 5  0 0 0
5 5 5  0 0 0

left   right
4 4 4  1 1 1
4 4 4  1 1 1
4 4 4  1 1 1

top    bottom
3 3 3  A B C
3 3 3  H 2 D
3 3 3  G F E

->

front  back
5 5 5  G H A 
5 5 5  F 0 B
5 5 5  E D C

left   right
4 4 4  1 1 1
4 4 4  1 1 1
2 2 2  3 3 3

top    bottom
3 3 3  2 2 2  
3 3 3  2 2 2
4 4 4  1 1 1
-------------
Mv

front  back
5 A 5  0 G 0
5 B 5  0 H 0
5 C 5  0 I 0

left   right
4 4 4  1 1 1
4 4 4  1 1 1
4 4 4  1 1 1

top    bottom
3 J 3  2 D 2
3 K 3  2 E 2
3 L 3  2 F 2

->

front  back
5 J 5  0 D 0 
5 K 5  0 E 0
5 L 5  0 F 0

left   right
4 4 4  1 1 1
4 4 4  1 1 1
4 4 4  1 1 1

top    bottom
3 A 3  2 G 2  
3 B 3  2 H 2
3 C 3  2 I 2
-------------

Mv'

front  back
5 A 5  0 G 0
5 B 5  0 H 0
5 C 5  0 I 0

left   right
4 4 4  1 1 1
4 4 4  1 1 1
4 4 4  1 1 1

top    bottom
3 J 3  2 D 2
3 K 3  2 E 2
3 L 3  2 F 2

->

front  back
5 J 5  0 D 0 
5 K 5  0 E 0
5 L 5  0 F 0

left   right
4 4 4  1 1 1
4 4 4  1 1 1
4 4 4  1 1 1

top    bottom
3 G 3  2 A 2  
3 H 3  2 B 2
3 I 3  2 C 2
-------------
*/
















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
=======


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
>>>>>>> renan
