#include <iostream>

#define NUM_List 10 //リストの要素数

/*リストの要素*/
struct node{
    int value; //値
    struct node *next; //次の要素へのポインら
};

struct node *top; //リストの先頭へのポインタ

/*値vを持つ要素をリストに追加する(実際に追加を行う)*/
void add_(int v, struct node **n)
{
    if(*n==NULL || (*n)->value<v){ //nの指している先のあたりに値vを持つ要素を追加するとき
        struct node *p; //値vを持つ要素の次に来る(予定)の要素へのポインタ

        if(*n==NULL){ //nの指している先のポインタが何も指していない
            p=NULL;
        }else if(*n==top){
            p=*n;
        } else{
            p=(*n)->next;
            n=&((*n)->next);
        }
        *n=(struct node *)calloc(1,sizeof(struct node));
        (*n)->value=v;
        (*n)->next=p;
    }else{
        add_(v,&((*n)->next));
    }
}

/*値vを持つ要素をリストに追加する*/
void add(int v)
{
    add_(v,&top);
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
    return 0;
}