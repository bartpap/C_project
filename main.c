#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define randnum( min, max) \
        ( ( rand()% ( int)( ( ( max)+ 1)- ( min)))+ ( min))

// direction:
// 1 up
// 2 right
// 3 down
// 4 left

void generate_1st_row(int block){
    if(block == 0){
        printf("XXX");
        return;
    }
    int is_start = 0;
    int is_end = 0;
    if ((block -40) > 0) {
        is_start = 1;
        block-=40;
    }
    else if ((block -20 ) > 0){
        if ( block == 28 ){
            is_end = 1;
        }
        block -= 20;
    }

    printf("X");

    if (is_start == 1)
        printf("S");
    else if (is_end == 1)
        printf("M");
    else{
        if(block == 1 || block == 3 || block == 5 || block == 6 || block == 10)
            printf("X");
        else
            printf(" ");
    }

    printf("X");
}

void generate_2nd_row(int block){
    if(block == 0){
        printf("XXX");
        return;
    }
    if ((block -40) > 0)
        block-=40;
    else if ((block -20 ) > 0)
        block -= 20;


    switch (block) {
        case 1:
            printf("XXX");
            break;
        case 3:
            printf("X X");
            break;
        case 2:
        case 12:
        case 10:
        case 11:
            printf("   ");
            break;
        case 4:
        case 5:
        case 9:
            printf("X  ");
            break;
        case 6:
        case 7:
        case 8:
            printf("  X");
    }
}

void generate_3rd_row(int block){
    if(block == 0){
        printf("XXX");
        return;
    }
    int is_end = 0;
    if ((block -40) > 0) {
        block-=40;
    }
    else if ((block -20 ) > 0){
        if ( block == 22 || block == 25 || block == 26){
            is_end = 1;
        }
        block -= 20;
    }

    printf("X");

    if (is_end == 1)
        printf("M");
    else{
        if(block == 1 || block == 3 || block == 4 || block == 7 || block == 11)
            printf("X");
        else
            printf(" ");
    }

    printf("X");
}

int move_x(int direction, int x){
    switch (direction) {
        case 2:
            x = x + 1;
            break;
        case 4:
            x = x - 1;
            break;
        default:
            return x;
    }
    return x;
}

int move_y(int direction, int y) {
    switch (direction) {
        case 1:
            y -= 1;
            break;
        case 3:
            y += 1;
            break;
        default:
            return y;
    }
    return y;
}

int check_in_array(int tab[], int a, int size){
    int t=0 , ans = 0;

    for(int i = 0; i<size; i++) {
        if (tab[i] == a)
            ans = -1;
        if (tab[i] != 0)
            t++;
    }

    if (t==size)
        ans = 0;

    if(ans == 0)
        return t;
    else
        return -1;
}

int choose_direction(int block, int direction){
    if(block<8){
        switch (direction) {
            case 1:{
                switch (block) {
                    case 4:
                        return 2;
                    case 7:
                        return 4;
                    case 2:
                        return 1;
                }
            }
            case 2:{
                switch (block) {
                    case 4:
                        return 1;
                    case 5:
                        return 3;
                    case 3:
                        return 2;
                }
            }
            case 3:{
                switch (block) {
                    case 5:
                        return 2;
                    case 6:
                        return 4;
                    case 3:
                        return 3;
                }
            }
            case 4:{
                switch (block) {
                    case 6:
                        return 3;
                    case 7:
                        return 1;
                    case 3:
                        return 4;
                }
            }
        }
    }
    else if (block <12){
        int a =randnum(1,2);
        switch (direction) {
            case 1:{
                switch (block) {
                    case 8:{
                        switch(a){
                            case 1:
                                return 4;
                            case 2:
                                return 3;
                        }
                    }
                    case 9:{
                        switch(a){
                            case 1:
                                return 2;
                            case 2:
                                return 3;
                        }
                    }
                    case 11:{
                        switch(a){
                            case 1:
                                return 2;
                            case 2:
                                return 4;
                        }
                    }
                }
            }
            case 2:{
                switch (block) {
                    case 9:{
                        switch(a){
                            case 1:
                                return 1;
                            case 2:
                                return 3;
                        }
                    }
                    case 10:{
                        switch(a){
                            case 1:
                                return 4;
                            case 2:
                                return 3;
                        }
                    }
                    case 11:{
                        switch(a){
                            case 1:
                                return 4;
                            case 2:
                                return 1;
                        }
                    }
                }
            }
            case 3:{
                switch (block) {
                    case 8:{
                        switch(a){
                            case 1:
                                return 1;
                            case 2:
                                return 4;
                        }
                    }
                    case 9:{
                        switch(a){
                            case 1:
                                return 1;
                            case 2:
                                return 2;
                        }
                    }
                    case 10:{
                        switch(a){
                            case 1:
                                return 2;
                            case 2:
                                return 4;
                        }
                    }
                }
            }
            case 4:{
                switch (block) {
                    case 8:{
                        switch(a){
                            case 1:
                                return 1;
                            case 2:
                                return 3;
                        }
                    }
                    case 10:{
                        switch(a){
                            case 1:
                                return 2;
                            case 2:
                                return 3;
                        }
                    }
                    case 11:{
                        switch(a){
                            case 1:
                                return 1;
                            case 2:
                                return 2;
                        }
                    }
                }
            }
        }
    }
    else
    {
        int a = randnum(1,3);

        switch (direction) {
            case 1:{
                switch (a) {
                    case 1:
                        return 4;
                    case 2:
                        return 2;
                    case 3:
                        return 3;

                }
            }
            case 2:{
                switch (a) {
                    case 1:
                        return 1;
                    case 2:
                        return 4;
                    case 3:
                        return 3;

                }
            }
            case 3:{
                switch (a) {
                    case 1:
                        return 1;
                    case 2:
                        return 2;
                    case 3:
                        return 4;

                }
            }
            case 4:{
                switch (a) {
                    case 1:
                        return 1;
                    case 2:
                        return 2;
                    case 3:
                        return 3;
                }
            }
        }
    }
}

int choose_block(int direction, int a){

    switch (direction) {
        case 1:{
            switch (a) {
                case 1:
                    return 2;
                case 2:
                    return 4;
                case 3:
                    return 7;
                case 4:
                    return 8;
                case 5:
                    return 9;
                case 6:
                    return 11;
                case 7:
                    return 12;
            }
        }
        case 2:{
            switch (a) {
                case 1:
                    return 3;
                case 2:
                    return 4;
                case 3:
                    return 5;
                case 4:
                    return 9;
                case 5:
                    return 10;
                case 6:
                    return 11;
                case 7:
                    return 12;
            }
        }
        case 3:{
            switch (a) {
                case 1:
                    return 2;
                case 2:
                    return 5;
                case 3:
                    return 6;
                case 4:
                    return 8;
                case 5:
                    return 9;
                case 6:
                    return 10;
                case 7:
                    return 12;
            }
        }
        case 4:{
            switch (a) {
                case 1:
                    return 3;
                case 2:
                    return 6;
                case 3:
                    return 7;
                case 4:
                    return 8;
                case 5:
                    return 10;
                case 6:
                    return 11;
                case 7:
                    return 12;
            }
        }
    }
}

int direction_update(int direction){

    switch (direction) {
        case 1:return 3;
        case 3:return 1;
        case 2:return 4;
        case 4:return 2;
    }
}

int generate_labyrinth(int **tab, int max_x, int max_y, int en_y, int en_x, int direction, int ex_y, int ex_x){
    // sprawdzenie czy jeuz nie dotarlismy do mety
    if (en_x == ex_x && en_y == ex_y) {
        int block;
        switch (direction) {
            case 1:
                block = 22;
                break;
            case 2:
                block = 25;
                break;
            case 3:
                block = 28;
                break;
            case 4:
                block = 26;
                break;
        }

        tab[en_y][en_x]= block;

        return 0;
    }

    //sprawdzenie czy nie wyszlismy po za tablice bądź nie nadpiszemy jakiegos elementu
    if(en_x<0 || en_x >= max_y || en_y < 0 || en_y >= max_x)
        return 1;
    if(tab[en_x][en_y] != 0)
        return 1;


    // sprawdzenie czy jest jakies wolne miejsce
    int number_of_busy_places = 0;

    if( en_y-1<0 )
        number_of_busy_places++;
    else if(tab[en_y-1][en_x] != 0)
        number_of_busy_places++;

    if( en_x-1<0 )
        number_of_busy_places++;
    else if(tab[en_y][en_x-1] != 0)
        number_of_busy_places++;

    if( en_y+1 >= max_y )
        number_of_busy_places++;
    else if(tab[en_y+1][en_x] != 0)
        number_of_busy_places++;

    if( en_x+1 >= max_x )
        number_of_busy_places++;
    else if(tab[en_y][en_x+1] != 0)
        number_of_busy_places++;

    if(number_of_busy_places == 4)
        return 1;

    int choose[8]={0,0,0,0,0,0,0,0}, f_direction, block, f_x, f_y, is_good = 1;
    while (is_good != 0) {
        int los = -1;
        while (los == -1) {
            int a = randnum(1,7);

            //losowanie klocka
            block = choose_block(direction, a);

            //sprawdz czy nie ma w choose
            los = check_in_array(choose, block, 7);

            //sprawdzenie czy tablica sie nie przepelnila
            if (los == 7){
                // brak nowych mozliwosci trzeba cofnac ruch
                // zerowanie bloku i cofniecie sie
                tab[en_y][en_x]=0;
                return 1;
            }
            choose[los] = block;
//            printf("L:%d B:%d D:%d\n", los, block, direction);
        }

        //losowanie kierunku
        f_direction = choose_direction(block, direction);

        // przesuniecie wspolzednych wzgledem kierunku
        f_x = move_x(f_direction, en_x);
        f_y = move_y(f_direction, en_y);

        // zapisywanie wybranego bloku
        tab[en_y][en_x] = block;

        //zmiana f_direction na wlasciwy nastepnego bloku
        f_direction = direction_update(f_direction);

        is_good = generate_labyrinth(tab, max_y, max_x, f_y, f_x, f_direction, ex_y, ex_x);
    }
    return 0;
}

int main( ){
    srand( time( NULL));

    int i,j;
    int max_y = 4;
    int max_x = 4;
    int number_labyrinths = 1;
    int entry_x = 1;
    int entry_y = 1;
    int exit_x = 4;
    int exit_y = 4;

    printf("Hello!\n");
    // Inicjowanie tablicy 3 wymiarowej
    // 1 wymiar - numer tablicy
    // dwa kolejne sa przeznaczone na przechowanie labiryntu

    int ***tab;
    tab = malloc(number_labyrinths * sizeof(**tab));

    for (size_t p = 0; p < number_labyrinths; ++p) {
        tab[p] = malloc(max_y * sizeof(*tab));

        for (size_t r = 0; r < max_y; ++r) {
            tab[p][r] = malloc(max_x * sizeof(tab[0]));
        }
    }

    // Tworzenie labiryntow

    printf("Im generating...\n");
    for( i = 0 ; i<number_labyrinths; i++){
        //generowanie labiryntu
        generate_labyrinth(tab[i], max_y, max_x, entry_y-1, entry_x-1, 1, exit_y-1, exit_x-1);
        tab[i][entry_y-1][entry_y-1] += 40;
        printf("skonczylem labirynt nr. %d\n", i+1);
        //uzupelnianie labiryntu
    }
    for(int k =0; k<number_labyrinths;k++)
    {
        printf("\nLabirynt nr. %d\n", k+1);
        for (i = 0; i < max_y; i++) {

            for (j = 0; j < max_x; j++)
                printf(" %d", tab[k][i][j]);
            printf("\n");

//            for (j = 0; j < max_x; j++)
//                generate_1st_row(tab[k][i][j]);
//            printf("\n");
//            for (j = 0; j < max_x; j++)
//                generate_2nd_row(tab[k][i][j]);
//            printf("\n");
//            for (j = 0; j < max_x; j++)
//                generate_3rd_row(tab[k][i][j]);
//            printf("\n");


        }
        printf("\n");
    }

    // Usuwanie tablicy
    printf("Im deleting...\n");

    for ( i = 0; i < number_labyrinths; i++ )
    {
        for ( j = 0; j < max_y; j++ )
        {
            free(tab[i][j]);
        }
        free(tab[i]);
    }
    free(tab);

    return 0;
}
