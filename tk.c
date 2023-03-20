// ./push_swap 700 100 300 1000 400 800 500 600 200 900 88 565 321 78 89         
// >>>>>>17   8  9 
78 89 700 100 300 1000 400 800 500 600 200 900 88 565 321 

>> 78 89 100 300 400 500 600 900


 ./push_swap 700 100 300 1000 400 800 500 600 200 201 202 900 565 321 78 222 89 
a 0 700 || : min 78 : max 1000 : size 17
a 1 100 || : min 78 : max 1000 : size 17
a 2 300 || : min 78 : max 1000 : size 17
a 3 1000        || : min 78 : max 1000 : size 17
a 4 400 || : min 78 : max 1000 : size 17
a 5 800 || : min 78 : max 1000 : size 17
a 6 500 || : min 78 : max 1000 : size 17
a 7 600 || : min 78 : max 1000 : size 17
a 8 200 || : min 78 : max 1000 : size 17
a 9 201 || : min 78 : max 1000 : size 17
a 10 202        || : min 78 : max 1000 : size 17
a 11 900        || : min 78 : max 1000 : size 17
a 12 565        || : min 78 : max 1000 : size 17
a 13 321        || : min 78 : max 1000 : size 17
a 14 78 || : min 78 : max 1000 : size 17
a 15 222        || : min 78 : max 1000 : size 17
a 16 89 || : min 78 : max 1000 : size 17
rra
rra
rra
78  89  100  300  400  500  600  900  

78 kayn
222 makaynch
89 kayn
700 makaynch
100 kayn
300 kayn
1000 makaynch
400 kayn
800 makaynch
500 kayn
600 kayn
200 makaynch
201 makaynch
202 makaynch
900 kayn
565 makaynch
321 makaynch

(mov:1,t:1)

ra
a    222
a    89
a    700
a    100
a    300
a    1000
a    400
a    800
a    500
a    600
a    200
a    201
a    202
a    900
a    565
a    321
a    78
222
pb

89 kayn
700 makaynch
100 kayn
300 kayn
1000 makaynch
400 kayn
800 makaynch
500 kayn
600 kayn
200 makaynch
201 makaynch
202 makaynch
900 kayn
565 makaynch
321 makaynch
78 kayn

(mov:1,t:2)

ra
a    700
a    100
a    300
a    1000
a    400
a    800
a    500
a    600
a    200
a    201
a    202
a    900
a    565
a    321
a    78
a    89
700
pb

100 kayn
300 kayn
1000 makaynch
400 kayn
800 makaynch
500 kayn
600 kayn
200 makaynch
201 makaynch
202 makaynch
900 kayn
565 makaynch
321 makaynch
78 kayn
89 kayn

(mov:2,t:3)

ra
ra
a    1000
a    400
a    800
a    500
a    600
a    200
a    201
a    202
a    900
a    565
a    321
a    78
a    89
a    100
a    300
1000
pb

400 kayn
800 makaynch
500 kayn
600 kayn
200 makaynch
201 makaynch
202 makaynch
900 kayn
565 makaynch
321 makaynch
78 kayn
89 kayn
100 kayn
300 kayn

(mov:1,t:5)

ra
a    800
a    500
a    600
a    200
a    201
a    202
a    900
a    565
a    321
a    78
a    89
a    100
a    300
a    400
800
pb

500 kayn
600 kayn
200 makaynch
201 makaynch
202 makaynch
900 kayn
565 makaynch
321 makaynch
78 kayn
89 kayn
100 kayn
300 kayn
400 kayn

(mov:2,t:6)

ra
ra
a    200
a    201
a    202
a    900
a    565
a    321
a    78
a    89
a    100
a    300
a    400
a    500
a    600
200
pb

201 makaynch
202 makaynch
900 kayn
565 makaynch
321 makaynch
78 kayn
89 kayn
100 kayn
300 kayn
400 kayn
500 kayn
600 kayn

(mov:0,t:12)

a    201
a    202
a    900
a    565
a    321
a    78
a    89
a    100
a    300
a    400
a    500
a    600
201
pb

202 makaynch
900 kayn
565 makaynch
321 makaynch
78 kayn
89 kayn
100 kayn
300 kayn
400 kayn
500 kayn
600 kayn

(mov:0,t:11)

a    202
a    900
a    565
a    321
a    78
a    89
a    100
a    300
a    400
a    500
a    600
202
pb

900 kayn
565 makaynch
321 makaynch
78 kayn
89 kayn
100 kayn
300 kayn
400 kayn
500 kayn
600 kayn

(mov:1,t:10)

ra
a    565
a    321
a    78
a    89
a    100
a    300
a    400
a    500
a    600
a    900
565
pb

321 makaynch
78 kayn
89 kayn
100 kayn
300 kayn
400 kayn
500 kayn
600 kayn
900 kayn

(mov:0,t:9)

a    321
a    78
a    89
a    100
a    300
a    400
a    500
a    600
a    900
321
pb

a 17 78 || : min 78 : max 1000 : size 8
a 18 89 || : min 78 : max 1000 : size 8
a 19 100        || : min 78 : max 1000 : size 8
a 20 300        || : min 78 : max 1000 : size 8
a 21 400        || : min 78 : max 1000 : size 8
a 22 500        || : min 78 : max 1000 : size 8
a 23 600        || : min 78 : max 1000 : size 8
a 24 900        || : min 78 : max 1000 : size 8

===========

b  321  || : min 78 : max 1000 : size 9
b  565  || : min 78 : max 1000 : size 9
b  202  || : min 78 : max 1000 : size 9
b  201  || : min 78 : max 1000 : size 9
b  200  || : min 78 : max 1000 : size 9
b  800  || : min 78 : max 1000 : size 9
b  1000 || : min 78 : max 1000 : size 9
b  700  || : min 78 : max 1000 : size 9
b  222  || : min 78 : max 1000 : size 9

 321 [4,0]
 565 [-2,1]
 202 [3,2]
 201 [3,3]
 200 [3,4]
 800 [-1,-4]
 1000 [0,-3]
 700 [-1,-2]
 222 [3,-1]

rrr
rrb
[-1,-2] 700
pa

a 1 700 || : min 78 : max 1000 : size 9
a 2 900 || : min 78 : max 1000 : size 9
a 3 78  || : min 78 : max 1000 : size 9
a 4 89  || : min 78 : max 1000 : size 9
a 5 100 || : min 78 : max 1000 : size 9
a 6 300 || : min 78 : max 1000 : size 9
a 7 400 || : min 78 : max 1000 : size 9
a 8 500 || : min 78 : max 1000 : size 9
a 9 600 || : min 78 : max 1000 : size 9
 222 [5,0]
 321 [-3,1]
 565 [-1,2]
 202 [5,3]
 201 [5,4]
 200 [5,-3]
 800 [1,-2]
 1000 [2,-1]

ra
[2,-1] 222
pa

a 0 222 || : min 78 : max 1000 : size 10
a 1 900 || : min 78 : max 1000 : size 10
a 2 78  || : min 78 : max 1000 : size 10
a 3 89  || : min 78 : max 1000 : size 10
a 4 100 || : min 78 : max 1000 : size 10
a 5 300 || : min 78 : max 1000 : size 10
a 6 400 || : min 78 : max 1000 : size 10
a 7 500 || : min 78 : max 1000 : size 10
a 8 600 || : min 78 : max 1000 : size 10
a 9 700 || : min 78 : max 1000 : size 10
 321 [1,0]
 565 [1,1]
 202 [5,2]
 201 [5,3]
 200 [5,-3]
 800 [1,-2]
 1000 [2,-1]

ra
[1,0] 321
pa

a 0 321 || : min 78 : max 1000 : size 11
a 1 900 || : min 78 : max 1000 : size 11
a 2 78  || : min 78 : max 1000 : size 11
a 3 89  || : min 78 : max 1000 : size 11
a 4 100 || : min 78 : max 1000 : size 11
a 5 300 || : min 78 : max 1000 : size 11
a 6 400 || : min 78 : max 1000 : size 11
a 7 500 || : min 78 : max 1000 : size 11
a 8 600 || : min 78 : max 1000 : size 11
a 9 700 || : min 78 : max 1000 : size 11
a 10 222        || : min 78 : max 1000 : size 11
 565 [1,0]
 202 [5,1]
 201 [5,2]
 200 [5,3]
 800 [1,-2]
 1000 [2,-1]

ra
[1,0] 565
pa

a 0 565 || : min 78 : max 1000 : size 12
a 1 900 || : min 78 : max 1000 : size 12
a 2 78  || : min 78 : max 1000 : size 12
a 3 89  || : min 78 : max 1000 : size 12
a 4 100 || : min 78 : max 1000 : size 12
a 5 300 || : min 78 : max 1000 : size 12
a 6 400 || : min 78 : max 1000 : size 12
a 7 500 || : min 78 : max 1000 : size 12
a 8 600 || : min 78 : max 1000 : size 12
a 9 700 || : min 78 : max 1000 : size 12
a 10 222        || : min 78 : max 1000 : size 12
a 11 321        || : min 78 : max 1000 : size 12
 202 [5,0]
 201 [5,1]
 200 [5,2]
 800 [1,-2]
 1000 [2,-1]

ra
[2,-1] 202
pa

a 0 202 || : min 78 : max 1000 : size 13
a 1 900 || : min 78 : max 1000 : size 13
a 2 78  || : min 78 : max 1000 : size 13
a 3 89  || : min 78 : max 1000 : size 13
a 4 100 || : min 78 : max 1000 : size 13
a 5 300 || : min 78 : max 1000 : size 13
a 6 400 || : min 78 : max 1000 : size 13
a 7 500 || : min 78 : max 1000 : size 13
a 8 600 || : min 78 : max 1000 : size 13
a 9 700 || : min 78 : max 1000 : size 13
a 10 222        || : min 78 : max 1000 : size 13
a 11 321        || : min 78 : max 1000 : size 13
a 12 565        || : min 78 : max 1000 : size 13
 201 [5,0]
 200 [5,1]
 800 [1,2]
 1000 [2,-1]

ra
[2,-1] 201
pa

a 0 201 || : min 78 : max 1000 : size 14
a 1 900 || : min 78 : max 1000 : size 14
a 2 78  || : min 78 : max 1000 : size 14
a 3 89  || : min 78 : max 1000 : size 14
a 4 100 || : min 78 : max 1000 : size 14
a 5 300 || : min 78 : max 1000 : size 14
a 6 400 || : min 78 : max 1000 : size 14
a 7 500 || : min 78 : max 1000 : size 14
a 8 600 || : min 78 : max 1000 : size 14
a 9 700 || : min 78 : max 1000 : size 14
a 10 222        || : min 78 : max 1000 : size 14
a 11 321        || : min 78 : max 1000 : size 14
a 12 565        || : min 78 : max 1000 : size 14
a 13 202        || : min 78 : max 1000 : size 14
 200 [5,0]
 800 [1,1]
 1000 [2,-1]

rr
[1,1] 800
pa

a 0 800 || : min 78 : max 1000 : size 15
a 1 900 || : min 78 : max 1000 : size 15
a 2 78  || : min 78 : max 1000 : size 15
a 3 89  || : min 78 : max 1000 : size 15
a 4 100 || : min 78 : max 1000 : size 15
a 5 300 || : min 78 : max 1000 : size 15
a 6 400 || : min 78 : max 1000 : size 15
a 7 500 || : min 78 : max 1000 : size 15
a 8 600 || : min 78 : max 1000 : size 15
a 9 700 || : min 78 : max 1000 : size 15
a 10 222        || : min 78 : max 1000 : size 15
a 11 321        || : min 78 : max 1000 : size 15
a 12 565        || : min 78 : max 1000 : size 15
a 13 202        || : min 78 : max 1000 : size 15
a 14 201        || : min 78 : max 1000 : size 15
 1000 [2,0]
 200 [5,1]

ra
ra
[2,0] 1000
pa

a 0 1000        || : min 78 : max 1000 : size 16
a 1 78  || : min 78 : max 1000 : size 16
a 2 89  || : min 78 : max 1000 : size 16
a 3 100 || : min 78 : max 1000 : size 16
a 4 300 || : min 78 : max 1000 : size 16
a 5 400 || : min 78 : max 1000 : size 16
a 6 500 || : min 78 : max 1000 : size 16
a 7 600 || : min 78 : max 1000 : size 16
a 8 700 || : min 78 : max 1000 : size 16
a 9 222 || : min 78 : max 1000 : size 16
a 10 321        || : min 78 : max 1000 : size 16
a 11 565        || : min 78 : max 1000 : size 16
a 12 202        || : min 78 : max 1000 : size 16
a 13 201        || : min 78 : max 1000 : size 16
a 14 800        || : min 78 : max 1000 : size 16
a 15 900        || : min 78 : max 1000 : size 16
 200 [4,0]

ra
ra
ra
ra
[4,0] 200
pa

a 0 200 || : min 78 : max 1000 : size 17
a 1 300 || : min 78 : max 1000 : size 17
a 2 400 || : min 78 : max 1000 : size 17
a 3 500 || : min 78 : max 1000 : size 17
a 4 600 || : min 78 : max 1000 : size 17
a 5 700 || : min 78 : max 1000 : size 17
a 6 222 || : min 78 : max 1000 : size 17
a 7 321 || : min 78 : max 1000 : size 17
a 8 565 || : min 78 : max 1000 : size 17
a 9 202 || : min 78 : max 1000 : size 17
a 10 201        || : min 78 : max 1000 : size 17
a 11 800        || : min 78 : max 1000 : size 17
a 12 900        || : min 78 : max 1000 : size 17
a 13 1000       || : min 78 : max 1000 : size 17
a 14 78 || : min 78 : max 1000 : size 17
a 15 89 || : min 78 : max 1000 : size 17
a 16 100        || : min 78 : max 1000 : size 17
rra
rra
rra

===========

a 0     78      || : max 1000 : size 17
a 1     89      || : max 1000 : size 17
a 2     100     || : max 1000 : size 17
a 3     200     || : max 1000 : size 17
a 4     300     || : max 1000 : size 17
a 5     400     || : max 1000 : size 17
a 6     500     || : max 1000 : size 17
a 7     600     || : max 1000 : size 17
a 8     700     || : max 1000 : size 17
a -8    222     || : max 1000 : size 17
a -7    321     || : max 1000 : size 17
a -6    565     || : max 1000 : size 17
a -5    202     || : max 1000 : size 17
a -4    201     || : max 1000 : size 17
a -3    800     || : max 1000 : size 17
a -2    900     || : max 1000 : size 17
a -1    1000    || : max 1000 : size 17

===========

b  0    0       || : min 78 : size 0 max : 1000 