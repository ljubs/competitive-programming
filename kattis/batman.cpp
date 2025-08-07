#include <iostream>
#include <vector>

int nQueens(int sizeOfBoard, 
            std::vector<std::vector<bool>>& isHole,
            std::vector<bool>& usedCol,
            std::vector<bool>& usedMainDiag,
            std::vector<bool>& usedAntiDiag,
            int solutions,
            int row)
{
    if (row == sizeOfBoard) {
        solutions++;
        return solutions;
    }

    for (int col = 0; col < sizeOfBoard; col++) {
        if (isHole[row][col])
            continue;


        if (usedCol[col] || usedMainDiag[row + col] || usedAntiDiag[row - col + sizeOfBoard - 1])
            continue;
        
        usedCol[col] = true;
        usedMainDiag[row + col] = true;
        usedAntiDiag[row - col + sizeOfBoard - 1] = true;

        solutions = nQueens(sizeOfBoard, isHole, usedCol, usedMainDiag, usedAntiDiag, solutions, row + 1);

        usedCol[col] = false;
        usedMainDiag[row + col] = false;
        usedAntiDiag[row - col + sizeOfBoard - 1] = false;
    }

    return solutions;
}

int main() {
    while (true) {
        int sizeOfBoard, numberOfHoles;
        std::cin >> sizeOfBoard >> numberOfHoles;
        if (sizeOfBoard == 0 && numberOfHoles == 0)
            break;
        
        std::vector<std::vector<bool>> isHole(sizeOfBoard, std::vector<bool>(sizeOfBoard, false));
        for (int i = 0; i < numberOfHoles; i++) {
            int row, col;
            std::cin >> row >> col;
            isHole[row][col] = true;
        }

        std::vector<bool> usedCol(sizeOfBoard, false);
        std::vector<bool> usedMainDiag(2 * sizeOfBoard - 1, false);
        std::vector<bool> usedAntiDiag(2 * sizeOfBoard - 1, false);
        std::cout << nQueens(sizeOfBoard, isHole, usedCol, usedMainDiag, usedAntiDiag, 0, 0) << std::endl;
    }

    return 0;
}
