//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;
#define maxSize 10
template<class T>
class node{
    T val;
    static node *front, *last;
    node *next;
    static int size;
    public:
    // node();
    void enqueue(T ele);
    void dequeue(void);
    T Front(void);
    T Rear(void);
};  
template<class T>
node<T>* node<T>::front=NULL;
template<class T>
node<T>* node<T>::last=NULL;
template<class T>
int node<T>::size=0;
template<class T>
void node<T>::enqueue(T ele)
{
    assert(this->size <= maxSize && this->size >= 0);
    if(this->size==maxSize)
    {
        cout<<"Overflow. Can't insert.\n";
        return;
    }
    node *Node=new node;
    Node->val=ele;
    if(this->front==NULL)
    {
        assert(last==NULL && size==0);
        front=last=Node;
        if(maxSize!=1)next=NULL;
        else this->next=last;
        size++;
        return;
    }
    last->next=Node;
    last=Node;
    last->next=NULL;
    if(size == maxSize-1)
    {
        last->next=front;
    }
    size++;
    return;
}

template<class T>
void node<T>::dequeue()
{
    assert(size>=0 && size<=maxSize);
    if(this->size==0)
    {
        assert(front==last && last==NULL);
        cout<<"Underflow. The queue is empty.\n";
        return;
    }
    if(size==maxSize)
    {
        last->next=NULL;
    }
    node* temp=front;
    front=front->next;
    size--;
    free(temp);
    return;
}

template<class T>
T node<T>::Front()
{
    assert(size>=0 && size<= maxSize);
    return front->val;
}

template<class T>
T node<T>::Rear()
{
    assert(size>=0 && size<=maxSize);
    return (last->val);
}

auto type(int ch)->decltype((ch<=1)?1:(ch==2)?'1':1.0)
{
    auto b=(ch<=1)?1:(ch==2)?'1':1.0;
    cout<<b<<endl;
    decltype((ch<=1)?1:(ch==2)?'1':1.0) a;
    cout<<ch<<" "<<typeid(a).name()<<endl;
    return a;
}

int main()
{
    // printf("select the datatype\n1.int\n2.char\n3.float\n");
    // int ch;
    // cin>>ch;
    // assert(ch>0 && ch<4);
    // auto ty=type(ch);
    cout<<"insert the first element:\n";
    node<int> cq;
    int ins;cin>>ins;
    cq.enqueue(ins);
    int ch;
    printf("1.enqueue\n2.dequeue\n3.front\n4.rear\notherwise:terminate\n");
    cin>>ch;
    while(ch<5 && ch>0)
    {
        switch(ch)
        {
            case 1:cout<<"ele: ";cin>>ins;cq.enqueue(ins);break;
            case 2:cq.dequeue();break;
            case 3:cout<<cq.Front()<<endl;break;
            case 4:cout<<cq.Rear()<<endl;break;
            default: exit(0);
        }
        cout<<"choice: ";
        cin>>ch;
    }
    return 0;
}