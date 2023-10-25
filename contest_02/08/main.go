func reverse(line string) string {
	lenght := len(line)
	reverse_line := ""
	for index := lenght - 1; index >= 0; index-- {
		reverse_line += string(line[index])
	}
	return reverse_line
}
func isPalindrome(line string) bool {
	new_line := ""
	for key := range line {
		if 65 <= line[key] && line[key] <= 90 {
			new_line += string(line[key])
		}
		if 97 <= line[key] && line[key] <= 122 {
			new_line += string(line[key] - 32)
		}
	}
	return new_line == reverse(new_line)
}