#include <iostream>
#include <iomanip>

using namespace std;

void InicialPrint(int** arr, int r, int c) {
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            arr[i][j] = i+j;
        }
    }
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void addColumn(int** arr, int r, int c, int index) {
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (j == index){
                for (int k = c; k > index; k--)
                {
                    arr[i][k] = arr[i][k - 1];
                }
                arr[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < r; i++){
        for (int j= 0; j < c; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteColumn(int** arr, int r, int c, int index) {
    for (int i = 0; i < r; i++){
        for (int j = index; j < c; j++)
        {
            arr[i][j] = arr[i][j + 1];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c-1; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

const int row = 3;
const int col = 4;
int arr[row][col];
int arr2[row][col]
{
 {4, 5, 6, 7},
 {1, 2, 4, 1},
 {4, 5, 6, 9}
};
int n;
int step;
int m;
void showArr2();
void stepArrRight(int arr2[][4], int row, int col, int step);
void stepArrLeft(int arr2[][4], int row, int col, int step);
void stepArrDown(int arr[][4], int row, int col, int step);
void stepArrUp(int arr[][4], int row, int col, int step);
void showArr();
 

int main()
{
    setlocale(LC_ALL,"");
    //задание 1 и 2
    /* const int r = 4;
    const int c = 6;
    int size=6;
    int** arr = new int*[r];
    for (int i = 0; i < r; i++){
        arr[i] = new int[c];
    }
    int index = 0;*/
    //Задание 1
    /*InicialPrint(arr, r, c);
    cout << "Введите номер куда надо добавить столбец 0-"<<c<<endl;
    cin >> index;
    if (index >= 0 && index <= size)
    {
        size++;
        addColumn(arr, r, size, index);
    }
    else
    {
        cout << "Uncorrect value" << endl;
    }
    for (int i = 0; i < r; i++)
        {
            delete[] arr[i];
        }
    delete[] arr;*/
    //Задание 2
    /*InicialPrint(arr, r, c);
    cout << "Введите номер столбца который надо удалить  0-" << c-1 << endl;
    cin >> index;
    if (index >= 0 && index < c)
    {
        deleteColumn(arr, r, c, index);
    }
    else
    {
        cout << "Uncorrect value" << endl;
    }
    for (int i = 0; i <r; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;*/

    //задание 3
    showArr();

}
void showArr2() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
}
void stepArrRight(int arr2[][4], int row, int col, int step) {
    if (step > 0) {
        for (int i = 0; i < row; i++) {
            int temp = arr2[i][col - 1];
            for (int j = col - 1; j > 0; j--) {
                arr2[i][j] = arr2[i][j - 1];
            }
            arr2[i][0] = temp;
        }
        stepArrRight(arr2, row, col, --step);
    }
}
void stepArrLeft(int arr2[][4], int row, int col, int step) {
    if (step > 0) {
        for (int i = 0; i < row; i++) {
            int temp = arr2[i][0];
            for (int j = 0; j < col; j++) {
                arr2[i][j] = arr2[i][j + 1];
            }
            arr2[i][col - 1] = temp;
        }
        stepArrLeft(arr2, row, col, --step);
    }
}
void stepArrDown(int arr[][4], int row, int col, int step) {
    if (step > 0) {
        for (int j = 0; j < col; j++) {
            int temp = arr[row - 1][j];
            for (int i = row - 1; i > 0; i--) {
                arr[i][j] = arr[i - 1][j];
            }
            arr[0][j] = temp;
        }
        stepArrDown(arr, row, col, --step);
    }
}
void stepArrUp(int arr[][4], int row, int col, int step) {
    if (step > 0) {
        for (int j = 0; j < col; j++) {
            int temp = arr[0][j];
            for (int i = 0; i < row - 1; i++) {
                arr[i][j] = arr[i + 1][j];
            }
            arr[row - 1][j] = temp;
        }
        stepArrUp(arr, row, col, --step);
    }
}
void showArr() {
    showArr2();
    cout << endl;
    cout << "Выберите кол-во сдвигов\n";
    cin >> step;
    cout << "Выберите куда сдвинуть\n";
    cout << "1-Right\n";
    cout << "2-Left\n";
    cout << "3-Up\n";
    cout << "4-Down\n";
    cin >> m;
    switch (m) {
    case 1:
        stepArrRight(arr2, row, col, step);
        break;
    case 2:
        stepArrLeft(arr2, row, col, step);
        break;
    case 3:
        stepArrUp(arr2, row, col, step);
        break;
    case 4:
        stepArrDown(arr2, row, col, step);
        break;
    default:
        cout << "Eror\n";
        break;
    }
    cout << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
}



