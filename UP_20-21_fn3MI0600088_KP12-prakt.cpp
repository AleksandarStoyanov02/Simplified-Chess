/**
*
* Solution to course project # 12
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Aleksandar Stoyanov
* @idnumber 3MI0600088
* @compiler VC
*
* <main file>
*
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include "Header.h"
using namespace std;

char** Create_Board(int SizeOfBoard) {
    char** Board = new char* [SizeOfBoard];
    for (int i = 0; i < SizeOfBoard; i++) {
        Board[i] = new char[SizeOfBoard];
    }

    for (int i = 0; i < SizeOfBoard; i++) {
        for (int j = 0; j < SizeOfBoard; j++) {
            Board[i][j] = '_';
        }
    }

    return Board;
}

void DeleteBoard(char** Board, int SizeOfBoard) {
    for (int i = 0; i < SizeOfBoard; i++) {
        delete[] Board[i];
    }
    delete[] Board;
}

//Validations for the Board

bool IsLegalMoveWhite(int SizeOfBoard, int Wrow, int Wcol) {
    if (Wrow < 0 || Wrow >= SizeOfBoard || Wcol < 0 || Wcol >= SizeOfBoard) {
        return false;
    }
    return true;
}
bool IsLegalMoveBlack(int SizeOfBoard, int Brow, int Bcol) {
    if (Brow < 0 || Brow >= SizeOfBoard || Bcol < 0 || Bcol >= SizeOfBoard) {
        return false;
    }
    return true;
}

//Visualisation of the Board

void ShowBoard(char** board, int sizeOfBoard)
{
    system("CLS");
    for (int i = 0; i < sizeOfBoard; i++){
        for (int j = 0; j < sizeOfBoard; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}

bool IsInCheck(char** Board, int SizeOfBoard, int LocationOf1Rook[], int LocationOf2Rook[], int LocationOfWhiteKing[], int Brow, int Bcol) {
    bool IsCheck = false;
    ShowBoard(Board, SizeOfBoard);
    for (int row = 0; row < SizeOfBoard; row++) {
        if ((Board[row][Bcol] == '1' || Board[row][Bcol] == '2') && (row != Brow)) {
            if (Bcol == LocationOfWhiteKing[1]) {
                if ((LocationOfWhiteKing[0] > row && LocationOfWhiteKing[0] < Brow) || (LocationOfWhiteKing[0] < row && LocationOfWhiteKing[0] > Brow)) {
                    continue;
                }
                else return true;
            }
            else return true;
        }
    }
    for (int col = 0; col < SizeOfBoard; col++) {
        if ((Board[Brow][col] == '1' || Board[Brow][col] == '2') && (col != Bcol)) {
            if (Brow == LocationOfWhiteKing[0]) {
                if ((LocationOfWhiteKing[1] > col && LocationOfWhiteKing[1] < Bcol) || (LocationOfWhiteKing[1] < col && LocationOfWhiteKing[1] > Bcol)) {
                    continue;
                }
                else return true;
            }
            else return true;
        }
    }
    return false;
}

//Move function for the white rooks and the white king

bool Move(char** Board, int SizeOfBoard, int Wrow, int Wcol, int* LocationOf1Rook, int* LocationOf2Rook, int* LocationOfWhiteKing, int* LocationOfBlackKing, char Piece) {
    if (!IsLegalMoveWhite(SizeOfBoard, Wrow, Wcol)) {
        return false;
    }
    if (Piece == '1') {
        if (Wrow == LocationOf1Rook[0]) {
            if (Board[Wrow][Wcol] != '_') {
                cout << "Invalid move! Try again!" << endl;
                return false;
            }
            else {
                if (Wcol > LocationOf1Rook[1]) {
                    for (int i = LocationOf1Rook[1] + 1; i < Wcol; i++) {
                        if (Board[Wrow][i] != '_') {
                            cout << "Invalid move! Try again!" << endl;
                            return false;
                        }

                    }
                    Board[Wrow][Wcol] = '1';
                    Board[LocationOf1Rook[0]][LocationOf1Rook[1]] = '_';
                    LocationOf1Rook[0] = Wrow;
                    LocationOf1Rook[1] = Wcol;
                    return true;
                }
                else if (Wcol < LocationOf1Rook[1]) {
                    for (int i = Wcol + 1; i < LocationOf1Rook[1]; i++) {
                        if (Board[Wrow][i] != '_') {
                            cout << "Invalid move! Try again!" << endl;
                            return false;
                        }

                    }
                    Board[Wrow][Wcol] = '1';
                    Board[LocationOf1Rook[0]][LocationOf1Rook[1]] = '_';
                    LocationOf1Rook[0] = Wrow;
                    LocationOf1Rook[1] = Wcol;
                    return true;
                }

            }

        }
        else if (Wcol == LocationOf1Rook[1]) {
            if (Board[Wrow][Wcol] != '_') {
                cout << "Invalid move! Try again!" << endl;
                return false;
            }
            else {
                if (Wrow > LocationOf1Rook[0]) {
                    for (int i = LocationOf1Rook[0] + 1; i < Wrow; i++) {
                        if (Board[i][Wcol] != '_') {
                            cout << "Invalid move! Try again!" << endl;
                            return false;
                        }

                    }
                    Board[Wrow][Wcol] = '1';
                    Board[LocationOf1Rook[0]][LocationOf1Rook[1]] = '_';
                    LocationOf1Rook[0] = Wrow;
                    LocationOf1Rook[1] = Wcol;
                    return true;
                }
                else if (Wrow < LocationOf1Rook[0]) {
                    for (int i = Wrow + 1; i < LocationOf1Rook[0]; i++) {
                        if (Board[i][Wcol] != '_') {
                            cout << "Invalid move! Try again!" << endl;
                            return false;
                        }

                    }
                    Board[Wrow][Wcol] = '1';
                    Board[LocationOf1Rook[0]][LocationOf1Rook[1]] = '_';
                    LocationOf1Rook[0] = Wrow;
                    LocationOf1Rook[1] = Wcol;
                    return true;
                }

            }

        }
    }

    if (Piece == '2') {
        if (Wrow == LocationOf2Rook[0]) {
            if (Board[Wrow][Wcol] != '_') {
                cout << "Invalid move! Try again!" << endl;
                return false;
            }
            else {
                if (Wcol > LocationOf2Rook[1]) {
                    for (int i = LocationOf2Rook[1] + 1; i < Wcol; i++) {
                        if (Board[Wrow][i] != '_') {
                            cout << "Invalid move! Try again!" << endl;
                            return false;
                        }
                    }
                    Board[Wrow][Wcol] = '2';
                    Board[LocationOf2Rook[0]][LocationOf2Rook[1]] = '_';
                    LocationOf2Rook[0] = Wrow;
                    LocationOf2Rook[1] = Wcol;
                    return true;
                }
                else if (Wcol < LocationOf2Rook[1]) {
                    for (int i = Wcol + 1; i < LocationOf2Rook[1]; i++) {
                        if (Board[Wrow][i] != '_') {
                            cout << "Invalid move! Try again!" << endl;
                            return false;
                        }

                    }
                    Board[Wrow][Wcol] = '2';
                    Board[LocationOf2Rook[0]][LocationOf2Rook[1]] = '_';
                    LocationOf2Rook[0] = Wrow;
                    LocationOf2Rook[1] = Wcol;
                    return true;
                }

            }

        }
        else if (Wcol == LocationOf2Rook[1]) {
            if (Board[Wrow][Wcol] != '_') {
                cout << "Invalid move! Try again!" << endl;
                return false;
            }
            else {
                if (Wrow > LocationOf2Rook[0]) {
                    for (int i = LocationOf2Rook[0] + 1; i < Wrow; i++) {
                        if (Board[i][Wcol] != '_') {
                            cout << "Invalid move! Try again!" << endl;
                            return false;
                        }

                    }
                    Board[Wrow][Wcol] = '2';
                    Board[LocationOf2Rook[0]][LocationOf2Rook[1]] = '_';
                    LocationOf2Rook[0] = Wrow;
                    LocationOf2Rook[1] = Wcol;
                    return true;
                }
                else if (Wrow < LocationOf2Rook[0]) {
                    for (int i = Wrow + 1; i < LocationOf2Rook[0]; i++) {
                        if (Board[i][Wcol] != '_') {
                            cout << "Invalid move! Try again!" << endl;
                            return false;
                        }

                    }
                    Board[Wrow][Wcol] = '2';
                    Board[LocationOf2Rook[0]][LocationOf2Rook[1]] = '_';
                    LocationOf2Rook[0] = Wrow;
                    LocationOf2Rook[1] = Wcol;
                    return true;
                }

            }

        }
    }
    else if (Piece == 'K') {
        if (Wrow == LocationOfWhiteKing[0] + 1 || Wrow == LocationOfWhiteKing[0] || Wrow == LocationOfWhiteKing[0] - 1) {
            if (Wcol == LocationOfWhiteKing[1] + 1 || Wcol == LocationOfWhiteKing[1] || Wcol == LocationOfWhiteKing[1] - 1) {
                if (Board[Wrow][Wcol] != '_') {
                    cout << "Invalid move! Try again!" << endl;
                    return false;
                }
                else {
                    if ((Wrow == LocationOfBlackKing[0] + 1 || Wrow == LocationOfBlackKing[0] || Wrow == LocationOfBlackKing[0] - 1)
                        && (Wcol == LocationOfBlackKing[1] + 1 || Wcol == LocationOfBlackKing[1] || Wcol == LocationOfBlackKing[1] - 1)) {
                        cout << "Invalid move! Try again!" << endl;
                        return false;
                    }
                    else {
                        Board[Wrow][Wcol] = 'K';
                        Board[LocationOfWhiteKing[0]][LocationOfWhiteKing[1]] = '_';
                        LocationOfWhiteKing[0] = Wrow;
                        LocationOfWhiteKing[1] = Wcol;
                        return true;
                    }
                }
            }
        }
    }
    cout << "Invalid move! Try again!" << endl;
    return false;
}

bool GeneratedBlackKingMove(char** Board, int SizeOfBoard, int* LocationOf1Rook, int* LocationOf2Rook, int* LocationOfWhiteKing, int* LocationOfBlackKing, int Brow, int Bcol, bool typeOfAction, bool*& rook1Exists, bool*& rook2Exists) {
    if (IsLegalMoveBlack(SizeOfBoard, Brow, Bcol)) {
        if (IsInCheck(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, Brow, Bcol) == false) {
            if (Board[Brow][Bcol] == '1' || Board[Brow][Bcol] == '2') {
                if ((Brow == LocationOfWhiteKing[0] + 1 || Brow == LocationOfWhiteKing[0] || Brow == LocationOfWhiteKing[0] - 1) && (Bcol == LocationOfWhiteKing[1] + 1 || Bcol == LocationOfWhiteKing[1] || Bcol == LocationOfWhiteKing[1] - 1)) {
                    return false;
                }
                else {
                    if (!typeOfAction) {
                        if (Board[Brow][Bcol] == '1')
                            *rook1Exists = false;
                        else if (Board[Brow][Bcol] == '2')
                            *rook2Exists = false;
                        Board[Brow][Bcol] = 'P';
                        Board[LocationOfBlackKing[0]][LocationOfBlackKing[1]] = '_';
                        LocationOfBlackKing[0] = Brow;
                        LocationOfBlackKing[1] = Bcol;
                    }
                    return true;
                }
            }
            else if (Board[Brow][Bcol] == '_') {
                if ((Brow == LocationOfWhiteKing[0] + 1 || Brow == LocationOfWhiteKing[0] || Brow == LocationOfWhiteKing[0] - 1) && (Bcol == LocationOfWhiteKing[1] + 1 || Bcol == LocationOfWhiteKing[1] || Bcol == LocationOfWhiteKing[1] - 1)) {
                    return false;
                }
                else {
                    if (!typeOfAction) {
                        Board[Brow][Bcol] = 'P';
                        Board[LocationOfBlackKing[0]][LocationOfBlackKing[1]] = '_';
                        LocationOfBlackKing[0] = Brow;
                        LocationOfBlackKing[1] = Bcol;
                    }
                    return true;
                }
            }
        }

    }
    return false;
}

//Checks all the possible moves for the Black king (case 1 is top left of the king's location( 1 row less and 1 column less) , case 2 is 1 row less same column , etc.)

bool PossibleBlackMove(char** Board, int SizeOfBoard, int* LocationOf1Rook, int* LocationOf2Rook, int* LocationOfWhiteKing, int* LocationOfBlackKing, int move, bool typeOfAction, bool* rook1Exists, bool* rook2Exists) {
    bool result = false;
    switch (move) {
    case 1: {
        result = GeneratedBlackKingMove(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, LocationOfBlackKing, LocationOfBlackKing[0] - 1, LocationOfBlackKing[1] - 1, typeOfAction, rook1Exists, rook2Exists);
        break;
    }
    case 2: {
        result = GeneratedBlackKingMove(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, LocationOfBlackKing, LocationOfBlackKing[0] - 1, LocationOfBlackKing[1], typeOfAction, rook1Exists, rook2Exists);
        break;
    }
    case 3: {
        result = GeneratedBlackKingMove(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, LocationOfBlackKing, LocationOfBlackKing[0] - 1, LocationOfBlackKing[1] + 1, typeOfAction, rook1Exists, rook2Exists);
        break;
    }
    case 4: {
        result = GeneratedBlackKingMove(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, LocationOfBlackKing, LocationOfBlackKing[0], LocationOfBlackKing[1] - 1, typeOfAction, rook1Exists, rook2Exists);
        break;
    }
    case 5: {
        result = GeneratedBlackKingMove(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, LocationOfBlackKing, LocationOfBlackKing[0], LocationOfBlackKing[1] + 1, typeOfAction, rook1Exists, rook2Exists);
        break;
    }
    case 6: {
        result = GeneratedBlackKingMove(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, LocationOfBlackKing, LocationOfBlackKing[0] + 1, LocationOfBlackKing[1] - 1, typeOfAction, rook1Exists, rook2Exists);
        break;
    }
    case 7: {
        result = GeneratedBlackKingMove(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, LocationOfBlackKing, LocationOfBlackKing[0] + 1, LocationOfBlackKing[1], typeOfAction, rook1Exists, rook2Exists);
        break;
    }
    case 8: {
        result = GeneratedBlackKingMove(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, LocationOfBlackKing, LocationOfBlackKing[0] + 1, LocationOfBlackKing[1] + 1, typeOfAction, rook1Exists, rook2Exists);
        break;
    }
    }
    return result;
}

//Randomly moves the king on a possible move location

void MoveBlackKing(char** Board, int SizeOfBoard, int* LocationOf1Rook, int* LocationOf2Rook, int* LocationOfWhiteKing, int* LocationOfBlackKing, bool* rook1Exists, bool* rook2Exists) {
    bool CheckForCheckmateOrStalemate = false;
    srand((unsigned int)time(NULL));
    int move;
    bool result;
    do {
        move = 1 + (rand() % 8);
        result = PossibleBlackMove(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, LocationOfBlackKing, move, CheckForCheckmateOrStalemate, rook1Exists, rook2Exists);
    } while (!result);
}

//Your turn

void Turn(char**& Board, int SizeOfBoard, int* LocationOf1Rook, int* LocationOf2Rook, int* LocationOfWhiteKing, int* LocationOfBlackKing, bool rook1Exists, bool rook2Exists) {
    char Piece;
    int WRow;
    int WCol;
    bool result;
    bool breakpoint;
    do {
        do {
            breakpoint = false;
            cin >> Piece >> WRow >> WCol;
            switch (Piece) {
            case '1': {
                if (rook1Exists) {
                    breakpoint = true;
                    break;
                }

                cout << "Invalid move! Try again!" << endl;
                break;
            }
            case '2': {
                if (rook2Exists) {
                    breakpoint = true;
                    break;
                }
                cout << "Invalid move! Try again!" << endl;
                break;
            }
            case 'K': {
                breakpoint = true;
                break;
            }
            default:
                cout << "Invalid move! Try again!" << endl;
            }
        } while (!breakpoint);

        result = Move(Board, SizeOfBoard, WRow, WCol, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, LocationOfBlackKing, Piece);
    } while (!result);
}

bool IsCheckmateOrStalemate(char** Board, int SizeOfBoard, int* LocationOf1Rook, int* LocationOf2Rook, int* LocationOfWhiteKing, int* LocationOfBlackKing, bool rook1Exists, bool rook2Exists) {
    bool CheckForCheckmateOfStalemate = 1;
    for (int i = 1; i < 9; i++) {
        if (PossibleBlackMove(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, LocationOfBlackKing, i, CheckForCheckmateOfStalemate, &rook1Exists, &rook2Exists)) {
            return false;
        }
    }
    if (IsInCheck(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, LocationOfBlackKing[0], LocationOfBlackKing[1])) {
        cout << "!Checkmate!" << endl;
        return true;
    }
    else {
        cout << "!Stalemate!" << endl;
        return true;
    }
}

void NewGame(int SizeOfBoard) {
    system("CLS");
    srand((unsigned int)time(NULL));
    char** Board = Create_Board(SizeOfBoard);
    int turn_counter = 0;
    int Spawn1, Spawn2;
    do {
        Spawn1 = 0 + (rand() % (SizeOfBoard - 1));
        Spawn2 = 0 + (rand() % (SizeOfBoard - 1));
    } while (!IsLegalMoveWhite(SizeOfBoard, Spawn1, Spawn2));

    int LocationOfWhiteKing[2] = { Spawn1, Spawn2 };
    Board[Spawn1][Spawn2] = 'K';

    do {
        Spawn1 = 0 + (rand() % (SizeOfBoard - 1));
        Spawn2 = 0 + (rand() % (SizeOfBoard - 1));
    } while (!IsLegalMoveWhite(SizeOfBoard, Spawn1, Spawn2) || Board[Spawn1][Spawn2] != '_');

    int LocationOf1Rook[2] = { Spawn1,Spawn2 };
    Board[Spawn1][Spawn2] = '1';

    do {
        Spawn1 = 0 + (rand() % (SizeOfBoard - 1));
        Spawn2 = 0 + (rand() % (SizeOfBoard - 1));
    } while (!IsLegalMoveWhite(SizeOfBoard, Spawn1, Spawn2) || Board[Spawn1][Spawn2] != '_');
    int LocationOf2Rook[2] = { Spawn1,Spawn2 };
    Board[Spawn1][Spawn2] = '2';

    do {
        Spawn1 = 0 + (rand() % (SizeOfBoard - 1));
        Spawn2 = 0 + (rand() % (SizeOfBoard - 1));
    } while (!IsLegalMoveWhite(SizeOfBoard, Spawn1, Spawn2) && Board[Spawn1][Spawn2] != '_' || IsInCheck(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, Spawn1, Spawn2) || ((Spawn1 == LocationOfWhiteKing[0] + 1 || Spawn1 == LocationOfWhiteKing[0] || Spawn1 == LocationOfWhiteKing[0] - 1) && (Spawn2 == LocationOfWhiteKing[1] + 1 || Spawn2 == LocationOfWhiteKing[1] || Spawn2 == LocationOfWhiteKing[1] - 1)));

    int LocationOfBlackKing[2] = { Spawn1,Spawn2 };
    Board[Spawn1][Spawn2] = 'P';

    bool rook1Exists = true;
    bool rook2Exists = true;

    while (true) {
        ShowBoard(Board, SizeOfBoard);
        Turn(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, LocationOfBlackKing, rook1Exists, rook2Exists);
        turn_counter++;
        if (IsCheckmateOrStalemate(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, LocationOfBlackKing, rook1Exists, rook2Exists))
            break;
        MoveBlackKing(Board, SizeOfBoard, LocationOf1Rook, LocationOf2Rook, LocationOfWhiteKing, LocationOfBlackKing, &rook1Exists, &rook2Exists);
        if (!rook1Exists && !rook2Exists)
            break;
    }
    if (!rook1Exists && !rook2Exists) {
        system("CLS");
        ShowBoard(Board, SizeOfBoard);
        cout << "Draw!" << endl;
    }
    cout << "Total moves needed: " << turn_counter << endl;
    DeleteBoard(Board, SizeOfBoard);
    system("Pause");
}

// Minimum size of board is 5x5

void ChangeSizeOfBoard(int& SizeOfBoard) {
    system("CLS");
    cout << "Insert a Number for the size of Board: ";
    int NewSizeOfBoard;
    cin >> NewSizeOfBoard;
    while (NewSizeOfBoard < 5) {
        cout << "Invalid size of board. Minimum size of board is 5x5" << endl;
        cin >> NewSizeOfBoard;
    }
    SizeOfBoard = NewSizeOfBoard;
}

void MainMenu(int& SizeOfBoard) {
    system("CLS");
    cout << "1.Start A New Game" << endl;
    cout << "2.Change the size of the board" << endl;
    cout << "3.Exit" << endl;

    int actionMainMenu;
    cout << "\nChoose action: ";

    do {
        cin >> actionMainMenu;
        switch (actionMainMenu) {
        case 1: {
            NewGame(SizeOfBoard);
            MainMenu(SizeOfBoard);
            break;
        }
        case 2: {
            ChangeSizeOfBoard(SizeOfBoard);
            MainMenu(SizeOfBoard);
            break;
        }
        case 3: {
            return;
        }
        default:
            cout << "Invalid action! Choose again.";
        }
    } while (actionMainMenu < 1 || actionMainMenu > 3);
}

int main() {
    int SizeOfBoard = 8;
    MainMenu(SizeOfBoard);
    return 0;
}
