#include <iostream>

#define NUM_List 10 //リストの要素数

/*値vを持つ要素をリストに追加する*/
#define add(v) add_(v,&top)

/*リストのメモリ領域を開放*/
#define myFree() myFree_(&top)

/*リストの要素*/
struct node{
    int value; //値
    struct node *next; //次の要素へのポインら
};

struct node *top; //リストの先頭へのポインタ

/*値vを持つ要素をリストに追加する(実際に追加を行う)*/
void add_(int v, struct node **n)
{
    if(*n==NULL || (*n==top && (*n)->value<v) || ((*n)->next!=NULL && (*n)->next->value<v)){ //nの指している先のあたりに値vを持つ要素を追加するとき
        struct node *p; //値vを持つ要素の次に来る(予定)の要素へのポインタ

        if(*n==NULL){ //nの指している先のポインタが何も指していないとき
            p=NULL;
        }else if(*n==top && (*n)->value<v){ //nの指している先のポインタがリストの先頭を指しているとき
            p=*n;
        } else{ //nの指している先のポインタがリストの途中を指しているとき
            p=(*n)->next;
            n=&((*n)->next);
        }
        //値vを持つ要素をリストに追加
        *n=(struct node *)malloc(sizeof(struct node));
        (*n)->value=v;
        (*n)->next=p;
    }else{
        add_(v,&((*n)->next));
    }
}

/*リストの内容を表示する(実際に表示を行う)*/
void show_(struct node *n)
{
    //末尾でないとき
    if(n!=NULL) {
        std::cout << n->value << " ";
        show_(n->next);
    }
}

/*リストの内容を表示する*/
void show()
{
    show_(top);
    std::cout<<std::endl;
}

/*リストのメモリ領域を開放*/
void myFree_(struct node **n)
{
    if((*n)->next!=NULL){
        myFree_(&((*n)->next));
    }
    free(*n);
    *n=NULL;
}

int main()
{
    //リストの初期値を入力
    std::cout<<"List["<<NUM_List<<"] = ";
    for (int i = 0; i < NUM_List; ++i) {
        int tmp;

        std::cin>>tmp;
        add(tmp);
    }

    //追加データを入力
    std::cout<<"Add Data = ";
    int input;
    std::cin >> input;
    add(input);

    //リストを表示
    std::cout<<"List["<<NUM_List+1<<"] = ";
    show();

    //リストのメモリ領域を開放
    myFree();
    return 0;
}