#include "board.h"
#include <algorithm>
#include<iostream>
Board::Board() : m_pits(14, 4){       
    m_pits[0] = 0;  // P 1's store
    m_pits[7] = 0;  // P 2's store
    }


void Board::initializeBoard() {
    std::fill(m_pits.begin(), m_pits.end(), 4);
    m_pits[0] = 0;  
    m_pits[7] = 0; 

    notify(*this);
}

int Board::getPitStones(int pitIndex) const {
    if (pitIndex >= 0 && pitIndex < 14) 
        return m_pits[pitIndex];
    return -1;
}


void Board::moveStonesFrom(int pitIndex) {
    std::cout << "moveStonesFrom function call" << std::endl;
    // if (pitIndex < 1 || pitIndex > 13 || pitIndex == 7 || m_pits[pitIndex] == 0) {
    //     std::cerr << "Неверный ход: Выбранная лунка пуста или недопустима." << std::endl;
    //     return;
    // }

    int stones = m_pits[pitIndex];
    m_pits[pitIndex] = 0; 
    int currentPit = pitIndex;

    while (stones > 0) {
        currentPit = (currentPit + 1) % 14;

        // Пропуск склада противника
        if ((pitIndex <= 6 && currentPit == 0) || (pitIndex >= 8 && currentPit == 7)) {
            continue; // Пропускаем склад противника
        }

        // Добавляем камень в текущую ячейку
        m_pits[currentPit]++;
        stones--; // Уменьшаем количество оставшихся камней
    }

    // Проверка условия захвата после размещения последнего камня
    // Если последний камень попал в пустую лунку на стороне текущего игрока
//    if ((pitIndex <= 6 && currentPit >= 1 && currentPit <= 6) ||  // Player 2's side
//     (pitIndex >= 8 && currentPit >= 8 && currentPit <= 13)) {  // Player 1's side

//     int oppositePit = 14 - currentPit;

//     // Perform capture if there are stones in the opposite pit
//     if (m_pits[oppositePit] > 0) {
//         int capturedStones = m_pits[oppositePit] + 1;

//         if (currentPit >= 8 && currentPit <= 13) {
//             m_pits[7] += capturedStones; // Add to Player 1's store
//         } else {
//             m_pits[0] += capturedStones; // Add to Player 2's store
//         }

//         m_pits[currentPit] = 0;
//         m_pits[oppositePit] = 0;
//     }
// }

    

    // Уведомляем наблюдателей об изменении
    notify(*this);
}



bool Board::isGameOver() const {

    std::cout << "isGameOver function call" << std::endl;
    return std::all_of(m_pits.begin()+ 1 , m_pits.begin() + 7, [](int stones) { return stones == 0; }) ||
           std::all_of(m_pits.begin() + 8, m_pits.end(), [](int stones) { return stones == 0; });
}

int Board::getWinner() const {
    
    std::cout << "getWinner function call" << std::endl;

    if (!isGameOver()) return -1;
    
    int player1Total = m_pits[7] + std::accumulate(m_pits.begin() + 1 , m_pits.begin() + 7, 0);
    int player2Total = m_pits[0] + std::accumulate(m_pits.begin() + 8, m_pits.end(), 0);
    if (player1Total > player2Total) return 1;
    else if (player2Total > player1Total) return 2;
    else return 0; 
}
int Board::getPlayer1Store() const {
    return m_pits[7];
}
int Board::getPlayer2Store() const {
    return m_pits[0];

}
