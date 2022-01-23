#pragma once

char** Create_Board(int SizeOfBoard);

void DeleteBoard(char** Board, int SizeOfBoard);

bool IsLegalMoveWhite(int SizeOfBoard, int Wrow, int Wcol);

bool IsLegalMoveBlack(int SizeOfBoard, int Brow, int Bcol);

void ShowBoard(char** board, int sizeOfBoard);

bool IsInCheck(char** Board, int SizeOfBoard, int LocationOf1Rook[], int LocationOf2Rook[], int LocationOfWhiteKing[], int Brow, int Bcol);

bool Move(char** Board, int SizeOfBoard, int Wrow, int Wcol, int* LocationOf1Rook, int* LocationOf2Rook, int* LocationOfWhiteKing, int* LocationOfBlackKing, char Piece);

bool GeneratedBlackKingMove(char** Board, int SizeOfBoard, int* LocationOf1Rook, int* LocationOf2Rook, int* LocationOfWhiteKing, int* LocationOfBlackKing, int Brow, int Bcol, bool typeOfAction, bool*& rook1Exists, bool*& rook2Exists);

bool PossibleBlackMove(char** Board, int SizeOfBoard, int* LocationOf1Rook, int* LocationOf2Rook, int* LocationOfWhiteKing, int* LocationOfBlackKing, int move, bool typeOfAction, bool* rook1Exists, bool* rook2Exists);

void MoveBlackKing(char** Board, int SizeOfBoard, int* LocationOf1Rook, int* LocationOf2Rook, int* LocationOfWhiteKing, int* LocationOfBlackKing, bool* rook1Exists, bool* rook2Exists);

void Turn(char**& Board, int SizeOfBoard, int* LocationOf1Rook, int* LocationOf2Rook, int* LocationOfWhiteKing, int* LocationOfBlackKing, bool rook1Exists, bool rook2Exists);

bool IsCheckmateOrStalemate(char** Board, int SizeOfBoard, int* LocationOf1Rook, int* LocationOf2Rook, int* LocationOfWhiteKing, int* LocationOfBlackKing, bool rook1Exists, bool rook2Exists);

void NewGame(int SizeOfBoard);

void ChangeSizeOfBoard(int& SizeOfBoard);

void MainMenu(int& SizeOfBoard);