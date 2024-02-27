#include<iostream>
#include<math.h>
using namespace std;

class ChessPiece {
private:
    string name;
    string color;
    char symbol;

public:
    ChessPiece() {
        this->name = "Pawn";
        this->color = "White";
        this->symbol = 'p';
    }

    ChessPiece(string newName, string newColor, char newSymbol) {
        this->name = newName;
        this->color = newColor;
        this->symbol = newSymbol;
    }

    string getPieceName() {
        return name;
    }

    string getPieceColor() {
        return color;
    }

    char getPieceSymbol() {
        return symbol;
    }

    void setName(string name) {
        this->name = name;
    }

    void setColor(string color) {
        this->color = color;
    }

    void setSymbol(char symbol) {
        this->symbol = symbol;
    }
};

class ChessBoard {
public:
    ChessPiece board[8][8];

    ChessBoard() {
        board[0][0] = ChessPiece("Rook", "white", 'r');
        board[0][1] = ChessPiece("Knight", "white", 'n');
        board[0][2] = ChessPiece("Bishup", "white", 'b');
        board[0][3] = ChessPiece("Queen", "white", 'q');
        board[0][4] = ChessPiece("King", "white", 'k');
        board[0][5] = ChessPiece("Bishup", "white", 'b');
        board[0][6] = ChessPiece("Knight", "white", 'n');
        board[0][7] = ChessPiece("Rook", "white", 'r');

        for (int i = 0; i < 8; i++) {
            board[1][i] = ChessPiece("Pawn", "white", 'p');
        }

        for (int i = 2; i < 6; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = ChessPiece(" ", " ", '.');
            }
        }
        
        for (int i = 0; i < 8; i++) {
            board[6][i] = ChessPiece("Pawn", "black", 'P');
        }

        board[7][0] = ChessPiece("Rook", "black", 'R');
        board[7][1] = ChessPiece("Knight", "black", 'N');
        board[7][2] = ChessPiece("Bishup", "black", 'B');
        board[7][3] = ChessPiece("Queen", "black", 'Q');
        board[7][4] = ChessPiece("King", "black", 'K');
        board[7][5] = ChessPiece("Bishup", "black", 'B');
        board[7][6] = ChessPiece("Knight", "black", 'N');
        board[7][7] = ChessPiece("Rook", "black", 'R');
    }

    bool movePiece(string source, string destination) {
        int source_c = source[0] - 'a';
        int source_r = source[1] - '0' - 1;
        int destination_c = destination[0] - 'a';
        int destination_r = destination[1] - '0' - 1;

        if (board[destination_r][destination_c].getPieceSymbol() == '.' || board[destination_r][destination_c].getPieceColor() != board[source_r][source_c].getPieceColor()) {
            if (board[source_r][source_c].getPieceSymbol() == 'n' || board[source_r][source_c].getPieceSymbol() == 'N') {
                if ((abs(source_r - destination_r) == 2) && (abs(source_c - destination_c) == 1)) {
                    board[destination_r][destination_c] = board[source_r][source_c];
                    board[source_r][source_c] = ChessPiece();
                    return true;
                } else {
                    cout << "Invalid move for " << board[source_r][source_c].getPieceSymbol() << endl;
                    return false;
                }
            } else if (board[source_r][source_c].getPieceSymbol() == 'p' || board[destination_r][destination_c].getPieceSymbol() == 'P') {
                if (((destination_r - source_r == 1) && (destination_c - source_c == 0)) || ((destination_r - source_r == 2) && (destination_c - source_c == 0) && source_r == 1)) {
                    board[destination_r][destination_c] = board[source_r][source_c];
                    board[source_r][source_c] = ChessPiece();
                    return true;
                } else if ((abs(destination_r - source_r) == 1) && (abs(source_c - destination_c) == 1)) {
                    board[destination_r][destination_c] = board[source_r][source_c];
                    board[source_r][source_c] = ChessPiece();
                    return true;
                } else {
                    cout << "Invalid move for " << board[destination_r][destination_c].getPieceSymbol() << endl;
                    return false;
                }
            }
        }
        return false;
    }

    void display() {
        cout << " " << "   ";
        for (char ch = 'a'; ch <= 'h'; ch++) cout << ch << "   ";
        cout << endl;

        int num = 8;
        for (int i = 7; i >= 0; i--) {
            cout << num << "   ";

            for (int j = 0; j < 8; j++) {
                cout << board[i][j].getPieceSymbol() << "   ";
            }
            cout << num-- << endl;
        }

        cout << " " << "   ";
        for (char ch = 'a'; ch <= 'h'; ch++) cout << ch << "   ";
        cout << endl;
    }
};

int main() {
    cout << "Programmer: Hafsa Rashid" <<endl<< "Student ID: 23k-0064" << endl<<endl;
    ChessBoard board1;
    board1.display();
    cout << "\n" << endl;
    if (board1.movePiece("b8","a6")) {
        cout << "VALID!" << endl;
    } else {
        cout << "INVALID MOVE!" << endl;
    }

    board1.display();

    cout << "\n" << endl;
    if (board1.movePiece("b8", "d7")) {
        cout << "VALID!" << endl;
    } else {
        cout << "INVALID MOVE!" << endl;
    }

    board1.display();

    return 0;
}
