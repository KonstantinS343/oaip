#include <iostream>

using namespace std;

struct Queue
{
    int info;
    Queue *next;
    Queue *prev;
};

void Create(Queue *&,Queue *&);
void PushToBegin(int, Queue *&,Queue *&,bool);
void PushToEnd(int, Queue *&,Queue *&,bool);
bool DeleteElement(int,Queue*&,Queue *&);
void Delete(Queue *&,Queue*&);
bool Task(Queue *&,Queue *&,int,Queue *&,Queue *&);
int max(Queue *);
void ViewToBegin(Queue*,Queue *);
void ViewToEnd(Queue*,Queue *);


int main()
{
    Queue* queuebegin = new Queue;
    Queue *queueend = new Queue;
    Queue* taskbegin=new Queue;
    Queue* taskend = new Queue;
    bool check = false, checkcreate = false, checkTask = false;
    int choice;
    Create(queuebegin, queueend);
    Create(taskbegin, taskend);
    while(!check){
        cout << "1. Push to begin" << endl;
        cout << "2. Push to end" << endl;
        cout << "3. Delete element" << endl;
        cout << "4. Delete all" << endl;
        cout << "5. View from the begin" << endl;
        cout << "6. View from the end" << endl;
        cout << "7. Task" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                cout<<"Enter a nember: ";
                cin>> choice;
                PushToBegin(choice, queuebegin ,queueend,checkcreate);
                checkcreate = true;
                cout<<endl;
                break;
            case 2:
             cout<<"Enter a nember: ";
                cin>> choice;
                PushToEnd(choice, queueend, queuebegin,checkcreate);
                checkcreate = true;
                cout<<endl;
                break;
            case 3:
                cout<<"Enter a nember: ";
                cin>> choice;
                checkcreate= DeleteElement(choice,queuebegin, queueend);
                break;
            case 4:
                 Delete(queuebegin,queueend);
                 Delete(taskbegin,taskend);
                 checkTask = false;
                 checkcreate = false;
                break;
            case 5:
                 ViewToBegin(queuebegin,queueend);
                break;
            case 6:
                 ViewToEnd(queueend, queuebegin);
                break;
            case 7:
                if(checkTask == false){
                   choice=max(queuebegin);
                   if(choice==INT_MIN){
                       break;
                   }
                    
                    checkTask=Task(queuebegin,queueend,choice,taskbegin,taskend);
                }else{
                     ViewToBegin(taskbegin,taskend);
                }
                break;
            case 8:
                check = true;
                break;
            default:
                cout << "Wrong choice" << endl;
                break;
        }   
    }
    return 0;
}

void Create(Queue *&queuebegin, Queue *&queueend)
{
    queuebegin=queueend=NULL;
}

void PushToBegin(int number, Queue *&queuebegin, Queue *& queueend, bool check)
{
    Queue *temp = new Queue;
    temp->info = number;
    temp->next = NULL;
    temp->prev = NULL;
    
    if(check == false){
        queuebegin = queueend = temp;
    }else{

        temp->next = queuebegin;
        queuebegin->prev = temp;
        queuebegin = temp;
    }
    
}

void PushToEnd(int number, Queue *& queueend, Queue *& queuebegin, bool check){

    Queue *temp = new Queue;
    temp->info = number;
    temp->next = NULL;
    temp->prev = NULL;

    if(check == false){
        queuebegin = queueend = temp;
    }else{

        temp->prev = queueend;
        queueend->next = temp;
        queueend = temp;
    
    }
}
bool DeleteElement(int index,Queue*& queuebegin, Queue  *& queueend){
Queue* buffer = new Queue;
    bool check = false;
    for(Queue* temp = queuebegin;temp!=NULL;temp=temp->next){


        if(buffer->prev == NULL){
            delete buffer;
        }

        if(temp->info == index){

            if(temp->next == NULL && temp->prev==NULL){
                delete temp;
                queuebegin=queueend=NULL;
                cout<<"The element was deleted!"<<endl;
                cout<<endl;
            return false;
        }

            buffer = temp;
            check = true;

            if(temp->prev == NULL){
                queuebegin = queuebegin->next;
                queuebegin->prev=NULL;
            }else if(temp->next==NULL){
                temp->prev->next = NULL;
                queueend = queueend->prev;
                delete temp;
                break;
            }else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp=temp->next;
                delete buffer;
                temp=temp->prev;
            }
            
        }
    }


    if(check){
        cout<<"The element was deleted!"<<endl;
        cout<<endl;
    }else{
         cout<<"Such element not found!"<<endl;
        cout<<endl;
    }
    return true;
}
void Delete(Queue *&queuebegin,Queue*& queueend){

    while(queuebegin!=NULL ){
        Queue * temp = queuebegin;
        queuebegin=queuebegin->next;
        delete temp;
    }
    queueend = NULL;

    cout<<"\nQueue was deleted!"<<endl;
    cout<<endl;
}
bool Task(Queue *&queuebegin,Queue*& queueend, int max,Queue*& taskbegin,Queue*&taskend){

    if(queuebegin==queueend || queuebegin->next == queueend || queuebegin->next->info ==max || queuebegin->info == max){
        cout<<"\nQueue: "<<endl<<endl;
        return false;
    }

    Queue* temp=queuebegin->next->next, *buffer;
    PushToEnd(queuebegin->next->info,taskend,taskbegin,false);

    while(temp->info!=max){
        PushToEnd(temp->info,taskend,taskbegin,true);
        buffer= temp->prev;
        temp=temp->next;
        delete buffer;
    }
    delete temp->prev;
    queuebegin->next=temp;
    temp->prev = queuebegin;
    return true;
}
int max(Queue* queuebegin){

    Queue* temp = queuebegin;
    if(temp == NULL){
        cout<<"\nThe queue is empty!"<<endl;
        cout<<endl;
        return INT_MIN;
    }
    int max_number = temp->info;

    while(temp->next!=NULL){
        temp=temp->next;
        if(temp->info > max_number){
            max_number = temp->info;
        }
    }

    return max_number;
}
void ViewToBegin(Queue* queuebegin,Queue* queueend){
    Queue * temp = queuebegin;
    cout<<"\nQueue: ";

    if(queuebegin==NULL){
        cout<<endl;
        cout<<endl;
        return; 

    }else if(queuebegin->next == NULL && queuebegin!=queueend ){
        cout<<endl;
        cout<<endl;
        return;
    }


    while(temp!=NULL){
        cout<<temp->info<<" ";
        temp= temp->next;
    }
    cout<<endl;
    cout<<endl;

}
void ViewToEnd(Queue * queueend,Queue* queuebegin){
    Queue * temp = queueend;
    cout<<"\nQueue: ";
    
    if(queueend==NULL){
        cout<<endl;
        cout<<endl;
        return; 

    }else if(queueend->prev == NULL && queuebegin!=queueend ){
        cout<<endl;
        cout<<endl;
        return;
    }

    while(temp!=NULL){
        cout<<temp->info<<" ";
        temp= temp->prev;
    }
    cout<<endl;
    cout<<endl;
}