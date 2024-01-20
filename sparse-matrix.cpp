#include <iostream>
using namespace std;

int main()
{
    int rows, cols;

    // Input the number of rows and columns
    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    int sparse_matrix[rows][cols];

    // Input the sparse matrix from the user
    cout << "Enter the elements of the sparse matrix:" << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> sparse_matrix[i][j];

    // Output the entered matrix
    cout << "Entered matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
          for (int j = 0; j < cols; j++)
            cout << sparse_matrix[i][j] << " ";
        cout << endl;
    }

    const double threshold_percentage = 55.0;
    int zero_count = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (sparse_matrix[i][j] == 0)
                zero_count++;

    double zero_percentage = static_cast<double>(zero_count) / (rows * cols) * 100;

    if (zero_percentage >= threshold_percentage) {
        cout << "The entered matrix is sparse." << endl;
    } else {
        cout << "Error: The entered matrix is not sparse. Please enter a sparse matrix." << endl;
        return 1;  // Return an error code to indicate non-sparse matrix
    }

    int size = 0;
    for (int i = 0; i < rows * cols; i++)
        if (sparse_matrix[i / cols][i % cols] != 0)
            size++;

    int new_matrix[3][size];
    int k = 0;
    for (int i = 0; i < rows * cols; i++)
        if (sparse_matrix[i / cols][i % cols] != 0)
        {
            new_matrix[0][k] = i / cols;
            new_matrix[1][k] = i % cols;
            new_matrix[2][k] = sparse_matrix[i / cols][i % cols];
            k++;
        }

    // Output the converted matrix
    cout << "Converted sparse matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
            cout << new_matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
