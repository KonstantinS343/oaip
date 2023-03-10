#include <iostream>

struct Stack{
    int info;
    Stack *next;
};

void push(Stack*&,int);
Stack* pop(Stack*&);
void StackView(Stack*);
void StackDelete(Stack*&);
void ValueSort(Stack*&);
void IndicatorSort(Stack*&);
Stack* FindMin(Stack *);
void Task(Stack*&,Stack*&,Stack*);

int main()
{
    bool again =true, check=false;
    int key=0,number=0;
    Stack* MyStackTop=new Stack;
    MyStackTop=NULL;
    Stack* NewStack=new Stack;
    NewStack = NULL;

    while (again==true)
    {
        std::cout<<"1.Add;\n2.View;\n3.Extract\n4.Delete\n5.Sort;\n6.Task;\n7.Exit;"<<std::endl;
        std::cin>>key;

        switch (key)
        {   
        case 1:

            std::cout<<std::endl;
            std::cout<<"Enter a number to add in Stack: ";

            std::cin>>number;
            push(MyStackTop,number);

            std::cout<<std::endl;
            break;

        case 2:

            std::cout<<std::endl;

            StackView(MyStackTop);

            std::cout<<std::endl;
            break;

        case 3:

            std::cout<<std::endl;

            pop(MyStackTop);

            std::cout<<std::endl;

            StackView(MyStackTop);

            std::cout<<std::endl;
            break;

        case 4:

            std::cout<<std::endl;

            StackDelete(MyStackTop);

            std::cout<<std::endl;
             std::cout<<std::endl;

            StackDelete(NewStack);

            std::cout<<std::endl;
            break;

        case 5:

            std::cout<<"1.Indicator Sort;\n2.Value Sort;"<<std::endl;
            std::cin>>key;

            switch (key)
            {
            case 1:

                IndicatorSort(MyStackTop);

                std::cout<<std::endl;

                StackView(MyStackTop);

                std::cout<<std::endl;
                break;

            case 2:

                ValueSort(MyStackTop);

                std::cout<<std::endl;

                StackView(MyStackTop);

                std::cout<<std::endl;
                break;

            default:
                break;
            }
            break;

        case 6:

            if(check==true && NewStack!=NULL){
                StackView(NewStack);
                break;
            }

            Task(MyStackTop,NewStack,FindMin(MyStackTop));

            std::cout<<std::endl;

            StackView(NewStack);

            std::cout<<std::endl;
            check=true;
                  
            break;
        case 7:

            again=false;
            break;

        default:
        std::cout<<"Please, try again;"<<std::endl;
            break;
        }
    }
    return 0;
}
void push(Stack *&MyStackTop,int number) {

    Stack * new_element=new Stack;

    new_element->info=number;
    new_element->next=MyStackTop;
    MyStackTop=new_element;

}
void StackView (Stack *MyStackTop){

    std::cout<<"Stack:  ";

    Stack * Out=MyStackTop;

    while(Out!=NULL){
        std::cout << Out->info<<"  ";
        Out=Out->next;
    }

    std::cout<<std::endl;
}

Stack* pop(Stack*&MyStackTop){

    if(MyStackTop==NULL){
        std::cout<<"The stack is empty!";

        return MyStackTop;
    }

    Stack *temp=MyStackTop;
    MyStackTop=temp->next;

    delete temp;
    return MyStackTop;
}
void StackDelete(Stack *&MyStackTop){

    while(MyStackTop!=NULL){
        Stack * temp=MyStackTop;
        MyStackTop=temp->next;

        delete temp;
    }

    std::cout<<"The stack is empty!"<<std::endl;
}
void IndicatorSort(Stack *& MyStackTop){

    if(MyStackTop==NULL){
        std::cout<<"The stack is empty!"<<std::endl;
        return ;
    }

    Stack * new_element=new Stack;
    new_element->info=-1;
    new_element->next=MyStackTop;
    MyStackTop=new_element;
    Stack * End=NULL, *Buffer,*Top;

    if(MyStackTop->next->next == End){ 
         pop(MyStackTop);

        return ;
    }

    do{

        for(Top=MyStackTop; Top->next->next!=End;Top = Top->next){

            if(Top->next->info>Top->next->next->info){

                Buffer=Top->next->next;
                Top->next->next=Buffer->next;
                Buffer->next=Top->next;
                Top->next=Buffer;
            }
        }

        End=Top->next;

    }while(MyStackTop->next->next != End);

    pop(MyStackTop);
}
void ValueSort(Stack*& MyStackTop){

    if(MyStackTop==NULL){
        std::cout<<"The stack is empty!"<<std::endl;

        return ;
    }

    if(MyStackTop->next == NULL){ 
        
        return ;
    }

    Stack * End=NULL,*Top;
    int Buffer;

    do{

        for(Top=MyStackTop; Top->next!=End;Top=Top->next){

            if(Top->info>Top->next->info){

                Buffer=Top->info;
                Top->info=Top->next->info;
                Top->next->info=Buffer;
            }
        }

        End=Top;

    }while(MyStackTop->next!=Top);
}
Stack* FindMin(Stack *MyStackTop ){

    Stack *min=new Stack;
    int buf=-1;
    Stack *Buffer=MyStackTop;

    while(Buffer!=NULL){

        if(Buffer->info>buf){
            buf=Buffer->info;
        }

        Buffer=Buffer->next;
    }

    min->info=buf;

    return min;
}
void Task(Stack *&MyStackTop,Stack *&NewStack ,Stack* min){

    if(MyStackTop==NULL || MyStackTop->next==NULL){
        return ;
    }

    if( MyStackTop->next->info == min->info || MyStackTop->info == min->info){
        return;
    }

    Stack * Buffer=MyStackTop,*temp=NULL;
    int i=0,counter=0;

    while(Buffer->info!=min->info){
            counter++;
            Buffer=Buffer->next;
    }

    Buffer=MyStackTop;
    push(temp,MyStackTop->info);

    while(Buffer!=NULL){

        if( i==counter){
            temp->next= Buffer;
        }

        i++;
        Buffer=Buffer->next;
    }

    Buffer=MyStackTop;
    i=0;
    Stack* deleteElement = NULL;

    while(Buffer!=NULL){

        if(i>=1 && i <=counter-1){
            deleteElement = Buffer;
            push(NewStack,Buffer->info);
            i++;
            Buffer=Buffer->next;
            delete deleteElement;
            continue;
            }

        i++;
        Buffer=Buffer->next;
    }
    delete MyStackTop;
    MyStackTop=temp;
    StackView(temp);
    delete Buffer;
}