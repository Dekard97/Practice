func fill(maze [][]int) {
	rows := len(maze)
	cols := len(maze[0])

	for row := 0; row < rows; row++ {
		for col := 0; col < cols; col++ {
			if maze[row][col] == -1 {
				updateNeighbors(maze, row, col, rows, cols)
			}
		}
	}
}

func updateNeighbors(maze [][]int, row, col, rows, cols int) {
	neighbors := [][2]int{
		{-1, 0}, {1, 0}, {0, -1}, {0, 1},
		{-1, -1}, {-1, 1}, {1, -1}, {1, 1},
	}

	for _, neighbor := range neighbors {
		nRow, nCol := row+neighbor[0], col+neighbor[1]
		if nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols && maze[nRow][nCol] != -1 {
			maze[nRow][nCol]++
		}
	}
}