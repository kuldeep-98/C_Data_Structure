#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

class List
{
private:
    ListNode *head;
    ListNode *end;
public:
    List(){
        head = NULL;
        end = NULL;
    };
    List(ListNode *t){
        head = t;
        end=NULL;
    }
    void Create(int A[], int n);
    void InsertLast(int val);
    void Display();
    ListNode* Merge(List *l,List *r);
};

void List::Create(int A[],int n)
{
    ListNode *temp;
    this->head = new ListNode(A[0]);
    this->end = this->head;
    for (int i = 1; i < n; i++)
    {
        temp = new ListNode(A[i]);
        this->end->next = temp;
        this->end = temp;
    } 
}

void List::InsertLast(int val){
    ListNode *temp = new ListNode(val);
    if (this->head==NULL)
    {
        this->head=this->end=temp;
    }else
    {
        this->end->next = temp;
        this->end = temp;
    }
}

void List::Display(){
    ListNode *temp = this->head;
    while (temp!=NULL)
    {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
}

ListNode* List::Merge(List *l,List *r){
    ListNode *f = l->head;
    ListNode *s = r->head;
    ListNode *third;
    ListNode *last;
    if(f==NULL&&s!=NULL)
        return s;
    else if(f!=NULL&&s==NULL)
        return f;
    else if(f==NULL&&s==NULL)
        return NULL;
    if (f->val<s->val)
    {
        third = last = f;
        f = f->next;
        last->next = NULL;
    }else
    {
        third = last = s;
        s = s->next;
        last->next = NULL;
    }
    while (f!=NULL&&s!=NULL)
    {
        if (f->val<s->val)
        {
            last->next = f;
            last = f;
            f = f->next;
            last->next = NULL;
        }else
        {
            last->next = s;
            last = s;
            s = s->next;
            last->next = NULL;
        }
    }
    if (f!=NULL) last->next=f;
    if (s!=NULL) last->next=s;
    return third;
}

int main(){
    List l,r;
    int a[3] = {1,2,4};
    r.Create(a,3);
    l.InsertLast(1);
    l.InsertLast(3);
    l.InsertLast(4);
    l.Display();
    cout<<endl;
    r.Display();
    cout<<endl;
    ListNode *t = l.Merge(&l,&r);
    List third(t);
    third.Display();
}