package slice

// Exists f
func Exists(arr []string, s string) bool {
	for _, v := range arr {
		if v == s {
			return true
		}
	}
	return false
}

// UniqAppend f
func UniqAppend(arr []string, s string) []string {
	if Exists(arr, s) {
		return arr
	}
	return append(arr, s)
}

// UniqStr f
func UniqStr(arr []string) []string {
	var res = make([]string, 0)
	for _, v := range arr {
		res = UniqAppend(res, v)
	}
	return res
}
