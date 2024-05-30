#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>

#define N 5

void printMatrix(float matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setprecision(5) << std::setw(10) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void initializeMatrix(float matrix[N][N]) {
    srand(time(0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 10.0);
        }
    }
}

float minMatrix(float matrix[N][N]) {
    float min = matrix[0][0];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

float maxMatrix(float matrix[N][N]) {
    float max = matrix[0][0];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

float minLowerTriangular(float matrix[N][N]) {
    float min = matrix[0][0];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

float maxUpperTriangular(float matrix[N][N]) {
    float max = matrix[0][0];
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

float minUpperTriangular(float matrix[N][N]) {
    float min = matrix[0][0];
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

float minMainDiagonal(float matrix[N][N]) {
    float min = matrix[0][0];
    for (int i = 0; i < N; ++i) {
        if (matrix[i][i] < min) {
            min = matrix[i][i];
        }
    }
    return min;
}

float maxMainDiagonal(float matrix[N][N]) {
    float max = matrix[0][0];
    for (int i = 0; i < N; ++i) {
        if (matrix[i][i] > max) {
            max = matrix[i][i];
        }
    }
    return max;
}

float minSecondaryDiagonal(float matrix[N][N]) {
    float min = matrix[0][N - 1];
    for (int i = 0; i < N; ++i) {
        if (matrix[i][N - 1 - i] < min) {
            min = matrix[i][N - 1 - i];
        }
    }
    return min;
}

float maxSecondaryDiagonal(float matrix[N][N]) {
    float max = matrix[0][N - 1];
    for (int i = 0; i < N; ++i) {
        if (matrix[i][N - 1 - i] > max) {
            max = matrix[i][N - 1 - i];
        }
    }
    return max;
}

float sumMainDiagonal(float matrix[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += matrix[i][i];
    }
    return sum;
}

float sumSecondaryDiagonal(float matrix[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += matrix[i][N - 1 - i];
    }
    return sum;
}

float sumLowerTriangular(float matrix[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

float sumUpperTriangular(float matrix[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

void minValuesRows(float matrix[N][N], float minValues[N]) {
    for (int i = 0; i < N; ++i) {
        float min = matrix[i][0];
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
        minValues[i] = min;
    }
}

void maxValuesRows(float matrix[N][N], float maxValues[N]) {
    for (int i = 0; i < N; ++i) {
        float max = matrix[i][0];
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        maxValues[i] = max;
    }
}

void minValuesCols(float matrix[N][N], float minValues[N]) {
    for (int j = 0; j < N; ++j) {
        float min = matrix[0][j];
        for (int i = 0; i < N; ++i) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
        minValues[j] = min;
    }
}

void maxValuesCols(float matrix[N][N], float maxValues[N]) {
    for (int j = 0; j < N; ++j) {
        float max = matrix[0][j];
        for (int i = 0; i < N; ++i) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        maxValues[j] = max;
    }
}

void avgValuesRows(float matrix[N][N], float avgValues[N]) {
    for (int i = 0; i < N; ++i) {
        float sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += matrix[i][j];
        }
        avgValues[i] = sum / N;
    }
}

void avgValuesCols(float matrix[N][N], float avgValues[N]) {
    for (int j = 0; j < N; ++j) {
        float sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += matrix[i][j];
        }
        avgValues[j] = sum / N;
    }
}

float closestToAverage(float matrix[N][N], float avg) {
    float closestValue = matrix[0][0];
    float minDifference = fabs(matrix[0][0] - avg);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            float difference = fabs(matrix[i][j] - avg);
            if (difference < minDifference) {
                minDifference = difference;
                closestValue = matrix[i][j];
            }
        }
    }
    return closestValue;
}

int main() {
    float matrix[N][N];

    initializeMatrix(matrix);
    printMatrix(matrix);

    float minVal = minMatrix(matrix);
    std::cout << "Min matrix: " << minVal << std::endl;

    float maxVal = maxMatrix(matrix);
    std::cout << "Max matrix: " << maxVal << std::endl;

    float minLowerTri = minLowerTriangular(matrix);
    std::cout << "Min lower triangular part of the matrix: " << minLowerTri << std::endl;

    float maxUpperTri = maxUpperTriangular(matrix);
    std::cout << "Max upper triangular part of the matrix: " << maxUpperTri << std::endl;

    float minUpperTri = minUpperTriangular(matrix);
    std::cout << "Min upper triangular part of the matrix: " << minUpperTri << std::endl;

    float minMainDiag = minMainDiagonal(matrix);
    std::cout << "Min main diagonal of the matrix: " << minMainDiag << std::endl;

    float maxMainDiag = maxMainDiagonal(matrix);
    std::cout << "Max main diagonal of the matrix: " << maxMainDiag << std::endl;

    float minSecDiag = minSecondaryDiagonal(matrix);
    std::cout << "Min secondary diagonal of the matrix: " << minSecDiag << std::endl;

    float maxSecDiag = maxSecondaryDiagonal(matrix);
    std::cout << "Max secondary diagonal of the matrix: " << maxSecDiag << std::endl;

    float sumMainDiag = sumMainDiagonal(matrix);
    std::cout << "Sum of main diagonal elements: " << sumMainDiag << std::endl;

    float sumSecDiag = sumSecondaryDiagonal(matrix);
    std::cout << "Sum of secondary diagonal elements: " << sumSecDiag << std::endl;

    float sumLowerTri = sumLowerTriangular(matrix);
    std::cout << "Sum of lower triangular part elements: " << sumLowerTri << std::endl;

    float sumUpperTri = sumUpperTriangular(matrix);
    std::cout << "Sum of upper triangular part elements: " << sumUpperTri << std::endl;

    float minValuesRowsArr[N];
    minValuesRows(matrix, minValuesRowsArr);
    std::cout << "Min values of rows: ";
    for (int i = 0; i < N; ++i) {
        std::cout << minValuesRowsArr[i] << " ";
    }
    std::cout << std::endl;

    float maxValuesRowsArr[N];
    maxValuesRows(matrix, maxValuesRowsArr);
    std::cout << "Max values of rows: ";
    for (int i = 0; i < N; ++i) {
        std::cout << maxValuesRowsArr[i] << " ";
    }
    std::cout << std::endl;

    float minValuesColsArr[N];
    minValuesCols(matrix, minValuesColsArr);
    std::cout << "Min values of columns: ";
    for (int j = 0; j < N; ++j) {
        std::cout << minValuesColsArr[j] << " ";
    }
    std::cout << std::endl;

    float maxValuesColsArr[N];
    maxValuesCols(matrix, maxValuesColsArr);
    std::cout << "Max values of columns: ";
    for (int j = 0; j < N; ++j) {
        std::cout << maxValuesColsArr[j] << " ";
    }
    std::cout << std::endl;

    float avgValuesRowsArr[N];
    avgValuesRows(matrix, avgValuesRowsArr);
    std::cout << "Average values of rows: ";
    for (int i = 0; i < N; ++i) {
        std::cout << avgValuesRowsArr[i] << " ";
    }
    std::cout << std::endl;

    float avgValuesColsArr[N];
    avgValuesCols(matrix, avgValuesColsArr);
    std::cout << "Average values of columns: ";
    for (int j = 0; j < N; ++j) {
        std::cout << avgValuesColsArr[j] << " ";
    }
    std::cout << std::endl;

    float avg = (sumLowerTri + sumUpperTri) / (N * N);
    float closestValue = closestToAverage(matrix, avg);
    std::cout << "Element closest to average value: " << closestValue << std::endl;

    return 0;
}

