func isLucky(num string) bool {
    if len(num) != 6 {
        return false // Проверка на длину строки
    }

    mp := map[rune]int{ // Маппинг по рунам (символам Unicode)
        '0': 0,
        '1': 1,
        '2': 2,
        '3': 3,
        '4': 4,
        '5': 5,
        '6': 6,
        '7': 7,
        '8': 8,
        '9': 9,
    }

    first := num[:3]
    last := num[3:]
    res_1 := 0
    res_2 := 0
    for _, ch := range first {
        if val, ok := mp[ch]; ok {
            res_1 += val
        } else {
            return false // Обработка некорректных символов
        }
    }
    for _, ch := range last {
        if val, ok := mp[ch]; ok {
            res_2 += val
        } else {
            return false // Обработка некорректных символов
        }
    }

    return res_1 == res_2
}