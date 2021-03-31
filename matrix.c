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
    printf("[----- [�� �� ��]  [2017038100] -----]\n");

    int row, col;           // �Է� ���� row(��) col(��) ���� ����
    srand(time(NULL));      // �Ź� �ٸ� ������ �ޱ����� �Լ� ����

    printf("Input row and col : ");
    scanf("%d %d", &row, &col);
    int** matrix_a = create_matrix(row, col);       //matrix ������  �Է� ���� row�� col�� matrix_a�� �����Ͽ� ����(��� A)
    int** matrix_b = create_matrix(row, col);       //matrix ������  �Է� ���� row�� col�� matrix_b�� �����Ͽ� ����(��� B)
    int** matrix_a_t = create_matrix(col, row);     //matrix ������  �Է� ���� row�� col�� matrix_a_t�� �����Ͽ� ����(��ġ��� T)

    printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) {return -1;} //matrix_a�� �� �Ǵ� matrix_b�� ���� NULL�� ��� -1 return

    do{         //�޴� �ý���
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);     //�޴� ������ ���� command �Է�

        switch(command) {       //commad�� ���� �޴� ���� case
        case 'z': case 'Z':     //Matrix ���� ����(rand())
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col);  //matrix_a ���� ����(rand())
            fill_data(matrix_b, row, col);  //matrix_b ���� ����(rand())
            break;
        case 'p': case 'P':     //Matrix ���
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col); ///matrix_a ���
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col); ///matrix_b ���
            break;
        case 'a': case 'A':     //matrix_a �� matrix_b�� �� ���
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);      // �� �� ���� �´� a,b �� �� ���
            break;
        case 's': case 'S':     //matrix_a �� matrix_b�� �� ���
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);   // �� �� ���� �´� a,b �� �� ���
            break;
        case 't': case 'T':     //matrix_a�� ��ġ��� ���
            printf("Transpose matrix_a \n");
            printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);   // matrix_a ����� ������ matrix_a_t��� ��ġ��� ���
            print_matrix(matrix_a_t, col, row);
            break;
        case 'm': case 'M':     //matrix_a�� matrix_a�� ��ġ����� matrix_a_t�� �� ���
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col);
            break;
        case 'q': case 'Q':     // ���α׷� ����
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);  // �Ҵ�� matrix_a_t ����  
            free_matrix(matrix_a, row, col);    // �Ҵ�� matrix_a ����
            free_matrix(matrix_b, row, col);    // �Ҵ�� matrix_b ����
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");  //�޴� ���� �� �Է½� ��� �޽��� ���
            break;
        }

    }while(command != 'q' && command != 'Q');   //q�� Q ���� �ƴ� ��� 1�� return

    return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col){      //2�� ��� ������ ���� �Լ�
    /* check pre conditions */
if(row <= 0 || col <=0) {           //row�� col�� ���� 0�̰ų� 0���� ���� ��� ��� �޽��� ���
printf("Check the sizes of row and col!\n");
return NULL;                        //NULL return
}

int **matrix = malloc(sizeof(int *) * row);     //row�� ������ ����

for (int i = 0; i <row; i++){

    matrix[i] = malloc(sizeof(int) * col);  //col�� ������ ����
}

for (int i = 0; i < row; i++){      //�Է��� row�� col�� ���� ��� ����
    for (int j = 0; j < col; j++){
        matrix[i][j] = 0;       //������ ����� ���� ���� 0���� �ʱ�ȭ
    }
}


/* check post conditions */
if(matrix == NULL) {
/* proper actions for unexpected conditions */
}

return matrix;      //������ matrix return �Ͽ� ���
}
/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)       //������ matrix ���
{
    for (int i = 0; i< row; i++){     
       for(int j = 0; j< col; j++){
             printf("%d\t", matrix[i][j]);
       }
       printf("\n");
    }printf("\n");

}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)     //������ matrix�� free�Լ��� ���� ���� 
{
for (int i = 0; i < col; i++){
        for (int j = 0; j < row; j++){
            matrix[i][j];
            free(matrix);    
        }
    }
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)      //������ matrix�� ���� �� ����
{
  
   for (int i = 0; i < row; i++){   //�Է��� row��ŭ�� �� ����
       for(int j = 0; j < col; j++){    //�Է��� col��ŭ�� �� ����
           matrix[i][j] = rand()%20;    //������ ��Ŀ� ���� �� ����
       }
   }

}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)   //matrix_a�� matrix_b�� ���� ���Ͽ� sum�̶�� ��ķ� ���
{
    int sum[50][50] = {0};      //sum�̶�� ��� ������ 0���� �ʱ�ȭ
    for (int i = 0; i< row; i++){     //�Է��� row��ŭ�� �� ����
       for(int j = 0; j< col; j++){     //�Է��� col��ŭ�� �� ����
           matrix_a[i][j];          //matrix_a ��� ����
           matrix_b[i][j];          //matrix_b ��� ����
           sum[i][j] = matrix_a[i][j] + matrix_b[i][j];     //matrix_a�� matrix_b�� ���� �� sum�� ����
        printf("%2d\t",sum[i][j]);  //sum ���
       }printf("\n");
    }
}
/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)    //matrix_a�� matrix_b�� ���� ���� sub�̶�� ��ķ� ���
{
  int sub[50][50] = {0};        //sub��� ��� ������ 0���� �ʱ�ȭ
    for (int i = 0; i< row; i++){       //�Է��� row��ŭ�� �� ����  
       for(int j = 0; j< col; j++){     //�Է��� col��ŭ�� �� ����
           matrix_a[i][j];          //matrix_a ��� ����
           matrix_b[i][j];          //matrix_b ��� ����
           sub[i][j] = matrix_a[i][j] - matrix_b[i][j];     //matrix_a�� matrix_b�� ���� sub�� ����
        printf("%2d\t",sub[i][j]);  //sub ���
       }printf("\n");
    }
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)    //matrix�� ���� ��ġ����Ͽ� matrix_t ����
{
for (int i = 0; i< row; i++){     
       for(int j = 0; j< col; j++){
             matrix_t[i][j] = matrix[j][i]; //row�� col�� ��ġ�� �ٲ��ָ鼭 ��ġ��� ����
       }\
}
}
/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)   //matrix_a ���� ��ġ����� matrix_t ���� �� ����
{
 int mul[50][50] = {0};
    if(row>col){                                                // row�� col ���� Ŭ ��� �迭 ��ü ���̸� col * col�� ����
    for (int i = 0; i< col; i++){     
       for(int j = 0; j< col; j++){
        matrix_a[i][j];
        matrix_t[i][j] = matrix_a[j][i];
        mul[i][j] = matrix_a[i][j] * matrix_t[i][j];
        printf("%2d\t", mul[i][j]);
       }printf("\n");
    }
    }else
    for (int i = 0; i< row; i++){                               // row�� col ���� ���� ��� �迭 ��ü ���̸� row * row�� ����
       for(int j = 0; j< row; j++){
        matrix_a[i][j];
        matrix_t[i][j] = matrix_a[j][i];
        mul[i][j] = matrix_a[i][j] * matrix_t[i][j];
        printf("%2d\t", mul[i][j]);
       }printf("\n");
    }
}