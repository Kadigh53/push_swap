// ./push_swap 700 100 300 1000 400 800 500 600 200 900 88 565 321 78 89         
// // >>>>>>17   8  9 
// 78 89 700 100 300 1000 400 800 500 600 200 900 88 565 321 

// >> 78 89 100 300 400 500 600 900


//  ./push_swap 700 100 300 1000 400 800 500 600 200 201 202 900 565 321 78 222 89 
// a 0 700 || : min 78 : max 1000 : size 17
// a 1 100 || : min 78 : max 1000 : size 17
// a 2 300 || : min 78 : max 1000 : size 17
// a 3 1000        || : min 78 : max 1000 : size 17
// a 4 400 || : min 78 : max 1000 : size 17
// a 5 800 || : min 78 : max 1000 : size 17
// a 6 500 || : min 78 : max 1000 : size 17
// a 7 600 || : min 78 : max 1000 : size 17
// a 8 200 || : min 78 : max 1000 : size 17
// a 9 201 || : min 78 : max 1000 : size 17
// a 10 202        || : min 78 : max 1000 : size 17
// a 11 900        || : min 78 : max 1000 : size 17
// a 12 565        || : min 78 : max 1000 : size 17
// a 13 321        || : min 78 : max 1000 : size 17
// a 14 78 || : min 78 : max 1000 : size 17
// a 15 222        || : min 78 : max 1000 : size 17
// a 16 89 || : min 78 : max 1000 : size 17

int main(int ac, char **av)
{
    char **k = av+1;
    int i = 0;
    while(i<7)
    {
        printf(">>%s\n",k[i++]);
    }
}