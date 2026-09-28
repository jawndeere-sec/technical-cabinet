#include <chrono>
#include <iostream>
#include <thread>

int main() {
    char mode;
    char color;
    char opening;

    std::cout << "Welcome to the Chess Opening Memory Aide\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    /* TODO: Do Drill section once you work out architectural pattern, changing to pretend there's only one option for now*/
    std::cout << "Press S to choose an opening and get the sequence for the first 15 moves.";
    std::cin >> mode;

    switch (mode) {
        case 'D':
        case 'd':
            std::cout << "You chose Drill - practice memorizing the first 10-15 moves of classic chess openings.\n";
            std::cout << "Are you playing as White (W) or Black (B)?\n";
            std::cin >> color;

            switch (color) {
                case 'W':
                case 'w':
                    std::cout << "White Drills have been selected.\n";
                    break;
                case 'B':
                case 'b':
                    std::cout << "Black Drills have been selected.\n";
                    break;
                default:
                    std::cout << "Invalid color choice - what kinda weird chess pieces are you using?\n";
                    break;
            }
            break;
        case 'S':
        case 's':
            std::cout << "You chose Sequence - just get the sequences of the first 10-15 moves of classic chess openings for reference during games.\n";
            std::cout << "Are you playing as White (W) or Black (B)? \n";
            std::cin >> color;

            switch (color) {
                case 'W':
                case 'w':
                    std::cout << "White Sequences have been selected.\n";
                    std::cout << "Which White opening would you like the classic line for?\n";
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << "Option 1: Italian Game (I)\n";
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << "Option 2: Vienna Game (V)\n";
                    std::cin >> opening;

                    switch (opening) {
                        case 'I':
                        case 'i':
                            std::cout << "Italian Game selected. In reality, Black may branch immediately, but this is a classic line to help reinforce the opening structure. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 1: Pawn e2 to square e4. Black likely moves the pawn from e7 to square e5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 2: Knight g1 to square f3. Black likely moves the knight from b8 to square c6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 3: Bishop f1 to square c4. Black likely moves the bishop from f8 to square c5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 4: Pawn c2 to square c3. Black likely moves the knight from g8 to square f6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 5: Pawn d2 to square d4. Black likely captures the pawn on d4 from the pawn on e5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 6: Capture on d4 with the pawn from c3. Black likely moves the bishop from c5 to b4 and gives check. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 7: Bishop c1 to square d2. Black likely captures that bishop with the bishop from b4. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 8: Capture on d2 with the knight from b1. Black likely moves the pawn from d7 to d5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 9: Capture on d5 with the pawn from e4. Black likely captures on d5 with the knight from f6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 10: Castle kingside. Black likely responds by also castling kingside. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 11: Rook f1 to square e1. Black likely moves the bishop from c8 to square e6.  \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 12: Rook a1 to square c1. Black likely moves the rook from f8 to square e8. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 13: Knight d2 to square e4. Black moves the pawn from h7 to square h6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 14: Knight e4 to square c5. Black likely moves the rook from a8 to b8. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 15: Capture the bishop on e6 with the knight from c5. Black likely captures that knight with the rook from e8. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Congrats, you're in the middlegame now! \n";
                            break;
                        case 'V':
                        case 'v':
                            std::cout << "Vienna Game selected. In reality, Black may branch immediately, but this is a classic line to help reinforce the opening structure.  \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 1: Pawn e2 to square e4. Black likely moves the pawn from e7 to square e5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 2: Knight b1 to square c3. Black likely moves the knight from g8 to square f6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 3: Pawn f2 to square f4. Black likely moves the pawn from d7 to square d5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 4: Capture the pawn on e5 with the pawn from f4. Black likely captures the pawn on e4 with the knight from f6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 5: Knight g1 to square f3. Black likely moves the bishop from f8 to square e7. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 6: Pawn d2 to square d4. Black likely castles kingside. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 7: Bishop f1 to square d3. Black likely moves the pawn from c7 to square c5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 8: Castle kingside. Black likely captures the pawn on d4 with the pawn from c5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 9: Capture the knight on e4 with the knight from c3. Black likely captures that knight with the pawn from d5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 10: Capture the pawn on e4 with the bishop from d3. Black likely moves the knight from b8 to square c6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 11: Bishop c1 to square f4. Black likely moves the bishop from c8 to square e6.  \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 12: Queen d1 to square d2. Black likely moves the rook from a8 to square c8. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 13: Pawn a2 to square a3. Black likely moves the queen from d8 to square b6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 14: Pawn b2 to square b4. Black likely moves the rook from f8 to square d8. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 15: Bishop e4 to square d3. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Congrats, you're in the middlegame now! \n";
                            break;
                    }
                    break;
                case 'B':
                case 'b':
                    std::cout << "Black Sequences have been selected.\n";
                    std::cout << "Which Black opening would you like the classic line for?\n";
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << "Option 1: Caro-Kann Defense (C) \n";
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << "Option 2: Slav Defense (S)\n";
                    std::cin >> opening;

                    switch (opening) {
                        case 'C':
                        case 'c':
                            std::cout << "Caro-Kann Defense selected. In reality, White may branch immediately, but this is a classic line to help reinforce the opening structure. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 1: White likely moves the pawn from e2 to square e4. Move the pawn from c7 to square c6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 2: White likely moves the pawn from d2 to square d4. Move the pawn from d7 to square d5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 3: White likely moves the knight from b1 to square c3. Capture the pawn on e4 with the pawn from d5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 4: White likely captures the pawn on e4 with the knight from c3. Move the bishop from c8 to square f5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 5: White likely moves the knight from e4 to square g3. Move the bishop from f5 to square g6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 6: White likely moves the pawn from h2 to square h4. Move the pawn from h7 to square h6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 7: White likely moves the knight from g1 to square f3. Move the knight from b8 to square d7. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 8: White likely moves the pawn from h4 to square h5. Move the bishop from g6 to square h7. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 9: White likely moves the bishop from f1 to square d3. Capture that bishop on d3 with the bishop from h7. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 10: White likely captures the bishop on d3 with the queen from d1. Move the pawn from e7 to square e6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 11: White likely moves the bishop from c1 to square d2. Move the knight from g8 to square f6.\n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 12: White likely castles queenside. Move the bishop from f8 to square e7. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 13: White likely moves the knight from g3 to square e4. Capture that knight on e4 with the knight from f6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 14: White likely captures the knight on e4 with the queen from d3. Move the knight from d7 to square f6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 15: White likely moves the queen from e4 to square e2. Castle kingside. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Congrats, you're in the middlegame now! \n";
                            break;
                        case 'S':
                        case 's':
                            std::cout << "Slav Defense selected. In reality, White may branch immediately, but this is a classic line to help reinforce the opening structure. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 1: White likely moves the pawn from d2 to square d4. Move the pawn from d7 to square d5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 2: White likely moves the pawn from c2 to square c4. Move the pawn from c7 to square c6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 3: White likely moves the knight from g1 to square f3. Move the knight from g8 to square f6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 4: White likely moves the knight from b1 to square c3. Capture the pawn on c4 with the pawn from d5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 5: White likely moves the pawn from a2 to square a4. Move the bishop from c8 to square f5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 6: White likely moves the pawn from e2 to square e3. Move the pawn from e7 to square e6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 7: White likely captures the pawn on c4 with the bishop from f1. Move the bishop from f8 to square b4. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 8: White likely castles kingside. Move the knight from b8 to square d7. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 9: White likely moves the queen from d1 to square e2. Move the bishop from f5 to square g6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 10: White likely moves the pawn from e3 to square e4. Castle kingside. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 11: White likely moves the bishop from c4 to square d3. Move the bishop from g6 to square h5.  \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 12: White likely moves the pawn from e4 to square e5. Move the knight from f6 to square d5. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 13: White likely captures the knight on d5 with the knight from c3. Capture that knight on d5 with the pawn from c6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 14: White likely moves the queen from e2 to square e3. Move the bishop from h5 to square g6. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Move 15: White likely moves the bishop from c1 to square d2. Capture that bishop on d2 with the bishop from b4. \n";
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "Congrats, you're in the middlegame now! \n";
                            break;
                    }
                    break;
                default:
                    std::cout << "Invalid color choice - what kinda weird chess pieces are you using?\n";
                    break;
            }
            break;
    }
}