#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int size_word, fault, points, rand_tip, total_points, option, counter_letters, cont_repeated;
char letter, word[15], game[15], user_caps[10], typed_letters[26], option_getche;


void HEAD(){

     if (total_points != 0){
         printf("----------- JOGO DA FORCA -----------\n");
         printf("\tPONTOS DE %s: %i\n\n", user_caps, total_points);
     }else{
         printf("----------- JOGO DA FORCA -----------\n\n");
     }
 }

void CAPS(char word1[], char word2[]){
    int counter=0;

    while(word1[counter] !='\0'){
        word2[counter] = toupper(word1[counter]);
        counter++;
    }

    word2[counter]= '\0';
}

int DIFFICULTY(){
    int counter, dif;
    counter = 1;

    while (counter==1){
        printf("\n\nEscolha a dificuldade:\n\n[ 1 ] FACIL\t[ 2 ] MEDIO\t[ 3 ] DIFICIL\n");
        option_getche = getche();
        dif = CHAR_TO_INT();

        if ((dif > 0)&&(dif<=3)){
            counter=2;
        }else{
            printf ("\nOPCAO INVALIDA\n\n");
        }
    }

    return dif;
}

int CHAR_TO_INT(){
    int dif;

    switch(option_getche){
    case '1':
        dif = 1;
        break;
    case '2':
        dif = 2;
        break;
    case '3':
        dif = 3;
        break;
    default:
        dif = 4;
    }

    return dif;
}

int RAND_TIP(){
    int random;

    srand(time(NULL));
    random = 1 + (rand() % 3);

    return random;
}
int RAND_WORD(){
    int random;

    srand(time(NULL));
    random = 1 + (rand() % 10);

    return random;
}

void EASY(char word[]){
    int rand_word;
    int counter=0;
    FILE *wordlist;

    rand_tip= RAND_TIP();
    rand_word = RAND_WORD();

    switch(rand_tip){
    case 1:
        wordlist = fopen ("EASYANIMAL.txt", "r");

        while(counter != rand_word){
            fscanf(wordlist,"%s",word);
            counter++;
        }

        fclose(wordlist);
        break;

    case 2:
        wordlist = fopen ("EASYFOOD.txt", "r");

        while(counter != rand_word){
            fscanf(wordlist,"%s",word);
            counter++;
        }

        fclose(wordlist);
        break;

    case 3:
        wordlist = fopen ("EASYTHING.txt", "r");

        while(counter != rand_word){
            fscanf(wordlist,"%s",word);
            counter++;
        }

        fclose(wordlist);
        break;
    }
}
void MEDIUM (char word[]){
    int rand_word;
    int counter=0;
    FILE *wordlist;

    rand_tip= RAND_TIP();
    rand_word = RAND_WORD();

    switch(rand_tip){
    case 1:
        wordlist = fopen ("MEDIANIMAL.txt", "r");

        while(counter != rand_word){
            fscanf(wordlist,"%s",word);
            counter++;
        }

        fclose(wordlist);
        break;

    case 2:
        wordlist = fopen ("MEDIFOOD.txt", "r");

        while(counter != rand_word){
            fscanf(wordlist,"%s",word);
            counter++;
        }

        fclose(wordlist);
        break;

    case 3:
        wordlist = fopen ("MEDITHING.txt", "r");

        while(counter != rand_word){
            fscanf(wordlist,"%s",word);
            counter++;
        }

        fclose(wordlist);
        break;
    }
}
void HARD (char word[]){
    int rand_word;
    int counter=0;
    FILE *wordlist;

    rand_tip= RAND_TIP();
    rand_word = RAND_WORD();

    switch(rand_tip){
    case 1:
        wordlist = fopen ("HARDANIMAL.txt", "r");

        while(counter != rand_word){
            fscanf(wordlist,"%s",word);
            counter++;
        }

        fclose(wordlist);
        break;

    case 2:
        wordlist = fopen ("HARDFOOD.txt", "r");

        while(counter != rand_word){
            fscanf(wordlist,"%s",word);
            counter++;
        }

        fclose(wordlist);
        break;

    case 3:
        wordlist = fopen ("HARDTHING.txt", "r");

        while(counter != rand_word){
            fscanf(wordlist,"%s",word);
            counter++;
        }

        fclose(wordlist);
        break;
    }
}

void FAULT(int fault){

    switch (fault){
    case 0:
        printf("\n______\n");
        printf("|    |\n");
        printf("|     \n");
        printf("|     \n");
        printf("|     \n\n");
        break;
    case 1:
        printf("\n______\n");
        printf("|    |\n");
        printf("|    O\n");
        printf("|     \n");
        printf("|     \n\n");
        break;
    case 2:
        printf("\n______\n");
        printf("|    |\n");
        printf("|    O\n");
        printf("|    | \n");
        printf("|      \n\n");
        break;
    case 3:
        printf("\n______\n");
        printf("|    |\n");
        printf("|    O\n");
        printf("|    | \n");
        printf("|   /  \n\n");
        break;
    case 4:
        printf("\n______\n");
        printf("|    |\n");
        printf("|    O\n");
        printf("|    |\n");
        printf("|   / \\\n\n");
        break;
    case 5:
        printf("\n______\n");
        printf("|    |\n");
        printf("|    O\n");
        printf("|   /| \n");
        printf("|   / \\\n\n");
        break;
    case 6:
        printf("\n______\n");
        printf("|    |\n");
        printf("|    O\n");
        printf("|   /|\\\n");
        printf("|   / \\\n\n");
        break;
    }
}

void TIP(){
    switch(rand_tip){
    case 1:
        printf("\t   DICA: ANIMAL\n");
        break;
    case 2:
        printf("\t   DICA: COMIDA\n");
        break;
    case 3:
        printf("\t   DICA: OBJETO\n");
        break;
}
}

void GAME(){
    int counter, cont_fault, cont_win, control;
    counter = cont_win = points = fault = 0;
    cont_fault = -1;

    TIP();
    while ((fault < 7) && (cont_win < size_word)){

        while (counter < size_word){

            if(letter == word[counter]){
                game[counter] = letter;
                points = points + 5;
                cont_win++;
            }else{
                cont_fault++;
            }

            if(cont_fault == size_word){
                fault++;

                if (points > 2){
                    points = points - 2;
                }else{
                    points = 0;
                }
            }

            counter++;
        }

        FAULT(fault);

        for(int counter2 = 0; counter2 < size_word; counter2++){
        printf("%c   ", game[counter2]);
        }

        cont_fault = counter = 0;
        cont_repeated = 1;


        if((fault < 7) && (cont_win < size_word)){

        while(cont_repeated != 0){
            cont_repeated = 0;
            printf("\n\nDIGITE UMA LETRA: ");
            letter = getche();
            letter = toupper(letter);

            if (counter_letters !=0){
                VALID_LETTERS();
            }else{
                cont_repeated = 0;
            }

            if (cont_repeated != 0){
                printf("  LETRA REPETIDA\n");
            }
        }

        system("cls");
        HEAD();
        TIP();
        TYPED_LETTERS();
        }
    }

   if(fault >= 7){

        if (points > 10){
            points = points - 10;
        }else{
            points = 0;
        }

    }else{
        points = points + 10;
    }

    total_points = total_points + points;
}

void POINTS(){

    printf("\n\nPONTOS DA RODADA: \t\t TOTAL DE PONTOS:\n\n");
    printf("\t%i\t\t\t\t%i\n\n", points, total_points);

}

void FINAL(){
    system("cls");

    printf("----------- JOGO DA FORCA -----------\n\n");
    printf("\nOBRIGADA %s! SUA PONTUACAO FINAL FOI: %i\n\n\n\n", user_caps, total_points);

    system("pause");
}

void POINTS_EXPLAIN(){
    system("cls");
    HEAD();
    printf("\n\nCADA LETRA CERTA VALE 5 PONTOS.\nCADA ERRO PERDE 2 PONTOS.\nCADA VITORIA VALE 10 PONTOS.\nCADA DERROTA PERDE 10 PONTOS.\n");
}

void MENU(){
    while((option > 1) && (option != 2)){
        printf("\n\nDESEJA JOGAR NOVAMENTE?\n\n [ 1 ] SIM\t [ 2 ] NAO\t [ 3 ] ENTENDA A PONTUACAO\n");
        option_getche = getche();
        option = CHAR_TO_INT();

        switch(option){
        case 1:
            break;

        case 2:
            FINAL();
            break;

        case 3:
            POINTS_EXPLAIN();
            break;

        default:
            printf("\nOPCAO INVALIDA");
        }
    }
}

void TYPED_LETTERS(){

    typed_letters[counter_letters] = letter;
    counter_letters++;

    printf("\n\nLETRAS JOGADAS: ");
    for(int counter2 = 0; counter2 < counter_letters; counter2++){
        printf(" %c   - ", typed_letters[counter2]);
    }
}

void VALID_LETTERS(){
    int control;
    control = 0;

    while (control <= 26){

        if (letter == typed_letters[control]){
            cont_repeated++;
        }

    control++;
    }
}

void RESULT(){
    if(fault >= 7){
        printf("QUE PENA %s! Voce perdeu.\n\nA palavra era: %s\n\n", user_caps, word);
    }else{
        printf("PARABENS %s! Voce ganhou.\n\nA palavra era: %s\n\n", user_caps, word);
    }
}

int main(){

    int difficulty, counter;
    char user[10];
    total_points = 0;
    option = 1;

    HEAD();
    printf("NOME DO JOGADOR: ");
    scanf("%s", &user);
    printf("\n\n");

    CAPS(user,user_caps);
    printf("BEM VINDO %s! ", user_caps);

    while (option == 1){
        counter = counter_letters = 0;

        difficulty = DIFFICULTY();

        switch(difficulty){
        case 1:
            EASY(word);
            break;

        case 2:
            MEDIUM(word);
            break;

        case 3:
            HARD(word);
            break;
        }

        size_word = strlen(word);
        game[15] = game[size_word];

        while (counter < size_word){
            game[counter]='_';
            counter++;
        }

        system("cls");
        HEAD();
        GAME();

        system("cls");
        HEAD();
        RESULT();
        POINTS();

        memset(typed_letters, 0, sizeof(typed_letters));
        option = 3;
        MENU();
   }

   return 0;
}


