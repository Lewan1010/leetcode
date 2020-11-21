
int longestValidParentheses(char * s){
    int i;
    int j;
    int len;
    int top;
    int validNumOfBrakets;
    int *stack = NULL;

    if (s == NULL || strlen(s) == 0) {
        return NULL;
    }
    len = strlen(s);
    stack = (int*)malloc((len + 1) *sizeof(int));
    memset(stack, 0 , (len + 1) *sizeof(int));
    i = 0;
    j = 0;
    top = -1;
    validNumOfBrakets = 0;
    stack[++top] = -1;
    while (j < len) {
        /* 将 ( 入栈 */
        if (s[j] == '(') {
            /* 入栈 */
            stack[++top] = j;  
        } else {
            --top;
            if (top == -1) {
                stack[++top] = j;
            } else {
                validNumOfBrakets = validNumOfBrakets >= (j - stack[top]) ? validNumOfBrakets: (j - stack[top]);
            }
        }
        j++;
    }
    free(stack);
    return validNumOfBrakets;
}