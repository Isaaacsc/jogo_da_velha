#include <iostream>

using namespace std;

bool verifica(char matrix[3][3]) {
    bool vitoria = false;
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2] && matrix[i][0] != '-') {
            vitoria = true;
        }
        else{
            for ( int j = 0; j < 3; j++) {
                if (matrix[0][j] == matrix[1][j] && matrix[0][j] == matrix[2][j] && matrix[0][j] != '-') {
                    vitoria = true;
                }
            }
        }
    }
    if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2] && matrix[0][0] != '-') {
        vitoria = true;
    } else if (matrix[2][0] == matrix[1][1] && matrix[0][2] == matrix[2][0] && matrix[0][2] != '-'){
        vitoria = true;
    }
    return vitoria;
};

int main() {
    bool continuar = true;
    while (continuar) {
        bool jogar = true;
        char matrix[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
        cout << endl;
        for (int k = 0; jogar == true; k++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
            if (k == 9) {
                cout << "Deu velha!";
                jogar = false;
            } else if (!verifica(matrix)) {
                cout << endl;
                char turn;
                if (k%2 != 0) {
                    turn = 'O';
                } else {
                    turn = 'X';
                }
                cout << "Digite onde deseja atacar: ";
                int i,j;
                cin >> i >> j;
                if (matrix[i-1][j-1] == '-') {
                    matrix[i-1][j-1] = turn;
                } else {
                    cout << "Jogada inválida!! tente novamente";
                    k--;
                }
            } else {
                char turn;
                if (k%2 != 0) {
                    turn = 'X';
                } else {
                    turn = 'O';
                }

                cout << "O '" << turn << "' Ganhou!!";

                jogar = false;
            }

            if (!jogar) {
                char ans;
                cout << "Deseja jogar novamente? {y/n}";
                cin >> ans;

                if (ans == 'n') {
                    continuar = false;
                }
            }
        }
    }
    return 0;
}
