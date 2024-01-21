#include <iostream>
using namespace std;

int main()
{
    int rows, cols;

    // Input the number of rows with validation
    do
    {
        cout << "Enter the number of rows (minimum 2): ";
        cin >> rows;

        if (rows < 2)
        {
            cout << "Error: Number of rows must be at least 2. Please try again." << endl;
        }
    } while (rows < 2);

    // Input the number of columns with validation
    do
    {
        cout << "Enter the number of columns (minimum 2): ";
        cin >> cols;

        if (cols < 2)
        {
            cout << "Error: Number of columns must be at least 2. Please try again." << endl;
        }
    } while (cols < 2);

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

    const double threshold_percentage = 67.0;
    int zero_count = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (sparse_matrix[i][j] == 0)
                zero_count++;

    double zero_percentage = static_cast<double>(zero_count) / (rows * cols) * 100;

    if (zero_percentage >= threshold_percentage)
    {
        cout << "The entered matrix is sparse." << endl;
    }
    else
    {
        cout << "Error: The entered matrix is not sparse. Please enter a sparse matrix." << endl;
        return 1; // Return an error code to indicate non-sparse matrix
    }

    int size = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (sparse_matrix[i][j] != 0)
                size++;
        }
    }
    int new_matrix[3][size];
    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (sparse_matrix[i][j] != 0)
            {
                new_matrix[0][k] = i;
                new_matrix[1][k] = j;
                new_matrix[2][k] = sparse_matrix[i][j];
                k++;
            }
        }
    }

    // Output the converted matrix
    cout << "Converted sparse matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << new_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
