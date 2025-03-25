#include <vector>
using namespace std;
#include <iostream>
// Clase Solution
class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            // Recorremos el tablero
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    // Si encontramos un número
                    if (board[i][j] != '.') {
                        // Comprobamos si el número se repite en la fila o columna
                        for (int k = 0; k < 9; k++) {
                            if ((k != i && board[k][j] == board[i][j]) || (k != j && board[i][k] == board[i][j])) {
                                return false;
                            }  
                        }
                        // Comprobamos si el número se repite en el cuadrante
                        for (int k = i / 3 * 3; k < i / 3 * 3 + 3; k++) {
                            for (int l = j / 3 * 3; l < j / 3 * 3 + 3; l++) {
                                if ((k != i || l != j) && board[k][l] == board[i][j]) {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
            return true;
            
        }
    };
int main() {
    //Se utiliza la clase, poniendo un ejemplo de uso
    Solution solution;
    vector<vector<char>> board = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    bool result = solution.isValidSudoku(board);
    // Se imprime el resultado
    if (result) {
        cout << "El sudoku es válido" << endl;
    } else {
        cout << "El sudoku no es válido" << endl;
    }
    return 0;
}

