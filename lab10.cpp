#include <iostream>

using namespace std;

/*
 * Функция для ввода графа, т.е. для создания матрицы смежности.
 */
int **matrix_init(int vertices_count, int edges_count) {
    /*
     * Выделяем память под двумерный массив (матрицу смежности)
     */
    int **matrix = new int *[vertices_count];
    for (int i = 0; i < vertices_count; i++)
        matrix[i] = new int[vertices_count];

    /*
     * Заполняем её нулями
     */
    for (int i = 0; i < vertices_count; i++)
        for (int j = 0; j < vertices_count; j++)
            matrix[i][j] = 0;

    /*
     * Считываем пару вершин (ребро) и записываем единицу в матрицу.
     * Также при записи уменьшаем введённые значения на 1, т.к. нумерация в массиве начинается с 0, а в графах обычно с
     * единицы.
     */
    int row_number, col_cumber;
    for (int i = 0; i < edges_count; i++) {
        cin >> row_number >> col_cumber;
        matrix[--row_number][--col_cumber] = 1;
    }

    return matrix;
}

int successors_count(int **matrix, int row_number, int vertices_count) {
    int count = 0;
    for (int i = 0; i < vertices_count; i++) {
        if (matrix[row_number][i] == 1)
            count++;
    }
    return count;
}

int predecessors_count(int **matrix, int col_number, int vertices_count) {
    int count = 0;
    for (int i = 0; i < vertices_count; i++) {
        if (matrix[i][col_number] == 1)
            count++;
    }
    return count;
}

void print_vertices_with_2_or_more_successors(int **matrix, int vertices_count) {
    for (int i = 0; i < vertices_count; i++) {
        if (successors_count(matrix, i, vertices_count) > 2) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

void print_vertices_without_predecessors(int **matrix, int vertices_count) {
    for (int i = 0; i < vertices_count; i++) {
        if (predecessors_count(matrix, i, vertices_count) == 0) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

void print_predecessors_list(int **matrix, int vertices_count) {
    int count = 0;
    for (int i = 0; i < vertices_count; i++) {
        cout << i + 1 << ": ";
        for (int j = 0; j < vertices_count; j++) {
            if (matrix[j][i] == 1) {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }
}

bool is_vertice_with_one_successor(int **matrix, int vertices_count) {
    for (int i = 0; i < vertices_count; i++) {
        if (successors_count(matrix, i, vertices_count) == 1)
            return true;
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "rus");

    int **matrix = nullptr, vertices_count, edges_count;
    cout << "Введите количество вершин и рёбер\n";
    cin >> vertices_count >> edges_count;
    if (vertices_count > 10) {
        cerr << "\nКоличество вершин больше 10!\n";
        return 1;
    }
    cout << "\nВведите рёбра (пара чисел)\n";
    matrix = matrix_init(vertices_count, edges_count);
    cout << "\nНомера вершин, имеющих больше 2 преемников:\n";
    print_vertices_with_2_or_more_successors(matrix, vertices_count);
    cout << "\nНомера вершин, не имеющих предшественников:\n";
    print_vertices_without_predecessors(matrix, vertices_count);
    cout << "\nНомера предшественников для каждой вершины:\n";
    print_predecessors_list(matrix, vertices_count);
    cout << "\nЕсть ли в графе вершины, имеющие только одного предшественника? ";
    is_vertice_with_one_successor(matrix, vertices_count) ? cout << "Да.\n" : cout << "Нет.\n";

    for (int i = 0; i < vertices_count; i++)
        delete[] matrix[i];

    return 0;
}