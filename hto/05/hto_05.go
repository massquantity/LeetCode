func replaceSpace(s string) string {
    var res bytes.Buffer
    for _, i := range s {
        if (i == ' ') {
            res.WriteString("%20")
        } else {
            res.WriteRune(i)
        }
    }
    return res.String()
}

func replaceSpace(s string) string {
    var res strings.Builder
    for i := range s {
        if (s[i] == ' ') {
            res.WriteString("%20")
        } else {
            res.WriteByte(s[i])
        }
    }
    return res.String()
}
