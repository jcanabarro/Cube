# Cube #

## Projeto de resolução do cubo mágico através de algorítmos ##

<p align="right">
<img src="https://user-images.githubusercontent.com/12617957/27193536-8d982b80-51d5-11e7-8575-668f5500b60b.png">
</p>
 	                                              
## Autores: ##
    João Victor Canabarro e Renan Tashiro.

# Específicação #

Lingugaem: *C++14*

Bibliotecas adicionais: https://github.com/nlohmann/json

# Descrição: #
Trabalho referente a diciplica de Inteligência artifícial objetiva testar diferentes tipos de algoritmos de busca e desempenho, para validação dos testes será desenvolvido o algoritmo de resolução do cubo mágico 3x3x3.

	Os algorítmos terão resoluções através de:
		1. Dois algorítmos de busca cega.
		2. Um algorítmo heurístico clássico.
		3. Um algorítmo heurístico desenvolvido pela equipe.
  
# Estrutura do código: #

# Algumas específicações do Cubo: #

    R e R'   -> Girar a face direita do cubo.
    L e L'   -> Girar a face esquerda do cubo.
	U e U'   -> Girar a face superior do cubo.
	D e D'   -> Girar a face inferior do cubo.    
	F e F'   -> Girar a face frontal do cubo.
	B e B'   -> Girar a face posterior do cubo.
	Mh e Mh' -> Girar a linha horizontal do centro do cubo. 
	Mv e Mv' -> Girar a linha vertical do centro do cubo.

	Movimentos com apostrofo são referentes as movimentações no sentido anti-horário.
	Movimento sem apostrofo são referentes as movimentações no sentido horário. 

## ##
# Movimentos: #
                  R               R'               L               L'
                                                     
		front  back     front  back       front  back     front  back
		5 5 5  0 0 0    5 5 5  0 0 0      5 5 5  0 0 0    5 5 5  0 0 0
		5 5 5  0 0 0    5 5 5  0 0 0      5 5 5  0 0 0    5 5 5  0 0 0
		5 5 5  0 0 0    5 5 5  0 0 0      5 5 5  0 0 0    5 5 5  0 0 0

		left   right    left   right      left   right    left   right
		4 4 4  A B C    4 4 4  A B C      A B C  1 1 1    A B C  1 1 1
		4 4 4  H 1 D    4 4 4  H 1 D      H 4 D  1 1 1    H 4 D  1 1 1
		4 4 4  G F E    4 4 4  G F E      G F E  1 1 1    G F E  1 1 1

		top    bottom   top    bottom     top    bottom   top    bottom
		3 3 3  2 2 2    3 3 3  2 2 2      3 3 3  2 2 2    3 3 3  2 2 2
		3 3 3  2 2 2    3 3 3  2 2 2      3 3 3  2 2 2    3 3 3  2 2 2
		3 3 3  2 2 2    3 3 3  2 2 2      3 3 3  2 2 2    3 3 3  2 2 2

		                             to  

		front  back     front  back       front  back     front  back
		5 5 2  0 0 3    5 5 3  0 0 2      3 5 5  2 0 0    2 5 5  3 0 0
		5 5 2  0 0 3    5 5 3  0 0 2      3 5 5  2 0 0    2 5 5  3 0 0
		5 5 2  0 0 3    5 5 3  0 0 2      3 5 5  2 0 0    2 5 5  3 0 0

		left   right    left   right      left   right    left   right
		4 4 4  G H A    4 4 4  C D E      C D E  1 1 1    G H A  1 1 1
		4 4 4  F 1 B    4 4 4  B 1 F      B 4 F  1 1 1    F 4 B  1 1 1
		4 4 4  E D C    4 4 4  A H G      A H G  1 1 1    E D C  1 1 1
                                                     
		top    bottom   top    bottom     top    bottom   top    bottom
		3 3 5  2 2 0    3 3 0  2 2 5      0 3 3  5 2 2    5 3 3  0 2 2
		3 3 5  2 2 0    3 3 0  2 2 5      0 3 3  5 2 2    5 3 3  0 2 2
		3 3 5  2 2 0    3 3 0  2 2 5      0 3 3  5 2 2    5 3 3  0 2 2
   
## ## 
   
                  U               U'               D                D'
                                                       
		front  back     front  back       front  back     front  back
		5 5 5  0 0 0    5 5 5  0 0 0      5 5 5  0 0 0    5 5 5  0 0 0
		5 5 5  0 0 0    5 5 5  0 0 0      5 5 5  0 0 0    5 5 5  0 0 0
		5 5 5  0 0 0    5 5 5  0 0 0      5 5 5  0 0 0    5 5 5  0 0 0

		left   right    left   right      left   right    left   right
		4 4 4  1 1 1    4 4 4  1 1 1      4 4 4  1 1 1    4 4 4  1 1 1
		4 4 4  1 1 1    4 4 4  1 1 1      4 4 4  1 1 1    4 4 4  1 1 1
		4 4 4  1 1 1    4 4 4  1 1 1      4 4 4  1 1 1    4 4 4  1 1 1

		top    bottom   top    bottom     top    bottom   top    bottom
		A B C  2 2 2    A B C  2 2 2      3 3 3  A B C    3 3 3  A B C
		H 3 D  2 2 2    H 3 D  2 2 2      3 3 3  H 2 D    3 3 3  H 2 D
		G F E  2 2 2    G F E  2 2 2      3 3 3  G F E    3 3 3  G F E

		                             to   

		front  back     front  back       front  back     front  back
		1 1 1  4 4 4    4 4 4  1 1 1      5 5 5  0 0 0    5 5 5  0 0 0
		5 5 5  0 0 0    5 5 5  0 0 0      5 5 5  0 0 0    5 5 5  0 0 0
		5 5 5  0 0 0    5 5 5  0 0 0      4 4 4  1 1 1    1 1 1  4 4 4

		left   right    left   right      left   right    left   right
		5 5 5  0 0 0    0 0 0  5 5 5      4 4 4  1 1 1    4 4 4  1 1 1
		4 4 4  1 1 1    4 4 4  1 1 1      4 4 4  1 1 1    4 4 4  1 1 1
		4 4 4  1 1 1    4 4 4  1 1 1      0 0 0  5 5 5    5 5 5  0 0 0

		top    bottom   top    bottom     top    bottom   top    bottom
		G H A  2 2 2    C D E  2 2 2      3 3 3  G H A    3 3 3  C D E 
		F 3 B  2 2 2    B 3 F  2 2 2      3 3 3  F 2 B    3 3 3  B 2 F
		E D C  2 2 2    A H G  2 2 2      3 3 3  E D C    3 3 3  A H G
   	
## ##   	
                  F               F'               B               B'
                                                     
		front  back     front  back       front  back     front  back
		A B C  0 0 0    A B C  0 0 0      5 5 5  0 0 0    5 5 5  0 0 0
		H 5 D  0 0 0    H 5 D  0 0 0      5 5 5  0 0 0    5 5 5  0 0 0
		G F E  0 0 0    G F E  0 0 0      5 5 5  0 0 0    5 5 5  0 0 0

		left   right    left   right      left   right    left   right
		4 4 4  1 1 1    4 4 4  1 1 1      4 4 4  1 1 1    4 4 4  1 1 1
		4 4 4  1 1 1    4 4 4  1 1 1      4 4 4  1 1 1    4 4 4  1 1 1
		4 4 4  1 1 1    4 4 4  1 1 1      4 4 4  1 1 1    4 4 4  1 1 1

		top    bottom   top    bottom     top    bottom   top    bottom
		3 3 3  2 2 2    3 3 3  2 2 2      3 3 3  A B C    3 3 3  A B C
		3 3 3  2 2 2    3 3 3  2 2 2      3 3 3  H 2 D    3 3 3  H 2 D
		3 3 3  2 2 2    3 3 3  2 2 2      3 3 3  G F E    3 3 3  G F E

		                              to   

		front  back     front  back       front  back      front  back
		G H A  0 0 0    C D E  0 0 0      5 5 5  C D E     5 5 5  G H A 
		F 5 B  0 0 0    B 5 F  0 0 0      5 5 5  B 0 F     5 5 5  F 0 B
		E D C  0 0 0    A H G  0 0 0      5 5 5  A H G     5 5 5  E D C

		left   right    left   right      left   right     left   right
		4 4 1  3 1 1    4 4 3  2 1 1      4 4 4  1 1 1     4 4 4  1 1 1
		4 4 1  3 1 1    4 4 3  2 1 1      4 4 4  1 1 1     4 4 4  1 1 1
		4 4 1  3 1 1    4 4 3  2 1 1      3 3 3  2 2 2     2 2 2  3 3 3

		top    bottom   top    bottom     top    bottom    top    bottom
		3 3 3  1 1 1    3 3 3  4 4 4      3 3 3  2 2 2     3 3 3  2 2 2 
		3 3 3  2 2 2    3 3 3  2 2 2      3 3 3  2 2 2     3 3 3  2 2 2
		4 4 4  2 2 2    1 1 1  2 2 2      1 1 1  4 4 4     4 4 4  1 1 1

## ##   	
                 Mh              Mh'               Mv               Mv'
                                                      
		front  back     front  back       front  back      front  back
		5 5 5  0 0 0    5 5 5  0 0 0      5 A 5  0 G 0     5 A 5  0 G 0
		A B C  G H I    A B C  G H I      5 B 5  0 H 0     5 B 5  0 H 0
		5 5 5  0 0 0    5 5 5  0 0 0      5 C 5  0 I 0     5 C 5  0 I 0

		left   right    left   right      left   right     left   right
		4 4 4  1 1 1    4 4 4  1 1 1      4 4 4  1 1 1     4 4 4  1 1 1
		L K J  D E F    L K J  D E F      4 4 4  1 1 1     4 4 4  1 1 1
		4 4 4  1 1 1    4 4 4  1 1 1      4 4 4  1 1 1     4 4 4  1 1 1

		top    bottom   top    bottom     top    bottom    top    bottom
		3 3 3  2 2 2    3 3 3  2 2 2      3 J 3  2 D 2     3 J 3  2 D 2
		3 3 3  2 2 2    3 3 3  2 2 2      3 K 3  2 E 2     3 K 3  2 E 2
		3 3 3  2 2 2    3 3 3  2 2 2      3 L 3  2 F 2     3 L 3  2 F 2

		                             to 

		front  back     front  back       front  back      front  back
		5 5 5  0 0 0    5 5 5  0 0 0      5 J 5  0 D 0     5 J 5  0 D 0 
		J K L  D E F    L K J  D E F      5 K 5  0 E 0     5 K 5  0 E 0
		5 5 5  0 0 0    5 5 5  0 0 0      5 L 5  0 F 0     5 L 5  0 F 0

		left   right    left   right      left   right     left   right
		4 4 4  1 1 1    4 4 4  1 1 1      4 4 4  1 1 1     4 4 4  1 1 1
		I H G  A B C    C B A  G H F      4 4 4  1 1 1     4 4 4  1 1 1
		4 4 4  1 1 1    4 4 4  1 1 1      4 4 4  1 1 1     4 4 4  1 1 1

		top    bottom   top    bottom     top    bottom    top    bottom
		3 3 3  2 2 2    3 3 3  2 2 2      3 A 3  2 G 2     3 G 3  2 A 2 
		3 3 3  2 2 2    3 3 3  2 2 2      3 B 3  2 H 2     3 H 3  2 B 2
		3 3 3  2 2 2    3 3 3  2 2 2      3 C 3  2 I 2     3 I 3  2 C 2
## ##
