func shift(ar []int, steps int) {
    // Избавляемся от повторяющихся операций steps % 10
    steps = (steps % 10 + 10) % 10

    ar_0 := make([]int, len(ar))
    copy(ar_0, ar)

    for index := 0; index < len(ar); index++ {
        newIndex := (index + steps) % len(ar)  // Новый индекс для элемента
        ar[newIndex] = ar_0[index]
    }
}