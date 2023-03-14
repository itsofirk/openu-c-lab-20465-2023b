
/* my_strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */ 
int my_strcmp(char *s1, char *s2) { 
    for (; *s1 == *s2; s1++, s2++) 
        if (*s1 == '\0') 
            return 0; 
    return *s1 - *s2; 
} 

/* my_strncmp: like strcmp, but for first n-chars */ 
int my_strncmp(char s1[], char s2[], int n) {
    int i = 0;
    while(s1[i] && i < n){
        if(s1[i] != s2[i])
            return s1[i] - s2[i];
        ++i;
    }
    return 0;
}


/* my_strchr: returns index of c in s, or -1 if not exists*/ 
int my_strchr(char s[], char c) {
    int i;
    for(i=0; s[i]; i++)
        if (s[i] == c)
            return i;
    return -1;
} 


