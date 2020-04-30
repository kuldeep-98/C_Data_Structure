#include <stdio.h>


int length(char *s) {
    int len;
    for (
            len = 0;
            s[len] != '\0'; ++len) {
    }
    return len;
}

void anagram(char *a,char *b){
    char h[26] ={};
    int k;
    for (int i = 0; a[i]!='\0'; ++i) {
        h[a[i]-97]++;
    }
    for (int i = 0; b[i]!='\0'; ++i) {
        h[b[i]-97]--;
    }
    for (k = 0; k <26 ; k++) {
        if (h[k]!=0) break;
    }
    if(k==26) printf("strings are anagram");
    else printf("not anagram");

}

char  reverse(char s[],int len){
    char r[len];
    for (int i = length(s)-1,j=0; i >=0; i--,j++) {
        r[j] = s[i];
    }
    for (int k = 0; k < len; ++k) {
        printf("%c",r[k]);
    }
}

int compare(char *a, char *b){
    int i ,j;
    if(length(a)>length(b)) printf("First String is greater");
    else printf("Second string is greater");
    for ( i = 0,j=0; a[i]!='\0'; ++i,j++) {
        if(a[i]!=b[i])
            break;
    }
    if(a[i] == b[j])printf("String are same");
    else if(a[i]>b[j]) printf("A is greater");
    else printf("B is greater");
}

int isPalindrome(char *s){
    for (int i = 0,j=length(s)-1; j>=i ; ++i,j--) {
        if (s[i]!=s[j])
            return 0;
    }
    return 1;
}

void duplicate(char *s){
    int h[26]={};
    for (int i = 0; s[i]!='\0'; ++i) {
        h[s[i]-97]++;
    }
    for (int j = 0; j <26 ; ++j) {
        if(h[j]>1){ printf("%c",j+97);
        printf("%d\n",h[j]);
    }}

}

char upper(char *s){
    for (int i = 0; s[i]!='\0' ; ++i) {
        if(s[i] >=65 && s[i] <=90)
        printf("%c",s[i]);
        else
            printf("%c",s[i]-32);
    }
}
int isValid(char *s){
    int i;
    for ( i = 0; s[i]!='\0'; i++) {
        if(!((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122)))
            return 0;
    }
    return 1;
}

void counting(char *s){
    int wcount=1;
    int vcount=0;
    int con = 0;
    for (int i = 0; s[i]!='\0' ; ++i) {
        if(s[i]==32 && s[i-1]!=32) wcount++;
        if(s[i]=='a'||s[i]=='o'||s[i]=='i'||s[i]=='u'||s[i]=='e') vcount++;
        if(!(s[i]=='a'||s[i]=='o'||s[i]=='i'||s[i]=='u'||s[i]=='e'||s[i]==32)) con++;
    }
    printf("Words: %d\n",wcount);
    printf("Vowels: %d",vcount);
    printf("Consonents: %d",con-wcount+1);
}
void fun(int n){
    if (n>0){
        fun(n-1);
        printf("%d",n);
    }
}

double p = 1;
double f = 1;

double taylor(int n,int power){
    if (power==0){
        return 1;
    } else{
        double r = taylor(n,power-1);
        p = p*n;
        f = f*power;
        return  r + (double)(p/f);
    }
}
int main() {
    char *s = "kulu";
    char *v = "uulk";
    printf("%lf",taylor(1,10));
    //fun(3);
    //anagram(s,v);
//    duplicate(v);
//    if(isPalindrome(s)) printf("palindrome");
//    else printf("not palindrome");
   // compare(s,v);
    //reverse(s,length(s));
//    upper(s);
//    counting(s);
//    if(isValid(s)) printf("valid");
//    else printf("invalid");
//    printf("%d",length(s));
}
