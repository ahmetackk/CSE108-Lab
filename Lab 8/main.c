#include <stdio.h>
#include <math.h>

// -------------------------- part 1 -----------------------------------
typedef struct {
    double data[3][3];
} matrix;

void print_matrix(matrix mat) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f ", mat.data[i][j]);
        }
        printf("\n");
    }
}

double determinant_of_matrix(matrix* initial_matrix){
    double m, a, b, c;

    a = initial_matrix->data[0][0]*( initial_matrix->data[1][1] * initial_matrix->data[2][2] - initial_matrix->data[1][2] * initial_matrix->data[2][1]); 
    b = initial_matrix->data[1][0]*( initial_matrix->data[0][1] * initial_matrix->data[2][2] - initial_matrix->data[2][1] * initial_matrix->data[0][2]);
    c = initial_matrix->data[2][0]*( initial_matrix->data[0][1] * initial_matrix->data[1][2] - initial_matrix->data[1][1] * initial_matrix->data[0][2]);

    m = a - b + c;

    return m;
}

void inverse_matrix(matrix* initial_matrix, matrix* inverted_matrix){

    double determinant = determinant_of_matrix(initial_matrix);
    if (determinant == 0) {
        printf("Matrix is not invertible.\n");
        return;
    }
    double a = initial_matrix->data[0][0];
    double b = initial_matrix->data[0][1];
    double c = initial_matrix->data[0][2];
    double d = initial_matrix->data[1][0];
    double e = initial_matrix->data[1][1];
    double f = initial_matrix->data[1][2];
    double g = initial_matrix->data[2][0];
    double h = initial_matrix->data[2][1];
    double i = initial_matrix->data[2][2];
    inverted_matrix->data[0][0] = (e*i - f*h) / determinant;
    inverted_matrix->data[0][1] = (c*h - b*i) / determinant;
    inverted_matrix->data[0][2] = (b*f - c*e) / determinant;
    inverted_matrix->data[1][0] = (f*g - d*i) / determinant;
    inverted_matrix->data[1][1] = (a*i - c*g) / determinant;
    inverted_matrix->data[1][2] = (c*d - a*f) / determinant;
    inverted_matrix->data[2][0] = (d*h - e*g) / determinant;
    inverted_matrix->data[2][1] = (b*g - a*h) / determinant;
    inverted_matrix->data[2][2] = (a*e - b*d) / determinant;

}

// ------------------------ part 2 ----------------------
typedef struct {
    double x;
    double y;
    double z;
} vector;


double find_orthogonal(vector vec_1, vector vec_2, vector* output_vec) {
    double angle;
    vector cross_product;

    cross_product.x = vec_1.y * vec_2.z - vec_1.z * vec_2.y;
    cross_product.y = vec_1.z * vec_2.x - vec_1.x * vec_2.z;
    cross_product.z = vec_1.x * vec_2.y - vec_1.y * vec_2.x;

    double dot_product = vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z;
    double vec_1_length = sqrt(vec_1.x * vec_1.x + vec_1.y * vec_1.y + vec_1.z * vec_1.z);
    double vec_2_length = sqrt(vec_2.x * vec_2.x + vec_2.y * vec_2.y + vec_2.z * vec_2.z);
    angle = acos(dot_product / (vec_1_length * vec_2_length)) * 180.0 / 3.141593;

    *output_vec = cross_product;

    return angle;
}

// ------------------------ part 3 ----------------------
typedef struct {
    double a;
    double b;
    double c;
    double d;
    char constant;
} third_order_polynomial;

typedef struct {
    double a;
    double b;
    double c;
    double d;
    double value;
    char constant;
} polynomial;

double calculate_polynomial(third_order_polynomial p, double x) {
    double result;
    result = p.a * pow(x, 3) + p.b * pow(x, 2) + p.c * x + p.d;
    return result;
}

double calculate_integrated_polynomial(third_order_polynomial p, double x) {
    double result;
    result = (p.a / 4) * pow(x, 4) + (p.b / 3) * pow(x, 3) + (p.c / 2) * pow(x, 2) + p.d * x;
    return result;
}


/*----- MAIN ------*/
int main(){
    // -------------------------- part 1 -----------------------------------
    matrix mat = {
        {{1.000, 0.9134, 0.2785},
        {0.9058, 0.6324, 0.5469},
        {0.1270, 0.0975, 0.9575}}
    };
    matrix inversemat;
    print_matrix(mat);
    double m = determinant_of_matrix(&mat);
    printf("%f\n", m);
    inverse_matrix(&mat, &inversemat);
    print_matrix(inversemat);
    m = determinant_of_matrix(&inversemat);
    printf("%f\n\n", m);

    // ------------------------ part 2 ----------------------
    vector vec_1 = {1, -2, 1};
    vector vec_2 = {3, 1, -1};
    vector ort_vec; 
    double angel;

    angel = find_orthogonal(vec_1, vec_2, &ort_vec);

    printf("Angel between vectors: %f\n", angel);
    printf("Cross product: %f,%f,%f", ort_vec.x, ort_vec.y, ort_vec.z);
}