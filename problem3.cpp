#include <iostream>

/*リストの要素*/
struct node{
    int value; //値
    struct node *next; //次の要素へのポインら
};

struct node *top; //リストの先頭へのポインタ

/*値valueを持つ要素をリストに追加する(実際に追加を行う)*/
void add_(int v, struct node **n)
{
    if(*n==NULL || (*n)->value<v){
        struct node *p;

        if(*n==NULL){
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

/*値valueを持つ要素をリストに追加する*/
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
    std::cout<<"List[10]="<<std::endl;
    for (int i = 0; i < 10; ++i) {
        int tmp;

        std::cin>>tmp;
        add(tmp);
    }

    //追加データを入力
    std::cout<<"Add Data="<<std::endl;
    int input;
    std::cin >> input;
    add(input);

    //リストを表示
    std::cout<<"List[11]="<<std::endl;
    show();
    return 0;
}