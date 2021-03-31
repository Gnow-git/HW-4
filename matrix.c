#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Method Declaration */
int** create_matrix(int row, int col);
void print_matrix(int** matrix, int row, int col);
int free_matrix(int** matrix, int row, int col);
int fill_data(int** matrix, int row, int col);
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);

int main()
{

    char command;
    printf("[----- [이 명 국]  [2017038100] -----]\n");

    int row, col;           // 입력 받을 row(행) col(열) 변수 지정
    srand(time(NULL));      // 매번 다른 난수를 받기위한 함수 선언

    printf("Input row and col : ");
    scanf("%d %d", &row, &col);
    int** matrix_a = create_matrix(row, col);       //matrix 생성시  입력 받은 row와 col을 matrix_a에 대입하여 지정(행렬 A)
    int** matrix_b = create_matrix(row, col);       //matrix 생성시  입력 받은 row와 col을 matrix_b에 대입하여 지정(행렬 B)
    int** matrix_a_t = create_matrix(col, row);     //matrix 생성시  입력 받은 row와 col을 matrix_a_t에 대입하여 지정(전치행렬 T)

    printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) {return -1;} //matrix_a의 값 또는 matrix_b의 값이 NULL일 경우 -1 return

    do{         //메뉴 시스템
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);     //메뉴 선택을 위한 command 입력

        switch(command) {       //commad에 따른 메뉴 선택 case
        case 'z': case 'Z':     //Matrix 난수 설정(rand())
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col);  //matrix_a 난수 설정(rand())
            fill_data(matrix_b, row, col);  //matrix_b 난수 설정(rand())
            break;
        case 'p': case 'P':     //Matrix 출력
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col); ///matrix_a 출력
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col); ///matrix_b 출력
            break;
        case 'a': case 'A':     //matrix_a 와 matrix_b의 합 출력
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);      // 각 행 열에 맞는 a,b 값 합 출력
            break;
        case 's': case 'S':     //matrix_a 와 matrix_b의 차 출력
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);   // 각 행 열에 맞는 a,b 값 차 출력
            break;
        case 't': case 'T':     //matrix_a의 전치행렬 출력
            printf("Transpose matrix_a \n");
            printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);   // matrix_a 행렬을 가지고 matrix_a_t라는 전치행렬 출력
            print_matrix(matrix_a_t, col, row);
            break;
        case 'm': case 'M':     //matrix_a과 matrix_a의 전치행렬인 matrix_a_t의 곱 출력
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col);
            break;
        case 'q': case 'Q':     // 프로그램 종료
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);  // 할당된 matrix_a_t 종료  
            free_matrix(matrix_a, row, col);    // 할당된 matrix_a 종료
            free_matrix(matrix_b, row, col);    // 할당된 matrix_b 종료
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");  //메뉴 외의 값 입력시 경고 메시지 출력
            break;
        }

    }while(command != 'q' && command != 'Q');   //q나 Q 값이 아닌 경우 1을 return

    return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col){      //2차 행렬 생성을 위한 함수
    /* check pre conditions */
if(row <= 0 || col <=0) {           //row나 col의 값이 0이거나 0보다 작을 경우 경고 메시지 출력
printf("Check the sizes of row and col!\n");
return NULL;                        //NULL return
}

int **matrix = malloc(sizeof(int *) * row);     //row의 사이즈 지정

for (int i = 0; i <row; i++){

    matrix[i] = malloc(sizeof(int) * col);  //col의 사이즈 지정
}

for (int i = 0; i < row; i++){      //입력한 row와 col에 따른 행렬 생성
    for (int j = 0; j < col; j++){
        matrix[i][j] = 0;       //생성된 행렬의 내부 값을 0으로 초기화
    }
}


/* check post conditions */
if(matrix == NULL) {
/* proper actions for unexpected conditions */
}

return matrix;      //생성된 matrix return 하여 출력
}
/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)       //생성된 matrix 출력
{
    for (int i = 0; i< row; i++){     
       for(int j = 0; j< col; j++){
             printf("%d\t", matrix[i][j]);
       }
       printf("\n");
    }printf("\n");

}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)     //생성된 matrix를 free함수를 통해 해제 
{
for (int i = 0; i < col; i++){
        for (int j = 0; j < row; j++){
            matrix[i][j];
            free(matrix);    
        }
    }
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)      //생성된 matrix에 랜덤 값 설정
{
  
   for (int i = 0; i < row; i++){   //입력한 row만큼의 행 생성
       for(int j = 0; j < col; j++){    //입력한 col만큼의 행 생성
           matrix[i][j] = rand()%20;    //생성된 행렬에 랜던 값 설정
       }
   }

}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)   //matrix_a와 matrix_b의 값을 합하여 sum이라는 행렬로 출력
{
    int sum[50][50] = {0};      //sum이라는 행렬 생성후 0으로 초기화
    for (int i = 0; i< row; i++){     //입력한 row만큼의 행 생성
       for(int j = 0; j< col; j++){     //입력한 col만큼의 행 생성
           matrix_a[i][j];          //matrix_a 행렬 생성
           matrix_b[i][j];          //matrix_b 행렬 생성
           sum[i][j] = matrix_a[i][j] + matrix_b[i][j];     //matrix_a와 matrix_b를 합한 후 sum에 대입
        printf("%2d\t",sum[i][j]);  //sum 출력
       }printf("\n");
    }
}
/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)    //matrix_a와 matrix_b의 값을 빼서 sub이라는 행렬로 출력
{
  int sub[50][50] = {0};        //sub라는 행렬 생성후 0으로 초기화
    for (int i = 0; i< row; i++){       //입력한 row만큼의 행 생성  
       for(int j = 0; j< col; j++){     //입력한 col만큼의 행 생성
           matrix_a[i][j];          //matrix_a 행렬 생성
           matrix_b[i][j];          //matrix_b 행렬 생성
           sub[i][j] = matrix_a[i][j] - matrix_b[i][j];     //matrix_a와 matrix_b를 뺀후 sub에 대입
        printf("%2d\t",sub[i][j]);  //sub 출력
       }printf("\n");
    }
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)    //matrix의 값을 전치행렬하여 matrix_t 생성
{
for (int i = 0; i< row; i++){     
       for(int j = 0; j< col; j++){
             matrix_t[i][j] = matrix[j][i]; //row와 col의 위치를 바꿔주면서 전치행렬 생성
       }\
}
}
/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)   //matrix_a 값과 전치행렬한 matrix_t 값의 곱 생성
{
 int mul[50][50] = {0};
    if(row>col){                                                // row가 col 보다 클 경우 배열 전체 길이를 col * col로 지정
    for (int i = 0; i< col; i++){     
       for(int j = 0; j< col; j++){
        matrix_a[i][j];
        matrix_t[i][j] = matrix_a[j][i];
        mul[i][j] = matrix_a[i][j] * matrix_t[i][j];
        printf("%2d\t", mul[i][j]);
       }printf("\n");
    }
    }else
    for (int i = 0; i< row; i++){                               // row가 col 보다 작을 경우 배열 전체 길이를 row * row로 지정
       for(int j = 0; j< row; j++){
        matrix_a[i][j];
        matrix_t[i][j] = matrix_a[j][i];
        mul[i][j] = matrix_a[i][j] * matrix_t[i][j];
        printf("%2d\t", mul[i][j]);
       }printf("\n");
    }
}