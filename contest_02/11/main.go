func isValidSudoku(board [9][9]int) bool {
    for i := 0; i < 9; i++ {
        if !isValidRow(board, i) || !isValidColumn(board, i) || !isValidBlock(board, i) {
            return false
        }
    }
    return true
}

func isValidRow(board [9][9]int, row int) bool {
    seen := make(map[int]bool)
    for col := 0; col < 9; col++ {
        num := board[row][col]
        if num != 0 {
            if seen[num] {
                return false
            }
            seen[num] = true
        }
    }
    return true
}

func isValidColumn(board [9][9]int, col int) bool {
    seen := make(map[int]bool)
    for row := 0; row < 9; row++ {
        num := board[row][col]
        if num != 0 {
            if seen[num] {
                return false
            }
            seen[num] = true
        }
    }
    return true
}

func isValidBlock(board [9][9]int, block int) bool {
    seen := make(map[int]bool)
    startRow, startCol := (block/3)*3, (block%3)*3
    for row := startRow; row < startRow+3; row++ {
        for col := startCol; col < startCol+3; col++ {
            num := board[row][col]
            if num != 0 {
                if seen[num] {
                    return false
                }
                seen[num] = true
            }
        }
    }
    return true
}